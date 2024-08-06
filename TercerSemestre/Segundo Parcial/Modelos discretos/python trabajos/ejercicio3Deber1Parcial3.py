import networkx as nx
import matplotlib.pyplot as plt

def crear_grafo_desde_aristas(aristas):
    grafo = nx.Graph()
    grafo.add_edges_from(aristas)
    return grafo

def dibujar_grafo(grafo):
    pos = nx.spring_layout(grafo)  # Posiciones de los nodos para el dibujo
    nx.draw(grafo, pos, with_labels=True, node_color='lightblue', edge_color='gray', node_size=2000, font_size=16)
    plt.show()

def main():
    aristas = [(0, 1), (0, 2), (1, 2), (1, 3), (2, 3), (3, 4)]
    
    grafo = crear_grafo_desde_aristas(aristas)
    dibujar_grafo(grafo)

if __name__ == "__main__":
    main()
