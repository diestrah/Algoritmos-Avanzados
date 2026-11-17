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

1. Genere una población inicial de individuos válidos.
2. Seleccione padres mediante ruleta proporcional al fitness.
3. Genere un hijo por cada pareja ordenada de padres con índices distintos, utilizando cruce de un punto.
4. Aplique mutación independiente a cada gen de los hijos.
5. Descarte las aberraciones después de la mutación.
6. Conserve los mejores individuos entre la población actual y los hijos válidos.

Además, compara dos formas de generar la población inicial:

- **Generación aleatoria con rechazo:** genera cromosomas binarios y descarta los que sean aberraciones.
- **Construcción aleatoria factible:** construye cada individuo incorporando objetos en orden aleatorio, sin superar la capacidad.

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
- Existe al menos un objeto cuyo peso no supera la capacidad.
- Cada objeto puede seleccionarse como máximo una vez.
- Los vectores de pesos y beneficios tienen la misma longitud.
- Cada cromosoma tiene un gen por objeto y contiene únicamente valores `0` o `1`.
- La población contiene al menos dos individuos y se permiten cromosomas repetidos.
- Todos los individuos incorporados a la población deben ser válidos.

### 🌱 Población inicial

Implementa las dos estrategias siguientes.

**Generación aleatoria con rechazo:**

- Genera cada gen aleatoriamente como `0` o `1`.
- Descarta los cromosomas que excedan la capacidad o no seleccionen objetos.
- Repite hasta completar el tamaño de población indicado.

**Construcción aleatoria factible:**

- Comienza cada individuo con todos sus genes en cero.
- Genera un orden aleatorio de los objetos, sin repetir índices.
- Recorre ese orden e incluye cada objeto si cabe en la capacidad restante.
- Si un objeto no cabe, continúa con el siguiente.
- Examina todos los objetos una vez.
- Repite el procedimiento para construir cada individuo de la población.

Como existe al menos un objeto que cabe, cada construcción debe seleccionar al menos uno.

### 🎯 Fitness y selección

- Comprueba la factibilidad mediante el peso total.
- Evalúa la calidad mediante el beneficio total.
- **Peso y beneficio cumplen funciones distintas:** no utilices el peso como fitness.
- Selecciona padres mediante ruleta con reemplazo.
- Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion`.
- Elige parámetros que produzcan al menos dos padres.
- Como los beneficios son positivos y ningún individuo está vacío, el fitness total de la población siempre es positivo.

### ✂️ Cruce y mutación

- Genera un hijo por cada pareja ordenada de índices distintos del vector de padres.
- Siempre aplica el cruce de un punto.
- Elige el corte entre `1` y `cantidadGenes - 1`, inclusive.
- El hijo recibe el segmento inicial del primer padre y el segmento final del segundo.
- Cada gen del hijo tiene una decisión independiente de mutación.
- Si un gen muta, invierte su valor.
- Para sorteos con `rand() % 100`, utiliza una probabilidad de mutación en `[0, 1]`, expresable en pasos de `0.01`.
- Comprueba la validez después de mutar.
- Descarta los hijos inválidos sin repararlos ni generar reemplazos.

### 🏆 Reemplazo y finalización

- Conserva los `cantidadIndividuos` mejores entre la población actual y los hijos válidos.
- En caso de empate de beneficio, prioriza al individuo de menor peso.
- Si también empatan en peso, puedes conservar cualquier orden.
- No elimines clones.
- Ejecuta todas las generaciones indicadas.
- Muestra el mejor beneficio de la población inicial y de cada nueva generación.
- Al finalizar, muestra el cromosoma, los objetos seleccionados, el peso, el beneficio y la capacidad restante.

### 🧪 Comparación de inicializaciones

- Ejecuta el algoritmo **10 veces por cada estrategia de inicialización**.
- Mantén iguales los datos y los parámetros del algoritmo.
- Utiliza la misma lista de 10 semillas para ambas estrategias e inicializa el generador una vez al comienzo de cada ejecución.
- Para cada estrategia, registra:
  - El promedio del mejor beneficio final.
  - El mayor beneficio encontrado.
  - La cantidad de cromosomas candidatos descartados durante la inicialización, por ejecución.
- Comenta las diferencias observadas. Una estrategia no tiene que superar necesariamente a la otra.

### 🛠️ Organización

- Separa el cálculo del peso, el cálculo del fitness y la detección de aberraciones.
- Implementa una función para cada estrategia de inicialización.
- Reutiliza y adapta las funciones de selección, cruce, mutación y reemplazo del ejercicio anterior.
- No se permite resolver mediante fuerza bruta, backtracking ni programación dinámica.

El algoritmo busca buenas selecciones, pero **no garantiza encontrar el beneficio óptimo**.

⬅️ [Volver al nivel básico](..)