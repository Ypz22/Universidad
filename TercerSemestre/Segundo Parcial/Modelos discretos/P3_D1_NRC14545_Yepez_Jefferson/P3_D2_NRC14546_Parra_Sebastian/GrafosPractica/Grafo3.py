import networkx as nx
import matplotlib.pyplot as plt

# Crear un grafo bipartito
B = nx.Graph()
# Añadir nodos con atributo bipartito (0 o 1)
B.add_nodes_from(['A', 'B', 'C'], bipartite=0)
B.add_nodes_from([1, 2, 3], bipartite=1)
# Añadir aristas solo entre los conjuntos bipartitos
B.add_edges_from([('A', 1), ('B', 2), ('C', 3)])

pos = nx.spring_layout(B)

nx.draw_networkx_nodes(B,pos,node_size=700)
nx.draw_networkx_edge_labels(B,pos)
# Verificar si el grafo es bipartito
print(nx.is_bipartite(B))  # Esto devolverá True

plt.show()
