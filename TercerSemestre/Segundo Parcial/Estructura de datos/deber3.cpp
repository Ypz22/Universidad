#include <iostream>

class Elemento {
    public:
        int valor;
        Elemento *proximo;
        Elemento(int valor) {
            this->valor = valor;
            proximo = nullptr;
        }
};

Elemento *inicio = nullptr;

Elemento contenedor[3] = {Elemento(0), Elemento(1), Elemento(3)};

void mostrarLista(Elemento *inicio) {
    Elemento *temp = inicio;
    while (temp != nullptr) {
        std::cout << temp->valor << " -> ";
        temp = temp->proximo;
    }
    std::cout << "NULL" << std::endl;
}

Elemento* crearElemento(int valor) {
    return new Elemento(valor);
}

void enlazarElementos(Elemento &base, Elemento *primero, Elemento *segundo = nullptr, Elemento *tercero = nullptr) {
    base.proximo = primero;
    if (primero) primero->proximo = segundo;
    if (segundo) segundo->proximo = tercero;
}

int main() {
    Elemento *elem1 = crearElemento(4);
    Elemento *elem2 = crearElemento(3);
    Elemento *elem3 = crearElemento(2);

    Elemento *elem4 = crearElemento(4);

    Elemento *elem5 = crearElemento(3);
    Elemento *elem6 = crearElemento(2);

    enlazarElementos(contenedor[0], elem1, elem2, elem3);
    enlazarElementos(contenedor[1], elem4);
    enlazarElementos(contenedor[2], elem5, elem6);

    for (int i = 0; i < 3; ++i) {
        mostrarLista(&contenedor[i]);
    }

    return 0;
}
