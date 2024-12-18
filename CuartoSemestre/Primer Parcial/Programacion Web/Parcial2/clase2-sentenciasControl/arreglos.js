//arreglos

//formas de declarar un arreglo

const array = [1,2,3,4,5]; //mas usada
const array1 = new Array(1,2,3,4,5);
const array2 = Array.of(1,2,3,4,5);

let numero = [1,2,3,4,5];
let colores = ["Rojo", "Azul", "Verde", "Amarillo","Negro"];
let vacio = [];
let conjunto = [{nombre: "Ricardo", apellido: "Vargas"},{color:"Rojo"}];

let videojuegos = [
    "Super Mario Bros",
    "Legend of Zelda",
    "Final Fantasy",
    "Donkey Kong"
];

console.log(videojuegos);

let arreglosCosas = [
    true,
    123,
    "Hola",
    function () {},
    ()=>{},
    {a:1},
    ["Hola","Mundo"]
]

console.log({arreglosCosas});
console.log(arreglosCosas[3]);

//map,filter y reduce
//Son metodos funcionales que se ueden usar para recorrer 
// y ademas transformar los datos de un arreglo

//map 
//transforma los datos de un arreglo

let arreglos = [1,2,3,4,5];
let cuadrados = arreglos.map(num => num * num);
console.log(cuadrados);

//filter
//Filtra los datos de un arreglo

let numerosPares = [1,2,3,4,5,6];
let pares = numerosPares.filter(num => num % 2 == 0);
console.log(pares);

//reduce
//Reduce los elementos de un array

let numerosR = [1,2,3,4,5,6];
let maximo = numerosR.reduce((acumulador,num) => (num > acumulador ? num: acumulador), numerosR[0]);
console.log(maximo);

//ventajas
//son ideales para trabajar con transformaciones complejas 
//permiten un estilo de programacion funcional mas limpio y facil de usar 
