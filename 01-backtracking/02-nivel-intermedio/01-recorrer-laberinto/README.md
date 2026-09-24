# Recorrido de Laberinto con Backtracking

## Enunciado

Dado un laberinto representado como una matriz de `0` y `1` (donde `1` indica 
camino libre y `0` indica pared), implementa una función que determine si 
existe un camino desde la posición inicial `(0, 0)` hasta la posición final 
`(n-1, m-1)`, marcando el recorrido encontrado, utilizando backtracking.

## Ejemplo de solución

Para el laberinto:

```
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
```

El programa debería imprimir:

```
2 0 0 0
2 2 0 1
0 2 0 0
1 2 2 2
```

Donde cada `2` representa una celda que forma parte del camino encontrado 
hacia el destino.

## Restricciones

- La solución debe implementarse **únicamente utilizando backtracking**.
- Solo se puede avanzar hacia celdas dentro de los límites de la matriz y cuyo valor sea `1` (camino libre, no visitado).
- Se deben explorar las **4 direcciones posibles**: derecha, abajo, izquierda y arriba.
- Cada celda visitada debe marcarse (por ejemplo, con el valor `2`) para no volver a recorrerla.
- Si un camino no lleva a la solución, se debe **deshacer la marca** de la celda (backtrack) antes de probar otra dirección.
- El caso base de éxito corresponde a alcanzar la posición final `(filaFin, colFin)`.

[Volver al nivel básico](..)
