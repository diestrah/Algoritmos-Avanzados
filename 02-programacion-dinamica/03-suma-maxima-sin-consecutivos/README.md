# 💰 Suma Máxima de Elementos No Consecutivos

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Bottom-Up (tabla 1D) · ⏱️ **Tiempo:** O(n) · 💾 **Espacio:** O(n)

## 📝 Enunciado

Dado un arreglo de enteros, implementa una función que calcule la **suma máxima** que se puede obtener seleccionando elementos del arreglo, con la condición de que **no se pueden elegir dos elementos consecutivos**. Debes resolverlo aplicando **programación dinámica**, evitando recalcular subproblemas ya resueltos.

## 🧪 Ejemplo de ejecución

Para el arreglo `{3, 2, 7, 11, 5, 10}`, el programa debería imprimir:

Suma maxima sin consecutivos: 23

La suma máxima se obtiene eligiendo los elementos `2`, `11` y `10`.

## 🚧 Restricciones

- La solución debe implementarse utilizando **programación dinámica**.
- No se pueden seleccionar **dos elementos adyacentes** del arreglo.
- En cada posición se debe decidir entre **tomar el elemento actual** (sumándolo al mejor resultado que deja libre el elemento anterior) o **descartarlo** (conservando el mejor resultado hasta el elemento anterior).
- La complejidad temporal del algoritmo debe ser **O(n)**.
- La complejidad espacial del algoritmo debe ser **O(n)**.
- Se da por sentado que el arreglo siempre tendrá más de 3 elementos.

⬅️ [Volver al índice](..)