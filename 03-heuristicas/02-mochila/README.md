# 🎒 Mochila 0/1

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Heurística voraz · 📐 **Representación:** Vector de objetos

## 📝 Enunciado

Dispones de una mochila con una capacidad máxima de peso y un conjunto de objetos. Cada objeto tiene un identificador, un peso y un valor.

Implementa una función que seleccione objetos sin superar la capacidad de la mochila, procurando **maximizar el valor total transportado**.

Debes identificar y aplicar un **criterio voraz** para seleccionar los objetos.

## 🧪 Ejemplo de ejecución

Para una mochila con capacidad de `50` unidades de peso y los siguientes objetos:

| Objeto | Peso | Valor |
|---|---|---|
| A | 30 | 120 |
| B | 10 | 60 |
| C | 20 | 100 |
| D | 25 | 90 |
| E | 15 | 45 |
| F | 8 | 16 |

Una salida del procedimiento voraz es:

```text
Objetos seleccionados: [B, C, E]
Peso total: 45
Valor total: 205
Capacidad restante: 5
```

## 🚧 Restricciones y suposiciones

- Se debe **justificar el criterio voraz** utilizado.
- La capacidad de la mochila es un entero **mayor o igual que cero**.
- Los pesos y valores de los objetos son enteros **positivos**.
- Los identificadores de los objetos son únicos.
- Los objetos se reciben **sin un orden establecido**.
- Cada objeto puede seleccionarse **como máximo una vez**.
- Los objetos son **indivisibles**: no se permite transportar una fracción de ellos.
- La suma de los pesos seleccionados no debe superar la capacidad de la mochila.
- Si dos objetos tienen la misma prioridad según tu criterio, se debe elegir primero el de **menor identificador en orden alfabético**.
- Si ningún objeto cabe en la mochila, se debe mostrar una selección vacía, con peso y valor totales iguales a `0`.
- No se permite utilizar fuerza bruta, backtracking ni programación dinámica.


⬅️ [Volver al índice](..)
