const express = require('express')
const app = express();
app.listen(3000,() => {
    console.log('Listening on 3000...');
});

app.get('/hello', (req,res) => {
    console.log(req.headers);
    res.send('hello\n');
});
