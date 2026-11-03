# 🛵 Asignación de Servicios con Límite de Costo

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Construcción voraz aleatorizada con múltiples inicios · 📐 **Representación:** Matriz de costos y vectores de asignación

## 📝 Enunciado

Una empresa debe realizar un envío a cada ciudad utilizando un servicio motorizado para la entrega final.

Cada ciudad tiene un costo fijo de transporte. Además, cada motorizado cobra una tarifa distinta según la ciudad. El costo de un envío es la **suma del transporte y la tarifa del motorizado**.

Implementa un procedimiento que asigne un motorizado a cada ciudad mediante una **lista restringida de candidatos (RCL)**, procurando **minimizar el costo total** sin superar el límite permitido por envío.

Cada motorizado puede atender como máximo una ciudad. Realiza varias construcciones y conserva la mejor asignación completa. Este ejercicio todavía no incluye búsqueda local.

## 🧪 Ejemplo de ejecución

Para `4` ciudades, `5` motorizados, un límite de `20` soles por envío, `α = 0.3` y `1000` iteraciones:

| Ciudad | A | B | C | D |
|---|---|---|---|---|
| Transporte (S/) | 16 | 15 | 12 | 18 |

Las tarifas de los motorizados son:

| Motorizado / Ciudad | A | B | C | D |
|---|---|---|---|---|
| 1 | 3 | 4 | 5 | 6 |
| 2 | 5 | 2 | 3 | 4 |
| 3 | 7 | 5 | 4 | 2 |
| 4 | 8 | 7 | 5 | 1 |
| 5 | 4 | 3 | 7 | 5 |

Una posible salida es:

```text
Limite por envio: 20 soles
Alfa: 0.3
Iteraciones: 1000

Ciudad A:
Motorizado: 1
Costo del envio: 19 soles

Ciudad B:
Motorizado: 2
Costo del envio: 17 soles

Ciudad C:
Motorizado: 3
Costo del envio: 16 soles

Ciudad D:
Motorizado: 4
Costo del envio: 19 soles

Costo total: 71 soles
```

El resultado puede variar según el criterio, la semilla y el generador aleatorio utilizados.

## 🚧 Restricciones y suposiciones

- Los costos son enteros no negativos y el límite por envío es positivo.
- Cada ciudad recibe un motorizado y cada motorizado atiende como máximo una ciudad.
- Ningún envío puede superar el límite de costo.
- La RCL solo incluye asignaciones factibles y se actualiza después de cada elección.
- `α` pertenece a `[0, 1]`; las iteraciones son positivas y la semilla se inicializa una sola vez.
- Descarta las construcciones incompletas; conserva la completa de menor costo.
- En empate, mantén la primera; si ninguna construcción se completa, informa ese resultado.
- No se permite fuerza bruta, backtracking, programación dinámica ni búsqueda local.

⬅️ [Volver al índice](..)