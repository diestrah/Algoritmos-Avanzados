```markdown
# Generación de Subconjuntos con Backtracking

## Enunciado

Dado un arreglo de elementos, implementa una función que genere todos los 
subconjuntos posibles de dicho arreglo, utilizando backtracking.

## Ejemplo de solución

Para el array `[1, 2, 3]`, el programa debería imprimir:

```
[1, 2, 3]
[1, 2]
[1, 3]
[1]
[2, 3]
[2]
[3]
[]
```

## Restricciones

- La solución debe implementarse **únicamente utilizando backtracking** (probar incluir un elemento, avanzar, deshacer y probar excluirlo).
- Por cada elemento del arreglo se deben explorar ambos caminos posibles: **incluirlo** o **no incluirlo** en el subconjunto actual.
- El caso base corresponde a cuando se ha decidido sobre todos los elementos del arreglo (índice igual al tamaño del arreglo).

[Volver al nivel básico](..)
```
