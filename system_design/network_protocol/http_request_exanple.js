/**
 * @class       : http_request_exanple
 * @author      : Shekhar Suman (shekhar0050m@gmail.com)
 * @created     : Wednesday Aug 18, 2021 10:20:11 IST
 * @description : http_request_exanple
 */

const httpRequest ={
    host: 'localhost',
    port: 8080,
    method: 'POST',
    path: '/payments',
    headers: {
        'content-type': 'application/json',
        'content-length': 51,
    },
    body: '{"data": "This is a piece of data in JSON format."}'
}

const httpResponse = {
    statuscode:200,
    headers: {
        'access-control-allow-origin': 'https://www.google.com',
        'content-type': 'application/json',
    },
    body: '{}'
}

