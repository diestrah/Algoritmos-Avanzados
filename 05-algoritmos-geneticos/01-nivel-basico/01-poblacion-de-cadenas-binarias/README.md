# 🧬 Población de Cadenas Binarias

🟢 **Dificultad:** Básica · 🧠 **Técnica:** Inicialización y evaluación de una población · 📐 **Representación:** Vectores binarios

## 📝 Enunciado

Antes de implementar un algoritmo genético completo, necesitas representar sus posibles soluciones, generar una población inicial y evaluar la calidad de cada individuo.

Implementa un programa que genere aleatoriamente una población de `cantidadIndividuos` cromosomas. Cada cromosoma debe contener `cantidadGenes` valores binarios: **0 o 1**.

La aptitud o **fitness** de un individuo será la cantidad de unos presentes en su cromosoma. Por lo tanto, un individuo con más unos tendrá una mejor evaluación.

El programa debe:

- Generar la población inicial.
- Calcular el fitness de cada individuo.
- Mostrar todos los cromosomas junto con su fitness.
- Identificar y mostrar el mejor individuo de la población.

## 🧪 Ejemplo de ejecución

Para `cantidadIndividuos = 5` y `cantidadGenes = 6`, una posible salida es:

```text
Poblacion inicial:

Individuo 1: 1 0 1 0 0 1 | Fitness: 3
Individuo 2: 0 1 0 0 1 0 | Fitness: 2
Individuo 3: 1 1 0 1 1 0 | Fitness: 4
Individuo 4: 0 0 0 0 0 0 | Fitness: 0
Individuo 5: 1 0 1 1 0 1 | Fitness: 4

Mejor individuo: 3
Cromosoma: 1 1 0 1 1 0
Fitness: 4
```

La población y sus evaluaciones pueden variar según la semilla y el generador aleatorio utilizados.

## 🚧 Restricciones y suposiciones

- `cantidadIndividuos` y `cantidadGenes` deben ser enteros positivos.
- Representa cada cromosoma mediante un `vector<int>` y la población mediante un `vector<vector<int>>`.
- Cada gen se genera aleatoriamente y solo puede tomar el valor `0` o `1`.
- La población debe contener exactamente la cantidad de individuos indicada.
- Se permiten cromosomas repetidos.
- Todos los cromosomas binarios del tamaño indicado son válidos, incluido el formado únicamente por ceros.
- El fitness pertenece al intervalo `[0, cantidadGenes]`.
- Si varios individuos tienen el mejor fitness, conserva el primero que aparece en la población.
- Inicializa la semilla aleatoria una sola vez, antes de generar la población.
- Separa en funciones la generación de la población, el cálculo del fitness, la presentación de los individuos y la identificación del mejor.
- En este ejercicio no se aplican selección, cruce, mutación ni reemplazo.

El mejor individuo mostrado es el **mejor de la población generada**. No necesariamente tendrá todos sus genes en uno.

⬅️ [Volver al nivel básico](..)