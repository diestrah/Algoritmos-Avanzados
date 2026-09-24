# Problema de las N-Reinas con Backtracking

## Enunciado

Dado un tablero de tamaño `N x N`, implementa una función que coloque `N` 
reinas de manera que ninguna pueda atacar a otra (ni en la misma fila, columna 
o diagonal), utilizando backtracking.

## Ejemplo de solución

Para `N = 4`, el programa debería imprimir una solución válida, por ejemplo:

```
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
```

Donde cada `1` representa la posición de una reina en el tablero.

## Restricciones

- La solución debe implementarse **únicamente utilizando backtracking**.
- En cada fila se debe colocar exactamente **una reina**, probando cada columna como posible posición.
- Antes de colocar una reina, se debe verificar que la posición sea válida, es decir, que ninguna otra reina ya colocada la ataque a través de la **columna**, la **diagonal superior izquierda** o la **diagonal superior derecha**.
- Si colocar una reina en una posición no conduce a una solución, se debe **deshacer la decisión** (quitar la reina) y probar la siguiente columna.
- El caso base corresponde a haber colocado una reina en cada una de las `N` filas del tablero.

[Volver al nivel básico](..)
