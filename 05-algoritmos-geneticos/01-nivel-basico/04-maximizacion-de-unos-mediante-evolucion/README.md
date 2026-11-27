# 🧬 Maximización de Unos mediante Evolución

🟢 **Dificultad:** Básica · 🧠 **Técnica:** Algoritmo genético · 📐 **Representación:** Vectores binarios

## 📝 Enunciado

Implementa un algoritmo genético que busque una cadena binaria con la mayor cantidad posible de unos.

Cada individuo es un cromosoma de `cantidadGenes` bits. Su **fitness** corresponde a la cantidad de unos presentes en él.

Un cromosoma formado únicamente por ceros se considera una **aberración** y no puede incorporarse a la población.

Integra los componentes de los ejercicios anteriores para evolucionar una población durante `cantidadGeneraciones` generaciones:

1. Genera una población inicial de individuos válidos.
2. Selecciona padres mediante ruleta.
3. Genera un hijo por cada pareja ordenada de padres con índices distintos, utilizando cruce de un punto.
4. Aplica mutación de bits a cada hijo.
5. Descarta los hijos que sean aberraciones después de la mutación.
6. Forma la siguiente generación conservando los mejores individuos entre la población actual y los hijos válidos.

El programa debe mostrar el mejor fitness de la población inicial y de cada nueva generación. Al finalizar, muestra el mejor cromosoma encontrado y su fitness.

## 🧪 Ejemplo de ejecución

Para los siguientes parámetros:

```text
Cantidad de individuos: 6
Cantidad de genes: 8
Cantidad de generaciones: 5
Tasa de seleccion: 0.8
Probabilidad de mutacion: 0.1
```

Se seleccionan `5` padres por generación, pues `round(6 × 0.8) = 5`.

Una posible salida es:

```text
Generacion 0 | Mejor fitness: 6
Generacion 1 | Mejor fitness: 7
Generacion 2 | Mejor fitness: 7
Generacion 3 | Mejor fitness: 8
Generacion 4 | Mejor fitness: 8
Generacion 5 | Mejor fitness: 8

Mejor cromosoma encontrado: 1 1 1 1 1 1 1 1
Mejor fitness encontrado: 8
```

La generación `0` corresponde a la población inicial. Los resultados pueden variar según la semilla y las elecciones aleatorias.

## 🚧 Restricciones y suposiciones

- `cantidadIndividuos` es mayor o igual que dos.
- `cantidadGenes` es mayor o igual que dos.
- `cantidadGeneraciones` es un entero positivo.
- Representa cada individuo mediante un `vector<int>` y la población mediante un `vector<vector<int>>`.
- Todos los genes deben tener el valor `0` o `1`.
- Cada individuo válido debe contener **al menos un uno**.
- Un cromosoma formado únicamente por ceros es una aberración.
- El fitness de un individuo válido pertenece al intervalo `[1, cantidadGenes]`.
- Se permiten individuos repetidos.

### 🌱 Población inicial

- Genera cromosomas binarios aleatorios.
- Comprueba cada cromosoma antes de incorporarlo a la población.
- Si es una aberración, descártalo y genera otro.
- Continúa hasta reunir exactamente `cantidadIndividuos` individuos válidos.

### 🎯 Selección de padres

- Utiliza selección por ruleta proporcional al fitness.
- Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion` al entero más cercano.
- `tasaSeleccion` pertenece a `(0, 1]`. Elige parámetros que produzcan al menos dos padres.
- La selección es con reemplazo: un individuo puede seleccionarse más de una vez.
- Como la población es no vacía y todos sus individuos son válidos, el fitness total siempre es positivo.

### ✂️ Cruce

- Recorre todas las parejas ordenadas de índices distintos del vector de padres.
- Las parejas `(i, j)` y `(j, i)` generan hijos mediante llamadas independientes.
- Cada pareja genera un único hijo.
- Siempre se aplica el cruce; no se utiliza una probabilidad para decidir si ocurre.
- Elige un punto de corte entre `1` y `cantidadGenes - 1`, inclusive.
- El hijo recibe el segmento inicial del primer padre y el segmento final del segundo.
- Los padres originales no se modifican.

Con `k` padres seleccionados se generan `k × (k - 1)` hijos antes de descartar aberraciones.

### 🔄 Mutación y validación

- Aplica la mutación a cada hijo generado.
- Cada gen tiene una decisión independiente de mutación.
- Cuando un gen muta, invierte su valor.
- La probabilidad de mutación pertenece a `[0, 1]`. Para sorteos con `rand() % 100`, utiliza probabilidades expresables en pasos de `0.01`.
- Comprueba la validez del hijo **después de aplicar la mutación**.
- Si el hijo queda formado únicamente por ceros, descártalo.
- No es necesario generar otro hijo para reemplazar uno descartado.
- Un hijo que tenga todos sus genes en cero antes de mutar puede aceptarse si la mutación lo convierte en un individuo válido.

### 🏆 Reemplazo

- Reúne los individuos de la población actual y los hijos válidos después de la mutación.
- Ordena el conjunto de mayor a menor fitness.
- Conserva exactamente `cantidadIndividuos` individuos para la siguiente generación.
- En los empates puedes conservar cualquier orden.
- No elimines clones en este ejercicio.
- Si todos los hijos se descartan, conserva la población actual.

Este reemplazo conserva las mejores soluciones disponibles. Por ello, el mejor fitness **no debe disminuir entre generaciones**.

### 🛠️ Organización y finalización

- Implementa una función que determine si un cromosoma es una aberración.
- Reutiliza las funciones de evaluación, selección, cruce, mutación e impresión.
- Implementa una función para seleccionar supervivientes y otra para coordinar el algoritmo.
- Inicializa la semilla aleatoria una sola vez al comenzar el programa.
- Ejecuta todas las generaciones indicadas, incluso si antes encuentras un cromosoma formado únicamente por unos.
- La población debe mantener su tamaño y contener únicamente individuos válidos durante todas las generaciones.

El fitness máximo posible es `cantidadGenes`, pero el algoritmo **no garantiza alcanzarlo en la cantidad de generaciones indicada**.

⬅️ [Volver al nivel básico](..)