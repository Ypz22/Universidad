#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

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
    return '\0'; // Indicador de pila vacía
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
            return 0; // Para otros caracteres, como paréntesis
    }
}

bool esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infijoASufijo(const string& infijo) {
    stack<char> pila;
    string sufijo;

    for (char c : infijo) {
        if (isalnum(c)) {
            sufijo += c;
        } else if (c == '(') {
            pila.push(c);
        } else if (c == ')') {
            while (!pila.empty() && pila.top() != '(') {
                sufijo += pila.top();
                pila.pop();
            }
            pila.pop(); // Sacar el '(' de la pila
        } else if (esOperador(c)) {
            while (!pila.empty() && precedencia(pila.top()) >= precedencia(c)) {
                sufijo += pila.top();
                pila.pop();
            }
            pila.push(c);
        }
    }

    while (!pila.empty()) {
        sufijo += pila.top();
        pila.pop();
    }

    return sufijo;
}

int main() {
    string infijo;
    cout << "Introduce una expresión infija: ";
    cin >> infijo;

    string sufijo = infijoASufijo(infijo);
    cout << "La expresión sufija (postfija) es: " << sufijo << endl;

    return 0;
}
