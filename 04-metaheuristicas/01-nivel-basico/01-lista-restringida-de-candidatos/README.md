# 🎯 Lista Restringida de Candidatos

🟢 **Dificultad:** Básica · 🧠 **Técnica:** Preparación para GRASP · 📐 **Representación:** Vector de candidatos

## 📝 Enunciado

Dispones de un conjunto de candidatos para realizar una misma actividad. Cada candidato tiene un identificador y un tiempo estimado de ejecución.

Implementa una función que construya una **lista restringida de candidatos (RCL)**, considerando que se prefieren los **menores tiempos**. La selección de integrantes estará controlada por un parámetro de relajación `α`.

Después, selecciona aleatoriamente un candidato de la RCL.

Esta práctica aborda una elección de la fase de construcción de GRASP; todavía no construye una solución completa.

## 🧪 Ejemplo de ejecución

Para los siguientes candidatos, `α = 0.5` y `SEMILLA = 46523`:

| Candidato | A | B | C | D | E | F |
|---|---|---|---|---|---|---|
| Tiempo estimado (min) | 25 | 10 | 40 | 15 | 30 | 20 |

Una posible salida es:

```text
Minimo: 10
Maximo: 40
Umbral: 25
RCL: A B D F
Candidato seleccionado: F
Tiempo del candidato: 20 min
```

El candidato seleccionado puede variar entre ejecuciones según la semilla utilizada.

## 🚧 Restricciones y suposiciones

- Existe al menos un candidato; sus identificadores son únicos y sus tiempos son enteros positivos.
- `α` pertenece al intervalo `[0, 1]`.
- Usa `β` como el menor tiempo y `τ` como el mayor.
- Incluye en la RCL todos los candidatos que cumplan `tiempo ≤ β + α × (τ − β)`.
- Todos los integrantes de la RCL deben tener la misma probabilidad de ser seleccionados.
- Muestra la RCL en orden alfabético y usa una semilla fija durante las pruebas.

## ✍️ Para analizar

- ¿Qué ocurre con la RCL cuando `α = 0`? ¿Y cuando `α = 1`?
- ¿Qué sucede si todos los candidatos tienen el mismo tiempo?
- ¿Aumentar `α` puede reducir la cantidad de integrantes de la RCL?

⬅️ [Volver al índice](..)
