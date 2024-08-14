import matplotlib.pyplot as plt
import networkx as nx

def dibujarGrafo(aristas):
    grafo = nx.Graph()
    grafo.add_edges_from(aristas)
    nx.draw(grafo, with_labels=True, node_color='lightblue', edge_color='gray', node_size=500, font_size=10)
    plt.title("Grafo Dibujado")
    plt.show()

aristas = [(0, 1), (0, 2), (1, 2), (1, 3), (2, 3), (3, 4)]
dibujarGrafo(aristas)

