# 👷 Asignación de Tareas a Empleados

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Algoritmo genético · 📐 **Representación:** Matriz binaria codificada en un vector

## 📝 Enunciado

Una empresa debe asignar `n` tareas a `n` empleados. La ganancia obtenida depende del empleado que realiza cada tarea.

Debes encontrar una asignación que maximice la ganancia total, cumpliendo que:

- Cada tarea se asigna a exactamente un empleado.
- Cada empleado realiza exactamente una tarea.

Representa cada individuo mediante una matriz binaria de `n × n`, almacenada en un `vector<int>`:

- Las filas representan tareas.
- Las columnas representan empleados.
- Un `1` indica que el empleado realiza la tarea correspondiente.
- Un `0` indica que esa asignación no se utiliza.

La posición correspondiente a una asignación es:

```text
indice = tarea × n + empleado
```

Los índices internos comienzan en cero.

Implementa un algoritmo genético con selección por ruleta, cruce de un punto, mutación por intercambio de asignaciones, eliminación de clones y reemplazo de los mejores individuos.

Al finalizar, muestra únicamente la mejor asignación encontrada y su ganancia total.

## 🧪 Ejemplo de ejecución

Para la siguiente matriz de ganancias:

| Tarea / Empleado | 1 | 2 | 3 | 4 |
|---|---:|---:|---:|---:|
| 1 | 9 | 2 | 7 | 8 |
| 2 | 6 | 4 | 3 | 7 |
| 3 | 5 | 8 | 1 | 8 |
| 4 | 7 | 6 | 9 | 4 |

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
1 0 0 0 | 0 0 0 1 | 0 1 0 0 | 0 0 1 0

Asignaciones:
Tarea 1 -> Empleado 1 | Ganancia: 9
Tarea 2 -> Empleado 4 | Ganancia: 7
Tarea 3 -> Empleado 2 | Ganancia: 8
Tarea 4 -> Empleado 3 | Ganancia: 9

Ganancia total: 33
```

Cada bloque del cromosoma corresponde a una tarea.

Los resultados pueden variar según la semilla y las elecciones aleatorias. No se exige obtener exactamente esta asignación.

## 🚧 Restricciones y suposiciones

- La cantidad de tareas es igual a la cantidad de empleados.
- `n` es mayor o igual que dos.
- La matriz de ganancias es de `n × n` y contiene enteros positivos.
- Cada cromosoma contiene exactamente `n × n` genes binarios.
- Un individuo válido tiene exactamente un `1` en cada fila y en cada columna.
- El tamaño de población es mayor o igual que dos y no supera `n!`, la cantidad de asignaciones distintas posibles.
- La población inicial y cada población resultante del reemplazo deben contener individuos válidos y distintos.

### 🌱 Población inicial

- Genera un orden aleatorio de los empleados, sin repeticiones.
- Asigna a cada tarea el empleado que aparece en su posición.
- Convierte esa asignación a la representación binaria de `n × n`.
- Rechaza los cromosomas repetidos.
- Continúa hasta completar el tamaño de población indicado.

El cromosoma almacenado debe ser binario; el orden de empleados se utiliza únicamente para construir una asignación válida.

### 🚧 Aberraciones

Se considera una aberración cualquier cromosoma que:

- No tenga exactamente un empleado asignado a cada tarea.
- Asigne un mismo empleado a más de una tarea.

No basta con comprobar que existan `n` genes en uno: también debes verificar cómo se distribuyen entre filas y columnas.

### 🎯 Fitness y selección

- El fitness es la suma de las ganancias de las asignaciones representadas por los genes en uno.
- Selecciona padres mediante ruleta proporcional al fitness, utilizando acumulados.
- La selección es con reemplazo.
- Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion`.
- La tasa pertenece al intervalo `(0, 1]`. Elige parámetros que produzcan al menos dos padres.
- Todos los individuos válidos tienen fitness positivo.

### ✂️ Cruce de un punto por tareas

- Genera un hijo por cada pareja ordenada de índices distintos del vector de padres.
- Siempre se aplica el cruce.
- Elige una cantidad de tareas de corte entre `1` y `n - 1`, inclusive.
- El hijo recibe las primeras tareas del primer padre y las restantes del segundo.
- El corte debe coincidir con el límite entre filas:

  ```text
  posicionDeCorte = tareasDeCorte × n
  ```

- No modifiques los padres originales.

Este cruce conserva una asignación por tarea, pero puede repetir empleados. Por ello, los hijos requieren validación.

### 🔄 Mutación por intercambio

- Realiza una única decisión de mutación por hijo.
- Si ocurre, elige dos tareas distintas e intercambia sus filas completas.
- La probabilidad de mutación pertenece al intervalo `[0, 1]`.
- Para sorteos con `rand() % 100`, utiliza probabilidades expresables en pasos de `0.01`.
- Comprueba las aberraciones después de aplicar la mutación.
- Descarta los hijos inválidos sin repararlos ni generar reemplazos.

Intercambiar filas conserva la validez de una asignación que ya era válida. Si el cruce produjo empleados repetidos, este intercambio no corrige esa aberración.

### 🧬 Clones y reemplazo

- Reúne la población actual y los hijos válidos.
- Elimina los cromosomas repetidos, conservando una copia de cada uno.
- Ordena de mayor a menor ganancia total.
- En caso de empate, puedes conservar cualquier orden.
- Conserva exactamente la cantidad inicial de individuos.
- Los individuos originales permanecen entre los candidatos al reemplazo.
- El mejor fitness no debe disminuir entre generaciones.

### 🛠️ Organización y finalización

- Implementa funciones para evaluar individuos y verificar filas y columnas.
- Reutiliza y adapta la selección por ruleta, la eliminación de clones y el reemplazo del ejercicio anterior.
- Implementa el cruce por tareas y la mutación por intercambio de filas.
- Inicializa la semilla aleatoria una sola vez al comenzar la ejecución.
- Ejecuta todas las generaciones indicadas.
- Al finalizar, muestra el cromosoma, cada asignación y la ganancia total.
- No se permite resolver mediante fuerza bruta, backtracking ni un algoritmo exacto de asignación.

El algoritmo busca buenas asignaciones, pero **no garantiza encontrar la de mayor ganancia posible**.

⬅️ [Volver al nivel intermedio](..)