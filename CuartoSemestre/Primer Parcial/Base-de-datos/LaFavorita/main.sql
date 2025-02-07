/*Postgresql*/
/*Create Database LA_FAVORITA*/
CREATE DATABASE LA_FAVORITA;

CREATE EXTENSION IF NOT EXISTS "uuid-ossp";


/*Create Table Users*/

CREATE TABLE Users (
    id SERIAL PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    email VARCHAR(50) NOT NULL,
    password VARCHAR(50) NOT NULL,
    role VARCHAR(50) NOT NULL
);

/*Create table Centro_Costos*/

CREATE TABLE Centro_Costos (
    ID_CENTRO_COSTO SERIAL PRIMARY KEY,
    NOMBRE VARCHAR(50) NOT NULL
);


/*Create Table Item*/

CREATE TABLE ITEM (
    ID_ITEM SERIAL PRIMARY KEY,
    NOMBRE VARCHAR(50) NOT NULL,
    UNIDAD_MEDIDA VARCHAR(20) NOT NULL,
    PRECIO_UNITARIO FLOAT NOT NULL
);

/*Create table responsable with fk to Centro_costo*/

CREATE TABLE RESPONSABLE (
    CEDULA VARCHAR(10) PRIMARY KEY,
    NOMBRE VARCHAR(50) NOT NULL,
    APELLIDO VARCHAR(50) NOT NULL,
    ID_CENTRO_COSTO INT NOT NULL,
    FOREIGN KEY (ID_CENTRO_COSTO) REFERENCES Centro_Costos(ID_CENTRO_COSTO) 
);

/*Create table iem_solicitud with fk for id_item*/

CREATE TABLE ITEM_SOLICITUD (
    ID_ITEM_SOLICITUD SERIAL PRIMARY KEY,
    ID_ITEM INT NOT NULL,
    CANTIDAD INT NOT NULL,
    FOREIGN KEY (ID_ITEM) REFERENCES ITEM(ID_ITEM) 
);

/*Create table solicitudes_compra
numero solicitus aS SERIAL pk
responsable id as fk
centro_costo id as fk
rubro presupuestal
fecha
autoriazada jefe areas as boolean
autorizada director financiero as boolean


every solicitud_compra could have one ore more item_solicitud
*/

CREATE TABLE SOLICITUD_COMPRA (
    NUMERO_SOLICITUD SERIAL PRIMARY KEY,
    ID_RESPONSABLE VARCHAR(10) NOT NULL,
    ID_CENTRO_COSTO INT NOT NULL,
    RUBRO_PRESUPUESTAL VARCHAR(50) NOT NULL,
    FECHA DATE NOT NULL,
    AUTORIZADA_JEFE_AREA BOOLEAN NOT NULL,
    AUTORIZADA_DIRECTOR_FINANCIERO BOOLEAN NOT NULL,
    TOTAL FLOAT NOT NULL,
    FOREIGN KEY (ID_RESPONSABLE) REFERENCES RESPONSABLE(CEDULA) ,
    FOREIGN KEY (ID_CENTRO_COSTO) REFERENCES Centro_Costos(ID_CENTRO_COSTO)
);

/*Create table solicitud_item with fk to solicitud_compra and item_solicitud*/

CREATE TABLE SOLICITUD_ITEM (
    ID_SOLICITUD INT NOT NULL,
    ID_ITEM_SOLICITUD INT NOT NULL,
    FOREIGN KEY (ID_SOLICITUD) REFERENCES SOLICITUD_COMPRA(NUMERO_SOLICITUD) ,
    FOREIGN KEY (ID_ITEM_SOLICITUD) REFERENCES ITEM_SOLICITUD(ID_ITEM_SOLICITUD)
);



/*
Cada bien es identificado por un código universal que es único y es de carácter devolutivo (suministro) o un bien inmueble. Una vez diligenciada la solicitud es remitida al área de compras para realizar su correspondiente cotización. Las cotizaciones son realizadas con uno o varios proveedores de los bienes solicitados. Una vez la cotización definitiva está lista, se crea una orden contractual que maneja la siguiente información: Número de la orden contractual y nombre del proveedor al cual se le va a realizar la compra, fecha de la orden, monto total de la orden, fecha de entrega. Cada orden puede tener asociado uno o varios ítems de la solicitud o solicitudes que van a ser despachadas. Cada ítem tiene la siguiente información: nombre del bien, cantidad solicitada, cantidad despachada, unidad de medida del bien, valor unitario y valor total. La orden de compra es aprobada por el Director Financiero para que sea enviada al proveedor elegido.
*/


/*Create table proveedores*/

CREATE TABLE PROVEEDORES (
    ID_PROVEEDOR SERIAL PRIMARY KEY,
    NOMBRE VARCHAR(50) NOT NULL,
    DIRECCION VARCHAR(50) NOT NULL,
    TELEFONO VARCHAR(50) NOT NULL,
    EMAIL VARCHAR(50) NOT NULL
);

/*CREATE TABLE Catalogo with fields serial id and nombre*/

CREATE TABLE CATALOGO (
    ID_CATALOGO SERIAL PRIMARY KEY,
    NOMBRE VARCHAR(50) NOT NULL
);

CREATE TABLE BIEN (
    ID_BIEN SERIAL PRIMARY KEY,
    TIPO_BIEN INT NOT NULL,
    PROVEEDOR INT NOT NULL,
    FOREIGN KEY (TIPO_BIEN) REFERENCES CATALOGO(ID_CATALOGO),
    FOREIGN KEY (PROVEEDOR) REFERENCES PROVEEDORES(ID_PROVEEDOR)
);

CREATE TABLE COTIZACION (
    ID_COTIZACION SERIAL PRIMARY KEY
);

/*Cotiazciones could have one or more provider*/

CREATE TABLE COTIZACION_PROVEEDOR (
    ID_COTIZACION INT NOT NULL,
    ID_PROVEEDOR INT NOT NULL,
    FOREIGN KEY (ID_COTIZACION) REFERENCES COTIZACION(ID_COTIZACION),
    FOREIGN KEY (ID_PROVEEDOR) REFERENCES PROVEEDORES(ID_PROVEEDOR)
);

/*Create table orden contractual*/

/*
Una vez la cotización definitiva está lista, se crea una orden contractual que maneja la siguiente información: Número de la orden contractual y nombre del proveedor al cual se le va a realizar la compra, fecha de la orden, monto total de la orden, fecha de entrega.*/

CREATE TABLE ORDEN_CONTRACTUAL (
    ID_ORDEN_CONTRACTUAL SERIAL PRIMARY KEY,
    ID_PROVEEDOR INT NOT NULL, /*TODO: check redundancia*/
    FECHA DATE NOT NULL,
    MONTO_TOTAL FLOAT NOT NULL,
    FECHA_ENTREGA DATE NOT NULL,
    APROBADA_DIRECTOR_FINANCIERO BOOLEAN,
    FOREIGN KEY (ID_PROVEEDOR) REFERENCES PROVEEDORES(ID_PROVEEDOR) 
);



CREATE TABLE ITEM_ORDEN_CONTRACTUAL (
    ID_ITEM INT NOT NULL,
    ID_ORDEN_CONTRACTUAL INT NOT NULL,
    CANTIDAD_SOLICITADA INT NOT NULL,
    CANTIDAD_DESPACHADA INT NOT NULL,
    UNIDAD_MEDIDA VARCHAR(20) NOT NULL,
    VALOR_UNITARIO NUMERIC(10,2) NOT NULL,
    VALOR_TOTAL NUMERIC(12,2) NOT NULL,
    FOREIGN KEY (ID_ITEM) REFERENCES ITEM(ID_ITEM),
    FOREIGN KEY (ID_ORDEN_CONTRACTUAL) REFERENCES ORDEN_CONTRACTUAL(ID_ORDEN_CONTRACTUAL)
);



/*ALMACEN*/

/*Si esta acción es correcta se registra una entrada de almacén por cada factura relacionada, con la siguiente información: Número de Entrada, Fecha, Número de factura, Proveedor, Total Bienes, Valor Total (los totales deben coincidir con los de la factura).*/


CREATE TABLE ENTRADA_ALMACEN (
    ID_ENTRADA_ALMACEN SERIAL PRIMARY KEY,
    FECHA DATE NOT NULL,
    NUMERO_FACTURA VARCHAR(50) NOT NULL,
    PROVEEDOR INT NOT NULL,
    TOTAL_BIENES INT NOT NULL,
    VALOR_TOTAL NUMERIC(12,2) NOT NULL,
    FOREIGN KEY (PROVEEDOR) REFERENCES PROVEEDORES(ID_PROVEEDOR)
);

/*Adjunto a esta se discriminan los ítems recibidos con la siguiente información: nombre del bien, cantidad entregada.*/

CREATE TABLE ITEM_ENTRADA_ALMACEN (
    ID_ITEM_ENTRADA_ALMACEN SERIAL PRIMARY KEY,
    ID_ENTRADA_ALMACEN INT NOT NULL,
    ID_ITEM INT NOT NULL,
    CANTIDAD_ENTREGADA INT NOT NULL,
    FOREIGN KEY (ID_ENTRADA_ALMACEN) REFERENCES ENTRADA_ALMACEN(ID_ENTRADA_ALMACEN) ,
    FOREIGN KEY (ID_ITEM) REFERENCES ITEM(ID_ITEM) 
);



/*Cuando el almacén decide despachar los bienes a las diferentes áreas solicitantes, registra cada una de las entregas en Salidas de Almacén con la siguiente información: Número de Salida, Empleado responsable del bien a entregar, fecha de salida, fecha de entrega. */

CREATE TABLE SALIDA_ALMACEN (
    ID_SALIDA_ALMACEN SERIAL PRIMARY KEY,
    ID_RESPONSABLE VARCHAR(10) NOT NULL,
    FECHA_SALIDA DATE NOT NULL,
    FECHA_ENTREGA DATE NOT NULL,
    FOREIGN KEY (ID_RESPONSABLE) REFERENCES RESPONSABLE(CEDULA) 
);





/*•El área de inventarios funciona de la siguiente forma: Es la encargada de administrar y controlar la ubicación de los bienes dentro de la empresa, por esto antes de que el bien salga del almacén debe ser codificado a través de un código único que lo haga identificable dentro de la empresa. La ubicación del bien se identifica por la siguiente información: responsable del bien, fecha de entrega, dirección del bien (ubicación).*/

CREATE TABLE PRODUCTOS_ALMACEN (
    UUID UUID DEFAULT uuid_generate_v4() PRIMARY KEY,
    ID_BIEN INT NOT NULL,
    ID_RESPONSABLE VARCHAR(10) NOT NULL,
    FECHA_ENTREGA DATE NOT NULL,
    DIRECCION VARCHAR(250) NOT NULL,
    FOREIGN KEY (ID_BIEN) REFERENCES BIEN(ID_BIEN),
    FOREIGN KEY (ID_RESPONSABLE) REFERENCES RESPONSABLE(CEDULA)
);


/*CREATE TABLE BIEN
uuid as pk
TIPO_bien as fk to catalogo

*/