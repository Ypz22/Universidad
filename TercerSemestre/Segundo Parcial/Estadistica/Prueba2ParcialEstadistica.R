#1.- 50 ventas en un almacen arrojaron una media de 150 dolares con una desviacion de 33usd.
# Valores conocidos
n <- 50
media <- 150
desviacion <- 33

# Calcular el error estándar
error_estandar <- desviacion / sqrt(n)

# Calcular el intervalo de confianza del 95%
alpha <- 0.05
t_alpha <- qt(1 - alpha/2, df = n - 1)
margen_error <- t_alpha * error_estandar
lim_inferior <- media - margen_error
lim_superior <- media + margen_error

# Calcular el error muestral
error_muestral <- margen_error

# Calcular el estadístico T observado (en caso se requiera para alguna comparación)
T <- media / error_estandar

# Mostrar resultados
cat("Media:", media, "USD\n")
cat("Desviación estándar:", desviacion, "USD\n")
cat("Error estándar:", error_estandar, "USD\n")
cat("Estadístico t (para el intervalo de confianza):", t_alpha, "\n")
cat("Intervalo de confianza (95%): [", lim_inferior, ", ", lim_superior, "] USD\n")
cat("Error muestral:", error_muestral, "USD\n")


#2.- En un laboratorio de computacion con 30 computadores se encontraron 7 con virus
# Valores conocidos
n <- 30
x <- 7
p_hat <- x / n

# Calcular el error estándar
error_estandar <- sqrt((p_hat * (1 - p_hat)) / n)

# Calcular el estadístico Z
Z <- p_hat / error_estandar

# Calcular el intervalo de confianza del 95%
alpha <- 0.05
Z_alpha <- qnorm(1 - alpha/2)
margen_error <- Z_alpha * error_estandar
lim_inferior <- p_hat - margen_error
lim_superior <- p_hat + margen_error

# Calcular el error muestral
error_muestral <- margen_error / p_hat * 100

# Mostrar resultados
cat("Proporción muestral (p̂):", p_hat, "\n")
cat("Error estándar:", error_estandar, "\n")
cat("Estadístico Z:", Z, "\n")
cat("Intervalo de confianza (95%): [", lim_inferior * 100, "%, ", lim_superior * 100, "% ]\n")
cat("Error muestral:", error_muestral, "%\n")

#3.- Las varianzas de tiempos de producción en 100 corridas realizadas en dos máquinas similares son 112 y 91 minutos cuadrados respectivamente
# Valores conocidos
var1 <- 112
var2 <- 91
n1 <- 100
n2 <- 100

# Calcular el estadístico F
F <- var1 / var2

# Grados de libertad
df1 <- n1 - 1
df2 <- n2 - 1

# Calcular el intervalo de confianza para la razón de varianzas
alpha <- 0.05
F_inf <- qf(alpha / 2, df1, df2)
F_sup <- qf(1 - alpha / 2, df1, df2)
lim_inferior <- F / F_sup
lim_superior <- F / F_inf

# Determinar si las varianzas se pueden considerar distintas
p_value <- 2 * min(pf(F, df1, df2), 1 - pf(F, df1, df2))
varianzas_distintas <- p_value < alpha

# Mostrar resultados
cat("Estadístico F:", F, "\n")
cat("Intervalo de confianza (95%) para la razón de varianzas: [", lim_inferior, ", ", lim_superior, "]\n")
cat("Las varianzas se pueden considerar distintas:", varianzas_distintas, "\n")
cat("p-valor:", p_value, "\n")

#4.- De 70 pedidos realizados al proveedor A, 10 llegaron con retraso. Además, 6 de 100 pedidos del proveedor B llegaron atrasados
# Valores conocidos
n_a <- 70
n_b <- 100
x_a <- 10
x_b <- 6

# Calcular proporciones
p_a <- x_a / n_a
p_b <- x_b / n_b

# Proporción combinada
p_comb <- (x_a + x_b) / (n_a + n_b)

# Error estándar de la diferencia de proporciones
error_estandar <- sqrt(p_comb * (1 - p_comb) * (1/n_a + 1/n_b))

# Estadístico Z
Z <- (p_a - p_b) / error_estandar

# Intervalo de confianza para la diferencia de proporciones
alpha <- 0.05
Z_alpha <- qnorm(1 - alpha/2)
margen_error <- Z_alpha * error_estandar
lim_inferior <- (p_a - p_b) - margen_error
lim_superior <- (p_a - p_b) + margen_error

# Determinar si las proporciones se pueden considerar iguales
p_value <- 2 * (1 - pnorm(abs(Z)))
proporciones_iguales <- p_value > alpha

# Calcular el error muestral
error_muestral <- margen_error / (p_a - p_b) * 100

# Mostrar resultados
cat("Proporción de retrasos del proveedor A:", p_a * 100, "%\n")
cat("Proporción de retrasos del proveedor B:", p_b * 100, "%\n")
cat("Intervalo de confianza (95%) para la diferencia de proporciones: [", lim_inferior * 100, "%, ", lim_superior * 100, "% ]\n")
cat("Las proporciones de retrasos se pueden considerar iguales:", proporciones_iguales, "\n")
cat("p-valor:", p_value, "\n")
cat("Error muestral:", error_muestral, "%\n")

#5.- Se desea comparar los tiempos de producción entre dos maquinas similares. Para esto, se analizan 100 corridas de producción en cada máquina obteniendo promedios de 17.5 y 20.7 min, y desviaciones muestrales de 1.2 y 2.2 min. Suponga poblaciones normales con varianzas iguales
# Valores conocidos
n1 <- 100
n2 <- 100
media1 <- 17.5
media2 <- 20.7
desviacion1 <- 1.2
desviacion2 <- 2.2

# Calcular la varianza combinada
var_comb <- ((n1 - 1) * desviacion1^2 + (n2 - 1) * desviacion2^2) / (n1 + n2 - 2)
error_estandar <- sqrt(var_comb * (1/n1 + 1/n2))

# Estadístico t
t <- (media1 - media2) / error_estandar

# Intervalo de confianza para la diferencia de medias
alpha <- 0.05
t_alpha <- qt(1 - alpha/2, df = n1 + n2 - 2)
margen_error <- t_alpha * error_estandar
lim_inferior <- (media1 - media2) - margen_error
lim_superior <- (media1 - media2) + margen_error

# Determinar si los tiempos medios se pueden considerar distintos
p_value <- 2 * (1 - pt(abs(t), df = n1 + n2 - 2))
medias_distintas <- p_value < alpha

# Calcular el error muestral
error_muestral <- margen_error

# Mostrar resultados
cat("Media de la máquina 1:", media1, "min\n")
cat("Media de la máquina 2:", media2, "min\n")
cat("Error estándar:", error_estandar, "min\n")
cat("Estadístico t:", t, "\n")
cat("Intervalo de confianza (95%) para la diferencia de medias: [", lim_inferior, ", ", lim_superior, "] min\n")
cat("Los tiempos medios se pueden considerar distintos:", medias_distintas, "\n")
cat("p-valor:", p_value, "\n")
cat("Error muestral:", error_muestral, "min\n")

#6.- En una muestra de 10 computadores se encontro un promedio de 5 viruscon una varianza de 0.25
#a. El estadistico T es igual a 2.26
# Valores conocidos
n <- 10
media <- 5
varianza <- 0.25
desviacion <- sqrt(varianza)

# Calcular el error estándar
error_estandar <- desviacion / sqrt(n)

# Calcular el intervalo de confianza del 95%
alpha <- 0.05
t_alpha <- qt(1 - alpha/2, df = n - 1)
margen_error <- t_alpha * error_estandar
lim_inferior <- media - margen_error
lim_superior <- media + margen_error

# Calcular el error muestral
error_muestral <- margen_error

# Calcular el estadístico T observado
T <- (media - 0) / error_estandar

# Mostrar resultados
cat("Media:", media, "\n")
cat("Desviación estándar:", desviacion, "\n")
cat("Error estándar:", error_estandar, "\n")
cat("Estadístico t:", t_alpha, "\n")
cat("Estadístico T observado:", T, "\n")
cat("Intervalo de confianza (95%): [", lim_inferior, ", ", lim_superior, "]\n")
cat("Error muestral:", error_muestral, "\n")

#7.- En una muestra de 200 graduados el 20% de ellos son mujeres.
#a. El estadistico Z es 1.96
# Valores conocidos
n <- 200
p <- 0.20

# Calcular el error estándar
error_estandar <- sqrt(p * (1 - p) / n)

# Calcular el intervalo de confianza del 95%
alpha <- 0.05
z_alpha <- qnorm(1 - alpha / 2)
margen_error <- z_alpha * error_estandar
lim_inferior <- p - margen_error
lim_superior <- p + margen_error

# Calcular el error muestral
error_muestral <- margen_error

# Calcular el estadístico Z observado
Z <- (p - 0.20) / error_estandar

# Mostrar resultados
cat("Proporción (p):", p * 100, "%\n")
cat("Error estándar:", error_estandar, "\n")
cat("Estadístico Z (para el intervalo de confianza):", z_alpha, "\n")
cat("Estadístico Z observado:", Z, "\n")
cat("Intervalo de confianza (95%): [", lim_inferior * 100, "%, ", lim_superior * 100, "% ]\n")
cat("Error muestral:", error_muestral * 100, "%\n")

#8.- Se desea comparar los tempos de conexion entre dos servidores. Para esto, se analizan 10 conexiones en cada servidor obteniendo promedios de 7.2 y 5.4 seg, y desviaciones muestrales de 0.5 y 0.4 seg. Suponga poblaciones normales con varianzas iguales
#b.- El error muestral correspondiente es igual a 0.42 seg
# Valores conocidos
n1 <- 10
n2 <- 10
media1 <- 7.2
media2 <- 5.4
desviacion1 <- 0.5
desviacion2 <- 0.4

# Calcular la varianza combinada
var_comb <- ((n1 - 1) * desviacion1^2 + (n2 - 1) * desviacion2^2) / (n1 + n2 - 2)
error_estandar <- sqrt(var_comb * (1/n1 + 1/n2))

# Estadístico t
t <- (media1 - media2) / error_estandar

# Calcular el intervalo de confianza para la diferencia de medias
alpha <- 0.05
t_alpha <- qt(1 - alpha/2, df = n1 + n2 - 2)
margen_error <- t_alpha * error_estandar
lim_inferior <- (media1 - media2) - margen_error
lim_superior <- (media1 - media2) + margen_error

# Determinar si los tiempos medios se pueden considerar iguales
p_value <- 2 * pt(-abs(t), df = n1 + n2 - 2)
tiempos_iguales <- p_value > alpha

# Calcular el error muestral
error_muestral <- margen_error

# Mostrar resultados
cat("Media del servidor 1:", media1, "seg\n")
cat("Media del servidor 2:", media2, "seg\n")
cat("Error estándar combinado:", error_estandar, "seg\n")
cat("Estadístico t:", t, "\n")
cat("Intervalo de confianza (95%) para la diferencia de medias: [", lim_inferior, ", ", lim_superior, "] seg\n")
cat("Los tiempos medios se pueden considerar iguales:", tiempos_iguales, "\n")
cat("p-valor:", p_value, "\n")
cat("Error muestral:", error_muestral, "seg\n")

#9.- De una muestra de 80 productos se encontraron 10 productos defectuosos
#b. El error muestral correspondiente es 0.072
# Valores conocidos
n <- 80
x <- 10

# Calcular la proporción muestral
p_hat <- x / n

# Calcular el error estándar de la proporción
error_estandar <- sqrt(p_hat * (1 - p_hat) / n)

# Calcular el intervalo de confianza del 95%
alpha <- 0.05
z_alpha <- qnorm(1 - alpha/2)
margen_error <- z_alpha * error_estandar
lim_inferior <- p_hat - margen_error
lim_superior <- p_hat + margen_error

# Calcular el error muestral
error_muestral <- margen_error

# Mostrar resultados
cat("Proporción muestral de productos defectuosos:", p_hat, "\n")
cat("Error estándar de la proporción:", error_estandar, "\n")
cat("Estadístico Z (para el intervalo de confianza):", z_alpha, "\n")
cat("Intervalo de confianza (95%) para la proporción: [", lim_inferior, ", ", lim_superior, "]\n")
cat("Error muestral:", error_muestral, "\n")

#10.- De 100 laptops con el antivirus A se han detectado 12 equipos infectados. De 120 laptops con el antivirus B, 8 tiene virus.
#a. El porcentaje de equipos infectados entre ambos antivirus se pueden considerar iguales
# Valores conocidos
n1 <- 100
x1 <- 12
n2 <- 120
x2 <- 8

# Calcular las proporciones muestrales
p1 <- x1 / n1
p2 <- x2 / n2

# Calcular el error estándar combinado para las proporciones
error_estandar <- sqrt(p1 * (1 - p1) / n1 + p2 * (1 - p2) / n2)

# Calcular el intervalo de confianza del 95% para la diferencia de proporciones
alpha <- 0.05
z_alpha <- qnorm(1 - alpha / 2)
margen_error <- z_alpha * error_estandar
diferencia_proporciones <- p1 - p2
lim_inferior <- diferencia_proporciones - margen_error
lim_superior <- diferencia_proporciones + margen_error

# Determinar si los porcentajes de equipos infectados son iguales
p_value <- 2 * (1 - pnorm(abs(diferencia_proporciones / error_estandar)))
porcentajes_iguales <- p_value > alpha

# Calcular el error muestral
error_muestral <- margen_error

# Mostrar resultados
cat("Proporción de equipos infectados con antivirus A:", p1 * 100, "%\n")
cat("Proporción de equipos infectados con antivirus B:", p2 * 100, "%\n")
cat("Error estándar combinado de las proporciones:", error_estandar, "\n")
cat("Intervalo de confianza (95%) para la diferencia de proporciones: [", lim_inferior * 100, "%, ", lim_superior * 100, "% ]\n")
cat("Los porcentajes de equipos infectados se pueden considerar iguales:", porcentajes_iguales, "\n")
cat("p-valor:", p_value, "\n")
cat("Error muestral:", error_muestral * 100, "%\n")

