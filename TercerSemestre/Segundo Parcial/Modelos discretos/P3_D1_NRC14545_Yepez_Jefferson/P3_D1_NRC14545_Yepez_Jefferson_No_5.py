def esTrayectoriaSimple(trayectoria):
    vertices = set()
    aristas = set()
    for (u, v) in trayectoria:
        if u in vertices or v in vertices or (u, v) in aristas or (v, u) in aristas:
            return False
        vertices.add(u)
        vertices.add(v)
        aristas.add((u, v))
    return True

def esCiclo(trayectoria):
    if trayectoria[0][0] != trayectoria[-1][1]:
        return False
    vertices = [u for (u, v) in trayectoria] + [trayectoria[-1][1]]
    if len(set(vertices)) == len(vertices):
        return False
    return True

def esCicloSimple(trayectoria):
    if not esCiclo(trayectoria):
        return False
    vertices = set()
    aristas = set()
    for (u, v) in trayectoria:
        if u in vertices or v in vertices or (u, v) in aristas or (v, u) in aristas:
            return False
        vertices.add(u)
        vertices.add(v)
        aristas.add((u, v))
    return True

def determinarTipoTrayectoria(trayectoria):
    if esCicloSimple(trayectoria):
        return "Ciclo Simple"
    elif esCiclo(trayectoria):
        return "Ciclo"
    elif esTrayectoriaSimple(trayectoria):
        return "Trayectoria Simple"
    else:
        return "Ninguno de los anteriores"

# Ejemplos de uso
trayectoria1 = [(1, 2), (2, 3), (3, 4)]
trayectoria2 = [(1, 2), (2, 3), (3, 1)]
trayectoria3 = [(1, 2), (2, 3), (3, 4), (4, 1)]

print(determinarTipoTrayectoria(trayectoria1)) # Trayectoria Simple
print(determinarTipoTrayectoria(trayectoria2)) # Ciclo Simple
print(determinarTipoTrayectoria(trayectoria3)) # Ciclo
