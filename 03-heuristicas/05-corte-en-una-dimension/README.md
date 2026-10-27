# ✂️ Corte de Material en Una Dimensión

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Heurística voraz · 📐 **Representación:** Vector de pedidos y rollos

## 📝 Enunciado

Una empresa dispone de rollos de tela de una longitud fija y recibe un pedido de segmentos de diferentes longitudes y cantidades.

Implementa una función que distribuya los cortes entre los rollos, procurando **minimizar la merma total**, es decir, la longitud de tela que queda sin utilizar.

Debes identificar y aplicar un **criterio voraz** para realizar la distribución.

## 🧪 Ejemplo de ejecución

Para rollos de `10` metros y el siguiente pedido:

| Longitud del segmento (m) | 2 | 3 | 5 | 6 | 8 |
|---|---|---|---|---|---|
| Cantidad solicitada | 4 | 2 | 3 | 2 | 2 |

Una salida del procedimiento voraz es:

```text
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

## 🚧 Restricciones y suposiciones

- Identifica y justifica el **criterio voraz** utilizado.
- Los rollos tienen igual longitud y su cantidad es ilimitada.
- Las longitudes y cantidades son enteros positivos; ningún segmento supera la longitud de un rollo.
- Los pedidos pueden recibirse en cualquier orden y tienen longitudes distintas.
- Debe cumplirse exactamente la cantidad solicitada de cada segmento.
- Cada segmento se obtiene de un solo rollo y los cortes no consumen material.
- En empates entre rollos, elige el de menor número, según su orden de apertura.
- No se permite fuerza bruta, backtracking ni programación dinámica.

⬅️ [Volver al índice](..)