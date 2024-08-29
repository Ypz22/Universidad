import matplotlib.pyplot as plt

#EJERCICIO 3.1

# Función para dibujar líneas entre nodos
def draw_line(x1, y1, x2, y2, color='k'):
    plt.plot([x1, x2], [y1, y2], color=color)

# Función para dibujar un nodo
def draw_node(x, y, text, color='skyblue'):
    plt.text(x, y, text, fontsize=12, ha='center', va='center', bbox=dict(facecolor=color, edgecolor='black', boxstyle='circle,pad=0.3'))

# Posiciones del árbol binario para la expresión
positions = {
    '-': (0, 0),
    '+1': (-1, -1),
    '+2': (1, -1),
    '*1': (-1.5, -2),
    '*2': (-0.5, -2),
    '/': (0.5, -2),
    '+3': (1.5, -2),
    'A1': (-2, -3),
    'B1': (-1, -3),
    'C': (-1.5, -3),
    'D1': (-0.5, -3),
    'A2': (0, -3),
    'B2': (1, -3),
    'D2': (1.5, -3),
    'E': (2, -3)
}

# Definir las conexiones entre los nodos (aristas)
edges = [
    ('-', '+1'), ('-', '+2'),
    ('+1', '*1'), ('+1', '*2'),
    ('*1', 'A1'), ('*1', 'B1'),
    ('*2', 'C'), ('*2', 'D1'),
    ('+2', '/'), ('+2', '+3'),
    ('/', 'A2'), ('/', 'B2'),
    ('+3', 'D2'), ('+3', 'E')
]

# Dibuja las líneas (aristas) entre nodos
for edge in edges:
    x1, y1 = positions[edge[0]]
    x2, y2 = positions[edge[1]]
    draw_line(x1, y1, x2, y2)

# Dibuja los nodos
for node, (x, y) in positions.items():
    draw_node(x, y, node)

plt.gca().invert_yaxis()  # Invertir el eje Y para que el nodo raíz esté en la parte superior
plt.axis('on')  # Mostrar los ejes
plt.show()

#---------------------------------------------------------------
#EJERCICIO 3.2

# Función para dibujar líneas entre nodos
def draw_line1(x1, y1, x2, y2, color='k'):
    plt.plot([x1, x2], [y1, y2], color=color)

# Función para dibujar un nodo
def draw_node1(x, y, text, color='skyblue'):
    plt.text(x, y, text, fontsize=12, ha='center', va='center', bbox=dict(facecolor=color, edgecolor='black', boxstyle='circle,pad=0.3'))

# Posiciones del árbol binario para la expresión
positions1 = {
    '-': (0, 0),
    '*1': (-2, -1),
    '*2': (2, -1),
    '*3': (-3, -2),
    'E': (-1, -2),
    '+1': (-4, -3),
    '+2': (-2, -3),
    'A1': (-5, -4),
    'B1': (-3, -4),
    'C1': (-3, -4),
    'D1': (-1, -4),
    '+3': (1, -2),
    '-1': (3, -2),
    'A2': (0, -3),
    'B2': (2, -3),
    'C2': (2, -3),
    'D2': (4, -3)
}

# Definir las conexiones entre los nodos (aristas)
edges1 = [
    ('-', '*1'), ('-', '*2'),
    ('*1', '*3'), ('*1', 'E'),
    ('*3', '+1'), ('*3', '+2'),
    ('+1', 'A1'), ('+1', 'B1'),
    ('+2', 'C1'), ('+2', 'D1'),
    ('*2', '+3'), ('*2', '-1'),
    ('+3', 'A2'), ('+3', 'B2'),
    ('-1', 'C2'), ('-1', 'D2')
]

# Dibuja las líneas (aristas) entre nodos
for edge in edges1:
    x1, y1 = positions1[edge[0]]
    x2, y2 = positions1[edge[1]]
    draw_line1(x1, y1, x2, y2)

# Dibuja los nodos
for node, (x, y) in positions1.items():
    draw_node1(x, y, node)

plt.gca().invert_yaxis()  # Invertir el eje Y para que el nodo raíz esté en la parte superior
plt.axis('on')  # Mostrar los ejes
plt.show()

#------------------------------------------------------------------------
#EJERCICIO 3.2

# Función para dibujar líneas entre nodos
def draw_line2(x1, y1, x2, y2, color='k'):
    plt.plot([x1, x2], [y1, y2], color=color)

# Función para dibujar un nodo
def draw_node2(x, y, text, color='skyblue'):
    plt.text(x, y, text, fontsize=12, ha='center', va='center', bbox=dict(facecolor=color, edgecolor='black', boxstyle='circle,pad=0.3'))

# Posiciones mejoradas del árbol binario para la expresión
positions2 = {
    '+': (0, 0),
    '-1': (-3, -1),
    '/1': (3, -1),
    '*': (-4, -2),
    '/2': (-2, -2),
    '-2': (2, -2),
    '+1': (4, -2),
    'A1': (-5, -3),
    'B1': (-3, -3),
    'C1': (-1.5, -3),
    '+2': (-2.5, -3.5),
    'D1': (-3, -4),
    'E': (-2, -4),
    'A2': (1, -3),
    'B2': (2, -3),
    'C2': (-0.2, -3),
    '*2': (3, -3),
    'D2': (1.8, -4),
    'A3': (3, -4),
    'B3': (4, -4),
    'C3': (5, -4)
}

# Definir las conexiones entre los nodos (aristas)
edges2 = [
    ('+', '-1'), ('+', '/1'),
    ('-1', '*'), ('-1', '/2'),
    ('*', 'A1'), ('*', 'B1'),
    ('/2', 'C1'), ('/2', '+2'),
    ('+2', 'D1'), ('+2', 'E'),
    ('/1', '-2'), ('/1', '+1'),
    ('-2', 'A2'), ('-2', 'B2'),
    ('-2', 'C2'), ('-2', '*2'),
    ('*2', 'D2'), ('*2', 'D2'),
    ('+1', 'A3'), ('+1', 'B3'), ('+1', 'C3')
]

# Dibuja las líneas (aristas) entre nodos
for edge in edges2:
    x1, y1 = positions2[edge[0]]
    x2, y2 = positions2[edge[1]]
    draw_line2(x1, y1, x2, y2)

# Dibuja los nodos
for node, (x, y) in positions2.items():
    draw_node2(x, y, node)

plt.gca().invert_yaxis()  # Invertir el eje Y para que el nodo raíz esté en la parte superior
plt.axis('on')  # Mostrar los ejes
plt.show()