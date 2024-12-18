let nombre;
let edad;
let altura;

nombre = "Juan";
edad = 20;
altura = 1.80;

console.log("El nombre de la persona es " + nombre);
console.log("La edad de la persona es "+edad );
console.log("La altura de la persona es "+ altura + " m");

//var para declarar una variable local o una variable de bloque
//const para declarar una variable constante, es decir, su valir no va a cambiar
//if marca un bloque de instrucciones que se ejecutan si una condicion se cumple 
//switch marca un bloque de instrucciones que se ejecutan si una condicion se cumple
// while marca una condicipn de instrucciones que se ejecutan varias veces
// function marca un bloque de instrucciones que se ejecutan cuando se llama 
//try se ejecuta cuando no se produce un error 
//catch se ejecuta cuando se produce un error
//return se ejecuta cuando una condicion se cumple, ademas de retornar un valor

/*Tipos de datos en javascript*/

//tipo de dato string

let nombre3 = "Juan";
console.log(nombre3);

//tipo de dato numerico

let edad1 = 29;
console.log(edad1);

//tipo de dato object
let objecto = {
    nombre: "Juan",
    edad: 30,
    altura: 1.8
}
console.log(objecto);

//tipo de dato typeof

let var1 = "Juan";
let var2 = false;
let var3 = BigInt(233);
let var4 = [1,2,3];

console.log(var1);
console.log("Tipo de dato " + typeof var1 );

console.log(var2);
console.log("Tipo de dato " + typeof var2);

console.log(var3);
console.log("Tipo de dato " + typeof var3);

console.log(var4);
console.log("Tipo de dato " + typeof var4);

//tipo de dato boolean

let bandera = true;
console.log(bandera);
console.log(typeof bandera);

//tipo de dato function
function saludar(){}
console.log(saludar);
console.log(typeof saludar);

//tipo clase: es una funcion tambien
class Persona {
    constructor(nombre,apellido) { //atributos constructor
        this.nombre = nombre; //propiedades
        this.apellido = apellido;
    }
}

let persona = new Persona("Juan","Apellido");
console.log(persona);
console.log(typeof persona);

//tipo undefined

let variable;
console.log(variable);
console.log(typeof variable);

//tipo de dato null

let variable1 = null;
console.log(variable1);
console.log(typeof variable1);

//tipo de datos de tipo arreglo en JavaScript

let animales = ["Perro", "Gato", "raton"]
console.log(animales);
console.log(typeof animales);


//tipo de dato cadenas vacias

let autos = "";
console.log(autos);
console.log(typeof autos);

//Reglas de nombre de variables de JavaScript
let nombreCompleto;
let _nombreCompleto;
let $nombreCompleto;

//Formas incorretas 
// let 1nombreCompleto
// let #nombreCompleto
// let %nombreCompleto
//No esta permitido ingresar estos tipos de variables

//operadores en javasScript
// + suma
// - decremento
// * multiplicacion
// ** exponecial
// / division
// % modulo o residuo
// ++a; pre-incremento
let a = 50;
let x;
x = a++;
console.log(a);
console.log(x);

// post-incremento
let b = 50;
let d;
d = ++b;
console.log(b);
console.log(d);
// i--; pre-decremento
// --i; post-incremento  

let x1 = 5;
let y = 10;
let z = x + y;
console.log(z);

// Operadores de comparacion
// == comparando
// != diferente
// mayor que >
// menor que <
// mayor igual >=
// menor igual <=

// === compara valores y tipo de dato
let comparacion1 = 10;
let comparacion2 = "10";

let comparacion3 = comparacion1 == comparacion2;
console.log(comparacion3);
let comparacion4 = comparacion1 === comparacion2;
console.log(comparacion4);

//Palabras de precedencia de operadores
// La anarqui de simbolos o operadores
let a1 = 1, b1 = 2, c1 = 1;
let dato = (a1 + b1) * c1;
console.log(dato);

// operadores de asignacion 
// =
// +=
// -=
// *=
// /=


//determinar si un numero es par o no par

let numero = 10;
if(numero % 2 == 0){
    console.log("El numero es par");
}else{
    console.log("El numero es impar");
    
}

//Determinar si una persona es mayor de edad o no
let edad2 = 16;
if(edad2 < 0 && edad2 > 110){
    console.log("No es una edad valida");
}else{
    if(edad2 < 18 && edad >= 0){
        console.log("Es menor de edad");
    }
    else{
        console.log("La persona es mayor de edad");
    }
}
let s = 110;

let valmin = 100;
let valmax = 150;

// operadores ternarios
let resultado = (s >= valmin && s <= valmax) ? "El valor es maximo": "El valor es minimo"; 
console.log(resultado);

let miNumero = "10";
console.log(typeof miNumero);

let edad3 = parseInt(miNumero);
let edad4 = Number(miNumero);

if(edad4 >= 10){
    console.log("Puede votar");
}else{
    console.log("No puede votar");
}


//parseint convierte un valor en un numero entero
//number convierte un valor en un numero

console.log(parseInt("42px")); //Convierte solo el numero 
console.log(parseInt(3.1415)); //convierte solo la parte entera
console.log(parseInt("abc")); //no hay valor para convertir 

console.log(Number("42px")); //No se puede convertir toda la cadeba 
console.log(Number(3.1415)); //convierte el numero en flotante
console.log(Number("abc")); //no hay valor para convertir en la cadena
