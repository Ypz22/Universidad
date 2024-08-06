import random 

def crearMatrizAdyacente(matriz,tamano):
    for i in range(0,tamano,1):
        for j in range(0,tamano,1):
            matriz[i][j] = numeroAleatorio()
            
            
def numeroAleatorio():
    return random.randint(1,5)

def mostraMatrizAdyacente(matriz):
    for fila in matriz:
        print(fila)
        
def contarAristas(matriz):
    contadorAristas = 0
    for fila in matriz:
        for columna in fila:
            contadorAristas += columna 
    print(f"La matriz contiene {contadorAristas} aristas")

def contarLazos(matriz, tamano):
    contadorLazos = 0
    for i in range(0,tamano,1):
        for j in range(0,tamano,1):
            if(i == j):
                contadorLazos += matriz[i][j]
    print(f"La matriz contiene {contadorLazos} lazos")

def contarGradoVertices(matriz,tamano):
    for i in range(0,tamano,1):
        contadorVertice = 0
        for j in range(0,tamano,1):
            contadorVertice += matriz[i][j]
        print(f"El vertice {i+1} tiene un grado de {contadorVertice}")       

tamanoMatriz = int(input("Ingrese el tamano de la matriz de adyacencia: "))
matriz = [[0 for _ in range(tamanoMatriz)] for _ in range(tamanoMatriz)]
crearMatrizAdyacente(matriz,tamanoMatriz)
mostraMatrizAdyacente(matriz)
contarAristas(matriz)
contarLazos(matriz,tamanoMatriz)
contarGradoVertices(matriz,tamanoMatriz)