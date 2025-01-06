//funciones declaradas

function miFuncion(a, b) {
    console.log("La suma es: " + (a + b));
}

miFuncion(4, 3);

//Utiliar returns para funciones
function retornaValor(a, b) {
    return a + b;
}

let resultado = retornaValor(2, 4);
console.log(resultado)

//funciones de tipo expresion
let sumar = function (a, b) {
    return a + b;
}

let resultado1 = sumar(5, 4);
console.log(resultado1);

//funciones de tipo self-invoking: funciones que se llaman asi mismo
//funciones anonimas
//Nota: se pueden utilizar estas funciones cuando se carga un programa

(function (a, b) {
    console.log('Ejecutando la funcion: ' + (a + b));
})(3, 4);

function total(x, y, z) {
    console.log(arguments.length);
    return x + y;
}

total(1, 2, 5);

//funciones tipo flecha (arrow function)
const multiplicar = (x, y) => x * y;
resultado2 = multiplicar(2, 3);
console.log(resultado2);

const cuadrado = x => x * x;
console.log(cuadrado(2));

//Funciones anonimas
//Es una funcion sin nombre, comunmente usada como argumento para otras funciones

setTimeout(function () {
    console.log('Funcion anonima');
}, 1000);

//Operaciones dentro de funciones flecha
const operaciones = { sumar: (a, b) => a + b, restar: (a, b) => a - b };
console.log(operaciones.sumar?.(3, 2)); //?. sirve para que no exista error y mande undefined
console.log(operaciones.restar?.(3, 2));

function calcularPromedio(num1, num2, num3) {
    return (num1 + num2 + num3)
}
