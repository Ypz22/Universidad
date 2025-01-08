class Producto {
  constructor(nombre, precio, cantidad) {
    this.nombre = nombre;
    this.precio = precio;
    this.cantidad = cantidad;
  }
}

const producto1 = new Producto("Laptop", 1500, 10);
const producto2 = new Producto("Mouse", 20, 50);
const producto3 = new Producto("Teclado", 30, 30);
const producto4 = new Producto("Monitor", 300, 5);

const inventario = {
  producto1,
  producto2,
  producto3,
  producto4,

  venderProducto: function (nombreProducto, cantidad) {
    for (const key in this) {
        const producto = this[key];
        if (producto && producto.nombre === nombreProducto) {
            if (producto.cantidad >= cantidad) {
                producto.cantidad -= cantidad;
                console.log(`La venta de ${cantidad} ${nombreProducto} ha sido exitosa!`);
            } else {
                console.log(`No hay suficiente stock de ${nombreProducto}`);
            }
            return;
        }
    }
    console.log(`El producto ${nombreProducto} no existe en el inventario.`);
},
  descuentoProducto: function (descuento) {
    for (let clave in this) {
        let producto = this[clave];
      if (producto.precio > 0 && producto.precio < 100) {
        producto.precio = producto.precio * (descuento / 100);
      }
    }
  },
};

Object.seal(inventario);
console.log(inventario);
inventario.venderProducto("Lapto", 11);
inventario.venderProducto("Mouse", 10);
inventario.venderProducto("Monitor", 2);
inventario.venderProducto("Teclado", 5);
inventario.descuentoProducto(10);
console.log(inventario);
