# Contar Todas las Soluciones de un Laberinto con Backtracking

## Enunciado

Dado un laberinto representado como una matriz de `0` y `1` (donde `1` indica 
camino libre y `0` indica pared), implementa una función que cuente **todas** 
las soluciones posibles desde la posición inicial `(0, 0)` hasta la posición 
final `(n-1, m-1)`, utilizando backtracking. Los movimientos permitidos son 
los 4 ortogonales: derecha, abajo, izquierda y arriba (no diagonales).

## Ejemplo de solución

Para el laberinto:

```
1 1 1 0
1 1 1 1
0 1 0 1
1 1 1 1
```

El programa debería imprimir:

```
Se encontraron 7 soluciones
```

## Restricciones

- La solución debe implementarse **únicamente utilizando backtracking**.
- Solo se puede avanzar hacia celdas dentro de los límites de la matriz y cuyo valor sea `1` (camino libre, no visitado).
- Se deben explorar las **4 direcciones posibles**: derecha, abajo, izquierda y arriba.
- Cada celda visitada debe marcarse temporalmente para no volver a recorrerla dentro del mismo camino.
- Al terminar de explorar un camino (haya llegado o no al destino), se debe **deshacer la marca** de la celda visitada, incluyendo la celda destino, para permitir que otros caminos también puedan usarla y así no perder soluciones válidas.
- El caso de conteo corresponde a cada vez que se alcanza la posición final `(n-1 , m-1)`.

[Volver al nivel básico](..)
