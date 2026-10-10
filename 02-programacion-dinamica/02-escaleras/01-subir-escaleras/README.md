# 👟 Subir Escaleras con Programación Dinámica

🟢 **Dificultad:** Básica · 🧠 **Técnica:** Bottom-Up (tabla 1D) · ⏱️ **Tiempo:** O(n) · 💾 **Espacio:** O(n)

## 📝 Enunciado

Dada una escalera con `n` escalones, implementa una función que calcule de cuántas
formas distintas se puede llegar hasta el último escalón, sabiendo que en cada paso se puede subir 
**1 o 2 escalones**. Debes resolverlo aplicando **programación dinámica**, evitando recalcular 
subproblemas ya resueltos.

## 🧪 Ejemplo de ejecución

Para `n = 6`, el programa debería imprimir:

- 13 formas

## 🚧 Restricciones

- La solución debe implementarse utilizando **programación dinámica** (enfoque Bottom-Up, construyendo la tabla desde los casos más pequeños).
- En cada paso solo se puede subir **1 o 2 escalones**.
- Si la cantidad de escalones es negativa, el resultado debe ser `0`.
- La complejidad temporal del algoritmo debe ser **O(n)**.
- La complejidad espacial del algoritmo debe ser **O(n)**.
- Puede usarse **vector** o **arreglos**.

⬅️ [Volver al índice](..)
