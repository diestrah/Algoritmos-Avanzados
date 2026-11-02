# 🛵 Ruta de Entregas con Ganancias

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Construcción voraz aleatorizada con múltiples inicios · 📐 **Representación:** Matriz de adyacencia y vector de ganancias

## 📝 Enunciado

Un repartidor inicia su recorrido en un punto determinado y recibe una ganancia por cada punto de entrega que visita.

Las conexiones son **dirigidas**: poder viajar de un punto a otro no implica que se pueda realizar el recorrido inverso.

Implementa un procedimiento que construya distintas rutas mediante una **lista restringida de candidatos (RCL)**, procurando **maximizar la ganancia acumulada**.

No es obligatorio visitar todos los puntos ni regresar al origen. Realiza varias construcciones y conserva la mejor ruta encontrada. Este ejercicio todavía no incluye búsqueda local.

## 🧪 Ejemplo de ejecución

Para los siguientes puntos y conexiones:

| Origen | Destinos permitidos |
|---|---|
| A | B, C, D, E, H |
| B | C, D, F, H |
| C | F |
| D | Ninguno |
| E | C, F, G |
| F | Ninguno |
| G | Ninguno |
| H | Ninguno |

Las ganancias por entrega son:

| Punto | A | B | C | D | E | F | G | H |
|---|---|---|---|---|---|---|---|---|
| Ganancia | 0 | 20 | 30 | 40 | 40 | 40 | 10 | 50 |

Partiendo de `A`, con `α = 0.4` y `1000` iteraciones, una posible salida es:

```text
Punto inicial: A
Alfa: 0.4
Iteraciones: 1000

Mejor ruta: A -> E -> C -> F
Ganancia total: 110
```

El resultado puede variar según el criterio, la semilla y el generador aleatorio utilizados.

## 🚧 Restricciones y suposiciones

- El grafo es dirigido, sin ciclos, y se representa mediante una matriz de adyacencia.
- Las ganancias son enteros no negativos; el origen tiene ganancia `0`.
- Cada movimiento debe respetar una conexión y ningún punto puede visitarse más de una vez.
- La RCL se actualiza desde el punto actual y solo incluye destinos factibles.
- La ruta termina cuando no existen destinos factibles.
- `α` pertenece a `[0, 1]`; las iteraciones son positivas y la semilla se inicializa una sola vez.
- Conserva la ruta de mayor ganancia; en empate, mantén la primera.
- No se permite fuerza bruta, backtracking, programación dinámica ni búsqueda local.

⬅️ [Volver al índice](..)