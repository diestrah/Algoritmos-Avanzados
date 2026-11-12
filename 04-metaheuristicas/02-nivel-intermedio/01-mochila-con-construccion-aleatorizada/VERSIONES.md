## 💻 Versiones de la solución

Este ejercicio incluye dos implementaciones del mismo procedimiento de construcción voraz aleatorizada:

| Archivo | Representación de los candidatos |
|---|---|
| [main_rcl_indices.cpp](main_rcl_indices.cpp) | Construye una RCL explícita de índices y utiliza un vector para marcar los objetos seleccionados. |
| [main_ordenamiento.cpp](main_ordenamiento.cpp) | Mantiene los objetos pendientes ordenados. La RCL corresponde a un prefijo del vector y los objetos seleccionados se eliminan. |

Ambas versiones aplican el mismo criterio de evaluación y respetan las mismas restricciones. Se compilan y ejecutan por separado.

El orden de los candidatos puede ser diferente entre implementaciones; por eso, utilizar la misma semilla no garantiza obtener exactamente la misma selección.

