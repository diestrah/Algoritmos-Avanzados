# 🔴 Nivel avanzado

Este nivel combina los **algoritmos genéticos** con restricciones de tiempo, presupuestos, conflictos y múltiples rutas. También incorpora la construcción GRASP para generar poblaciones iniciales.

## 🎯 Objetivos

Al finalizar este nivel deberías poder:

- evaluar soluciones mediante simulaciones de horarios y recorridos
- distinguir restricciones obligatorias de penalizaciones
- combinar GRASP con algoritmos genéticos
- trabajar con objetivos ordenados por prioridad
- representar varias rutas dentro de un individuo
- adaptar los operadores y la detección de aberraciones a restricciones combinadas

## 📚 Ejercicios

1. [Programación de tareas con ventanas de tiempo](01-programacion-de-tareas-con-ventanas-de-tiempo)
2. [Asignación de tareas a agentes con presupuesto](02-asignacion-de-tareas-a-agentes-con-presupuesto)
3. [Planificación de exámenes por franjas horarias](03-planificacion-de-examenes-por-franjas-horarias)
4. [Corte de barras con prioridades de desperdicio](04-corte-de-barras-con-prioridades-de-desperdicio)
5. [Rutas de reparto con múltiples vehículos](05-rutas-de-reparto-con-multiples-vehiculos)

## 👀 Antes de comenzar

Identifica qué representa el cromosoma y cómo se transforma en una solución completa. La evaluación puede requerir construir horarios, acumular recursos o separar rutas.

Cuando existan varios objetivos, define su prioridad. Por ejemplo, minimizar primero la cantidad de barras incompletas y después el desperdicio requiere comparar ambos criterios en ese orden.

Si utilizas GRASP para inicializar la población, genera distintas construcciones válidas. Repetir una misma solución no aporta diversidad.

## 🧪 Interpretación de resultados

Compara configuraciones mediante varias ejecuciones y conserva condiciones equivalentes: datos, generaciones y tamaño de población.

Encontrar una solución de buena calidad no demuestra que sea óptima. Asimismo, no encontrar una solución factible no demuestra que el problema sea imposible.

⬅️ [Volver a algoritmos evolutivos](..)