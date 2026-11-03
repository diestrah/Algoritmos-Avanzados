# 🏗️ Selección de Proyectos con Predecesores

🔴 **Dificultad:** Avanzada · 🧠 **Técnica:** Construcción voraz aleatorizada con múltiples inicios
· 📐 **Representación:** Vector de proyectos y listas de predecesores

## 📝 Enunciado

Una empresa debe seleccionar los proyectos que ejecutará durante el año. Cada proyecto tiene un costo, 
ganancia esperada y una lista de proyectos predecesores.

Un proyecto solo puede seleccionarse si **todos sus predecesores ya fueron seleccionados**.

Implementa un procedimiento que construya distintas selecciones mediante una **lista restringida de 
candidatos (RCL)**, procurando **maximizar la ganancia total** sin superar el presupuesto disponible.

Debes identificar y justificar el criterio de evaluación utilizado. Realiza varias construcciones y 
conserva la mejor selección encontrada, sin aplicar búsqueda local.

## 🧪 Ejemplo de ejecución

Para un presupuesto de `400` y los siguientes proyectos:

| Proyecto | 1   | 2 | 3 | 4   | 5 | 6 | 7   |
|---|-----|---|---|-----|---|---|-----|
| Costo | 100 | 50 | 150 | 50  | 50 | 150 | 100 |
| Ganancia | 200 | 300 | 300 | 400 | 200 | 800 | 250 |
| Predecesores | -   | 1 | 1 | -   | 4 | 2, 4 | -   |

Con `α = 1.0` y `1000` iteraciones, una posible salida es:

```text
Presupuesto inicial: 400
Alfa: 1
Iteraciones: 1000

Proyectos seleccionados: [4, 1, 2, 6, 5]
Costo total: 400
Ganancia total: 1900
Presupuesto restante: 0
```

Los proyectos se muestran en el orden en que fueron seleccionados. El resultado puede variar según el criterio, la semilla y el generador aleatorio utilizados.

## 🚧 Restricciones y suposiciones

- Los costos y ganancias son enteros positivos; el presupuesto es no negativo.
- Los proyectos tienen identificadores únicos y sus dependencias no forman ciclos.
- Cada proyecto se selecciona como máximo una vez y requiere que todos sus predecesores estén seleccionados.
- La RCL solo incluye proyectos que cumplen las dependencias y caben en el presupuesto restante.
- Cada construcción comienza sin proyectos seleccionados y con el presupuesto original.
- `α` pertenece a `[0, 1]`; las iteraciones son positivas y la semilla se inicializa una sola vez.
- Conserva la selección de mayor ganancia; en empate, mantén la primera.
- No se permite fuerza bruta, backtracking, programación dinámica ni búsqueda local.

⬅️ [Volver al índice](..)