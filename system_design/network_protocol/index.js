const express = require ('express');

const app = express();

app.listen(8080,'localhost', () => 'Listening on port 8080');

app.get('/', (req,res) => {
    res.send('Hello World');
});

app.get('/about',(req,res) => {
    res.send('Fuck you' + req.header);
})
