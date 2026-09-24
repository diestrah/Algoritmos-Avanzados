# Generación de Paréntesis Válidos con Backtracking

## Enunciado

Dada una cantidad de pares de paréntesis, implementa una función que genere 
todas las combinaciones válidas de paréntesis, utilizando backtracking.

## Ejemplo de solución

Para `n = 3`, el programa debería imprimir:

```
((()))
(()())
(())()
()(())
()()()
```

## Restricciones

- La solución debe implementarse **únicamente utilizando backtracking**.
- Solo se debe agregar un paréntesis de apertura `(` mientras la cantidad de abiertos sea menor a `n`.
- Solo se debe agregar un paréntesis de cierre `)` mientras la cantidad de cerrados sea menor a la cantidad de abiertos (para mantener la combinación válida).
- El caso base corresponde a cuando la cadena construida tiene una longitud igual a `n * 2` y la cantidad de abiertos es igual a la de cerrados.
- Se debe **podar** la búsqueda cuando la cantidad de abiertos o cerrados supera a `n`, o cuando la cantidad de cerrados supera a la de abiertos.

[Volver al nivel básico](..)
