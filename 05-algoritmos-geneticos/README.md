# 🧬 Algoritmos Genéticos

Los algoritmos genéticos son estrategias de búsqueda inspiradas en la evolución natural. Trabajan con una **población de soluciones** y generan nuevas alternativas mediante selección, cruce y mutación.

Este tema desarrolla progresivamente sus componentes y los adapta a problemas de selección, asignación, planificación y recorridos.

## 🎯 Objetivos

Al completar este recorrido deberías poder:

- representar soluciones mediante cromosomas adecuados
- definir funciones de evaluación y comprobar restricciones
- generar poblaciones iniciales válidas
- seleccionar padres mediante ruleta y torneo
- aplicar operadores de cruce y mutación
- detectar aberraciones y eliminar clones
- conservar las mejores soluciones durante el reemplazo
- combinar GRASP con algoritmos genéticos
- interpretar resultados sin asumir que son óptimos

## 📚 Niveles

| # | Nivel | Qué practicas |
|---|---|---|
| 1 | [🟢 Nivel básico](01-nivel-basico) | Poblaciones binarias, fitness, selección, operadores y evolución |
| 2 | [🟡 Nivel intermedio](02-nivel-intermedio) | Representaciones y restricciones de selección, asignación y recorridos |
| 3 | [🔴 Nivel avanzado](03-nivel-avanzado) | Ventanas de tiempo, presupuestos, conflictos, GRASP y múltiples rutas |

## 🔁 Esquema de un algoritmo genético

1. **Inicialización:** generar una población de soluciones.
2. **Evaluación:** determinar la calidad de cada individuo.
3. **Selección:** elegir los padres.
4. **Cruce:** combinar información de los padres para generar hijos.
5. **Mutación:** introducir modificaciones aleatorias.
6. **Validación:** comprobar las restricciones de los hijos.
7. **Reemplazo:** formar la siguiente generación.
8. **Repetición:** continuar hasta cumplir la condición de parada.

Cada ejercicio establece qué componentes utiliza y cómo se aplican.

## 🧩 Representación de soluciones

El significado de un gen depende del problema.

| Representación | Ejemplo de uso |
|---|---|
| Vector binario | Seleccionar objetos o activos |
| Bloques binarios | Codificar recursos o franjas asignadas |
| Vector de enteros | Asignar operadores a máquinas |
| Permutación | Establecer un orden de tareas o ciudades |
| Permutación con cortes | Representar varias rutas |

El cruce y la mutación deben adaptarse a la representación. Un operador puede conservar algunas propiedades y romper otras, por lo que no todos los hijos serán necesariamente válidos.

## 🎯 Fitness y evaluación

La evaluación expresa la calidad de una solución según el objetivo del problema:

- **Maximización:** una ganancia o beneficio mayor es mejor.
- **Minimización:** una distancia, penalización o cantidad de recursos menor es mejor.
- **Prioridades:** se compara primero el objetivo principal y, en caso de empate, el siguiente.

No existe una fórmula universal de fitness ni es obligatorio elevarlo al cuadrado.

La selección por ruleta requiere pesos no negativos y una suma positiva. En los ejercicios de maximización se utiliza cuando las evaluaciones cumplen estas condiciones. El torneo permite comparar directamente soluciones de maximización, minimización o varios criterios.

## 🚧 Aberraciones y clones

Una **aberración** es una solución que incumple las restricciones definidas en el ejercicio. Una evaluación baja no implica necesariamente invalidez.

Los **clones** son individuos con la misma representación. Según el problema, puede eliminarse su repetición para conservar diversidad.

La selección de padres puede ser con reemplazo aunque la población no contenga clones: un mismo individuo puede elegirse varias veces.

Si se exige una población sin clones, deben existir suficientes soluciones válidas distintas para completarla.

## 🎲 Parámetros y operadores

- La **tasa de selección** determina cuántos padres se eligen.
- La **probabilidad de cruce**, cuando se utiliza, determina si se combinan los padres.
- El **punto de corte** determina dónde se combinan sus segmentos.
- La **probabilidad de mutación** determina cuándo se aplica una modificación.

La mutación puede evaluarse por gen o por individuo. Consulta cada enunciado: algunas variantes invierten bits, otras cambian una asignación o intercambian posiciones.

En varios ejercicios siempre se realiza el cruce. No confundas esa decisión con la posición de corte ni con la probabilidad de heredar un gen de cada padre.

## 🌱 Inicialización con GRASP

Los ejercicios avanzados incorporan la fase de construcción de GRASP para generar soluciones iniciales mediante elecciones voraces aleatorizadas.

Cada construcción debe comenzar con el estado original del problema. La población debe reunir diferentes soluciones, respetando las restricciones y las condiciones de diversidad del ejercicio.

## 🧪 Interpretación de resultados

Las salidas son **ejemplos de resultados posibles**, no respuestas que deban reproducirse exactamente.

Una semilla fija permite repetir pruebas en el mismo entorno. Los resultados también dependen del generador aleatorio y de la implementación.

Cuando el reemplazo conserva los mejores individuos entre la población actual y los hijos, la mejor evaluación no debe empeorar entre generaciones.

Encontrar una solución de buena calidad no demuestra que sea óptima. Asimismo, no encontrar una solución factible no demuestra que sea imposible obtenerla.

⬅️ [Volver al índice general](..)