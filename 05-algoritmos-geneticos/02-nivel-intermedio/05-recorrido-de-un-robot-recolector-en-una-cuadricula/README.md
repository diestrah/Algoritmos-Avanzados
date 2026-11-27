# 🤖 Recorrido de un Robot Recolector en una Cuadrícula

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Algoritmo genético · 📐 **Representación:** Matriz binaria codificada en un vector

## 📝 Enunciado

Un robot debe recorrer un almacén representado por una cuadrícula de `N × N`. Cada celda contiene un producto con un peso determinado.

El robot comienza en la esquina superior izquierda y termina en la esquina inferior derecha. Solo puede desplazarse **una celda hacia la derecha o hacia abajo**.

Al visitar una celda, recoge obligatoriamente su producto, incluidos los de las celdas inicial y final.

Debes encontrar un recorrido que maximice el peso recolectado sin superar la capacidad del robot.

Representa el recorrido mediante un vector binario de `N × N` genes:

- `1`: la celda pertenece al recorrido.
- `0`: la celda no se visita.

La posición de una celda se calcula mediante:

```text
indice = fila × N + columna
```

Los índices internos comienzan en cero.

Implementa un algoritmo genético con selección por ruleta, cruce de un punto, mutación de un bit, eliminación de clones y reemplazo de los mejores individuos.

Al finalizar, muestra únicamente el mejor recorrido encontrado.

## 🧪 Ejemplo de ejecución

Para `N = 3`, capacidad `20` y los siguientes pesos:

```text
2  4  6
3  5  2
7  1  4
```

Con los parámetros:

```text
Cantidad de individuos: 6
Cantidad de generaciones: 100
Tasa de seleccion: 0.8
Probabilidad de mutacion: 0.1
```

Una posible salida es:

```text
Mejor cromosoma encontrado:
1 1 1 | 0 0 1 | 0 0 1

Recorrido en la cuadricula:
1 1 1
0 0 1
0 0 1

Celdas visitadas:
(0, 0) -> (0, 1) -> (0, 2) -> (1, 2) -> (2, 2)

Peso recolectado: 18
Capacidad restante: 2
```

Los resultados pueden variar según la semilla y las elecciones aleatorias. No se exige obtener exactamente este recorrido.

## 🚧 Restricciones y suposiciones

- `N` es mayor o igual que dos.
- Los pesos y la capacidad son enteros positivos.
- No existen obstáculos.
- El robot recoge todos los productos del recorrido; no puede omitir una recolección.
- Existe al menos un recorrido que respeta la capacidad.
- Cada cromosoma contiene exactamente `N × N` genes binarios.
- Todo recorrido válido visita exactamente `2 × N - 1` celdas.
- El tamaño de población es mayor o igual que dos.
- Existen al menos tantos recorridos válidos distintos como individuos se requieren en la población.
- La población inicial y cada población resultante del reemplazo deben contener individuos válidos y distintos.

### 🌱 Población inicial

- Construye cada candidato desde `(0, 0)`.
- Marca la celda inicial y elige aleatoriamente movimientos hacia la derecha o hacia abajo.
- Si llegas al borde inferior, continúa hacia la derecha.
- Si llegas al borde derecho, continúa hacia abajo.
- Marca todas las celdas visitadas hasta alcanzar `(N - 1, N - 1)`.
- Descarta los recorridos que excedan la capacidad o estén repetidos.
- Continúa hasta completar el tamaño de población indicado.

Esta construcción garantiza la forma del recorrido, pero todavía debes comprobar su peso.

### 🚧 Aberraciones

Un individuo es una aberración si:

- No incluye la celda inicial o la final.
- No contiene exactamente `2 × N - 1` genes en uno.
- Las celdas marcadas no forman un único recorrido continuo mediante movimientos a la derecha o hacia abajo.
- El peso recolectado supera la capacidad.

**Contar los unos no basta para validar el recorrido.** Debes comprobar que todas las celdas marcadas formen parte del mismo camino.

### 🎯 Fitness y selección

- El fitness de un individuo válido es el peso total de las celdas visitadas.
- Selecciona padres mediante ruleta proporcional al fitness, utilizando acumulados.
- La selección es con reemplazo.
- Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion`.
- Elige una tasa en `(0, 1]` que produzca al menos dos padres.
- Como los pesos son positivos, todos los individuos válidos tienen fitness positivo.

### ✂️ Cruce de un punto

- Genera un hijo por cada pareja ordenada de índices distintos del vector de padres.
- Siempre se aplica el cruce.
- Elige el punto de corte entre `1` y `N × N - 1`, inclusive.
- El hijo recibe el segmento inicial del primer padre y el segmento final del segundo.
- No modifiques los padres originales.

El cruce puede producir celdas desconectadas o una cantidad incorrecta de celdas visitadas. Los hijos deben validarse.

### 🔄 Mutación y validación

- Realiza una única decisión de mutación por hijo.
- Si ocurre, elige un gen al azar e invierte su bit.
- Cada hijo cambia como máximo un gen.
- La probabilidad de mutación pertenece a `[0, 1]`.
- Para sorteos con `rand() % 100`, utiliza probabilidades expresables en pasos de `0.01`.
- Comprueba todas las restricciones después de mutar.
- Descarta los hijos inválidos sin repararlos ni generar reemplazos.

Invertir un bit de un recorrido válido altera su cantidad de celdas y lo vuelve inválido. Sin embargo, un hijo inválido producido por el cruce podría convertirse en válido después de mutar. Esta variante permite observar la importancia de elegir operadores compatibles con la representación.

### 🧬 Clones y reemplazo

- Reúne la población actual y los hijos válidos.
- Elimina los cromosomas repetidos.
- Ordena de mayor a menor peso recolectado.
- En caso de empate, puedes conservar cualquier orden.
- Conserva exactamente la cantidad inicial de individuos.
- Los individuos originales permanecen entre los candidatos al reemplazo.
- El mejor fitness no debe disminuir entre generaciones.

### 🛠️ Organización y finalización

- Implementa funciones separadas para calcular el peso y comprobar la continuidad del recorrido.
- Reutiliza la selección por ruleta, la eliminación de clones y el reemplazo.
- Inicializa la semilla aleatoria una sola vez al comenzar la ejecución.
- Ejecuta todas las generaciones indicadas.
- Al finalizar, muestra el cromosoma, la cuadrícula binaria, las celdas del recorrido, el peso recolectado y la capacidad restante.
- No se permite resolver mediante fuerza bruta, backtracking ni programación dinámica.

El algoritmo busca buenos recorridos, pero **no garantiza encontrar el de mayor peso factible**.

⬅️ [Volver al nivel intermedio](..)