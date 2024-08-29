import random

def suma(x,y):
    return x+y

def numIn():
    return random.randint(0,1)

def numeroRan():
    return random.randint(0,3)

matriz = []
for i in range(4):
    fila = []
    for j in range(4):
        if i != j:
            fila.append(numeroRan())
        else:
            fila.append(numIn())
    matriz.append(fila)
    
contador = 0
cont = 0
print("Los numeros aleatorios generados son: ")
for fila in matriz:
    print(fila)

for fila in matriz:
    for i in fila:
        if i != 0:
            contador = contador + 1   

for i in range(len(matriz)):
    if matriz[i][i] != 0:
        cont += 1

sumar = 0
ar = 0
for i in range(len(matriz)):
    for j in range(len(matriz)):
        if matriz[i][j] != 0:
            sumar = matriz[i][j]
            ar = ar + sumar
    print(f"El grado del nodo {i+1} es: ",ar)
    
        

print("El numero de lazos es: ",cont)
print("El numero de aristas son: ", contador)

#print("La suma de los dos numeros es: ", suma(5,4))