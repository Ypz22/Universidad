class Producto {
    constructor(nombre, precio, cantidad) {
        this.nombre = nombre;
        this.precio = precio;
        this.cantidad = cantidad;
    }
}

let producto1 = new Producto("laptop", 500, 50);
let producto2 = new Producto("celular", 800, 20);
let producto3 = new Producto("cargador", 30, 100);
let producto4 = new Producto("teclado", 50, 20);

const inventario = {
    productos: [producto1, producto2, producto3, producto4],

    venderProducto: function (nombre, cantidad) {
        let productoObjeto = this.productos.filter(producto => producto.nombre === nombre);
        let producto = productoObjeto[0];
        if (producto) {
            if (producto.cantidad >= cantidad) {
                producto.cantidad -= cantidad;
            } else {
                console.log('No hay suficiente stock');
            }
        } else {
            console.log("No se encontro el producto!");
        }
    },

    descuento: function (descuento) {
        for (let producto of this.productos) {
            producto.precio -= producto.precio * (descuento / 100);
        }
    }
};

Object.seal(inventario);
console.log(inventario);
inventario.venderProducto("laptop", 21);
inventario.descuento(10);
console.log(inventario);


