const express = require('express');
const app = express();
const fs = require('fs');
app.use(express.json());
app.listen(3000, ()=>{console.log('Listening')});

const DATA_DIR = 'aedb_data';

const hashtable={};

app.post('/memory/:key', (req,res) => {
    hashtable[req.params.key] = req.body.data;
    res.send('Success');
});

app.get('/memory/:key', (req,res) => {
    const key = req.params.key;
    if(key in hashtable){
        res.send(console.log(hashtable[req.params.key]));
        return;
    }
    res.send(console.log(null));
});

app.post('/disk/:key', (req,res) => {
    const destinationFile = `${DATA_DIR}/${req.params.key}`;
    fs.writeFileSync( destinationFile , req.body.data);
    res.send();
});

app.get('/disk/:key', (req,res) => {
    const destinationFile = `${DATA_DIR}/${req.params.key}`;
    try {
        const data = fs.readFileSync(destinationFile);
        res.send(data);
    } catch (e) {
        res.send(e);
    }
});
