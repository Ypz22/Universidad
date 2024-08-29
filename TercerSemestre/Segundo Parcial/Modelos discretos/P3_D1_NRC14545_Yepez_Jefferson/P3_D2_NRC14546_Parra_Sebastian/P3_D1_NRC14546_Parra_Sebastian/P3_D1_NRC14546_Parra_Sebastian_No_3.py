import networkx as nx
import matplotlib.pyplot as plt

def dibujar_grafo(aristas):
    G = nx.Graph()  

    
    for arista in aristas:
        G.add_edge(arista[0], arista[1])

  
    nx.draw(G, with_labels=True, node_color='skyblue', node_size=700, font_size=15, font_weight='bold')
    plt.show() 


aristas = [(1, 2), (1, 3), (2, 4), (3, 4), (4, 5)]


dibujar_grafo(aristas)
