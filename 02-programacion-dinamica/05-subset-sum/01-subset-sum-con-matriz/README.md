# 🧮 Subset Sum (Suma de Subconjunto)

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Bottom-Up (matriz 2D) · ⏱️ **Tiempo:** O(n · objetivo) · 💾 **Espacio:** O(n · objetivo)

## 📝 Enunciado

Dado un arreglo de enteros no negativos y un valor objetivo, 
implementa una función que determine si **existe un subconjunto** 
de elementos del arreglo cuya suma sea exactamente igual al objetivo. 
Cada elemento puede utilizarse **como máximo una vez**. 
Debes resolverlo aplicando **programación dinámica**.

## 🧪 Ejemplo de ejecución

Para el arreglo `{2, 3, 5, 7}` y un objetivo `10`, el programa debería imprimir:

Es posible sumar 10

Existen subconjuntos que lo logran, como `{2, 3, 5}` o `{3, 7}`. A diferencia del reto de backtracking, aquí solo se responde **si es posible o no**, sin listar las combinaciones.

## 🚧 Restricciones

- La solución debe implementarse utilizando **programación dinámica**.
- Los elementos del arreglo y el objetivo deben ser **no negativos**.
- Cada elemento del arreglo puede utilizarse **como máximo una vez**.
- La suma `0` siempre es posible, ya que corresponde al subconjunto vacío.
- La función debe retornar un valor booleano (existe o no existe el subconjunto).
- La complejidad temporal del algoritmo debe ser **O(n · objetivo)**, donde `n` es la cantidad de elementos del arreglo.
- La complejidad espacial del algoritmo debe ser **O(n · objetivo)**.
- Debe imprimir la matriz booleana de estados.

⬅️ [Volver al índice](..)