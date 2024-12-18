let estudiante1 = {
    nombre: "Sebastian Parra",
    notas: [15,12,16,18],
    promedio: 0,
    maximo: 0,
    minimo: 0,
    mensaje: ""
}

let estudiante2 = {
    nombre: "Mateo Garcia",
    notas: [17,14,16,20],
    promedio: 0,
    maximo: 0,
    minimo: 0,
    mensaje: ""
}

let estudiante3 = {
    nombre: "David Cepeda",
    notas: [10,11,8,5],
    promedio: 0,
    maximo: 0,
    minimo: 0,
    mensaje: ""
}

let estudiante4 = {
    nombre: "Jefferson Yepez",
    notas: [20,18,19,17],
    promedio: 0,
    maximo: 0,
    minimo: 0,
    mensaje: ""
}

let estudiante5 = {
    nombre: "Juan Perez",
    notas: [12,15,15,16],
    promedio: 0,
    maximo: 0,
    minimo: 0,
    mensaje: ""
}

let estudiante6 = {
    nombre: "Daniel Hinojosa",
    notas: [16,19,20,13],
    promedio: 0,
    maximo: 0,
    minimo: 0,
    mensaje: ""
}

let estudiante7 = {
    nombre: "Andres Romero",
    notas: [17,18,19,20],
    promedio: 0,
    maximo: 0,
    minimo: 0,
    mensaje: ""
}

let estudiante8 = {
    nombre: "Eduardo Garcia",
    notas: [14,16,17,13],
    promedio: 0,
    maximo: 0,
    minimo: 0,
    mensaje: ""
}

let estudiante9 = {
    nombre: "Luis Sagnay",
    notas: [18,19,17,16],
    promedio: 0,
    maximo: 0,
    minimo: 0,
    mensaje: ""
}

let estudiante10 = {
    nombre: "Mateo Iza",
    notas: [19,18,10,11],
    promedio: 0,
    maximo: 0,
    minimo: 0,
    mensaje: ""
}

let estudianteMayor = {
    nombre: "",
    promedio:0
} 

let estudianteMenor = {
    nombre: "",
    promedio:0
} 

let estudiantes = [estudiante1,estudiante2,estudiante3,estudiante4,estudiante5,estudiante6,estudiante7,estudiante8,estudiante9,estudiante10];

for(let estudiante of estudiantes){
    for(let notas of estudiante.notas){
        estudiante.promedio += notas;
    }
    estudiante.promedio = estudiante.promedio / estudiante.notas.length;
}

for(let estudiante of estudiantes){
    let maximo = estudiante.notas.reduce((acumulador,num) => (num > acumulador ? num: acumulador), estudiante.notas[0]);
    estudiante.maximo = maximo;
    let minimo = estudiante.notas.reduce((acumulador,num) => (num < acumulador ? num: acumulador), estudiante.notas[0]);
    estudiante.minimo = minimo;
}


for(let estudiante of estudiantes){
    if(estudiante.promedio >= 0 && estudiante.promedio < 8){
        estudiante.mensaje = "Reprobado";
    }else if(estudiante.promedio >= 8 && estudiante.promedio < 12){
        estudiante.mensaje = "Aprobado";

    }else if(estudiante.promedio >= 12 &&  estudiante.promedio < 16){
        estudiante.mensaje = "Bueno";
    }else if(estudiante.promedio >= 16 && estudiante.promedio < 20){
        estudiante.mensaje = "Excelente";
    }else{
        estudiante.mensaje = "No valida";
    }
    
}

for(let estudiante of estudiantes){
    console.log(estudiante.nombre);
    console.log("Calificacion " + estudiante.mensaje);
    console.log("Promedio: " + estudiante.promedio);
    console.log("Calificacion mas alta: " + estudiante.maximo);
    console.log("Calificacion mas baja: " + estudiante.minimo);
}

for(let estudiante1 of estudiantes){
    for(let estudiante2 of estudiantes){
        if(estudiante1.maximo > estudiante2.maximo){
            estudianteMayor.nombre = estudiante1.nombre;
            estudianteMayor.promedio = estudiante1.promedio;
        }
        if(estudiante1.minimo < estudiante2.minimo){
            estudianteMenor.nombre = estudiante1;
            estudianteMenor.promedio = estudiante1.promedio;
        }
    }
}

console.log("El estudiante con el peor promedio es " + estudianteMenor.nombre + " con un promedio de " + estudianteMenor.promedio);


console.log("El estudiante con el mejor promedio es " + estudianteMayor.nombre + " con un promedio de " + estudianteMayor.promedio);