var express = require('express');
var path = require('path');
var exphbs  = require('express-handlebars');
var multer = require('multer');

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

app.post('/upload', upload.single("file"), function (req, res, next) {
	console.log(req.body.filename);
	res.redirect("/");
})

app.listen(8080);