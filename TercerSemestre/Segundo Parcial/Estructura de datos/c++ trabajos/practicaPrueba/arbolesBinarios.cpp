#include <iostream>
#include <stdlib.h>

using namespace std;

class Arbol{
    public:
    int dato;
    Arbol *der;
    Arbol *izq;

    Arbol(int dato){
        this->dato = dato;
        this->der = NULL;
        this->izq = NULL;
    }
};


class FuncionesArbol{
    public:
    Arbol *raiz;
    FuncionesArbol(int dato){
        raiz = new Arbol(dato);
    }

    void insertarDatoArbol(int dato){
        insertar(raiz,dato);
    }

    void inOrden(Arbol *raiz){
        if(raiz != NULL){
            inOrden(raiz->izq);
            cout << raiz->dato << " ";
            inOrden(raiz->der);
        }
    }

    void preOrden(Arbol *raiz){
        if(raiz != NULL){
            cout << raiz->dato << " ";
            preOrden(raiz->izq);
            preOrden(raiz->der);
        }
    }

    void postOrden(Arbol *raiz){
        if(raiz != NULL){
            postOrden(raiz->izq);
            postOrden(raiz->der);
            cout << raiz->dato << " ";
        }
    }

    private:
    void insertar(Arbol *raiz, int dato){
        if(raiz->dato > dato){
            if(raiz->izq == NULL){
                raiz->izq = new Arbol(dato);
            }else{
                insertar(raiz->izq, dato);
            }
        }else{
            if(raiz->der == NULL){
                raiz->der = new Arbol(dato);
            }else{
                insertar(raiz->der, dato);
            }
        }
    }
};

int main(){
    FuncionesArbol arbol(15);
    arbol.insertarDatoArbol(6);
    arbol.insertarDatoArbol(20);
    arbol.insertarDatoArbol(3);
    arbol.insertarDatoArbol(9);
    arbol.insertarDatoArbol(18);
    arbol.insertarDatoArbol(24);
    arbol.insertarDatoArbol(17);
    arbol.insertarDatoArbol(1);
    arbol.insertarDatoArbol(4);
    arbol.insertarDatoArbol(7);
    arbol.insertarDatoArbol(12);

    cout<<"In orden: "<<endl;
    arbol.inOrden(arbol.raiz);
    cout<<endl;

    cout<<arbol.raiz->dato<<endl;

    cout<<"Pre orden: "<<endl;
    arbol.preOrden(arbol.raiz);
    cout<<endl;

    cout<<"Post orden: "<<endl;
    arbol.postOrden(arbol.raiz);
    cout<<endl;
    return 0;
}