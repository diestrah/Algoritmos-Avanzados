# ⚙️ Asignación de Tareas a Máquinas

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Heurística voraz · 📐 **Representación:** Vector de tareas y cargas de máquinas

## 📝 Enunciado

Dispones de varias máquinas y un conjunto de tareas. Cada tarea tiene un identificador y un tiempo de procesamiento.

Implementa una función que distribuya las tareas entre las máquinas, procurando **minimizar el tiempo necesario para terminar todas las tareas**. Este tiempo corresponde a la mayor carga acumulada entre las máquinas.

Debes identificar y aplicar un **criterio voraz** para realizar la asignación.

## 🧪 Ejemplo de ejecución

Para `3` máquinas y las siguientes tareas:

| Tarea | A | B | C | D | E | F | G | H | I |
|---|---|---|---|---|---|---|---|---|---|
| Tiempo de procesamiento | 2 | 8 | 6 | 5 | 10 | 3 | 8 | 4 | 7 |

Una salida del procedimiento voraz es:

```text
Máquina 1:
Tareas asignadas: [E, D, F]
Carga total: 18

Máquina 2:
Tareas asignadas: [B, I, A]
Carga total: 17

Máquina 3:
Tareas asignadas: [G, C, H]
Carga total: 18

Tiempo para completar todas las tareas: 18
```

## 🚧 Restricciones y suposiciones

- Se debe **identificar y justificar el criterio voraz** utilizado.
- La cantidad de máquinas es un entero **mayor que cero**.
- Todas las máquinas son **idénticas**: una tarea tarda lo mismo en cualquiera de ellas.
- Los tiempos de procesamiento son enteros **positivos**.
- No existen dependencias entre las tareas.
- Cada tarea debe asignarse a **exactamente una máquina**.
- Las tareas son **indivisibles**: no pueden repartirse entre máquinas ni interrumpirse una vez iniciadas.
- Cada máquina procesa **una tarea a la vez**, pero las distintas máquinas pueden trabajar simultáneamente.
- Si dos tareas tienen la misma prioridad según tu criterio, se debe elegir primero la de **menor identificador en orden alfabético**.
- Una máquina sin tareas asignadas tiene una carga igual a `0`.
- No se permite utilizar fuerza bruta, backtracking ni programación dinámica.

⬅️ [Volver al índice](..)
