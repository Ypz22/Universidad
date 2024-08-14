def listarTrayectorias(grafo, inicio, fin, path=[]):
    path = path + [inicio]
    if inicio == fin:
        return [path]
    if inicio not in grafo:
        return []
    trayectorias = []
    for nodo in grafo[inicio]:
        if nodo not in path:
            nuevas_trayectorias = listarTrayectorias(grafo, nodo, fin, path)
            for trayectoria in nuevas_trayectorias:
                trayectorias.append(trayectoria)
    return trayectorias


grafo = {
    'A': ['B', 'C'],
    'B': ['C', 'D'],
    'C': ['D'],
    'D': ['C'],
    'E': ['F'],
    'F': ['C']
}

inicio = 'A'
fin = 'D'
trayectorias = listarTrayectorias(grafo, inicio, fin)
print(f"Trayectorias simples de {inicio} a {fin}:")
for trayectoria in trayectorias:
    print(trayectoria)
