def es_trayectoria_simple(trayectoria):
    
    return len(trayectoria) == len(set(trayectoria))

def es_ciclo(trayectoria):
   
    return trayectoria[0] == trayectoria[-1]

def es_ciclo_simple(trayectoria):
  
    return es_ciclo(trayectoria) and es_trayectoria_simple(trayectoria[:-1])

def clasificar_trayectoria(trayectoria):
    if es_ciclo_simple(trayectoria):
        return "Ciclo Simple"
    elif es_ciclo(trayectoria):
        return "Ciclo"
    elif es_trayectoria_simple(trayectoria):
        return "Trayectoria Simple"
    else:
        return "Ninguna de las anteriores"


trayectoria1 = [1, 2, 3, 4, 1]
trayectoria2 = [1, 2, 3, 1, 2]  
trayectoria3 = [1, 2, 3, 4]    
trayectoria4 = [1, 2, 3, 1]    

for i, trayectoria in enumerate([trayectoria1, trayectoria2, trayectoria3, trayectoria4], 1):
    resultado = clasificar_trayectoria(trayectoria)
    print(f"Trayectoria {i}: {trayectoria} - {resultado}")
