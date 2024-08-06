#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void intercaacion(string archivo1,string archivo2, string archivoSalida){
    ifstream entradaArchivo1(archivo1);
    ifstream entradaArchivo2(archivo2);
    ofstream salidaArchivo(archivoSalida);

    if(!entradaArchivo1.is_open() || !entradaArchivo2.is_open() || salidaArchivo.is_open()){
        cout << "No se pudo abrir el archivo"<<endl;
        return;
    }

    int datosArchivo1,datosArchivo2;
    bool archivoTerminado1 = !(entradaArchivo1 >> datosArchivo1);
    bool archivoTerminado2 = !(entradaArchivo2 >> datosArchivo2);

    while(!archivoTerminado1 || !archivoTerminado2){
        if(archivoTerminado1){
            salidaArchivo << datosArchivo2 << " ";
            archivoTerminado2 = !(entradaArchivo2 >> datosArchivo2);
        }else if(archivoTerminado2){
            salidaArchivo << datosArchivo1 << " ";
            archivoTerminado1 = !(entradaArchivo1 >> datosArchivo1);
        }else if(datosArchivo1 < datosArchivo2){
            salidaArchivo << datosArchivo1 << " ";
            archivoTerminado1 = !(entradaArchivo1 >> datosArchivo1);
        }else{
            salidaArchivo << datosArchivo2<< " ";
            archivoTerminado2 = !(entradaArchivo2 >> datosArchivo2);
        }
    }

    entradaArchivo1.close();
    entradaArchivo2.close();
    salidaArchivo.close();
}

int main(){
    intercaacion("datos1.txt", "datos2.txt", "datos3.txt");
    return 0;
}