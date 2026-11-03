# 🧳 Viajante con Múltiples Construcciones

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Construcción voraz aleatorizada con múltiples inicios · 📐 **Representación:** Matriz de distancias

## 📝 Enunciado

Un viajante debe visitar todas las ciudades exactamente una vez y regresar a la ciudad inicial.

Extiende el ejercicio anterior para generar varias rutas mediante construcción voraz aleatorizada y **conservar la de menor distancia total**.

El programa recibe una matriz de distancias, una ciudad inicial, un parámetro de relajación `α` y una cantidad de iteraciones. Cada iteración debe construir una ruta completa.

Al finalizar, muestra la mejor ruta encontrada y su distancia. Este ejercicio todavía no incluye búsqueda local.

## 🧪 Ejemplo de ejecución

Para la siguiente matriz, partiendo de la ciudad `0`, con `α = 0.3` y `1000` iteraciones:

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
Iteraciones: 1000

Mejor ruta: 0 -> 2 -> 5 -> 4 -> 3 -> 1 -> 0
Distancia total: 74
```

El resultado puede variar según la semilla y el generador aleatorio utilizados.

## 🚧 Restricciones y suposiciones

- La matriz es simétrica, de tamaño `n × n`, con `n ≥ 2`; la diagonal contiene ceros y las demás distancias son enteros positivos.
- La ciudad inicial es válida, `α` pertenece a `[0, 1]` y las iteraciones son un entero positivo.
- Cada construcción debe comenzar sin ciudades visitadas y terminar regresando al origen.
- Las elecciones deben realizarse mediante una RCL actualizada en cada paso.
- Inicializa el generador aleatorio una sola vez y usa una semilla fija durante las pruebas.
- Conserva la ruta de menor distancia; en empate, mantén la primera encontrada.
- No se permite fuerza bruta, backtracking ni búsqueda local.

⬅️ [Volver al índice](..)