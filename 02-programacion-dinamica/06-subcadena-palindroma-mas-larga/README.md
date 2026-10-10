# Subcadena Palíndroma Más Larga

## Enunciado

Dada una cadena de texto, implementa una función que encuentre la **subcadena palíndroma más larga** contenida en ella. Una subcadena palíndroma es una secuencia **contigua** de caracteres que se lee igual de izquierda a derecha que de derecha a izquierda. Debes resolverlo aplicando **programación dinámica**, evitando volver a comprobar subcadenas cuyo resultado ya se conoce.

## Ejemplo de ejecución

Para la cadena `SOLILOLPLALI`, el programa debería imprimir:

Palindromo: OLILO


Otras subcadenas palíndromas como `LIL`, `LOL`, `LPL` o `LAL` son válidas, pero más cortas.

## Restricciones

- La solución debe implementarse utilizando **programación dinámica** (enfoque Bottom-Up, construyendo una tabla de subproblemas).
- La tabla debe indicar, para cada par de posiciones `(i, j)`, si la subcadena que va de `i` a `j` es un palíndromo.
- Una subcadena de un solo carácter siempre es palíndroma.
- Una subcadena de más de tres caracteres solo es palíndroma si sus extremos son iguales **y** la subcadena interior también lo es.
- La comparación distingue entre mayúsculas y minúsculas.
- La complejidad temporal del algoritmo debe ser **O(n²)**, donde `n` es la longitud de la cadena.
- La complejidad espacial del algoritmo debe ser **O(n²)**.

[Volver al índice](..)