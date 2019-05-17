var express = require('express');
var path = require('path');
var exphbs  = require('express-handlebars');
var multer = require('multer');
var fs = require('fs');
var findInFiles = require('find-in-files');
const escapeStringRegexp = require('escape-string-regexp');

var storage = multer.diskStorage({
  destination: function (req, file, cb) {
	cb(null, 'uploads/')
  },
  filename: function (req, file, cb) {
	cb(null, req.body.filename+path.extname(file.originalname));
  }
})

var upload = multer({dest: 'uploads/', storage: storage});

var app = express();

// app.engine('handlebars', exphbs({defaultLayout: 'main'}));
var handlebars = exphbs.create({
	extname: '.html'
});
app.set('views', path.join(__dirname, '/../Website'));
app.engine('html', handlebars.engine);
app.set('view engine', 'html');

app.use(express.static(path.join(__dirname, '/../Website')));

app.get('/', function (req, res) {
	res.render('homepage');
});

app.get('/file/:filename', function (req, res) {
	var filename = req.params.filename;
	if(fs.existsSync("./uploads/" + filename)) {
		var imgregex = /\.(jpg|jpeg|png|gif)$/i;
		res.render('page template', {
			filename: filename, 
			isImage: imgregex.test(filename)
		});
	} else {
		res.redirect('/files')
	}
});

app.get('/download/:filename', function (req, res) {
	res.download(__dirname + "/uploads/" + req.params.filename);
});

app.get('/files', function(req, res) {
	var fileNames = fs.readdirSync(__dirname + "/uploads/");
	if (!req.query.q) {
		fileNames.splice(fileNames.indexOf('.gitignore'), 1);
		res.render('files', {fileNames: fileNames});
	} else {
		var search = escapeStringRegexp(req.query.q);
		var nameMatches = fileNames.filter(word => word.match(search));
		findInFiles.find(search, './uploads', '\.(txt|py|cpp|h|java|html|css|js|json)$').then(function(results) {
			var contentMatches = Object.keys(results);
			contentMatches = contentMatches.map(function(name) {
				return name.split('\\').pop();
			});
			var matchedFiles = contentMatches.concat(nameMatches);
			console.log("Search matched:", matchedFiles);
			res.render('files', {fileNames: matchedFiles});
		});
	}
});

app.post('/upload', upload.single("file"), function (req, res, next) {
	var fileName = req.body.filename+path.extname(req.file.originalname);
	console.log("Uploading: " + fileName);
	res.redirect("/file/" + fileName);
})

app.listen(8080);