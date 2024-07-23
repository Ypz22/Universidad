#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int posicion(int clave) {
    if(clave < 0){
        cout << "La matricula no puede tener numeros negativos!"<<endl;
        return -1;
    }
    long long cuadrado = static_cast<long long>(clave) * clave;
    if(cuadrado < 10){
        return cuadrado;
    }
    cout<< "clave^2 = "<<cuadrado<<endl;
    string cuadradoStr = to_string(cuadrado);
    int longitud = cuadradoStr.length();
    int medio = longitud / 2;
    string medioStr = cuadradoStr.substr(medio - 1, 2);


    return stoi(medioStr) ;
}

int main() {
    int matricula;
    cout << "Ingrese el numero de matricula del auto de alquiler: ";
    cin >> matricula;

    int valorHash = posicion(matricula);
    cout << "El valor hash es: " << valorHash << endl;

    return 0;
}
