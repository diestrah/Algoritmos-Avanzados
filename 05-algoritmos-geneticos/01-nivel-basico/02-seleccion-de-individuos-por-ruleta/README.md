# 🎯 Selección de Individuos por Ruleta y Torneo

🟢 **Dificultad:** Básica · 🧠 **Técnica:** Selección de padres · 📐 **Representación:** Vectores binarios

## 📝 Enunciado

En un algoritmo genético, la selección permite elegir los individuos que participarán como padres en la generación de nuevas soluciones.

Retoma la población de cadenas binarias del ejercicio anterior. El **fitness** de cada individuo seguirá siendo la cantidad de unos presentes en su cromosoma.

Implementa dos métodos de selección:

- **Ruleta:** la probabilidad de seleccionar un individuo debe ser proporcional a su fitness.
- **Torneo:** elige aleatoriamente `tamanoTorneo` participantes y selecciona al que tenga mayor fitness.

Aplica ambos métodos sobre la **misma población inicial**, seleccionando en cada caso una cantidad de padres determinada por `tasaSeleccion`.

El programa debe mostrar:

- La población inicial y el fitness de cada individuo.
- Los padres seleccionados mediante ruleta y sus evaluaciones.
- Los padres seleccionados mediante torneo y sus evaluaciones.

## 🧪 Ejemplo de ejecución

Para `cantidadIndividuos = 5`, `cantidadGenes = 6`, `tasaSeleccion = 0.6` y `tamanoTorneo = 3`, se seleccionan `3` padres por cada método.

Dada la siguiente población:

```text
Poblacion inicial:

Individuo 1: 1 0 1 0 0 1 | Fitness: 3
Individuo 2: 0 1 0 0 1 0 | Fitness: 2
Individuo 3: 1 1 0 1 1 0 | Fitness: 4
Individuo 4: 0 0 0 0 0 0 | Fitness: 0
Individuo 5: 1 0 1 1 0 1 | Fitness: 4
```

Una posible selección es:

```text
Seleccion por ruleta:

Padre 1: 1 0 1 1 0 1 | Fitness: 4
Padre 2: 1 0 1 0 0 1 | Fitness: 3
Padre 3: 1 0 1 1 0 1 | Fitness: 4

Seleccion por torneo:

Padre 1: 1 1 0 1 1 0 | Fitness: 4
Padre 2: 1 0 1 1 0 1 | Fitness: 4
Padre 3: 1 1 0 1 1 0 | Fitness: 4
```

Los resultados pueden variar según la semilla y las elecciones aleatorias. Un individuo puede seleccionarse más de una vez.

## 🚧 Restricciones y suposiciones

- La población es no vacía y todos los cromosomas tienen la misma cantidad positiva de genes binarios.
- El fitness es la cantidad de unos del cromosoma.
- `tasaSeleccion` pertenece al intervalo `(0, 1]`.
- Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion` al entero más cercano. Si el resultado es cero, devuelve una lista de padres vacía.
- Cada método debe devolver exactamente la cantidad de padres calculada, sin modificar la población original.
- La selección es **con reemplazo**: seleccionar un individuo no lo elimina de la población.

### 🎡 Selección por ruleta

- Si el fitness total es positivo, la probabilidad de elegir al individuo `i` es:

  ```text
  probabilidad(i) = fitness(i) / sumaFitness
  ```

- Los individuos con fitness cero no pueden seleccionarse cuando existe alguno con fitness positivo.
- Si todos tienen fitness cero, selecciona uniformemente entre todos los individuos.
- Puedes utilizar intervalos acumulados o una ruleta de tickets. Evita redondear porcentajes de forma que se pierdan probabilidades o queden posiciones sin asignar.

### 🏆 Selección por torneo

- `tamanoTorneo` es un entero positivo.
- Para seleccionar cada padre, realiza un torneo nuevo.
- Los participantes se eligen uniformemente y con reemplazo: un individuo puede aparecer varias veces dentro del mismo torneo.
- Gana el participante con mayor fitness.
- En caso de empate, conserva al primero que fue elegido dentro de ese torneo.

### 🛠️ Organización

- Reutiliza las funciones de generación, evaluación e impresión del ejercicio anterior.
- Implementa una función de selección por ruleta y otra de selección por torneo.
- Inicializa la semilla aleatoria una sola vez al comenzar el programa.
- En este ejercicio no se aplican cruce, mutación ni reemplazo generacional.

La selección favorece a los individuos con mayor aptitud, pero **no garantiza que todos los padres sean los mejores de la población**.

⬅️ [Volver al nivel básico](..)
