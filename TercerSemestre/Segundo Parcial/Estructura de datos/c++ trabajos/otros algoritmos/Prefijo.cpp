#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Nodo {
    char valor;
    Nodo* siguiente;
};

void apilar(Nodo*& cima, char c) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->valor = c;
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
}

char desapilar(Nodo*& cima) {
    if (cima) {
        Nodo* temp = cima;
        char valor = cima->valor;
        cima = cima->siguiente;
        delete temp;
        return valor;
    }
    return '\0';
}

char cima(Nodo* cima) {
    return cima ? cima->valor : '\0';
}

bool vacia(Nodo* cima) {
    return cima == nullptr;
}

int precedencia(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

bool esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infijoAPrefijo(const string& infijo) {
    string infijoInvertido = infijo;
    reverse(infijoInvertido.begin(), infijoInvertido.end());

    for (char& c : infijoInvertido) {
        if (c == '(') {
            c = ')';
        } else if (c == ')') {
            c = '(';
        }
    }

    Nodo* pila = nullptr;
    string postfijo;

    for (char c : infijoInvertido) {
        if (isalnum(c)) {
            postfijo += c;
        } else if (c == '(') {
            apilar(pila, c);
        } else if (c == ')') {
            while (!vacia(pila) && cima(pila) != '(') {
                postfijo += desapilar(pila);
            }
            desapilar(pila);
        } else if (esOperador(c)) {
            while (!vacia(pila) && precedencia(cima(pila)) > precedencia(c)) {
                postfijo += desapilar(pila);
            }
            apilar(pila, c);
        }
    }

    while (!vacia(pila)) {
        postfijo += desapilar(pila);
    }

    reverse(postfijo.begin(), postfijo.end());

    return postfijo;
}

int main() {
    string infijo;
    cout << "Introduce una expresión infija: ";
    cin >> infijo;

    string prefijo = infijoAPrefijo(infijo);
    cout << "La expresión prefija es: " << prefijo << endl;

    return 0;
}
