# 🎒 Mochila con Algoritmo Genético Binario

🟢 **Dificultad:** Básica · 🧠 **Técnica:** Algoritmo genético · 📐 **Representación:** Vector binario de selección

## 📝 Enunciado

Dispones de un conjunto de objetos. Cada uno tiene un **peso** y un **beneficio**. Debes seleccionar cuáles colocar en una mochila para maximizar el beneficio total sin superar su capacidad.

Representa cada solución mediante un cromosoma binario:

- `1`: el objeto correspondiente se incluye.
- `0`: el objeto correspondiente no se incluye.

El **fitness** de un individuo válido es la suma de los beneficios de los objetos seleccionados.

Se considera una **aberración** cualquier cromosoma que supere la capacidad de la mochila o que no seleccione ningún objeto.

Implementa un algoritmo genético que:

1. Genere una población inicial de individuos válidos y distintos.
2. Seleccione padres mediante ruleta proporcional al fitness.
3. Genere un hijo por cada pareja ordenada de padres con índices distintos, utilizando cruce de un punto.
4. Aplique mutación independiente a cada gen de los hijos.
5. Descarte las aberraciones después de la mutación.
6. Elimine los cromosomas repetidos del conjunto formado por la población actual y los hijos válidos.
7. Conserve los mejores individuos para la siguiente generación.

## 🧪 Ejemplo de ejecución

Para una mochila con capacidad `15` y los siguientes objetos:

| Objeto | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| Peso | 2 | 3 | 4 | 5 | 8 | 9 |
| Beneficio | 6 | 8 | 9 | 12 | 20 | 22 |

Con los parámetros:

```text
Cantidad de individuos: 6
Cantidad de generaciones: 20
Tasa de seleccion: 0.8
Probabilidad de mutacion: 0.1
```

Una posible solución encontrada es:

```text
Mejor cromosoma encontrado: 1 0 0 1 1 0
Objetos seleccionados: 1 4 5
Peso total: 15
Beneficio total: 38
Capacidad restante: 0
```

Los resultados pueden variar según la semilla, la población inicial y las elecciones aleatorias. No se exige obtener exactamente esta selección.

## 🚧 Restricciones y suposiciones

- Hay al menos dos objetos.
- Los pesos, beneficios y la capacidad son enteros positivos.
- Los vectores o estructuras de objetos mantienen una correspondencia fija con las posiciones del cromosoma.
- Cada objeto puede seleccionarse como máximo una vez.
- Cada cromosoma tiene un gen por objeto y contiene únicamente valores `0` o `1`.
- La población contiene al menos dos individuos.
- Existen al menos tantos cromosomas válidos distintos como individuos se requieren en la población.
- Todos los individuos incorporados a la población deben ser válidos.
- La población inicial y cada población resultante del reemplazo deben contener cromosomas distintos.

### 🌱 Población inicial

- Genera cada gen aleatoriamente como `0` o `1`.
- Descarta los cromosomas que excedan la capacidad o no seleccionen objetos.
- Descarta también los cromosomas que ya estén presentes en la población.
- Continúa hasta reunir exactamente `cantidadIndividuos` individuos válidos y distintos.

### 🎯 Fitness y selección

- Comprueba la factibilidad mediante el peso total.
- Evalúa la calidad mediante el beneficio total.
- **Peso y beneficio cumplen funciones distintas:** el fitness corresponde al beneficio.
- Selecciona padres mediante ruleta proporcional al fitness.
- Puedes utilizar fitness acumulados para determinar a qué individuo pertenece cada ticket.
- Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion`.
- `tasaSeleccion` pertenece al intervalo `(0, 1]`. Elige parámetros que produzcan al menos dos padres.
- La selección es con reemplazo: un mismo individuo puede aparecer varias veces en el vector de padres.
- Como los beneficios son positivos y ningún individuo está vacío, el fitness total de la población siempre es positivo.

### ✂️ Cruce

- Recorre todas las parejas ordenadas de índices distintos del vector de padres.
- Las parejas `(i, j)` y `(j, i)` generan hijos mediante llamadas independientes.
- Los padres pueden tener cromosomas iguales debido a la selección con reemplazo.
- Cada pareja genera un único hijo.
- Siempre aplica el cruce de un punto.
- Elige el corte entre `1` y `cantidadGenes - 1`, inclusive.
- El hijo recibe el segmento inicial del primer padre y el segmento final del segundo.
- Los padres originales no se modifican.

Con `k` padres seleccionados se generan `k × (k - 1)` hijos antes de descartar aberraciones y eliminar clones.

### 🔄 Mutación y validación

- Cada gen del hijo tiene una decisión independiente de mutación.
- Si un gen muta, invierte su valor.
- La probabilidad de mutación pertenece al intervalo `[0, 1]`.
- Para sorteos con `rand() % 100`, utiliza probabilidades expresables en pasos de `0.01`.
- Comprueba la validez del hijo después de aplicar la mutación.
- Descarta los hijos inválidos sin repararlos ni generar reemplazos.

### 🧬 Eliminación de clones

- Dos individuos son clones si sus cromosomas coinciden en todas las posiciones.
- Elimina los clones después de reunir la población actual y los hijos válidos, antes de ordenar y recortar.
- Conserva una sola copia de cada cromosoma.
- Puedes utilizar un `map<vector<int>, bool>` para identificar los cromosomas distintos.
- El orden del mapa no representa la calidad de los individuos; posteriormente debes ordenarlos por fitness.
- No elimines repeticiones del vector de padres: la selección sigue siendo con reemplazo.

### 🏆 Reemplazo y finalización

- Ordena los individuos únicos de mayor a menor beneficio.
- En caso de empate de beneficio, prioriza al individuo de menor peso.
- Si también empatan en peso, puedes conservar cualquier orden.
- Conserva exactamente `cantidadIndividuos` individuos.
- Los individuos originales permanecen en el conjunto de candidatos, por lo que siempre existen suficientes cromosomas distintos para conservar el tamaño de población.
- Ejecuta todas las generaciones indicadas.
- Muestra el mejor beneficio de cada nueva generación.
- Al finalizar, muestra el cromosoma, los objetos seleccionados, el peso, el beneficio y la capacidad restante.

El mejor beneficio no debe disminuir entre generaciones.

## 🛠️ Organización

- Separa el cálculo del peso, el cálculo del fitness y la detección de aberraciones.
- Implementa funciones para generar la población, seleccionar padres, cruzar, mutar, eliminar clones y seleccionar supervivientes.
- Inicializa la semilla aleatoria una sola vez al comenzar cada ejecución.
- No se permite resolver mediante fuerza bruta, backtracking ni programación dinámica.

El algoritmo busca buenas selecciones, pero **no garantiza encontrar el beneficio óptimo**.

⬅️ [Volver al nivel básico](..)