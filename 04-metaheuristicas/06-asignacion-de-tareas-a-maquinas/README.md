# ⚙️ Asignación de Tareas con Construcción Aleatorizada

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Construcción voraz aleatorizada con múltiples inicios · 📐 **Representación:** Vector de tareas y máquinas

## 📝 Enunciado

Dispones de varias máquinas idénticas y un conjunto de tareas. Cada tarea tiene un identificador y un tiempo de procesamiento.

Implementa un procedimiento que genere distintas asignaciones mediante una **lista restringida de candidatos (RCL)**, procurando **minimizar el tiempo necesario para completar todas las tareas**. Este tiempo corresponde a la mayor carga acumulada entre las máquinas.

Debes identificar y justificar cómo evalúas los candidatos y cómo eliges la máquina que recibe cada tarea.

Realiza varias construcciones y conserva la mejor asignación encontrada. Este ejercicio todavía no incluye búsqueda local.

## 🧪 Ejemplo de ejecución

Para `3` máquinas, con `α = 0.3`, `1000` iteraciones y las siguientes tareas:

| Tarea | A | B | C | D | E | F | G | H | I |
|---|---|---|---|---|---|---|---|---|---|
| Tiempo de procesamiento | 2 | 8 | 6 | 5 | 10 | 3 | 8 | 4 | 7 |

Una posible salida es:

```text
Cantidad de máquinas: 3
Alfa: 0.3
Iteraciones: 1000

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

El resultado y el orden de asignación pueden variar según el criterio, la semilla y el generador aleatorio utilizados.

## 🚧 Restricciones y suposiciones

- Hay al menos una máquina; todas están disponibles desde el instante `0`.
- Las tareas tienen identificadores únicos, tiempos enteros positivos y no presentan dependencias.
- Cada tarea es indivisible y debe asignarse exactamente una vez.
- Cada máquina procesa una tarea a la vez; las máquinas trabajan simultáneamente.
- La RCL se actualiza después de cada elección y solo incluye candidatos pendientes.
- `α` pertenece a `[0, 1]`; las iteraciones son positivas y la semilla se inicializa una sola vez.
- Cada construcción comienza con todas las máquinas vacías.
- Conserva la asignación de menor tiempo de finalización; en empate, mantén la primera.
- No se permite fuerza bruta, backtracking, programación dinámica ni búsqueda local.

⬅️ [Volver al índice](..)