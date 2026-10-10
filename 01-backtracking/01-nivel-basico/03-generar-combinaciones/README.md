# Generación de Combinaciones con Backtracking

## Enunciado

Dado un rango de elementos `[1, n]` y un tamaño `k`, implementa una función que 
genere todas las combinaciones posibles de `k` elementos dentro de dicho rango, 
utilizando backtracking.

## Ejemplo de solución

Para `n = 4` y `k = 2`, el programa debería imprimir:

```
[1, 2]
[1, 3]
[1, 4]
[2, 3]
[2, 4]
[3, 4]
```

## Restricciones

- La solución debe implementarse **únicamente utilizando backtracking** (agregar un elemento, avanzar, deshacer y probar el siguiente).
- Cada combinación generada debe tener exactamente **k elementos**.
- No se deben repetir elementos dentro de una misma combinación, ni generar la misma combinación en distinto orden (cada nueva llamada recursiva debe comenzar desde el elemento siguiente al último agregado).
- El caso base corresponde a cuando la combinación actual alcanza el tamaño `k`.

[Volver al nivel básico](..)
