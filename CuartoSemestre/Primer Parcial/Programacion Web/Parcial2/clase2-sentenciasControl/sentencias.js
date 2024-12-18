// sentencia if
// sentencia switch

let numero = 10;

if(numero == 1){
    console.log("El numero es 1");
}else if(numero == 2){
    console.log("El numero es 2");
}else{
    console.log("El numero no es 1 ni 2");
}

//Ejercicio estaciones de año

let mes = 5;
let estaciones;

if(mes == 1 || mes == 2){
    estaciones = "invierno";
}else if(mes = 5 || mes == 6){
    estaciones = "Primavera";
}else if(mes == 7 || mes == 8){
    estaciones = "Otoño";
}else{
    console.log("No es un mes del año");
}

console.log(estaciones);


// //calculo de la hora del dia
// 6am - 11am = mañana buenos dias
// 12pm - 19pm = tarde buenas tardes
// 20pm - 23pm = noche buenas noches 
// 24pm - 5am = dia/mañana durmiendo

let horadia = 23; 
let mensaje; 

if(horadia >= 6 && horadia < 12){
    mensaje = "Buenos dias";
}else if(horadia >=12 && horadia < 19){
    mensaje = "Buenas tardes";
}else if(horadia >= 19 && horadia < 24){
    mensaje = "Buenas noches";
}else if(horadia > 0 && horadia < 6){
    mensaje = "Durmiendo";
}else{
    mensaje ="No es una hora del dia";
}
//Tambieb funciona sin poner llaves

//Switch

let mes1 = 11;

switch (mes1) {
    case 1:
    case 2:
        estaciones = "Invierno";
        break;
    case 3:
    case 4:
        estaciones = "Primavera";
        break;
    case 5:
    case 6:
        estaciones = "Verano";
        break;
    case 7:
    case 8:
        estaciones = "Otono";
        break;
    default:
        estaciones = "No es un mes del año";
        break;
}
console.log(estaciones);

