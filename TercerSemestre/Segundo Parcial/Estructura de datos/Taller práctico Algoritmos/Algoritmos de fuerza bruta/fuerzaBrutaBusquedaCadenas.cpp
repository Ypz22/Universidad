#include <iostream>
#include <stdlib.h>

using namespace std;

void fuerzaBrutaBusquedaCadenas(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    int contadorIteraciones = 0;
    // Recorrer el texto hasta el punto donde el patrón puede caber
    for (int i = 0; i <= n - m; i++) {
        int j;
        // Comparar el patrón con la subcadena de text que empieza en la posición i
        for (j = 0; j < m; j++) {
            contadorIteraciones++;
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        // Si j alcanzó el tamaño del patrón, significa que se encontró una coincidencia
        if (j == m) {
            cout << "Patrón encontrado en el índice " << i << endl;
        }
    }
    cout << "Numero de iteraciones realizadas: " << contadorIteraciones << endl;
}
int main() {
    string text = "elrapidozorrocoloradobrincasobreelperrozafaryelzorronegro";
    string pattern = "zorro";
    fuerzaBrutaBusquedaCadenas(text, pattern);
    return 0;
}