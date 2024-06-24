#include <iostream>

using namespace std;

void mostrarArreglo(int arreglo[]){
    for(int i = 0;i < 5;i++){
        cout<<arreglo[i]<<",";
    }
    cout<<endl;
}

void elementoInicioArreglo(int arreglo[]){
    cout<<" ----- Insercion en primer elemento. -----"<<endl;
    int numero;
    cout<<"Ingrese el numero para cambiar: ";
    cin >> numero;

    for(int i = 5; i > 0; i--){
        arreglo[i] = arreglo[i - 1];
    }
    arreglo[0] = numero;
}

void insertarElementoIndice(int arreglo[]){
    cout<<"----- Insertar elemento en un indice especifico -----"<<endl;
    int indice;
    int numero;
    cout<<"Ingrese el numero para cambiar: ";
    cin>>numero;
    while(true){
        cout<<"Ingrese el indice en el cual cambiar: ";
        cin>>indice;
        if(indice >= 0 && indice < 5){
            arreglo[indice] = numero;
            break;
        }else{
            cout<<"Indice incorrecto"<<endl;
        }
    }
}

void insertarElementoIndiceDespues(int arreglo[]){
    cout<<" -----Insertar elemento un indice despues -----"<<endl;
    int indice;
    int numero;
    cout<<"Ingrese el numero para cambiar: ";
    cin>>numero;
    while(true){
        cout<<"Ingrese el indice en el cual cambiar: ";
        cin>>indice;
        if(indice >= 0 && indice < 5){
            for (int i = 5; i > indice; --i) {
                arreglo[i] = arreglo[i - 1];
            }
            arreglo[indice + 1] = numero;
            break;
        }else{
            cout<<"Indice incorrecto"<<endl;
        }
    }
}

void insertarElementoIndiceAntes(int arreglo[]){
    cout<<" -----Insertar elemento un indice antes -----"<<endl;
    int indice;
    int numero;
    cout<<"Ingrese el numero para cambiar: ";
    cin>>numero;
    while(true){
        cout<<"Ingrese el indice en el cual cambiar: ";
        cin>>indice;
        if(indice >= 0 && indice < 5){
            for (int i = 5; i >= indice; --i) {
                arreglo[i] = arreglo[i - 1];
            }
            arreglo[indice - 1] = numero;
            break;
        }else{
            cout<<"Indice incorrecto"<<endl;
        }
    }

}

void eliminarElemento(int arr[]) {
    cout<<" ----- Eliminar elemento -----"<<endl;
    int tamano = 5;
    int indice = 2;
    while(true){
        cout<<"Ingrese el indice en el cual cambiar: ";
        cin>>indice;
        if(indice >= 0 && indice < 5){
            for (int i = indice; i < tamano - 1; ++i) {
                arr[i] = arr[i + 1];
            }
            --tamano;
            break;
        }else{
            cout<<"Indice incorrecto"<<endl;
        }
    }
}

int buscarElementoPorDato(int arreglo[]){
    cout<<" ----- Buscar elemento por el dato. -----"<<endl;
    int numero;
    cout<<"Ingrese el numero a buscar: ";
    cin>>numero;
    for(int i = 0;i < 5;i++){
        if(arreglo[i] == numero)
        {
            cout<<"el numero "<< numero <<" se encuentra en el indice "<< i <<endl;
            break;
        }
    }

}

int buscarElementoPorIndice(int arreglo[]){
    cout<<" ----- Buscar elemento por el indice -----"<<endl;
    int indice;
    while(true){
        cout<<"Ingrese el indice para buscar el elemento: ";
        cin>>indice;
        if(indice >= 0 && indice < 5){
            cout<<"El numero es: "<<arreglo[indice];
            break;
        }else{
            cout<<"Indice incorrecto"<<endl;
        }
    }

}

int main()
{
    int arreglo[5] = {2,6,10,15,20};
    cout<<"Arreglo original: ";
    mostrarArreglo(arreglo);
    elementoInicioArreglo(arreglo);
    mostrarArreglo(arreglo);
    insertarElementoIndice(arreglo);
    mostrarArreglo(arreglo);
    insertarElementoIndiceAntes(arreglo);
    mostrarArreglo(arreglo);
    insertarElementoIndiceDespues(arreglo);
    mostrarArreglo(arreglo);
    eliminarElemento(arreglo);
    mostrarArreglo(arreglo);
    buscarElementoPorDato(arreglo);
    buscarElementoPorIndice(arreglo);

    return 0;
}

