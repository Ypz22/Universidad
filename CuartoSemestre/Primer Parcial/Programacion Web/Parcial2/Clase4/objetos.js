// Objetos

//Caracteristicas principales de loas objetos en JavaScript

//Claves y valores

//Las claves son cadenas o simbolos(unicos)

//Los valores pueden ser de cualquier tipo: string, number, boolean, array, function, object

//Dinamicos

//Los obajetos pueden moficarse en tiempo de ejecucion(agregar, modificar, eliminar propiedades)

//Metodos
//Los metodos son funciones que se asocian a un objeto

let persona = {
  nombre: "Juan",
  apellido: "Perez",
  email: "jperez@gmail.com",
  edad: 25,
};

console.log(persona);

let persona2 = {
  nombre: "Dario",
  apellido: "Vargas",
  direecion: "Quito",
  email: "dvargas@gmail.com",
  nombreCompleto: function () {
    return this.nombre + " " + this.apellido;
  },
};

console.log(persona2.nombreCompleto());

const persona3 = {
  nombre: "Maria",
  email: 25,
  saludar: function () {
    console.log(`Hola, me llamo ${this.nombre}`);
  },
};
console.log(persona3.nombre);
persona3.saludar();

//Creacion de objetos con el constructor Object
//otra forma de crear un objeto vacio y agregarle propiedades

const persona4 = new Object(); //crea un objeto en memoria, es decir reserva un nuevo espacio en memoria
persona4.nombre = "Jose";
persona4.apellido = "Martinez";
persona4.saludar = () => console.log(`Hola, me llamo ${this.nombre}`);

console.log(persona4);

//usando la clase Object.create()
//Permire crear un nuevo objeto, tomando como prototipo un objeto existente

const prototipoPersona = {
  saludar: function () {
    console.log(`Hola desde prototipo, soy ${this.nombre}`);
  },
};

const persona5 = Object.create(prototipoPersona);
persona5.nombre = "Carlos";
persona5.saludar();

//Usando clases
//proporciona una sintaxis mas estructurada par la creacion de objetos JS
class Persona {
  constructor(nombre, apellido, edad, telefono) {
    this.nombre = nombre;
    this.apellido = apellido;
    this.edad = edad;
    this.telefono = telefono;
  }
  saludo() {
    console.log(`Hola desde la clase, soy ${this.nombre}`);
  }
}

const persona6 = new Persona("Juan", "Perez", 25, "0987654321");
persona6.saludo();

//Usando funciones constructoras
//Una forma mas antigua de crear objetos en JS

function Persona1(nombre, edad, email) {
  this.nombre = nombre;
  this.edad = edad;
  this.email = email;
  this.saludar = function () {
    console.log(`Hola desde funciones constructoras, soy ${this.nombre}`);
  };
}

const persona7 = new Persona1("Juan", 25, "juanperez@gmail.com");
persona7.saludar();

//Manipular objetos
//1.- agregar o modificar propiedades

const add = { nombre: "Juan" };
add.edad = 35; //agregar propiedad
add.apellido = "Perez";
add.nombre = "Carlos"; //modificar propiedad

console.log(add);

//2.- Eliminar propiedades
delete add.edad;
console.log(add);

//3. iterar sobre las propiedades de un objeto
for (let nombrePropiedad in add) {
  console.log(nombrePropiedad);
  console.log(add[nombrePropiedad]);
}

for (let clave in add) {
  console.log(`${clave}: ${add[clave]}`);
}

//4.Verificar propiedades de un objeto
console.log("nombre" in add);
console.log(add.hasOwnProperty("nombre"));

//Entornos utiles para trabajar con objetos

//1.- Object.keys()
//Devuelve un array con las claves del objeto

console.log(Object.keys(add));

//2.- Object.values()
//Devuelve un array con los valores del objeto

console.log(Object.values(add));

//3.- Object.entries()
//Devuelve un array con los pares clave-valor
console.log(Object.entries(add));

//4.- Object.assign()
//Copia las propiedades de un objeto a otro objeto
const copiaObjeto = Object.assign(add);
console.log(copiaObjeto);

//5. Object.freeze()
//Congela un objeto, es decir, no se pueden agregar, modificar o eliminar propiedades
Object.freeze(add);

//6. Object.seal()
//Permite modificar propiedades existentes pero no agregar o eliminar propiedades
Object.seal(add);

//Impriemir las propiedades de un objeto en un array
let personaArray = Object.values(add);
console.log(personaArray);

//Convertir un objeto a un string
let personaString = JSON.stringify(add);
//Notacion convierte en una cadena, stringify es convertir en cadenas las propeidades
console.log(personaString);

//Metodos get en objetos JS
//mejores practicas para acceder y modificar las propiedades de un objeto
//Acceder a los valores de las propiedades de un objeto

let personaGet = {
  nombre: "Juan",
  apellido: "Perez",
  edad: 50,
  get nombreCompleto() {
    return this.nombre + " " + this.apellido;
  }
};

console.log(personaGet.nombreCompleto);

let personaSet = {
  nombre: "Marco",
  apellido: "Valdiviezo",
  edad: 23,
  idioma: "ES",
  get lang() {
    return this.idioma.toUpperCase();
  },
  get nombreCompleto() {
    return this.nombre + " " + this.apellido;
  }
}

console.log(personaSet.lang);


let personaSet2 = {
  nombre: "Marco",
  apellido: "Valdiviezo",
  edad: 23,
  idioma: "ES",
  get lang() {
    return this.idioma.toUpperCase();
  },
  set lang(lang) {
    this.idioma = lang.toUpperCase();
  },
  get nombreCompleto() {
    return this.nombre + " " + this.apellido;
  }
}

personaSet2.lang = "en";
console.log(personaSet2.lang);

//Constructores en JavaScript
//Si se desea crear varios objetos con las mismas propiedades y metodos, se puede usar un constructor
//Por esta razon se crean constructores

//Es una funcion especial que permite trabajar con un objeto
function PersonaFC(nombre, apellido, email) {
  this.nombre = nombre;
  this.apellido = apellido;
  this.email = email;
}

let padre = new PersonaFC("Juan", "Perez", "j@gmail.com");
console.log(padre);
padre.telefono = "0987654321";
console.log(padre);

let madre = new PersonaFC("Maria", "Velez", "m@gmai.com");
console.log(madre);

function PersonaFCM(nombre, apellido, email) {
  this.nombre = nombre;
  this.apellido = apellido;
  this.email = email;
  this.nombreCompleto = function () {
    return this.nombre + " " + this.apellido;
  };
}

let padre2 = new PersonaFCM("Juan", "Perez", "j@mail.com");
console.log(padre2.nombreCompleto());

let hijo

//Uso de prototype
PersonaFCM.prototype.tel = "0987654321"; //agregar una propiedad al prototipo
console.log(padre2.tel);

//Usando metodo call
let personaCall = {
  nombre: "Diego",
  apellido: "Cajas",
  nombreCompleto: function () {
    return this.nombre + " " + this.apellido;
  },
};

let personaCall2 = {
  nombre: "Maria",
  apellido: "Velez",
};

//Para usar el metodo nombreCompleto de personaCall en personaCall2
console.log(personaCall.nombreCompleto());
console.log(personaCall.nombreCompleto.call(personaCall2));

//pasar parametros a funciones con call
let personaCall3 = {
  nombre: "Diego",
  apellido: "Cajas",
  nombreCompleto: function (titulo, tel) {
    return titulo + ": " + this.nombre + " " + this.apellido + ", " + tel;
  },
};

console.log(personaCall3.nombreCompleto("Ing", "0987654321"));
console.log(personaCall3.nombreCompleto.call(personaCall, "Lic", "0987654321"));