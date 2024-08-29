#Diseña un autómata finito determinista (AFD) 
#que acepte todas las cadenas sobre el 
#alfabeto {a, b} que contengan un número par de as.

class Automata:
    def __init__(self):
        self.estado = 'q0'
    
    def transicion(self, simboloIngresado):
        if self.estado == 'q0':
            if simboloIngresado == 'a':
                self.estado = 'q1' #cambia de estado
            elif simboloIngresado == 'b':
                pass #se queda en el estado q0
        elif self.estado == 'q1':
            if simboloIngresado == 'a':
                self.estado = 'q0'
            elif simboloIngresado == 'b':
                pass
        
    def proceso(self, cadenaEntrada):
        for simbolo in cadenaEntrada:
            self.transicion(simbolo)
        return self.estado == 'q0'

automata = Automata()

cadeEntrada = 'aabb'

esAceptada = automata.proceso(cadeEntrada)

print("Cadena Entrada: ", cadeEntrada)
print("¿Es aceptada?", esAceptada)