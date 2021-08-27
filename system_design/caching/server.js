const express = require('express');
const database = require('./database');

const app = express();
const cache = {};

app.get('/nocache/index.html' , (req,res) => {
    database.get('index.html', page => {
        res.send(page);
    });
});

app.get('/cache/index.html' , (req,res) => {
    if('index.html' in cache){
        res.send(cache['index.html']);
        return;
    }
    database.get('index.html', page => {
        cache['index.html'] = page;
        res.send(page);
    });
});

app.listen(3000, ()=> {
    console.log('Listening on 3000');
});

