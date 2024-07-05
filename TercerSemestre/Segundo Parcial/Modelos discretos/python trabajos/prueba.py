class Persona:
    def __init__(self,nombre,edad, dni):
        self.nombre = nombre
        self.edad = edad
        self.dni = dni
    
    def presentarse(self):
        print(f"¡Hola! Me llamo {self.nombre} y tengo {self.edad} años")


oscar = Persona("oscar","23","123123123")
oscar.presentarse()
print(oscar.dni)


class Trabajador(Persona):
    def __init__(self,nombre,edad,dni,sueldo,cargo,empresa):
        super().__init__(nombre,edad,dni)
        self.sueldo = sueldo
        self.cargo = cargo
        self.empresa = empresa
    
    def calcularSueldoAnual(self):
        return 12 * self.sueldo + 2000
    
class Estudiante(Persona):
    def __init__(self, nombre, edad, dni,universidad,curso,asignatura):
        super().__init__(nombre, edad, dni)
        self.universidad = universidad
        self.curso = curso
        self.asignatura = asignatura

    def describirse(self):
        print(f"""¡Hola! soy {self.nombre}. Tengo {self.edad} y estudio en la universidad {self.universidad}
        Estoy en el curso {self.curso}
        """)

trabajador1 = Trabajador("Juan","24","1242355334",500,"gerente","UNIT")
trabajador1.presentarse()
print(trabajador1.cargo)
print(trabajador1.calcularSueldoAnual())

estudiante1 = Estudiante("Maria","20","12124234","Espe",3,["Programacion","calculo","algebra"])
estudiante1.describirse()