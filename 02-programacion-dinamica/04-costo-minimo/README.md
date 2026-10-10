# Costo Mínimo para Llegar al Último Escalón
## Enunciado

Dado un arreglo de costos, donde cada posición representa un escalón y su valor es el costo de pisarlo, implementa una función que calcule el costo mínimo para llegar al último escalón.

Puedes comenzar desde el escalón 0 o desde el escalón 1. En cada movimiento puedes avanzar 1 o 2 escalones. Cada vez que pisas un escalón, pagas su costo, incluido el del último escalón.

Resuelve el problema utilizando programación dinámica, evitando recalcular subproblemas ya resueltos.

## Ejemplo de ejecución

Para el arreglo de costos {10, 15, 20, 8, 15}, el programa imprime:

Costos: 10 15 30 23 38 <br>
Costo minimo: 38

## Restricciones
- La solución debe utilizar programación dinámica ascendente (Bottom-Up).
- Se puede comenzar en el escalón 0 o en el escalón 1.
- En cada movimiento solo se puede avanzar 1 o 2 escalones.
- Se suma el costo de cada escalón pisado, incluido el último.
- Para cada escalón i >= 2, el costo mínimo se calcula a partir del menor costo acumulado entre i - 1 e i - 2.
- Complejidad temporal: O(n).
- Complejidad espacial: O(n).

[Volver al índice](..)