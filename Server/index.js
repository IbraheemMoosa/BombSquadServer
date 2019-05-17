var express = require('express');
var path = require('path');
var exphbs  = require('express-handlebars');
var multer = require('multer');
var fs = require('fs');

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
	var imgregex = /\.(jpg|jpeg|png|gif)$/i;
    res.render('page template', {
    	filename: filename, 
    	isImage: imgregex.test(filename)
    });
});

app.get('/download/:filename', function (req, res) {
	res.download(__dirname + "/uploads/" + req.params.filename);
});

app.get('/files', function(req, res) {
	var fileNames = fs.readdirSync(__dirname + "/uploads/");
	fileNames.splice(fileNames.indexOf('.gitignore'), 1);
	if (!req.query.q) {
		res.render('files', {fileNames: fileNames});
	} else {
		
		res.render('files', {fileNames: fileNames});
	}
});

app.post('/upload', upload.single("file"), function (req, res, next) {
	var fileName = req.body.filename+path.extname(req.file.originalname);
	console.log("Uploading: " + fileName);
	res.redirect("/file/" + fileName);
})

app.listen(8080);