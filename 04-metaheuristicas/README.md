# 🔎 Metaheurísticas

Las metaheurísticas son estrategias para explorar distintas soluciones de un problema de optimización, buscando resultados de buena calidad **sin garantizar necesariamente el óptimo**.

Este tema se centra inicialmente en **GRASP**, conectando las heurísticas voraces con la construcción aleatorizada y, posteriormente, la búsqueda local.

## 🎯 Objetivos

Al completar este recorrido deberías poder:

- representar soluciones y comprobar su factibilidad
- definir criterios de evaluación y funciones objetivo
- construir y actualizar una **lista restringida de candidatos (RCL)**
- comprender el efecto de `α` y de las múltiples construcciones
- conservar la mejor solución encontrada
- incorporar restricciones, recursos y dependencias
- distinguir la construcción de una solución de su mejora mediante búsqueda local

## 📚 Niveles

| # | Nivel | Qué practicas |
|---|---|---|
| 1 | [🟢 Nivel básico](01-nivel-basico) | RCL, selección aleatoria y múltiples construcciones |
| 2 | [🟡 Nivel intermedio](02-nivel-intermedio) | Selección, distribución y recorridos con restricciones |
| 3 | [🔴 Nivel avanzado](03-nivel-avanzado) | Doble RCL, recursos múltiples y dependencias |

## 🧩 ¿Qué es GRASP?

**GRASP** significa *Greedy Randomized Adaptive Search Procedure*. Su esquema combina:

1. **Construcción:** formar una solución mediante elecciones voraces aleatorizadas.
2. **Búsqueda local:** mejorar la solución construida mediante cambios factibles.
3. **Repetición:** realizar nuevas construcciones y mejoras, conservando el mejor resultado.

Los primeros ejercicios trabajan únicamente la **fase de construcción con múltiples inicios**. La búsqueda local se incorporará progresivamente.

## 🎲 Lista restringida de candidatos

La **RCL** reúne candidatos factibles que cumplen un umbral de calidad. En cada elección se selecciona aleatoriamente uno de sus integrantes.

En este repositorio se utiliza la siguiente convención:

- **`α = 0`:** solo se admiten candidatos con la mejor evaluación.
- **`α = 1`:** se admiten todos los candidatos factibles.
- **`0 < α < 1`:** se permite un margen respecto al mejor valor.

Un valor mayor de `α` amplía las posibilidades de elección, pero **no garantiza mejores soluciones**.

## 🧪 Interpretación de resultados

Las salidas de los ejercicios son **ejemplos de resultados posibles**, no respuestas que deban reproducirse exactamente.

Una semilla fija permite repetir las pruebas en el mismo entorno. El resultado también puede depender del generador aleatorio y de su implementación.

Encontrar una solución mejor que otra no demuestra que sea óptima. Asimismo, no encontrar una solución factible no demuestra que sea imposible obtenerla.

⬅️ [Volver al índice general](..)