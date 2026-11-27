# 🕒 Programación de Tareas con Ventanas de Tiempo

🔴 **Dificultad:** Avanzada · 🧠 **Técnica:** Algoritmo genético · 📐 **Representación:** Permutación de tareas

## 📝 Enunciado

Una empresa dispone de una máquina para ejecutar un conjunto de tareas. Cada tarea tiene:

- Una duración.
- Un instante mínimo de inicio.
- Un plazo máximo de finalización.
- Una penalización fija si no se completa dentro de su ventana de tiempo.

Debes encontrar un orden de evaluación de las tareas que **minimice la penalización total de las tareas no programadas**.

La máquina puede ejecutar una sola tarea a la vez y cada tarea debe realizarse de forma continua, sin interrupciones.

Representa cada individuo mediante una permutación de los índices de las tareas. El cromosoma establece el orden en que se intentan programar; no contiene directamente sus horas de inicio.

Implementa un algoritmo genético con selección por torneo, cruce de un punto, mutación por intercambio, eliminación de clones y reemplazo de los mejores individuos.

Al finalizar, muestra la mejor planificación encontrada y su penalización total.

## 🧪 Ejemplo de ejecución

Para las siguientes tareas:

| Tarea | Duración | Inicio mínimo | Fin máximo | Penalización |
|---|---:|---:|---:|---:|
| 1 | 3 | 0 | 4 | 10 |
| 2 | 2 | 0 | 3 | 8 |
| 3 | 2 | 3 | 7 | 12 |
| 4 | 1 | 5 | 8 | 5 |
| 5 | 3 | 6 | 10 | 15 |
| 6 | 2 | 8 | 12 | 9 |

Con los parámetros:

```text
Cantidad de individuos: 10
Cantidad de generaciones: 200
Tasa de seleccion: 0.8
Tamano de torneo: 3
Probabilidad de mutacion: 0.2
```

Una posible salida es:

```text
Mejor cromosoma encontrado: 1 2 3 4 5 6

Tareas programadas:
Tarea 1: inicio 0, fin 3
Tarea 3: inicio 3, fin 5
Tarea 4: inicio 5, fin 6
Tarea 5: inicio 6, fin 9
Tarea 6: inicio 9, fin 11

Tareas no programadas: 2
Penalizacion total: 8
```

Los identificadores se muestran desde uno; los índices internos comienzan en cero.

Los resultados pueden variar según la semilla y las elecciones aleatorias. No se exige obtener exactamente esta planificación.

## 🚧 Restricciones y suposiciones

- Hay al menos dos tareas.
- Las duraciones y penalizaciones son enteros positivos.
- Los instantes de inicio mínimo y fin máximo son enteros no negativos.
- Para cada tarea se cumple:

  ```text
  inicioMinimo + duracion <= finMaximo
  ```

- La máquina está disponible desde el instante `0`.
- Los intervalos de ejecución se interpretan como `[inicio, fin)`: una tarea puede comenzar exactamente cuando termina otra.
- Las tareas no tienen dependencias.
- Cada cromosoma contiene exactamente una vez cada índice de tarea.
- El tamaño de población es mayor o igual que dos y no supera `cantidadTareas!`.
- La población inicial y cada población resultante del reemplazo deben contener individuos válidos y distintos.

### 🗓️ Construcción del horario

Evalúa cada cromosoma simulando la máquina:

1. Inicializa `tiempoActual = 0` y la penalización total en cero.
2. Recorre las tareas en el orden del cromosoma.
3. Calcula:

   ```text
   inicio = max(tiempoActual, inicioMinimo)
   fin = inicio + duracion
   ```

4. Si `fin <= finMaximo`, programa la tarea y actualiza `tiempoActual = fin`.
5. Si no cabe en su ventana, no la ejecutes, suma su penalización y conserva el tiempo actual.
6. Continúa con las tareas restantes.

La máquina puede esperar hasta que comience la ventana de una tarea. No se insertan tareas en huecos anteriores ni se reconsideran las tareas descartadas.

Una tarea no programada **no convierte al cromosoma en una aberración**: contribuye a su penalización.

### 🌱 Población inicial

- Genera permutaciones aleatorias de las tareas.
- Rechaza los cromosomas repetidos.
- Continúa hasta completar el tamaño de población indicado.

### 🚧 Aberraciones

Un individuo es una aberración si:

- Su longitud no coincide con la cantidad de tareas.
- Algún gen está fuera del rango permitido.
- Alguna tarea aparece más de una vez.

Con longitud y rango correctos, la ausencia de repeticiones garantiza que todas las tareas estén presentes.

### 🎯 Evaluación y selección

- La evaluación principal es la suma de penalizaciones de las tareas no programadas.
- **Una penalización menor representa una solución mejor.**
- En caso de empate, prioriza la planificación que programa más tareas.
- Si también empatan, puedes conservar cualquier orden.
- Utiliza estos criterios tanto en la selección como en el reemplazo.
- Selecciona padres mediante torneo con participantes elegidos al azar y con reemplazo.
- En un empate completo dentro del torneo, conserva al primer participante sorteado.
- Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion`.
- Elige una tasa en `(0, 1]` que produzca al menos dos padres.

### ✂️ Cruce de un punto

- Genera un hijo por cada pareja ordenada de índices distintos del vector de padres.
- Siempre se aplica el cruce.
- Elige el punto de corte entre `1` y `cantidadTareas - 1`, inclusive.
- El hijo recibe el segmento inicial del primer padre y el segmento final del segundo.
- No modifiques los padres originales.
- No repares las repeticiones producidas por el cruce.

El cruce puede producir tareas repetidas y ausentes. Esos hijos deben descartarse después de la etapa de mutación.

### 🔄 Mutación por intercambio

- Realiza una única decisión de mutación por hijo.
- Si ocurre, elige dos posiciones distintas e intercambia sus valores.
- La probabilidad de mutación pertenece al intervalo `[0, 1]`.
- Para sorteos con `rand() % 100`, utiliza probabilidades expresables en pasos de `0.01`.
- Comprueba la validez después de mutar.
- Descarta los hijos inválidos sin generar reemplazos.

Intercambiar posiciones conserva una permutación válida, pero no corrige las repeticiones de un hijo inválido.

### 🧬 Clones y reemplazo

- Reúne la población actual y los hijos válidos.
- Elimina los cromosomas repetidos.
- Dos individuos son clones si contienen exactamente la misma secuencia de tareas, aunque distintos cromosomas puedan producir el mismo horario.
- Ordena utilizando los criterios de evaluación.
- Conserva exactamente la cantidad inicial de individuos.
- Los individuos originales permanecen entre los candidatos al reemplazo.
- La mejor penalización no debe aumentar entre generaciones.

### 🛠️ Organización y finalización

- Utiliza una estructura para los datos de cada tarea.
- Implementa una función que transforme un cromosoma en un horario y calcule su evaluación.
- Reutiliza esa evaluación en el torneo, el reemplazo y la presentación del resultado.
- Separa la validez del cromosoma de la posibilidad de programar cada tarea.
- Inicializa la semilla aleatoria una sola vez al comenzar la ejecución.
- Ejecuta todas las generaciones indicadas.
- Al finalizar, muestra el cromosoma, las tareas programadas con sus horas, las tareas no programadas y la penalización total.
- No se permite resolver mediante fuerza bruta, backtracking ni programación dinámica.
- No se utilizan cruces especiales como OX.

El algoritmo busca buenas planificaciones, pero **no garantiza encontrar la penalización mínima posible**.

⬅️ [Volver al nivel avanzado](..)