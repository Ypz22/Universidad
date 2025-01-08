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
    for (let producto in this) {
      if (
        this[producto].nombre === nombreProducto &&
        this[producto].cantidad >= cantidad
      ) {
        this[producto].cantidad -= cantidad;
        console.log(
          `La venta de ${cantidad} ${nombreProducto} ha sido exitosa!`
        );
      }
    }
  },
  descuentoProducto: function (descuento) {
    for (let producto in this) {
      if (this[producto].precio > 0 && this[producto].precio < 100) {
        this[producto].precio = this[producto].precio * (descuento / 100);
      }
    }
  },
};

Object.seal(inventario);

inventario.venderProducto("Laptop", 5);
inventario.venderProducto("Mouse", 10);
inventario.venderProducto("Monitor", 2);
inventario.venderProducto("Teclado", 5);
inventario.descuentoProducto(10);
console.log(inventario);
