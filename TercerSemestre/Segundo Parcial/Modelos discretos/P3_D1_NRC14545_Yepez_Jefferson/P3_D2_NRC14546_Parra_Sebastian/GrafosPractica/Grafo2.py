import networkx as nx
import matplotlib.pyplot as plt
import numpy as np

gaf = nx.MultiGraph()
gaf.add_nodes_from([2,7,5,8,9])
gaf.add_edges_from([(2,7),(7,9),(2,5),(5,9),(7,8),(7,9)])


#Obtenemos las posiciones de los nodos usando spring_layout
pos = nx.spring_layout(gaf)

#Dibujamos los nodos
nx.draw_networkx_nodes(gaf,pos,node_size=700)

#Dibujamos etiquetas en los nodos
nx.draw_networkx_labels(gaf,pos)

#Dibujamos las aristas rectas
#nx.draw_networkx_edges(gaf,pos,edgelist=[(2,7)],width=2)

#Creamos aristas curvas para las otras conexiones
arc = 0.2 #El valor del arco que quiero darle a la curva

for(u,v) in [(2,7),(7,9),(2,5),(5,9),(7,8),(7,9)]:
    rad = arc if u < v else -arc #Nos aseguramos que las curvas no se superpongan
    nx.draw_networkx_edges(gaf,pos,edgelist=[(u,v)],connectionstyle=f'arc3,rad={rad}',width=2)

#nx.draw(gaf,with_labels=True)
plt.axis('off') #ocultamos los ejes
plt.show()