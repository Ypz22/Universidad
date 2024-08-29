import networkx as nx
import matplotlib.pyplot as plt

class Node:
    def __init__(self, value):
        self.value = value
        self.connections = []

class Edge:
    def __init__(self, origin, destination):
        self.origin = origin
        self.destination = destination

node_a = Node("A")
node_b = Node("B")
node_c = Node("C")
edge_ab = Edge(node_a, node_b)
edge_bc = Edge(node_b, node_c)
edge_ca = Edge(node_c, node_a)
node_a.connections.append(edge_ab)
node_b.connections.append(edge_bc)
node_c.connections.append(edge_ca)

# Función para hallar el grado de un nodo
def node_degree(node):
    return len(node.connections)

# Función para verificar si un nodo tiene lazos
def has_loops(node):
    for edge in node.connections:
        if edge.origin == edge.destination:
            return True
    return False

# Función para verificar si un grafo tiene un bucle Euleriano
def has_eulerian_cycle(nodes):
    # Para que un grafo tenga un ciclo euleriano, todos los nodos deben tener un grado par
    for node in nodes:
        if node_degree(node) % 2 != 0:
            return False
    return True

# Función para verificar si un grafo tiene un bucle Hamiltoniano
def has_hamiltonian_cycle(nodes):
    # Chequeo simple, un grafo completo de n nodos tiene un ciclo hamiltoniano si n >= 3
    return len(nodes) >= 3 and all(node_degree(node) >= len(nodes) - 1 for node in nodes)

# Función para verificar si un grafo es bipartito
def is_bipartite(nodes):
    color = {}
    
    def dfs(node, current_color):
        color[node] = current_color
        for edge in node.connections:
            neighbor = edge.destination if edge.origin == node else edge.origin
            if neighbor not in color:
                if not dfs(neighbor, 1 - current_color):
                    return False
            elif color[neighbor] == color[node]:
                return False
        return True
    
    for node in nodes:
        if node not in color:
            if not dfs(node, 0):
                return False
    return True

# Ejemplos de uso
nodes = [node_a, node_b, node_c]

print(f"Grado de node_a: {node_degree(node_a)}")
print(f"node_a tiene lazos: {has_loops(node_a)}")
print(f"El grafo tiene un bucle Euleriano: {has_eulerian_cycle(nodes)}")
print(f"El grafo tiene un bucle Hamiltoniano: {has_hamiltonian_cycle(nodes)}")
print(f"El grafo es bipartito: {is_bipartite(nodes)}")

# Crear un grafo usando networkx
G = nx.Graph()

# Añadir nodos al grafo
G.add_node(node_a.value)
G.add_node(node_b.value)
G.add_node(node_c.value)

# Añadir aristas al grafo
G.add_edge(node_a.value, node_b.value)
G.add_edge(node_b.value, node_c.value)
G.add_edge(node_c.value, node_a.value)

# Dibujar el grafo usando matplotlib
plt.figure()
nx.draw(G, with_labels=True, node_color='skyblue', node_size=2000, edge_color='gray', font_size=15, font_weight='bold')
plt.title("Visualización del Grafo")
plt.show()