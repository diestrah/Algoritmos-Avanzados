
# Generación de Permutaciones con Backtracking

## Enunciado

Dado un arreglo de elementos, implementa una función que genere todas las 
permutaciones posibles del arreglo, utilizando backtracking.

## Ejemplo de solución

Para el array `[1, 2, 3]`, el programa debería imprimir:

```
[1, 2, 3]
[1, 3, 2]
[2, 3, 1]
[2, 1, 3]
[3, 1, 2]
[3, 2, 1]
```

## Restricciones

- La solución debe implementarse **únicamente utilizando backtracking** (probar un elemento, avanzar, deshacer y probar el siguiente).
- Un elemento solo puede utilizarse si **aún no forma parte** de la permutación que se está construyendo.
- El caso base corresponde a cuando la permutación actual tiene el mismo tamaño que el arreglo original.

[Volver al nivel básico](..)
