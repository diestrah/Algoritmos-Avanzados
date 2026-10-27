# 🪙 Cambio de Monedas

🟢 **Dificultad:** Básica · 🧠 **Técnica:** Heurística voraz · 📐 **Representación:** Vector de denominaciones

## 📝 Enunciado

Dado un monto entero y un conjunto de denominaciones de monedas, implementa una función que construya un cambio cuya suma sea exactamente el monto solicitado, procurando utilizar la **menor cantidad de monedas**.

Debes identificar y aplicar un **criterio voraz** para seleccionar las monedas.

Si el procedimiento no logra completar el cambio, el programa debe informar el monto pendiente.

## 🧪 Ejemplo de ejecución

Para las denominaciones `[5, 20, 1, 13]` y un monto de `39`, una salida del procedimiento voraz es:

```text
Monedas seleccionadas: [20, 13, 5, 1]
Cantidad de monedas: 4
Monto pendiente: 0
```

## 🚧 Restricciones y suposiciones

- Debes **identificar y justificar el criterio voraz** utilizado.
- Las denominaciones son enteros **positivos, distintos y se reciben sin ordenar**.
- El monto es un entero **mayor o igual que cero**.
- Se dispone de una cantidad **ilimitada** de monedas de cada denominación.
- Si se completa el cambio, la suma de las monedas seleccionadas debe ser exactamente igual al monto solicitado.
- Si el monto es `0`, se debe mostrar una lista vacía y una cantidad de monedas igual a `0`.
- Si el procedimiento no completa el cambio, se deben mostrar las monedas seleccionadas y el monto pendiente.
- No se permite utilizar fuerza bruta, backtracking ni programación dinámica.

⬅️ [Volver al índice](..)
