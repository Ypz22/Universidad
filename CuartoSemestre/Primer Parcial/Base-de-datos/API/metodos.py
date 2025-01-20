from flask import Flask, request, jsonify  # permite manejar archivos json
from pymongo import MongoClient  # Conectarnos a la BDD
app = Flask(__name__)  # Definir el nombre de nuestra aplicacion

# Credenciales de la BDD
mongo_uri = "mongodb+srv://jyepez:Hola_135@cluster0.2r5lb.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0"
client = MongoClient(mongo_uri)
db = client['espe']
students_collection = db['estudiantes']

# Definición de rutas
@app.route('/students', methods=['GET'])  # la ruta con el método GET
def get_students():
    students = list(students_collection.find({}, {'_id': 0}))
    return jsonify(students)


@app.route('/students/<student_id>', methods=['GET'])
def get_students_by_id(student_id):
    student = students_collection.find_one({"username": student_id}, {'_id': 0})
    if student:
        return jsonify(student)
    else:

        return jsonify({"message": "Estudiante no encontrado en la BDD"}), 404

@app.route('/students', methods=['POST'])
def add_student():
    student = request.json
    if not student.get('username') or students_collection.find_one({"username": student["username"]}):
        return jsonify({"message": "ID de estudiante es obligatorio y debe ser único"}), 400

    students_collection.insert_one(student)
    return jsonify({"message": "Estudiante insertado"}), 201


@app.route('/students/<student_id>', methods=['DELETE'])
def delete_student(student_id):
    result = students_collection.delete_one({"username": student_id})

    if result.deleted_count:
        return jsonify({"message": "Estudiante eliminado de la BDD"}), 200
    else:
        return jsonify({"message": "No se pudo encontrar un estudiante"}), 404

@app.route('/students/<student_id>', methods=['PUT'])  # Actualizar estudiante por ID
def update_student(student_id):
    student = students_collection.find_one({"username": student_id})
    if not student:
        return jsonify({"error": "Estudiante no encontrado"}), 404

    data = request.get_json()
    if not data:
        return jsonify({"error": "Cuerpo de la solicitud vacío"}), 400

    students_collection.update_one({"username": student_id}, {"$set": data})
    updated_student = students_collection.find_one({"username": student_id}, {'_id': 0})
    return jsonify({"message": "Estudiante actualizado", "student": updated_student}), 200



if __name__ == '__main__':
    app.run(debug=True)



