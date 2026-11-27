# 📈 Selección de un Portafolio de Activos

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Algoritmo genético · 📐 **Representación:** Vector binario de selección

## 📝 Enunciado

Una empresa dispone de un presupuesto para invertir en un conjunto de activos. Cada activo tiene:

- Un precio actual de compra.
- Un precio futuro optimista.
- Un precio futuro pesimista.

Debes seleccionar un portafolio que maximice la diferencia entre las ganancias potenciales y las pérdidas potenciales, sin superar el presupuesto.

Representa cada portafolio mediante un cromosoma binario:

- `1`: se compra el activo.
- `0`: no se compra el activo.

Para evaluar un portafolio, calcula:

```text
Costo actual = suma de precios actuales seleccionados
Valor optimista = suma de precios optimistas seleccionados
Valor pesimista = suma de precios pesimistas seleccionados

Ganancia potencial = Valor optimista - Costo actual
Perdida potencial = Costo actual - Valor pesimista

Fitness = Ganancia potencial - Perdida potencial
```

Se considera una **aberración** cualquier portafolio vacío o cuyo costo supere el presupuesto.

Implementa un algoritmo genético que genere una población válida, seleccione padres mediante ruleta y produzca hijos mediante cruce uniforme. Después de aplicar la mutación, descarta las aberraciones, elimina clones y conserva los mejores individuos.

Al finalizar, muestra únicamente el detalle del mejor portafolio encontrado.

## 🧪 Ejemplo de ejecución

Para un presupuesto de `300` y los siguientes activos:

| Activo | Precio actual | Precio optimista | Precio pesimista |
|---|---:|---:|---:|
| 1 | 100 | 150 | 80 |
| 2 | 120 | 180 | 100 |
| 3 | 80 | 110 | 70 |
| 4 | 150 | 230 | 120 |
| 5 | 90 | 140 | 75 |
| 6 | 110 | 160 | 90 |

Con los parámetros:

```text
Cantidad de individuos: 6
Cantidad de generaciones: 100
Tasa de seleccion: 0.8
Probabilidad de mutacion: 0.1
```

Una posible salida es:

```text
Mejor cromosoma encontrado: 0 0 0 1 1 0
Activos seleccionados: 4 5

Presupuesto: 300
Costo actual: 240
Valor optimista: 370
Valor pesimista: 195
Ganancia potencial: 130
Perdida potencial: 45
Fitness: 85
Presupuesto restante: 60
```

Los resultados pueden variar según la semilla y las elecciones aleatorias. No se exige obtener exactamente este portafolio.

## 🚧 Restricciones y suposiciones

- Hay al menos dos activos.
- Los precios y el presupuesto son enteros positivos.
- Para cada activo se cumple:

  ```text
  precioPesimista <= precioActual <= precioOptimista
  ```

- La ganancia potencial de cada activo es estrictamente mayor que su pérdida potencial:

  ```text
  precioOptimista - precioActual > precioActual - precioPesimista
  ```

- Esta condición garantiza que todo portafolio no vacío tenga fitness positivo.
- Cada activo puede comprarse como máximo una vez.
- Cada cromosoma contiene un gen binario por activo.
- El tamaño de población es mayor o igual que dos.
- Existen al menos tantos portafolios válidos distintos como individuos se requieren en la población.
- La población inicial y cada población resultante del reemplazo deben contener individuos válidos y distintos.

### 🌱 Población inicial

- Genera cromosomas binarios aleatorios.
- Descarta los portafolios vacíos y los que superen el presupuesto.
- Elimina o rechaza los cromosomas repetidos.
- Continúa hasta completar el tamaño de población indicado.

### 🎯 Evaluación y selección

- Calcula los totales de precios actuales, optimistas y pesimistas.
- El fitness corresponde a la ganancia potencial menos la pérdida potencial.
- Selecciona padres mediante ruleta proporcional al fitness, utilizando acumulados.
- La selección es con reemplazo: un individuo puede seleccionarse varias veces.
- Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion`.
- La tasa pertenece al intervalo `(0, 1]`. Elige parámetros que produzcan al menos dos padres.
- Como todos los individuos de la población son válidos y tienen fitness positivo, el fitness total siempre es mayor que cero.

### 🎲 Cruce uniforme

- Genera un hijo por cada pareja ordenada de índices distintos del vector de padres.
- Las parejas `(i, j)` y `(j, i)` generan hijos mediante llamadas independientes.
- Los cromosomas de ambos padres pueden coincidir debido a la selección con reemplazo.
- Siempre se aplica el cruce.
- Para cada posición, el hijo recibe el gen del primer o del segundo padre con probabilidad `0.5`.
- Realiza una decisión independiente por posición.
- No modifiques los padres originales.

Con `k` padres seleccionados se generan `k × (k - 1)` hijos antes de descartar aberraciones y eliminar clones.

### 🔄 Mutación y validación

- Realiza una única decisión de mutación por hijo.
- Si ocurre la mutación, elige una posición al azar e invierte su bit.
- Cada hijo cambia como máximo un gen durante la mutación.
- La probabilidad de mutación pertenece al intervalo `[0, 1]`.
- Para sorteos con `rand() % 100`, utiliza probabilidades expresables en pasos de `0.01`.
- Comprueba la validez después de mutar.
- Descarta los hijos vacíos o que superen el presupuesto.
- No repares ni reemplaces los hijos descartados.

### 🧬 Clones y reemplazo

- Reúne la población actual y los hijos válidos.
- Elimina los cromosomas repetidos, conservando una sola copia de cada uno.
- Puedes utilizar un `map<vector<int>, bool>` para identificar los cromosomas distintos.
- Ordena de mayor a menor fitness.
- En caso de empate, prioriza el portafolio de menor costo actual.
- Si también empatan en costo, puedes conservar cualquier orden.
- Conserva exactamente la cantidad inicial de individuos.
- Los individuos originales permanecen entre los candidatos al reemplazo, garantizando suficientes cromosomas distintos.
- El mejor fitness no debe disminuir entre generaciones.

### 🛠️ Organización y finalización

- Utiliza una estructura para representar los datos de cada activo.
- Separa el cálculo de totales, la evaluación, la detección de aberraciones, la selección, el cruce, la mutación y el reemplazo.
- Inicializa la semilla aleatoria una sola vez al comenzar la ejecución.
- Ejecuta todas las generaciones indicadas.
- Al finalizar, muestra el mejor cromosoma, los activos seleccionados, los totales y el presupuesto restante.
- No es necesario mostrar resultados por generación ni comparar probabilidades de mutación.
- No se permite resolver mediante fuerza bruta, backtracking ni programación dinámica.

El algoritmo busca buenos portafolios, pero **no garantiza encontrar el óptimo**. Los escenarios optimista y pesimista son datos del ejercicio; no representan probabilidades de ocurrencia.

⬅️ [Volver al nivel intermedio](..)