var express = require('express');
var path = require('path');
var exphbs  = require('express-handlebars');

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

app.listen(8080);