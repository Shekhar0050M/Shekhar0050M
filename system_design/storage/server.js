const express = require('express');
const app = express();
app.use(express.json());
app.use(express.urlencoded({ extended: true }));
app.listen(3000,()=>{console.log('Listening')});

const hashtable = {};

app.post('/memory/:key_id', (res,req)=>{
    hashtable[req.body.key_id] = req.body.data;
    res.send(req.body.key);
});

app.get('/memory/:key',(req,res)=>{
    if(req.params.key in hashtable){
        res.send(hashtable[req.params.key]);
        return;
    }
    res.send(req.params.key + "\n");
});
