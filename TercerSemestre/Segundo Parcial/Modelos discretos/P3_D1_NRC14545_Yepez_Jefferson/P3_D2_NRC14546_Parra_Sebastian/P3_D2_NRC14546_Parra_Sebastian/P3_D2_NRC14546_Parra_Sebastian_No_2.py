class DisjointSet:
    def __init__(self, vertices):
        self.parent = {}
        self.rank = {}
        for v in vertices:
            self.parent[v] = v
            self.rank[v] = 0

    def find(self, v):
        if self.parent[v] != v:
            self.parent[v] = self.find(self.parent[v])
        return self.parent[v]

    def union(self, v1, v2):
        root1 = self.find(v1)
        root2 = self.find(v2)

        if root1 != root2:
            if self.rank[root1] > self.rank[root2]:
                self.parent[root2] = root1
            elif self.rank[root1] < self.rank[root2]:
                self.parent[root1] = root2
            else:
                self.parent[root2] = root1
                self.rank[root1] += 1

def kruskal(vertices, edges):
    mst = []
    disjoint_set = DisjointSet(vertices)

    # Ordenar las aristas por peso
    edges = sorted(edges, key=lambda x: x[2])

    for edge in edges:
        v1, v2, weight = edge
        # Si no forman un ciclo
        if disjoint_set.find(v1) != disjoint_set.find(v2):
            mst.append(edge)
            disjoint_set.union(v1, v2)

    return mst

# Definir los vértices y aristas del grafo
vertices = [1, 2, 3, 4, 5, 6, 7, 8, 9]
edges = [
    (1, 2, 4), (1, 4, 12), (2, 3, 1),
    (2, 5, 6), (2, 6, 7), (3, 6, 5), 
    (4, 5, 11), (4, 7, 8), (4, 8, 13),
    (5, 6, 14), (5, 8, 3), (6, 9, 9),
    (7, 8, 2), (8, 9, 10)
]

# Hallar el árbol de expansión mínima usando Kruskal
mst = kruskal(vertices, edges)

# Imprimir el árbol de expansión mínima
print("Árbol de Expansión Mínima (MST):")
for edge in mst:
    print(f"{edge[0]} -- {edge[1]} == {edge[2]}")

# Dibujar el grafo y el MST
import matplotlib.pyplot as plt

# Crear un diccionario de posiciones para los nodos
positions = {
    1: (0, 0), 2: (1, 0), 3: (2, 0),
    4: (0, 1), 5: (1, 1), 6: (2, 1),
    7: (0, 2), 8: (1, 2), 9: (2, 2)
}

def draw_graph(edges, mst):
    plt.figure(figsize=(8, 6))
    
    # Dibujar todas las aristas
    for edge in edges:
        v1, v2, weight = edge
        x1, y1 = positions[v1]
        x2, y2 = positions[v2]
        plt.plot([x1, x2], [y1, y2], 'gray')
        plt.text((x1 + x2) / 2, (y1 + y2) / 2, str(weight), color='black', fontsize=12)

    # Resaltar las aristas del MST
    for edge in mst:
        v1, v2, weight = edge
        x1, y1 = positions[v1]
        x2, y2 = positions[v2]
        plt.plot([x1, x2], [y1, y2], 'red', linewidth=2)

    # Dibujar los nodos
    for vertex, (x, y) in positions.items():
        plt.scatter(x, y, s=100)
        plt.text(x, y, str(vertex), fontsize=12, ha='center', va='center')

    plt.grid(True)
    plt.show()

# Dibujar el grafo y el MST
draw_graph(edges, mst)
