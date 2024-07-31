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

    void ingresarDatoArbol(int dato){
        ingresar(raiz,dato);
    }


    void ingresar(Arbol *raiz, int dato){
        if(dato < raiz->dato){
            if(raiz->izq == NULL){
                raiz->izq = new Arbol(dato);
            }else{
                ingresar(raiz->izq,dato);
            }
        }else{
            if(raiz->der == NULL){
                raiz->der = new Arbol(dato);
            }else{
                ingresar(raiz->der,dato);
            }
        }
    }

    void inOrden(Arbol *raiz){
        if(raiz != NULL){ 
            inOrden(raiz->izq);
            cout<<raiz->dato<<" ";
            inOrden(raiz->der);
        }
    }

    void preOrden(Arbol *raiz){
        if(raiz != NULL){
            cout<< raiz->dato<<" ";
            preOrden(raiz->izq);
            preOrden(raiz->der);
        }
    }

    void postOrden(Arbol *raiz){
        if(raiz != NULL){
            postOrden(raiz->izq);
            postOrden(raiz->der);
            cout <<raiz->dato << " ";
        }
    }

    Arbol* eliminarDatoArbol(int dato){
        raiz = eliminar(raiz,dato);
    }

    private:

    Arbol* eliminar(Arbol *raiz, int dato){
        if(raiz == NULL){
            return raiz;
        }if(dato < raiz->dato){
            raiz->izq = eliminar(raiz->izq, dato);
        }else if(dato > raiz->dato){
            raiz->der = eliminar(raiz->der,dato);
        }else{
            if(raiz->izq == NULL){
                Arbol *temp = raiz->der;
                delete raiz;
                return temp;
            }else if(raiz->der == NULL){
                Arbol *temp = raiz->izq;
                delete raiz;
                return temp;
            }
            Arbol *temp = nodoValorMinimo(raiz->der);
            raiz->dato = temp->dato;
            raiz->der = eliminar(raiz->der,temp->dato);
        }
    }
    
    Arbol* nodoValorMinimo(Arbol *raiz){
        Arbol *actual = raiz;
        while(actual && actual->izq != NULL){
            actual = actual->izq;
        }return actual;
    }
};


int main(){
    FuncionesArbol arbol(8);
    arbol.ingresarDatoArbol(3);
    arbol.ingresarDatoArbol(1);
    arbol.ingresarDatoArbol(20);
    arbol.ingresarDatoArbol(10);
    arbol.ingresarDatoArbol(5);
    arbol.ingresarDatoArbol(4);

    cout<<"In orden: "<<endl;
    arbol.inOrden(arbol.raiz);

    cout<<endl;

    arbol.eliminarDatoArbol(10);

    cout<<"In orden: "<<endl;
    arbol.inOrden(arbol.raiz);

    cout<<endl;

    cout<<"Pre orden: "<<endl;
    arbol.preOrden(arbol.raiz);

    cout<<endl;

    cout<<"Post orden: "<<endl;
    arbol.postOrden(arbol.raiz);

    cout<<endl;
    return 0;
}