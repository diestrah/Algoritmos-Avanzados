# 🟢 Nivel básico

Este nivel introduce los componentes de un **algoritmo genético**, desde la generación de individuos hasta la evolución de una población para resolver un problema de selección con restricciones.

## 🎯 Objetivos

Al finalizar este nivel deberías poder:

- representar individuos mediante cromosomas binarios
- generar y evaluar una población inicial
- seleccionar padres mediante ruleta y torneo
- aplicar cruce de un punto, cruce uniforme y mutación
- detectar aberraciones y eliminar clones
- conservar las mejores soluciones durante el reemplazo
- adaptar el algoritmo al problema de la mochila

## 📚 Ejercicios

1. [Población de cadenas binarias](01-poblacion-de-cadenas-binarias)
2. [Selección de individuos por ruleta y torneo](02-seleccion-de-individuos-por-ruleta)
3. [Cruce y mutación de cadenas binarias](03-cruce-y-mutacion-de-cadenas-binarias)
4. [Maximización de unos mediante evolución](04-maximizacion-de-unos-mediante-evolucion)
5. [Mochila con algoritmo genético binario](05-mochila-con-algoritmo-genetico-binario)

## 👀 Antes de avanzar

Comprueba que puedes explicar qué representa cada gen, cómo se calcula el fitness y qué condiciones hacen inválida una solución.

Distingue la **tasa de selección**, que determina cuántos padres se eligen, de la **probabilidad de mutación**, que determina cuándo se aplica ese operador. Consulta cada enunciado para identificar si la mutación se evalúa por gen o por individuo.

Los resultados pueden variar entre ejecuciones. Encontrar la mejor solución de una población no demuestra que sea el óptimo del problema.

## ➡️ Siguiente nivel

[Nivel intermedio](../02-nivel-intermedio)

⬅️ [Volver a algoritmos evolutivos](..)