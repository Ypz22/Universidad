//FETCH API

//Fetch API en JS perite hacer solicitudes HTTP de manera sencilla utilizando promesas. Se usa principalmente para obtener o enviar datos a un servidor(8000).
// Ejemplo basico de uso de fetch() es atravez del metodo get

fetch('https://jsonplaceholder.typicode.com/posts/1') //Uso de la API
    .then(response => response.json()) // Convierte la respuesta de la API en un objeto JSON
    .then(json => console.log(json)) // Imprime el objeto JSON en la consola
    .catch(error => console.error('Error', error)) // Si hay un error en la solicitud, se imprime en la consola


fetch('https://jsonplaceholder.typicode.com/posts', { //Uso de la API
    method: 'POST', // Metodo POST
    body: JSON.stringify({ // Cuerpo de la solicitud
        title: 'foo',
        body: 'bar',
        userId: 1
    }),
    headers: {
        'Content-type': 'application/json; charset=UTF-8',
    },
})
    .then(response => response.json()) // Convierte la respuesta de la API en un objeto JSON
    .then(json => console.log(json)) // Imprime el objeto JSON en la consola
    .catch(error => console.error('Error', error)) // Si hay un error en la solicitud, se imprime en la consola


//Fetch API
//Metodos async y await

async function obtenerDatos() {
    try {
        const respuesta = await fetch('https://jsonplaceholder.typicode.com/posts/1'); //Uso de la API
        const json = await respuesta.json(); // Convierte la respuesta de la API en un objeto JSON
        console.log(json); // Imprime el objeto JSON en la consola
    } catch (error) {
        console.error('Error', error); // Si hay un error en la solicitud, se imprime en la consola
    }
}

obtenerDatos();

// Cuando utilizamos fetch api? 
// Cuando queremos hacer solicitudes HTTP de manera sencilla utilizando promesas. Se usa principalmente para obtener o enviar datos a un servidor(8000).
//Cuando ustilizamos fetch API
// Cuando utilizamos fetch api? 
// Cuando queremos hacer solicitudes HTTP de manera sencilla utilizando promesas. Se usa principalmente para obtener o enviar datos a un servidor(8000).
//1.- Cuando necesitamos hacer algun tipo de peticiones a traves de HTTP
//2.- Para el consumo de informacion a traves de datos creados de forma no estructurada
//3.- Un uso moderno del consumo de informacion de manera asincrona

fetch('https://jsonplaceholder.typicode.com/users')
    .then(response => response.json())
    .then(users => {
        const list = document.getElementById('usuarios');
        users.forEach(element => {
            const li = document.createElement('li');
            li.textContent = element.name;
            list.appendChild(li);
        });
    })
    .catch(error => console.error('Error', error));
