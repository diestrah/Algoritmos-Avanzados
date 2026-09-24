# Generación de Cadenas Binarias con Backtracking

## Enunciado

Dada una cantidad de bits, implementa una función que genere todas las 
combinaciones posibles en binario de dicho tamaño, utilizando backtracking.

## Ejemplo de solución

Para `bits = 3`, el programa debería imprimir:

```
000
001
010
011
100
101
110
111
```

## Restricciones

- La solución debe implementarse **únicamente utilizando backtracking**.
- Por cada posición de la cadena se deben explorar ambos caminos posibles: agregar **'0'** o agregar **'1'**.
- El caso base corresponde a cuando la cadena construida alcanza el tamaño indicado por `bits`.

[Volver al nivel básico](..)
