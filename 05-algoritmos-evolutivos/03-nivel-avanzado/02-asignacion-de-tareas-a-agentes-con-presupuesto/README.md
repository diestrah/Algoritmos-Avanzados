# 💼 Asignación de Tareas a Agentes con Presupuesto

🔴 **Dificultad:** Avanzada · 🧠 **Técnica:** GRASP construcción y algoritmo genético · 📐 **Representación:** Vector de asignaciones enteras

## 📝 Enunciado

Una empresa dispone de varios agentes para realizar un conjunto de tareas. Asignar una tarea a un agente genera una ganancia y consume parte del presupuesto de ese agente.

Cada tarea puede asignarse a **un único agente** o quedar sin asignar. Un agente puede realizar varias tareas, siempre que no supere su presupuesto.

Debes encontrar una asignación que **maximice la ganancia total**.

Representa cada individuo mediante un vector de enteros:

- La posición representa una tarea.
- El valor `0` indica que la tarea no se asigna.
- Los valores de `1` a `cantidadAgentes` identifican al agente asignado.

Por ejemplo:

```text
Cromosoma: [1, 0, 2, 1, 3, 0]
```

Las tareas 1 y 4 se asignan al agente 1, la tarea 3 al agente 2 y la tarea 5 al agente 3. Las tareas 2 y 6 quedan sin asignar.

Implementa un algoritmo genético cuya población inicial se genere mediante **GRASP, utilizando únicamente la fase de construcción**.

Utiliza selección por torneo, cruce uniforme, mutación de una asignación, eliminación de clones y reemplazo de los mejores individuos.

Al finalizar, muestra únicamente la mejor asignación encontrada.

## 🧪 Ejemplo de ejecución

Para seis tareas y tres agentes, se tienen los siguientes costos:

| Agente / Tarea | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---:|---:|---:|---:|---:|---:|
| 1 | 4 | 6 | 5 | 3 | 7 | 4 |
| 2 | 5 | 4 | 6 | 5 | 3 | 6 |
| 3 | 6 | 5 | 3 | 4 | 5 | 2 |

Y las siguientes ganancias:

| Agente / Tarea | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---:|---:|---:|---:|---:|---:|
| 1 | 12 | 15 | 10 | 9 | 14 | 8 |
| 2 | 10 | 12 | 15 | 10 | 12 | 11 |
| 3 | 11 | 10 | 12 | 11 | 10 | 8 |

Los presupuestos son:

```text
Agente 1: 8
Agente 2: 7
Agente 3: 6
```

Con los parámetros:

```text
Cantidad de individuos: 10
Cantidad de generaciones: 100
Alfa de construccion GRASP: 0.3
Tasa de seleccion: 0.8
Tamano de torneo: 2
Probabilidad de mutacion: 0.3
```

Una posible salida es:

```text
Mejor cromosoma encontrado: 1 2 3 1 2 3

Asignaciones:
Tarea 1 -> Agente 1
Tarea 2 -> Agente 2
Tarea 3 -> Agente 3
Tarea 4 -> Agente 1
Tarea 5 -> Agente 2
Tarea 6 -> Agente 3

Presupuestos:
Agente 1: usado 7 de 8 | Restante: 1
Agente 2: usado 7 de 7 | Restante: 0
Agente 3: usado 5 de 6 | Restante: 1

Tareas sin asignar: Ninguna
Ganancia total: 65
```

Los resultados pueden variar según la semilla y las elecciones aleatorias. No se exige obtener exactamente esta asignación.

## 🚧 Restricciones y suposiciones

- Hay al menos dos tareas y dos agentes.
- Los costos, ganancias y presupuestos son enteros positivos.
- Las matrices de costos y ganancias tienen una fila por agente y una columna por tarea.
- Cada cromosoma contiene un gen por tarea.
- Los valores permitidos van de `0` a `cantidadAgentes`.
- El valor `0` representa una tarea sin asignar y no consume presupuesto ni genera ganancia.
- El tamaño de población es mayor o igual que dos.
- Existe al menos una asignación individual que cabe en el presupuesto de algún agente.
- Para la inicialización, utiliza datos y un tamaño de población que permitan obtener suficientes cromosomas distintos mediante las construcciones GRASP descritas.

### 🌱 Población inicial mediante GRASP

Construye cada individuo desde cero:

1. Inicializa todos sus genes en `0` y los presupuestos restantes con sus valores originales.
2. Forma candidatos de la forma `(tarea, agente)`.
3. Incluye únicamente candidatos cuya tarea siga sin asignar y cuyo costo quepa en el presupuesto restante del agente.
4. Evalúa cada candidato mediante:

   ```text
   criterio = ganancia / costo
   ```

   Utiliza división decimal.

5. Calcula el menor y el mayor criterio entre los candidatos factibles.
6. Construye la lista restringida de candidatos:

   ```text
   umbral = criterioMaximo - alfa × (criterioMaximo - criterioMinimo)

   RCL = candidatos con criterio >= umbral
   ```

7. Elige aleatoriamente un candidato de la RCL.
8. Asigna la tarea y actualiza el presupuesto restante del agente.
9. Repite hasta que no queden candidatos factibles.

Realiza nuevas construcciones hasta completar la población inicial, rechazando cromosomas repetidos.

Cada construcción parte de los presupuestos originales. No se aplica búsqueda local.

### 🚧 Aberraciones

Un individuo es una aberración si:

- Algún gen está fuera del rango permitido.
- La suma de costos asignados a algún agente supera su presupuesto.

Comprueba los valores antes de utilizarlos como índices. El agente almacenado con identificador `a` corresponde a la fila `a - 1` de las matrices.

Las tareas sin asignar no son aberraciones. El cromosoma formado únicamente por ceros también es válido, aunque su ganancia es cero.

### 🎯 Evaluación y selección

- El fitness es la suma de las ganancias de las tareas asignadas.
- No sumes ganancia ni costo para genes con valor `0`.
- Selecciona padres mediante torneo con participantes sorteados con reemplazo.
- Gana el participante de mayor ganancia.
- En caso de empate, conserva al primero sorteado en ese torneo.
- Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion`.
- Elige una tasa en `(0, 1]` que produzca al menos dos padres.

### 🎲 Cruce uniforme

- Genera un hijo por cada pareja ordenada de índices distintos del vector de padres.
- Siempre se aplica el cruce.
- Para cada tarea, el hijo recibe el gen del primer o del segundo padre con probabilidad `0.5`.
- Realiza una decisión independiente por posición.
- No modifiques los padres originales.

Aunque ambos padres sean válidos, combinar sus asignaciones puede superar el presupuesto de un agente.

### 🔄 Mutación y validación

- Realiza una única decisión de mutación por hijo.
- Si ocurre, elige una tarea al azar y cambia su gen por otro valor distinto entre `0` y `cantidadAgentes`, inclusive.
- La mutación puede asignar una tarea, cambiarla de agente o dejarla sin asignar.
- Cada hijo cambia como máximo un gen.
- La probabilidad de mutación pertenece al intervalo `[0, 1]`.
- Para sorteos con `rand() % 100`, utiliza probabilidades expresables en pasos de `0.01`.
- Comprueba la validez después de mutar.
- Descarta los hijos inválidos sin repararlos ni generar reemplazos.

### 🧬 Clones y reemplazo

- Reúne la población actual y los hijos válidos.
- Elimina los cromosomas repetidos, conservando una copia de cada uno.
- Ordena de mayor a menor ganancia total.
- En caso de empate, puedes conservar cualquier orden.
- Conserva exactamente la cantidad inicial de individuos.
- Los individuos originales permanecen entre los candidatos al reemplazo.
- La mejor ganancia no debe disminuir entre generaciones.

### 🛠️ Organización y finalización

- Implementa una función para construir un individuo mediante GRASP.
- Separa la evaluación, el cálculo de costos por agente y la detección de aberraciones.
- Reutiliza el torneo, el cruce uniforme, la eliminación de clones y el reemplazo.
- Inicializa la semilla aleatoria una sola vez al comenzar la ejecución.
- Ejecuta todas las generaciones indicadas.
- Al finalizar, muestra el cromosoma, las asignaciones, las tareas pendientes, el presupuesto usado y restante por agente y la ganancia total.
- No se permite resolver mediante fuerza bruta, backtracking ni programación dinámica.

GRASP aporta soluciones iniciales factibles y el algoritmo genético explora nuevas asignaciones. La combinación **no garantiza encontrar la ganancia óptima**.

⬅️ [Volver al nivel avanzado](..)