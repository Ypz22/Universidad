//call, set interval y set timeout, promesas en javascript, async await,

// 1. - call back: Se refiere al llamado de una funcion dentro de otra funcion, esta funcion se ejecuta luego de ejecutarse la funcion contenedora
// Ejemplo: 

function procesarUsuario(nombre, callback) {
    console.log("Procesando usuario: " + nombre);
    setTimeout(() => {
        callback(nombre);
    }, 2000); // Simula una operación asincrónica
}

function mostrarMensaje(nombre) {
    console.log("Bienvenido, " + nombre);
}

procesarUsuario("Bryan", mostrarMensaje);

// 2.- Set interval: es una funcion que ejecuta repetidamente una funcion despues de un intervalo de tiempo especifico
// Estructura: setInterval(función, milisegundos, parámetros_opcionales);
// Signficado: 
// función: La función que se ejecutará repetidamente.
// milisegundos: Tiempo en milisegundos entre cada ejecución. (1000 ms = 1 segundo)
// parámetros_opcionales: Argumentos que se pueden pasar a la función.

//Ejemplo: 

let contador = 0;

let intervalo = setInterval(() => {
    contador++;
    console.log(`Contador: ${contador}`);

    if (contador === 5) {
        clearInterval(intervalo);
        console.log("Intervalo detenido.");
    }
}, 1000);

// 3.- set timeout: es una funcion que ejecuta una sola vez una funcion despues de un tiempo especifico
// Estructura: setTimeout(función, milisegundos, parámetros_opcionales);
// Significado: 
// función: La función que se ejecutará después del tiempo especificado.
// milisegundos: Tiempo en milisegundos antes de ejecutar la función (1000 ms = 1 segundo).
// parámetros_opcionales: Argumentos que se pueden pasar a la función.

// Ejemplo: 

function mostrarMensaje(nombre) {
    console.log(`Hola ${nombre}, este mensaje aparece después de 2 segundos`);
}

setTimeout(mostrarMensaje, 2000, "Bryan");

// Existe esta funcion clearTimeout(temporizador) la cual cancela antes de que se ejecute.


// 4.- Promesas: Representa un valor que estará disponible ahora, en un futuro o nunca, se utiliza para operaciones asincronas, como solicitudes de servidores, lectura de archivos o temporizadores

//Estados: 
// Pendiente (pending) → La operación aún no ha terminado.
// Resuelta (fulfilled) → La operación fue exitosa.
// Rechazada (rejected) → Ocurrió un error en la operación.

// Creacion: 
const miPromesa = new Promise((resolve, reject) => {
    let exito = true;  // Simula si la operación fue exitosa o no

    setTimeout(() => {
        if (exito) {
            resolve("✅ Operación exitosa");
        } else {
            reject("❌ Ocurrió un error");
        }
    }, 2000); // Simula una operación asincrónica de 2 segundos
});

// Consuminedo la promesa: 

miPromesa
    .then(resultado => {
        console.log(resultado); // Si todo sale bien
    })
    .catch(error => {
        console.log(error); // Si ocurre un error
    });

// .then() → Se ejecuta si la promesa se resuelve exitosamente.
// .catch() → Se ejecuta si la promesa es rechazada.



async function obtenerDatos() {
    try {
        let respuesta = await miPromesa;
        console.log(respuesta);
    } catch (error) {
        console.log(error);
    }
}

// async → Marca la función como asincrónica.
// await → Espera a que la promesa se resuelva antes de continuar.
// try/catch → Maneja los errores de manera más limpia.

obtenerDatos();

// 5.- Async / await: 
// Async: La palabra clave async se usa para declarar una función asincrónica. Esto significa que esa función siempre devolverá una promesa, incluso si no la tienes explícitamente en el código.
// Await = La palabra clave await solo se puede usar dentro de una función marcada como async. Permite "pausar" la ejecución de la función hasta que la promesa se resuelva o se rechace, lo que hace que el código se vea más secuencial (más parecido al código sincrónico).

// Ventajas de async/await sobre .then() y .catch()
// Código más legible: Usar async/await da la apariencia de código síncrono, lo que hace que sea más fácil de seguir y entender, especialmente cuando se tienen múltiples promesas encadenadas.
// Manejo de errores más sencillo: try/catch es más intuitivo y directo para manejar errores comparado con .catch().

async function obtenerUsuario(id) {
    try {
        let respuesta = await fetch(`https://api.example.com/usuarios/${id}`);
        if (!respuesta.ok) {
            throw new Error("Usuario no encontrado");
        }
        let usuario = await respuesta.json();
        console.log(usuario);
    } catch (error) {
        console.log("Error:", error.message);
    }
}

obtenerUsuario(1);  // Prueba con un id válido o inválido
