# 🧭 Heurísticas

Una **heurística** es una regla práctica que encuentra una **buena solución rápidamente**, sin garantizar que sea la óptima. En estos ejercicios, la regla es un **criterio voraz**: en cada paso se toma la mejor decisión local, sin retroceder.

> 🎯 Decidir rápido, sin mirar atrás.

## 🎯 Objetivos

Al finalizar estos ejercicios deberías poder:

- 🧠 plantear una regla voraz para un problema
- 🔀 ordenar o priorizar los datos según el criterio elegido
- 📐 representar los problemas con vectores y matrices
- ⚖️ comparar la solución voraz con la óptima y reconocer cuándo no coinciden
- ⏱️ analizar la complejidad de una solución voraz

## 📚 Ejercicios

| # | Ejercicio | Regla heurística | Representación | Dificultad |
|---|-----------|------------------|----------------|------------|
| 1 | [🪙 Cambio de monedas voraz](01-cambio-de-monedas) | Elegir la mayor denominación que quepa | Vector de denominaciones | 🟢 Básica |
| 2 | [🎒 Mochila 0/1 por densidad](02-mochila) | Priorizar mayor valor por unidad de peso | Vector de objetos | 🟡 Intermedia |
| 3 | [🛠️ Asignación de tareas a máquinas](03-asignacion-de-tareas) | Asignar las tareas largas a la máquina menos cargada | Vectores de tareas y cargas | 🟡 Intermedia |
| 4 | [🧳 Viajante por vecino más cercano](04-viajante-por-vecino-mas-cercano) | Visitar la ciudad no visitada más próxima | Matriz de distancias | 🟡 Intermedia |
| 5 | [✂️ Corte en una dimensión](05-corte-en-una-dimension) | Cortar primero la pieza de mayor valor por unidad de longitud | Vectores de longitudes y valores | 🟡 Intermedia |
| 6 | [🎨 Coloreo voraz de grafos](06-coloreo-voraz-de-grafos) | Asignar a cada vértice el menor color disponible entre sus vecinos ya coloreados | Matriz de adyacencia | 🔴 Avanzada |

## ⚠️ Recuerda

Una heurística voraz **no siempre encuentra la solución óptima**. Prueba cada ejercicio con varios casos y compara tu resultado con el mejor posible.
<br>
⬅️ [Volver al índice](..)
