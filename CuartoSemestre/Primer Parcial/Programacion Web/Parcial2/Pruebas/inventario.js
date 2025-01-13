class Producto {
    constructor(nombre, precio, cantidad, categoria) {
        this.nombre = nombre;
        this.precio = precio;
        this.cantidad = cantidad;
        this.categoria = categoria;
    }

    get obtenerNombre() {
        return this.nombre;
    }

    set ModificarNombre(nombre) {
        this.nombre = nombre;
    }

}

class Venta {
    #ventas = [];

    get obtenerVentas() {
        return this.#ventas;
    }

    realizarVenta(nombreProducto, cantidad) {
        let productos = this.productos.filter(producto => producto.nombre === nombreProducto);
        let producto = productos[0];
        if (producto) {
            if (producto.cantidad >= cantidad) {
                producto.cantidad -= cantidad;
                let productosVendido = this.#ventas.filter(producto => producto.nombre === nombreProducto);
                let productoVendido = productosVendido[0];
                if (productoVendido) {
                    productoVendido.cantidad += cantidad;
                    productoVendido.fecha = new Date();
                } else {
                    this.#ventas.push({ "nombre": producto.nombre, "cantidad": cantidad, "fecha": new Date() });
                }
                this.ingresosGenerados += producto.precio;
                console.log(`Venta del producto ${producto.nombre} se realizo con exito!!`);

            } else {
                console.log(`No hay suficiente stock de ${producto.nombre}`);
            }
        } else {
            console.log(`El producto ${nombreProducto} no se encontró o no existe!`);
        }
    }

    productoMasVendido() {
        let ventas = this.#ventas;
        let ventasMayorObtenidas = 0;
        for (let i = 0; i < ventas.length; i++) {
            if (ventas[i].cantidad > ventasMayorObtenidas) {
                ventasMayorObtenidas = ventas[i].cantidad
                this.masVentas = ventas[i].nombre;
            }
        } return this.masVentas;
    }
}

class Inventario extends Venta {
    productos = []
    ingresosGenerados = 0;

    agregarProductos(nombre, precio, cantidad, categoria) {
        this.productos.push(new Producto(nombre, precio, cantidad, categoria));
    }

    mostrarAscendente() {
        let productos = this.productos;
        for (let i = 0; i < productos.length; i++) {
            for (let j = i; j < productos.length; j++) {
                if (productos[i].precio > productos[j].precio) {
                    let temp = productos[i];
                    productos[i] = productos[j];
                    productos[j] = temp;
                }
            }
        } console.log(productos);
    }


    filtrarCategoria(categoria) {
        let elementosCategoria = this.productos.filter(producto => producto.categoria === categoria);
        console.log(elementosCategoria);
        return elementosCategoria;
    }

    aplicarDescuento(categoria, porcentaje) {
        let elementosDescuento = this.filtrarCategoria(categoria);
        for (let producto of elementosDescuento) {
            producto.precio -= producto.precio * (porcentaje / 100);
        }
        console.log(elementosDescuento);
        return elementosDescuento;
    }

    reporteDetallado() {
        console.log('Inventario actual: \n');
        for (let producto of this.productos) {
            console.log(producto);
        }
        console.log('Ventas Realizadas:');
        console.log(this.obtenerVentas);
        console.log(`Ingresos Generados: ${this.ingresosGenerados}`);
        this.productoMasVendido();
        console.log(`Producto más vendido: ${this.masVentas}`);

    }
}





let inventario = new Inventario();

//Agregar Productos
inventario.agregarProductos("laptop", 500, 20, "tecnologia");
inventario.agregarProductos("celular", 200, 30, "celulares");
inventario.agregarProductos("manzanas", 6, 30, "Comida");
inventario.agregarProductos("cargador", 400, 30, "tecnologia");
inventario.agregarProductos("chancho", 5, 100, "tecnologia");
inventario.agregarProductos("peras", 2, 200, "tecnologia");

//Uso de get y set
console.log(inventario.productos[0].obtenerNombre);

//Mostrar ascendentemente
inventario.mostrarAscendente();

//Reporte inicial
inventario.reporteDetallado();

//Filtrado por categorias
console.log('Categoria Tecnologia');
inventario.filtrarCategoria('tecnologia');

//Descuentos
console.log('Descuentos: ');
inventario.aplicarDescuento('tecnologia', 10);

//Ventas
inventario.realizarVenta('celular', 10);
inventario.realizarVenta('laptop', 15);
inventario.realizarVenta('celular', 10);
inventario.realizarVenta('chancho', 10);


//Reporte Final
inventario.reporteDetallado();

