import random

class Nodo:
    def __init__(self, value):
        self.value = value
        self.connections = []
        
class Edge:
    def __init__(self, origin, destination):
        self.origin = origin
        self.destination = destination

numA = random.sample(range(1,10),1)
numAl = random.sample(range(1,10),numA[0]) #Para generar numeros aleatorios para los nodos

n = numA[0]#Numero de nodos
nodos = []

for i in range(n):
    nodo = Nodo(i+1)
    nodos.append(nodo)
    
edges = []
for i in range(n):
    org = nodos[i]
    destino = nodos[(i+1) % n]
    edge = Edge(org,destino)
    org.connections.append(edge)
    edges.append(edge)


# Crear y llenar la matriz de adyacencia
matriz_adyacencia = [[0 for _ in range(n)] for _ in range(n)]
for nodo in nodos:
    for connection in nodo.connections:
        origen = nodo.value - 1  # Índice del nodo de origen
        destino = connection.destination.value - 1  # Índice del nodo de destino
        matriz_adyacencia[origen][destino] = 1

for i in range(n):
    matriz_adyacencia[i][i] = 1    

# Imprimir la matriz de adyacencia
print("Matriz de Adyacencia:")
for fila in matriz_adyacencia:
    print(fila)

grados = [sum(fila) for fila in matriz_adyacencia]
numAristas = (sum(sum(fila) for fila in matriz_adyacencia)-sum(matriz_adyacencia[i][i] for i in range(n)) )//2 + sum(matriz_adyacencia[i][i] for i in range(n))
num_lazos = sum(matriz_adyacencia[i][i] for i in range(n))

print(f"El numero de aristas es: {numAristas}")
print(f"El numero de lazos es: {num_lazos}")
print(f"El grado de cada vertice es: {grados}")

    