# ✂️ Corte de Material con Construcción Aleatorizada

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Construcción voraz aleatorizada con múltiples inicios · 📐 **Representación:** Vector de pedidos y rollos

## 📝 Enunciado

Una empresa dispone de rollos de tela de una longitud fija y recibe pedidos de segmentos de distintas longitudes y cantidades.

Implementa un procedimiento que genere varias distribuciones de cortes mediante una **lista restringida de candidatos (RCL)**, procurando **minimizar la merma total**.

Debes identificar y justificar el criterio para evaluar los candidatos y seleccionarlos aleatoriamente mediante un parámetro de relajación `α`.

Cada construcción debe satisfacer el pedido completo. Al finalizar las iteraciones, muestra la mejor distribución encontrada. Este ejercicio todavía no incluye búsqueda local.

## 🧪 Ejemplo de ejecución

Para rollos de `10` metros, con `α = 0.3`, `1000` iteraciones y el siguiente pedido:

| Longitud del segmento (m) | 2 | 3 | 5 | 6 | 8 |
|---|---|---|---|---|---|
| Cantidad solicitada | 4 | 2 | 3 | 2 | 2 |

Una posible salida es:

```text
Longitud de cada rollo: 10 m
Alfa: 0.3
Iteraciones: 1000

Rollo 1:
Segmentos: [8, 2]
Merma: 0 m

Rollo 2:
Segmentos: [8, 2]
Merma: 0 m

Rollo 3:
Segmentos: [6, 3]
Merma: 1 m

Rollo 4:
Segmentos: [6, 3]
Merma: 1 m

Rollo 5:
Segmentos: [5, 5]
Merma: 0 m

Rollo 6:
Segmentos: [5, 2, 2]
Merma: 1 m

Rollos utilizados: 6
Merma total: 3 m
```

El resultado y el orden de los cortes pueden variar según el criterio, la semilla y el generador aleatorio utilizados.

## 🚧 Restricciones y suposiciones

- Identifica y justifica el **criterio de evaluación** utilizado.
- Los rollos tienen igual longitud y su cantidad es ilimitada.
- Las longitudes y cantidades son enteros positivos; ningún segmento supera la longitud de un rollo.
- Los pedidos tienen longitudes distintas y pueden recibirse en cualquier orden.
- Cada construcción debe satisfacer exactamente el pedido, sin dividir segmentos ni perder material en los cortes.
- La RCL solo incluye candidatos factibles y debe actualizarse después de cada elección.
- `α` pertenece a `[0, 1]`; las iteraciones son positivas y la semilla se inicializa una sola vez.
- Conserva la distribución de menor merma; en empate, mantén la primera encontrada.
- No se permite fuerza bruta, backtracking, programación dinámica ni búsqueda local.

⬅️ [Volver al índice](..)