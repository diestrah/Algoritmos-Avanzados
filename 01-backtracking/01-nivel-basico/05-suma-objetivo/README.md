# ➕ Suma Objetivo con Backtracking

🟢 **Dificultad:** Básica · 🧠 **Técnica:** Backtracking (índice de inicio con poda) · ⏱️ **Tiempo:** O(2ⁿ · n) · 💾 **Espacio:** O(n)

## 📝 Enunciado

Dado un arreglo de elementos y un valor objetivo, implementa una función que 
encuentre todas las combinaciones posibles de elementos del arreglo cuya suma 
sea igual al objetivo, utilizando backtracking. Cada elemento del arreglo puede 
seleccionarse **como máximo una vez**.

## 🧪 Ejemplo de solución

Para el array `[2, 3, 5, 7]` y un objetivo de suma `10`, el programa debería imprimir:

```
[2, 3, 5]
[3, 7]
```

## 🚧 Restricciones

- La solución debe implementarse **únicamente utilizando backtracking**