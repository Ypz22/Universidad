//Ciclos
//for

const heroes = ["Spiderman", "Iroman", "Hulk", "Capitan America"];

console.log(" **** FOR condicional ****");

for (let i = 0; i < heroes.length; i++) {
    console.log(heroes[i]);
}

//itera propiedades de un objeto o los indices de un array
console.log(" **** FOR in ****");
for(let i in heroes){
    console.log(heroes[i]);
}

//Itera los valores directamente de un iterable por ejemplo array, cadenas, strings, etc
console.log("**** FOR of ****");
for(let heroe of heroes){
    console.log(heroe);
}

//Se usa for tradicional o clasico cuando se necesite el control total del indice
//Se usa el for in para iterar los propiedades de un objeto, so obtiene los indices
//Se usa of para iterar los valores de in iterable

for(let contador = 0; contador <= 10; contador++){
    if(contador % 2 == 0){
        continue; //ir a la siguiente iteracion
        //break; rompe el ciclo, sale del bucle
    }
    console.log(contador);
}

//while
const carros = ["Mazda", "Audi", "Ferrari", "BMW"];

let i = 0;

// while (i < carros.length) {
//     console.log(carros[i]);
//     i++;
// }

//usando continue

while (carros[i]){
    if(i == 1){
        i++;
        continue;
    }
    console.log(carros[i]);
    i++;
}
