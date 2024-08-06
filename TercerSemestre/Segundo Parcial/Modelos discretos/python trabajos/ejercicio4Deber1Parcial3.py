import networkx as nx

def listar_trayectorias_simples(grafo, inicio, fin):
    try:
        todas_las_trayectorias = list(nx.all_simple_paths(grafo, source=inicio, target=fin))
        return todas_las_trayectorias
    except nx.NetworkXNoPath:
        return []

def main():
    # Ejemplo de entrada de aristas
    aristas = [(0, 1), (0, 2), (1, 2), (1, 3), (2, 3), (3, 4)]
    grafo = nx.Graph()
    grafo.add_edges_from(aristas)
    
    inicio = 0
    fin = 4
    
    trayectorias = listar_trayectorias_simples(grafo, inicio, fin)
    
    if trayectorias:
        print(f"Todas las trayectorias simples de {inicio} a {fin}:")
        for i, tray in enumerate(trayectorias):
            print(f"{i+1}: {tray}")
    else:
        print(f"No hay trayectorias simples de {inicio} a {fin}")

if __name__ == "__main__":
    main()
