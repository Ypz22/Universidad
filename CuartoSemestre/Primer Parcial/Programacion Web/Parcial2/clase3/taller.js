function calcularPromedio(num1, num2, num3) {
    if (typeof num1 === 'number' && typeof num2 === 'number' && typeof num3 === 'number') {
        return (num1 + num2 + num3) / 3;
    } else {
        console.log('No esta bien pasado el parametro, no es numero!');
    }
}

const determinarMayor = function (num1, num2) {
    if (typeof num1 === 'number' && typeof num2 === 'number') {
        return num1 > num2 ? num1 : num2;
    } else {
        console.log('No esta bien pasado el parametro, no es numero!');
    }
}

const esPar = num => num % 2 === 0 && typeof num === 'number' ? true : false;

(function () {
    console.log(calcularPromedio(3, 6, 3));
    console.log(determinarMayor(10, 6));
    console.log(esPar(6));
})();




