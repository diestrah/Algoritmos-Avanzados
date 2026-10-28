# 🧳 Viajante con Construcción Aleatorizada

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Construcción voraz aleatorizada · 📐 **Representación:** Matriz de distancias

## 📝 Enunciado

Un viajante debe visitar todas las ciudades exactamente una vez y regresar a la ciudad inicial.

Dada una matriz de distancias, construye **una ruta completa** utilizando una lista restringida de candidatos (RCL) y un parámetro de relajación `α`.

En cada elección se prefieren distancias menores, pero la siguiente ciudad debe seleccionarse aleatoriamente entre las integrantes de la RCL.

Este ejercicio extiende la práctica anterior: ahora realizarás varias elecciones para construir una solución. Todavía no debes repetir construcciones ni aplicar búsqueda local.

## 🧪 Ejemplo de ejecución

Para la siguiente matriz, partiendo de la ciudad `0` y con `α = 0.3`:

```text
     0   1   2   3   4   5
0    0  10  15  20  25  30
1   10   0  35  12  28  40
2   15  35   0  30   9  11
3   20  12  30   0   8  22
4   25  28   9   8   0  18
5   30  40  11  22  18   0
```

Los números de la primera fila y de la primera columna identifican las ciudades; no forman parte de la matriz.

Una posible salida es:

```text
Ciudad inicial: 0
Alfa: 0.3

Ruta: 0 -> 2 -> 4 -> 3 -> 1 -> 5 -> 0
Distancia total: 114
```

La ruta obtenida puede variar según la semilla y el generador aleatorio utilizados.

## 🚧 Restricciones y suposiciones

- La diagonal contiene ceros y las demás distancias son enteros positivos.
- La ciudad inicial pertenece al conjunto de ciudades y `α` está en `[0, 1]`.
- Cada ciudad se visita una sola vez, excepto la inicial, que también cierra la ruta.
- En cada paso, reconstruye la RCL considerando las distancias desde la ciudad actual a las ciudades no visitadas.
- Selecciona aleatoriamente una integrante de la RCL e incluye el regreso al origen en la distancia total.
- Inicializa la semilla una sola vez y mantenla fija durante las pruebas.
- Construye una sola ruta, sin fuerza bruta, backtracking ni búsqueda local.


⬅️ [Volver al índice](..)