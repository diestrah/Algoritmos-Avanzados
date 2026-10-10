# 🧩 Generación de Paréntesis Válidos con Backtracking

🟢 **Dificultad:** Básica · 🧠 **Técnica:** Backtracking (poda por validez) · ⏱️ **Tiempo:** O(4ⁿ / √n) · 💾 **Espacio:** O(n)

## 📝 Enunciado

Dada una cantidad de pares de paréntesis, implementa una función que genere 
todas las combinaciones válidas de paréntesis, utilizando backtracking.

## 🧪 Ejemplo de solución

Para `n = 3`, el programa debería imprimir:

```
((()))
(()())
(())()
()(())
()()()
```

## 🚧 Restricciones

- La solución debe implementarse **únicamente utilizando backtracking**.
- Solo se deben generar combinaciones **válidas**: en ningún momento puede haber más paréntesis de cierre `)` que de apertura `(`.
- La cantidad de paréntesis de apertura no puede superar a `n`.
- El caso base corresponde a cuando la cadena construida tiene una longitud igual a `n * 2` y la cantidad de abiertos es igual a la de cerrados.
- Se debe **podar** la búsqueda cuando la cantidad de abiertos supera a `n` o cuando la cantidad de cerrados supera a la de abiertos.

⬅️ [Volver al nivel básico](..)