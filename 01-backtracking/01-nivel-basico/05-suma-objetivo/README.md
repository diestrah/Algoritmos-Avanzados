# Suma Objetivo con Backtracking

## Enunciado

Dado un arreglo de elementos y un valor objetivo, implementa una función que 
encuentre todas las combinaciones posibles de elementos del arreglo cuya suma 
sea igual al objetivo, utilizando backtracking. Cada elemento del arreglo puede 
seleccionarse **como máximo una vez**.

## Ejemplo de solución

Para el array `[2, 3, 5, 7]` y un objetivo de suma `10`, el programa debería imprimir:

```
[2, 3, 5]
[3, 7]
```

## Restricciones

- La solución debe implementarse **únicamente utilizando backtracking** (agregar un elemento, avanzar, deshacer y probar el siguiente).
- Cada elemento del arreglo puede utilizarse **como máximo una vez** en cada combinación.
- Se debe explorar, para cada elemento, ambos caminos posibles: **incluirlo** o **no incluirlo** en la combinación actual.
- El caso base corresponde a cuando la suma acumulada es igual al objetivo.
- Se debe **podar** la búsqueda cuando la suma acumulada supera el objetivo o cuando ya no quedan elementos por evaluar.

[Volver al nivel básico](..)
