# 🎒 Mochila 0/1 con Construcción Aleatorizada

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Construcción voraz aleatorizada con múltiples inicios · 📐 **Representación:** Vector de objetos

## 📝 Enunciado

Dispones de una mochila con una capacidad máxima de peso y un conjunto de objetos. Cada objeto tiene un identificador, un peso y un valor.

Implementa un procedimiento que construya distintas selecciones mediante una **lista restringida de candidatos (RCL)**, procurando **maximizar el valor total transportado** sin superar la capacidad de la mochila.

Debes identificar y justificar el criterio utilizado para evaluar los candidatos. La selección entre los integrantes de la RCL debe ser aleatoria y estar controlada por un parámetro de relajación `α`.

Realiza varias construcciones y conserva la selección de mayor valor total. Este ejercicio todavía no incluye búsqueda local.

## 🧪 Ejemplo de ejecución

Para una mochila de capacidad `50`, con `α = 0.3`, `1000` iteraciones y los siguientes objetos:

| Objeto | A | B | C | D | E | F |
|---|---|---|---|---|---|---|
| Peso | 30 | 10 | 20 | 25 | 15 | 8 |
| Valor | 120 | 60 | 100 | 90 | 45 | 16 |

Una posible salida es:

```text
Capacidad de la mochila: 50
Alfa: 0.3
Iteraciones: 1000

Objetos seleccionados: [C, B, E]
Peso total: 45
Valor total: 205
Capacidad restante: 5
```

El resultado y el orden de selección pueden variar según el criterio, la semilla y el generador aleatorio utilizados.

## 🚧 Restricciones y suposiciones

- Identifica y justifica el **criterio de evaluación** utilizado.
- La capacidad es un entero no negativo; los pesos y valores son enteros positivos.
- Los objetos tienen identificadores únicos y se reciben sin ordenar.
- Cada objeto es indivisible y puede seleccionarse como máximo una vez.
- La RCL solo debe incluir objetos no seleccionados que quepan en la capacidad restante.
- `α` pertenece a `[0, 1]` y la cantidad de iteraciones es positiva.
- Cada construcción comienza con la mochila vacía; inicializa la semilla una sola vez.
- Conserva la selección de mayor valor; en empate, mantén la primera encontrada.
- No se permite fuerza bruta, backtracking, programación dinámica ni búsqueda local.

⬅️ [Volver al índice](..)