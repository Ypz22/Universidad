import matplotlib.pyplot as plt

# Función para dibujar líneas entre nodos
def draw_line(x1, y1, x2, y2, color = 'k'):
    plt.plot([x1, x2], [y1, y2], color=color)

# Función para dibujar un nodo
def draw_node(x, y, text, color = 'skyblue'):
    plt.text(x, y, text, fontsize=12, ha='center', va='center', bbox=dict(facecolor=color, edgecolor='black', boxstyle='circle,pad=0.3'))

positions = {
    'a': (0, 0),
    'b': (-0.5, -0.47),
    'c': (-1, -1),
    'd': (0, -1),
    'e': (-0.5, -1.50),
    'f': (0.5, -2)
}

Nodos = ['a','b','c','d','e','f']

# Definir las conexiones entre los nodos (aristas)
edges = [
    ('a', 'b'), ('b','c'),('b','d'),('d','e'),('e','f')
]

# Dibuja las líneas (aristas) entre nodos
for edge in edges:
    x1, y1 = positions[edge[0]]
    x2, y2 = positions[edge[1]]
    draw_line(x1, y1, x2, y2)

# Dibuja los nodos
for node, (x, y) in positions.items():
    draw_node(x, y, node)

def encontrarHijos(nodo, arista):
    
    hijos = []
        
    for arista in edges:
        padre, hijo = arista
        if padre == nodo:
            hijos.append(hijo)      
    return hijos

def PreOrden(nodo, edges, visitados = None):
    if visitados is None:
        visitados = []
    
    visitados.append(nodo)
    
    hijos = encontrarHijos(nodo, edges)
    
    for hijo in hijos:
        PreOrden(hijo,edges,visitados)
    
    return visitados

def Inorden(nodo, edges, visitados = None):
    if visitados is None:
        visitados = []
    
    hijos = encontrarHijos(nodo, edges)
    
    if hijos:
        Inorden(hijos[0],edges,visitados)
    
    visitados.append(nodo)
    
    if len(hijos) > 1:
        Inorden(hijos[1],edges,visitados)
    
    return visitados

def PostOrden(nodo, edges, visitados = None):
    if visitados is None:
        visitados = []
    
    hijos = encontrarHijos(nodo, edges)
    
    if hijos:
        PostOrden(hijos[0],edges,visitados)
        
    if len(hijos)>1:
        PostOrden(hijos[1],edges,visitados)
        
    visitados.append(nodo)
    
    return visitados

RecorridoPreOrden = PreOrden('a',edges)
print("El recorrido en PreOrden es: ",RecorridoPreOrden)

RecorridoInorden = Inorden('a',edges)
print("El recorrido en InOrden es: ",RecorridoInorden)

RecorridoPostOrden = PostOrden('a',edges)
print("El recorrido en PostOrden es: ",RecorridoPostOrden)

plt.gca().invert_yaxis()  # Invertir el eje Y para que el nodo raíz esté en la parte superior
plt.axis('on')  # Mostrar los ejes
plt.title("Árbol 1")
plt.show()
#----------------------------------------------------------------------

# Función para dibujar líneas entre nodos
def draw_line1(x1, y1, x2, y2, color = 'k'):
    plt.plot([x1, x2], [y1, y2], 'k-')

# Función para dibujar un nodo
def draw_node1(x, y, text, color = 'skyblue'):
    plt.text(x, y, text, fontsize=12, ha='center', va='center', bbox=dict(facecolor=color, edgecolor='black', boxstyle='circle,pad=0.3'))

positions1 = {
    'A': (0, 0),
    'B': (1, -0.3),
    'C': (-1, -0.3),
    'D': (-0.3, -0.7),
    'E': (-1, -1),
    'F': (-0.3, -1.8),
    'G': (-1.5, -1.8),
    'H': (1.5, -0.7),
    'I': (2, -1),
    'J': (1, -1),
    'K': (1.5, -1.3),
    'L': (2, -2),
    'M': (1, -2),
}

Nodos1 = ['A','B','C','D','E','F','G','H','I','J','K','L','M']

# Definir las conexiones entre los nodos (aristas)
edges1 = [
    ('A', 'B'), ('A', 'C'), ('B','H'),('C','D'),
    ('H','I'),('H','J'),('I','K'),('K','L'),('K','M'),
    ('D','E'),('E','F'),('E','G')
]

# Dibuja las líneas (aristas) entre nodos
for edge in edges1:
    x1, y1 = positions1[edge[0]]
    x2, y2 = positions1[edge[1]]
    draw_line1(x1, y1, x2, y2)

# Dibuja los nodos
for node, (x, y) in positions1.items():
    draw_node1(x, y, node)

def encontrarHijos1(nodo, arista):
    
    hijos = []
        
    for arista in edges1:
        padre, hijo = arista
        if padre == nodo:
            hijos.append(hijo)      
    return hijos

def PreOrden1(nodo, edges, visitados = None):
    if visitados is None:
        visitados = []
    
    visitados.append(nodo)
    
    hijos = encontrarHijos1(nodo, edges)
    
    for hijo in hijos:
        PreOrden1(hijo,edges,visitados)
    
    return visitados

def Inorden1(nodo, edges, visitados = None):
    if visitados is None:
        visitados = []
    
    hijos = encontrarHijos1(nodo, edges)
    
    if hijos:
        Inorden1(hijos[0],edges,visitados)
    
    visitados.append(nodo)
    
    if len(hijos) > 1:
        Inorden1(hijos[1],edges,visitados)
    
    return visitados

def PostOrden1(nodo, edges, visitados = None):
    if visitados is None:
        visitados = []
    
    hijos = encontrarHijos1(nodo, edges)
    
    if hijos:
        PostOrden1(hijos[0],edges,visitados)
        
    if len(hijos)>1:
        PostOrden1(hijos[1],edges,visitados)
        
    visitados.append(nodo)
    
    return visitados


RecorridoPreOrden1 = PreOrden1('A',edges)
print("El recorrido en PreOrden es: ",RecorridoPreOrden1)

RecorridoInorden1 = Inorden1('A',edges)
print("El recorrido en InOrden es: ",RecorridoInorden1)

RecorridoPostOrden1 = PostOrden1('A',edges)
print("El recorrido en PostOrden es: ",RecorridoPostOrden1)

plt.gca().invert_yaxis()  # Invertir el eje Y para que el nodo raíz esté en la parte superior
plt.axis('on')  # Mostrar los ejes
plt.title("Árbol 2")
plt.show()