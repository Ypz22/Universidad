from collections import defaultdict

def encontrar_trayectorias(grafo, inicio, fin, camino=[]):
    camino = camino + [inicio]
    if inicio == fin:
        return [camino]
    if inicio not in grafo:
        return []
    caminos = []
    for nodo in grafo[inicio]:
        if nodo not in camino:
            nuevos_caminos = encontrar_trayectorias(grafo, nodo, fin, camino)
            for nuevo_camino in nuevos_caminos:
                caminos.append(nuevo_camino)
    return caminos

grafo = defaultdict(list)
grafo[1] = [2, 3]
grafo[2] = [4]
grafo[3] = [4]
grafo[4] = [5]
grafo[5] = []


inicio = 1
fin = 5


trayectorias = encontrar_trayectorias(grafo, inicio, fin)


print(f"Todas las trayectorias simples de {inicio} a {fin}:")
for trayectoria in trayectorias:
    print(trayectoria)
