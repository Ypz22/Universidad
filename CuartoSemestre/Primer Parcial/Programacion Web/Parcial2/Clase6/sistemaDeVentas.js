class Producto {
    // Atributo estático
    //Se utiliza para acceder directamente a traves de la clase
    //los metodos o propiedades no requieren que se creen una instancia
    //de la clase para ser utilizados
    //se accede a traves de la clase
    static contadorProductos = 0;

    constructor(nombre, precio, categoria, cantidad) {
        this._idProducto = ++Producto.contadorProductos;
        this._nombre = nombre;
        this._precio = precio >= 0 ? precio : 0;
        this._categoria = categoria;
        this._cantidad = cantidad;
    }

    get IdProducto() {
        return this._idProducto;
    }

    get Nombre() {
        return this._nombre;
    }

    set Nombre(nombre) {
        this._nombre = nombre;
    }

    get Precio() {
        return this._precio;
    }

    set Precio(precio) {
        this._precio = precio;
    }

    toString() {
        return `IdProducto: ${this._idProducto}, Nombre: ${this._nombre}, Precio: $${this._precio}`;
    }
}


class Orden {
    static contadorOrdenes = 0;

    static get MAX_PRODUCTOS() {
        return 5;
    }

    constructor() {
        this._idOrden = ++Orden.contadorOrdenes;
        this._productos = [];
        // this._contadorProductosAgregados = 0;
    }

    get idOrden() {
        return this._idOrden;
    }

    OrdernarDescendente() {
        for (let i = 0; i < this._productos.length; i++) {
            for (let j = i; j < this._productos.length; j++) {
                if (this._productos[i]._precio > this._productos[j]._precio) {
                    let temp = this._productos[i];
                    this._productos[i] = this._productos[j];
                    this._productos[j] = temp;
                }
            }
        }
    }

    agregarProducto(producto, cantidad) {
        if (this._productos.length < Orden.MAX_PRODUCTOS) {
            if (producto._cantidad - cantidad >= 0) {
                if (producto._categoria === 'tecnologia') {
                    producto._precio -= producto._precio * 0.1;
                }
                this._productos.push(producto);
                producto._cantidad -= cantidad;
                // this._productos[this._contadorProductosAgregados++] = producto;
            } else {
                console.log(`No hay suficiente stock de ${producto._nombre}\n`);
            }
        } else {
            console.log('No se pueden agregar más productos a la orden');
        }
    }

    calcularTotal() {
        let totalVenta = 0;
        for (let producto of this._productos) {
            totalVenta += this.calcularImpuesto(producto);
        }
        return totalVenta;
    }

    mostrarOrden() {
        let productosOrden = '';
        for (let producto of this._productos) {
            productosOrden += '\n{' + producto.toString() + '}\n';
        }

        console.log(`Orden: ${this._idOrden}, Total: $${this.calcularTotal()}, Productos: \n${productosOrden}`);
    }

    calcularImpuesto(producto) {
        return producto.Precio + producto.Precio * 15 / 100;
    }
}


let producto1 = new Producto('Pantalon', 200, 'ropa', 10);
let producto2 = new Producto('Vestido', 300, 'ropa', 5);
let producto3 = new Producto('Camisa', 100, 'ropa', 10);
let producto4 = new Producto('Laptop', 500, 'tecnologia', 10);
let producto5 = new Producto('Celular', 200, 'tecnologia', 10);
let producto6 = new Producto('Tablet', 300, 'tecnologia', 10);
let producto7 = new Producto('Manzana', 5, 'comida', 10);
console.log(producto1.toString());
console.log(producto2.toString());
console.log('\n');

let orden2 = new Orden();
orden2.agregarProducto(producto1, 2);
orden2.agregarProducto(producto2, 3);
orden2.agregarProducto(producto3, 5);
orden2.agregarProducto(producto3, 6);
orden2.OrdernarDescendente();
orden2.mostrarOrden();



// //Ejemplo static
// class Calculadora {
//     static sumar(a, b) {
//         return a + b;
//     }
// }

// //Acceso al metodo estatico directamente a traves de la clase

// console.log(Calculadora.sumar(2, 3));

// // No se puede acceder desde una instancia
// // const calc = new Calculadora();
// // console.log(calc.sumar(2, 3)); // Error

// class Contador {

//     static totalInstancias = 0;
//     constructor() {
//         Contador.totalInstancias++;
//     }

//     static mostrarInstancias() {
//         return `Se han creado ${Contador.totalInstancias} instancias de la clase Contador`;
//     }
// }

// const c1 = new Contador();
// const c2 = new Contador();
// console.log(Contador.mostrarInstancias()); // Se han creado 2 instancias de la clase Contador