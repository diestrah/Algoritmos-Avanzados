# 🪶 Subset Sum con Espacio Optimizado

🔴 **Dificultad:** Avanzada · 🧠 **Técnica:** Bottom-Up (arreglo 1D) · ⏱️ **Tiempo:** O(n · objetivo) · 💾 **Espacio:** O(objetivo)

## 📝 Enunciado

Dado un arreglo de enteros no negativos y un valor objetivo, implementa una función que determine si **existe un subconjunto** de elementos del arreglo cuya suma sea exactamente igual al objetivo. Cada elemento puede utilizarse **como máximo una vez**. Debes resolverlo aplicando **programación dinámica**, pero esta vez reduciendo el espacio utilizado: no se permite almacenar una tabla de `n × objetivo`.

## 🧪 Ejemplo de ejecución

Para el arreglo `{2, 3, 5, 7}` y un objetivo `10`, el programa debería imprimir:

Es posible sumar 10

Existen subconjuntos que lo logran, como `{2, 3, 5}` o `{3, 7}`.

## 🚧 Restricciones

- La solución debe implementarse utilizando **programación dinámica** (enfoque Bottom-Up).
- Los elementos del arreglo y el objetivo deben ser **no negativos**.
- La suma `0` siempre es posible, ya que corresponde al subconjunto vacío.
- La función debe retornar un valor booleano (existe o no existe el subconjunto).
- Solo se puede utilizar **un arreglo unidimensional** de tamaño `objetivo + 1`, no una matriz.
- La complejidad temporal del algoritmo debe ser **O(n · objetivo)**, donde `n` es la cantidad de elementos del arreglo.
- La complejidad espacial del algoritmo debe ser **O(objetivo)**.

⬅️ [Volver al índice](..)