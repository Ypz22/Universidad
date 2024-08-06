from collections import deque

def es_bipartito(grafo):
    color = {}
    
    for vertice in grafo:
        if vertice not in color:
            color[vertice] = 0
            queue = deque([vertice])
            
            while queue:
                u = queue.popleft()
                
                for v in grafo[u]:
                    if v not in color:
                        color[v] = 1 - color[u]
                        queue.append(v)
                    elif color[v] == color[u]:
                        return False, None
    
    conjunto1 = [v for v in color if color[v] == 0]
    conjunto2 = [v for v in color if color[v] == 1]
    
    return True, (conjunto1, conjunto2)

# Ejemplo de uso
grafo = {
    0: [1, 3],
    1: [0, 2],
    2: [1, 3],
    3: [0, 2]
}

es_bipartito, conjuntos = es_bipartito(grafo)

if es_bipartito:
    print("El grafo es bipartito.")
    print("Conjunto 1:", conjuntos[0])
    print("Conjunto 2:", conjuntos[1])
else:
    print("El grafo no es bipartito.")
