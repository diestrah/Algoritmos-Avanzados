# Cambio de Monedas con Backtracking

## Enunciado

Dado un monto y un conjunto de monedas disponibles, implementa una función que 
genere todas las combinaciones posibles de monedas cuya suma sea igual al 
monto, utilizando backtracking. Las monedas pueden repetirse dentro de una 
misma combinación.

## Ejemplo de solución

Para `monto = 5` y las monedas `{1, 2, 5}`, el programa debería imprimir:

```
[1, 1, 1, 1, 1]
[1, 1, 1, 2]
[1, 2, 2]
[5]
```

## Restricciones

- La solución debe implementarse **únicamente utilizando backtracking** (agregar una moneda, avanzar, deshacer y probar la siguiente).
- Una misma moneda **puede repetirse** dentro de una combinación, pero cada nueva llamada recursiva debe comenzar desde la moneda actual en adelante (no se pueden reutilizar monedas anteriores), evitando así generar la misma combinación en distinto orden.
- El caso base corresponde a cuando la suma acumulada es igual al monto.
- Se debe **podar** la búsqueda cuando la suma acumulada supera el monto.

[Volver al nivel básico](..)
