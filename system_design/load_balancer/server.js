const express = require('express');
const app = express();

const PORT = process.env.port;

app.listen(PORT,()=>console.log(`Listening to ${PORT}.`));

app.get('/hello',(req,res)=>{
    console.log(req.headers);
    res.send(`Hello from ${PORT}.`);
});
