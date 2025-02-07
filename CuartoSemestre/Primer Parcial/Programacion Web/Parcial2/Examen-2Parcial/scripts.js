class libro {
    constructor(titulo, autor, año, genero) {
        this.titulo = titulo;
        this.autor = autor;
        this.año = año;
        this.genero = genero;
    }
}

const inputGeneroAutor = document.getElementById("Genero-autor"); //btn buscar
const librosFiltrados = document.getElementById("libros-filtrados");
const btnBuscar = document.getElementById("btn-search");

const btnfilter = document.getElementById("filter-libros");
const btnDisponibles = document.getElementById("disponibles");
const bntPrestados = document.getElementById("btn-mostrar-prestados");
const pLibros = document.getElementById("libros-disponibles");

const inputPrestados = document.getElementById("prestar-libro");
const btnPrestar = document.getElementById("btn-prestar");
const pPrestados = document.getElementById("libro-prestado");



let libros = [new libro("El señor de los anillos", "J.R.R. Tolkien", 1954, "Fantasía"), new libro("Harry Potter", "J.K. Rowling", 2000, "Fantasía"), new libro("Cien años de soledad", "Gabriel García Márquez", 1967, "Realismo mágico", new libro("El principito", "Antoine de Saint-Exupéry", 1943, "Infantil"))];

let prestados = [];

btnPrestar.addEventListener("click", function () {
    let libroPrestado = inputPrestados.value;
    pPrestados.innertHTML = '';
    let libroEncontrado = libros.find(libro => libro.titulo === libroPrestado);
    if (libroEncontrado) {
        pPrestados.innerHTML += '<br>El libro se ha prestado con exito!!';
        pPrestados.innerHTML = 'Libro prestado: ' + libroEncontrado.titulo + ' ' + libroEncontrado.autor + ' ' + libroEncontrado.año + ' ' + libroEncontrado.genero;
        prestados.push(libroEncontrado);
        libros.pop(libroEncontrado);

    } else {
        pLibros.innerHTML = 'Libro no encontrado';
    }
})


btnBuscar.addEventListener("click", function () {
    librosFiltrados.innerHTML = '';
    let generoAutor = inputGeneroAutor.value;
    let librosPorFiltracion = libros.filter(libro => libro.genero === generoAutor || libro.autor === generoAutor || libro.titulo === generoAutor);
    for (let i = 0; i < librosPorFiltracion.length; i++) {
        librosFiltrados.innerHTML += 'Libro ' + i + ' ' + librosPorFiltracion[i].titulo + ' ' + librosPorFiltracion[i].autor + ' ' + librosPorFiltracion[i].año + ' ' + librosPorFiltracion[i].genero + '<br>';
    }
})

btnDisponibles.addEventListener("click", function () {
    pLibros.innerHTML = '';
    for (let i = 0; i < libros.length; i++) {
        pLibros.innerHTML += 'Libro ' + i + ' ' + libros[i].titulo + ' ' + libros[i].autor + ' ' + libros[i].año + ' ' + libros[i].genero + '<br>';
    }
})







