def es_bipartito(matriz_adyacencia):
    n = len(matriz_adyacencia)
    colores = [-1] * n  # -1 significa que no está coloreado
    conjuntos = ([], [])  # Para almacenar los conjuntos de vértices ajenos

    for start in range(n):
        if colores[start] == -1:  # Si no está coloreado, empezar BFS desde aquí
            queue = [start]
            colores[start] = 0  # Colorear el primer nodo con color 0

            while queue:
                nodo = queue.pop(0)  # Sacar el primer elemento de la lista

                for vecino in range(n):
                    if matriz_adyacencia[nodo][vecino] == 1:  # Si hay una arista
                        if colores[vecino] == -1:  # Si no está coloreado
                            colores[vecino] = 1 - colores[nodo]  # Colorear con el color opuesto
                            queue.append(vecino)
                        elif colores[vecino] == colores[nodo]:  # Si está coloreado con el mismo color
                            return False, ([], [])  # No es bipartito

    for i in range(n):
        conjuntos[colores[i]].append(i)

    return True, conjuntos

# Ejemplo de uso:
matriz_adyacencia = [
    [0, 1, 0, 1],
    [1, 0, 1, 0],
    [0, 1, 0, 1],
    [1, 0, 1, 0]
]

es_bipartito, conjuntos = es_bipartito(matriz_adyacencia)
if es_bipartito:
    print("El grafo es bipartito.")
    print(f"Conjunto 1: {conjuntos[0]}")
    print(f"Conjunto 2: {conjuntos[1]}")
else:
    print("El grafo no es bipartito.")
