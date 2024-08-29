import matplotlib.pyplot as plt

# Función para dibujar líneas entre nodos
def draw_line(x1, y1, x2, y2, color = 'k'):
    plt.plot([x1, x2], [y1, y2], 'k-')

# Función para dibujar un nodo
def draw_node(x, y, text, color = 'skyblue'):
    plt.text(x, y, text, fontsize=12, ha='center', va='center', bbox=dict(facecolor=color, edgecolor='black', boxstyle='circle,pad=0.3'))

positions = {
    'a': (0, 0),
    'b': (-2, -1),
    'c': (-1, -1),
    'd': (1, -1),
    'e': (2, -1),
    'f': (-3, -2),
    'g': (-2, -2),
    'h': (-1.5, -2),
    'i': (-0.5, -2),
    'j': (0.5, -2),
    'k': (1.5, -2),
    'l': (3, -2),
    'm': (-2.5, -3),
    'n': (-1.5, -3),
    'o': (-0.75, -3),
    'p': (0.75, -3),
    'q': (3, -2.5),
    'r': (2.5, -3),
}

Nodos = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r']

# Definir las conexiones entre los nodos (aristas)
edges = [
    ('a', 'b'), ('a', 'c'), ('a', 'd'), ('a', 'e'),
    ('b', 'f'),
    ('c', 'g'),
    ('g', 'm'), ('g', 'n'),
    ('c', 'h'), ('c', 'i'),
    ('d', 'j'), ('j', 'o'), ('j', 'p'),
    ('e', 'k'),('e', 'l'),
    ('q', 'r'),('l', 'q'),
]

def encontrarPadre(nodo,arista):
    for arista in edges:
        padre, hijo = arista
        if hijo == nodo:
            return padre
    return None

def encontrarHijos(nodo, arista):
    
    hijos = []
        
    for arista in edges:
        padre, hijo = arista
        if padre == nodo:
            hijos.append(hijo)      
    return hijos

def encontrarDescendientes(nodoObjetivo, edges, descendientes = None):
    if descendientes is None:
        descendientes  = []
    
    for arista in edges:
        padre, hijo = arista
        if padre == nodoObjetivo:
            descendientes.append(hijo)
            encontrarDescendientes(hijo,edges,descendientes)
            
    return descendientes

def encontrarAncestros(nodoObjetivo, edges, ancestros = None):
    if ancestros is None:
        ancestros = []
    
    for arista in edges:
        padre, hijo = arista
        if hijo == nodoObjetivo:
            ancestros.append(padre)
            encontrarAncestros(padre,edges,ancestros)
            break
    return ancestros
 
def encontrarHermanos(nodo1,edges, hermanos = None):
    if hermanos is None:
        hermanos = []
    
    padre = None
    for arista in edges:
        padre_tempr, hijo = arista
        if hijo == nodo1:
            padre = padre_tempr
    
    if padre is not None:
        for arista in edges:
            padre_tempr, hijo = arista
            if padre_tempr == padre and hijo != nodo1:
                hermanos.append(hijo)
    
    return hermanos

def encontrarNodosTerminales(edges,NodosTerminales = None):
    NodosTerminales = []
    
    for nodo in Nodos:
        Hijos = encontrarHijos(nodo,edges)
        if len(Hijos) == 0:
            NodosTerminales.append(nodo)
    
    return NodosTerminales
    
def encontrarNosInternos(edges, NodosInternos = None):
    NodosInternos = []
    
    for nodo in Nodos:
        Hijos = encontrarHijos(nodo,edges)
        if len(Hijos) != 0:
            NodosInternos.append(nodo)
    
    return NodosInternos

def dibujarSubArbol(raiz, edges,color_arista = 'r', color_nodo = 'lightgreen'):
    
    descndientes = encontrarDescendientes(raiz,edges)
    subarbol = [raiz] + descndientes
    
    subArbolAristas = [edge for edge in edges if edge[0] in subarbol and edge[1] in subarbol]
   
    for edge in subArbolAristas:
        x1, y1 = positions[edge[0]]
        x2, y2 = positions[edge[1]]
        draw_line(x1, y1, x2, y2,color = color_arista)
    
   
    for node in subarbol:
        x,y = positions[node]
        draw_node(x,y,node,color = color_nodo)
 

# Dibuja las líneas (aristas) entre nodos
for edge in edges:
    x1, y1 = positions[edge[0]]
    x2, y2 = positions[edge[1]]
    draw_line(x1, y1, x2, y2)

# Dibuja los nodos
for node, (x, y) in positions.items():
    draw_node(x, y, node)

           

padreC = encontrarPadre('c',edges)
padreH = encontrarPadre('h',edges)

print("El padre del nodo c es: ",padreC)
print("El padre del nodo h es: ",padreH)

AncestrosC = encontrarAncestros('c',edges)
AncestrosJ = encontrarAncestros('j',edges)

print("Los ancestros del nodo c son: ",AncestrosC)
print("Los ancestros del nodo j son: ",AncestrosJ)

HijoD = encontrarHijos('d',edges)
HijoE = encontrarHijos('e',edges)

print("Los hijos del nodo d son: ",HijoD)
print("Los hijos del nodo e son: ",HijoE)

DescendientesC = encontrarDescendientes('c',edges)
DescendientesE = encontrarDescendientes('e',edges)

print("Los descendientes del nodo c son: ",DescendientesC)
print("Los descendientes del nodo E son: ",DescendientesE)

HermnaosF = encontrarHermanos('f',edges)
HermanosH = encontrarHermanos('h',edges)

print("Los hermanos del nodo f son: ",HermnaosF)
print("Los hermanos del nodo h son: ",HermanosH)

NTerminales = encontrarNodosTerminales(edges)

print("Los nodos terminales son: ",NTerminales)

NInternos = encontrarNosInternos(edges)

print("Los nodos internos son: ",NInternos)

#Solo resalta el subarbol j
dibujarSubArbol('j',edges)
#Resalta el subarbol e
dibujarSubArbol('e',edges)

plt.gca().invert_yaxis()  # Invertir el eje Y para que el nodo raíz esté en la parte superior
plt.axis('on')  #muestra los ejes
plt.show()
