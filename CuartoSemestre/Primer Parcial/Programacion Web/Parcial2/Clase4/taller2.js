class Conductor {
    #nombre;
    #edad;
    constructor(nombre, licencia, edad) {
        this.#nombre = nombre;
        this.licencia = licencia;
        this.#edad = edad;
        this.rutas = [];
    }

    obtenerNombre() {
        return this.#nombre;
    }

    registrarRuta(ruta) {
        console.log("El conductor " + this.#nombre + " ha registrado la ruta: " + ruta);
        this.rutas.push(ruta);
    }
}

class Vehiculo {
    constructor(marca, modelo, color) {
        this.marca = marca;
        this.modelo = modelo;
        this.color = color;
    }
    registrarVehiculo() {
        console.log("El vehiculo " + this.marca + " " + this.modelo + " ha sido registrado") + " de color " + this.color;
    }
}

class ConductorVIP extends Conductor {
    constructor(nombre, licencia, vehiculoPreferido, correo) {
        super(nombre, licencia);
        this.vehiculoPreferido = vehiculoPreferido;
        this.correo = correo;
    }
    asignarVehiculoPreferido(vehiculo) {
        if (vehiculo.modelo === this.vehiculoPreferido) {
            console.log(`${this.obtenerNombre()} tiene asignado su vehículo preferido: ${vehiculo.modelo}`);
        } else {
            console.log(`${this.obtenerNombre()} ha sido asignado un vehículo diferente.`);
        }
    }
}

const conductor1 = new Conductor('Carlos', 'ABC123', 30);
const vehiculo1 = new Vehiculo('Toyota', 'Corolla', 'Rojo');
const vehiculoVIP = new Vehiculo('Honda', 'Civic', 'Azul');

conductor1.registrarRuta('Ruta A - B');

const conductorVIP = new ConductorVIP('Ana', 'XYZ456', 28, 'Civic', 'ana@mail.com');
conductorVIP.asignarVehiculoPreferido(vehiculoVIP);
conductorVIP.asignarVehiculoPreferido(vehiculo1);