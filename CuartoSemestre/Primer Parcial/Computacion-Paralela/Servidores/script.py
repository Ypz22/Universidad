import requests
import time
import matplotlib.pyplot as plt

url = "http://192.168.204.138/"
num_requests = 100
times = []

for _ in range(num_requests):
    start_time = time.time()
    response = requests.get(url)
    end_time = time.time()
    times.append(end_time - start_time)
plt.plot(times, marker='o', linestyle='-')
plt.xlabel("Número de solicitud")
plt.ylabel("Tiempo de respuesta (s)")
plt.title("Tiempos de respuesta del balanceador de carga")
plt.show()