# 🦘 Subir Escaleras con Programación Dinámica (hasta k Pasos)

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Bottom-Up (tabla 1D) · ⏱️ **Tiempo:** O(n · k) · 💾 **Espacio:** O(n)

## 📝 Enunciado

Dada una escalera con `n` escalones, implementa una función que calcule de cuántas formas distintas se puede llegar hasta el último escalón, sabiendo que en cada paso se pueden subir **entre 1 y `k` escalones** (en este reto, `k = 4`). Debes resolverlo aplicando **programación dinámica**, evitando recalcular subproblemas ya resueltos.

## 🧪 Ejemplo de ejecución

Para `n = 6` y `k = 4`, el programa debería imprimir:

29 formas

## 🚧 Restricciones

- La solución debe implementarse utilizando **programación dinámica**.
- En cada paso se pueden subir **1, 2, 3 o 4 escalones** (el máximo de pasos debe definirse como una constante).
- Nunca se debe considerar un paso mayor a la cantidad de escalones restantes.
- Si la cantidad de escalones es negativa, el resultado debe ser `0`.
- La complejidad temporal del algoritmo debe ser **O(n · k)**, donde `k` es la cantidad máxima de escalones por paso.
- La complejidad espacial del algoritmo debe ser **O(n)**.
- Puede utilizarse un vector o un array.

⬅️ [Volver al índice](..)