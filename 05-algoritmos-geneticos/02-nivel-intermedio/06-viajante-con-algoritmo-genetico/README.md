# 🗺️ Viajante con Algoritmo Genético

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Algoritmo genético · 📐 **Representación:** Permutación de ciudades

## 📝 Enunciado

Una empresa debe realizar entregas en un conjunto de ciudades. El vehículo parte de un depósito, visita cada ciudad exactamente una vez y regresa al depósito.

Dispones de una matriz con las distancias entre todas las ubicaciones.

Debes encontrar un recorrido que **minimice la distancia total**.

Representa cada individuo mediante un vector de enteros que contenga el orden de visita de las ciudades. El depósito tiene índice `0` y no se almacena en el cromosoma.

Por ejemplo:

```text
Cromosoma: [2, 4, 1, 3]

Recorrido:
0 -> 2 -> 4 -> 1 -> 3 -> 0
```

Implementa un algoritmo genético con selección por torneo, cruce de un punto, mutación por intercambio, eliminación de clones y reemplazo de los mejores individuos.

El cruce puede producir ciudades repetidas. Detecta y descarta esos hijos; en este ejercicio no se utilizan operadores especiales de permutaciones.

Al finalizar, muestra únicamente el mejor recorrido encontrado.

## 🧪 Ejemplo de ejecución

Para la siguiente matriz de distancias:

| Ubicación | 0 | 1 | 2 | 3 | 4 |
|---|---:|---:|---:|---:|---:|
| 0 | 0 | 4 | 7 | 6 | 3 |
| 1 | 4 | 0 | 5 | 8 | 6 |
| 2 | 7 | 5 | 0 | 3 | 7 |
| 3 | 6 | 8 | 3 | 0 | 4 |
| 4 | 3 | 6 | 7 | 4 | 0 |

Con los parámetros:

```text
Cantidad de individuos: 6
Cantidad de generaciones: 100
Tasa de seleccion: 0.8
Tamano de torneo: 3
Probabilidad de mutacion: 0.1
```

Una posible salida es:

```text
Mejor cromosoma encontrado: 1 2 3 4

Recorrido:
0 -> 1 -> 2 -> 3 -> 4 -> 0

Distancia total: 19
```

La distancia incluye la salida del depósito y el regreso:

```text
4 + 5 + 3 + 4 + 3 = 19
```

Los resultados pueden variar según la semilla y las elecciones aleatorias. No se exige obtener exactamente este recorrido.

## 🚧 Restricciones y suposiciones

- Hay al menos dos ciudades además del depósito.
- Todas las ubicaciones están conectadas directamente entre sí.
- Las distancias entre ubicaciones distintas son enteros positivos.
- La diagonal de la matriz contiene ceros.
- La matriz puede ser asimétrica: viajar de una ubicación a otra no necesariamente cuesta lo mismo que regresar.
- Cada cromosoma contiene exactamente una vez cada ciudad, con índices de `1` a `cantidadCiudades`.
- El depósito no aparece en el cromosoma.
- El tamaño de población es mayor o igual que dos y no supera `cantidadCiudades!`.
- La población inicial y cada población resultante del reemplazo deben contener individuos válidos y distintos.

### 🌱 Población inicial

- Genera permutaciones aleatorias de las ciudades.
- No repitas ciudades dentro de un individuo.
- Rechaza los cromosomas que ya estén en la población.
- Continúa hasta completar el tamaño de población indicado.

### 🚧 Aberraciones

Un individuo es una aberración si:

- Su longitud no coincide con la cantidad de ciudades.
- Algún gen está fuera del rango permitido.
- Alguna ciudad aparece más de una vez.

Con la longitud y el rango correctos, no tener repeticiones garantiza que estén presentes todas las ciudades.

### 🎯 Evaluación y selección

- Evalúa cada individuo mediante la distancia total de su recorrido.
- Incluye la distancia del depósito a la primera ciudad, las distancias entre ciudades consecutivas y el regreso al depósito.
- **Una distancia menor representa una solución mejor.**
- Selecciona padres mediante torneo.
- Para cada padre, sortea `tamanoTorneo` participantes con reemplazo.
- Gana el participante de menor distancia total.
- En caso de empate, conserva al primero sorteado en ese torneo.
- Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion`.
- Elige una tasa en `(0, 1]` que produzca al menos dos padres.

### ✂️ Cruce de un punto

- Genera un hijo por cada pareja ordenada de índices distintos del vector de padres.
- Siempre se aplica el cruce.
- Elige el punto de corte entre `1` y `cantidadCiudades - 1`, inclusive.
- El hijo recibe el segmento inicial del primer padre y el segmento final del segundo.
- No modifiques los padres originales.
- No repares las repeticiones producidas por el cruce.

Por ejemplo:

```text
Padre: [1, 2 | 3, 4]
Madre: [3, 4 | 1, 2]
Hijo:  [1, 2 | 1, 2]
```

Este hijo es una aberración porque repite ciudades.

### 🔄 Mutación por intercambio

- Realiza una única decisión de mutación por hijo.
- Si ocurre, elige dos posiciones distintas e intercambia sus valores.
- La probabilidad de mutación pertenece a `[0, 1]`.
- Para sorteos con `rand() % 100`, utiliza probabilidades expresables en pasos de `0.01`.
- Comprueba la validez después de mutar.
- Descarta los hijos inválidos sin generar reemplazos.

El intercambio conserva una permutación válida, pero no elimina las repeticiones de un hijo inválido.

### 🧬 Clones y reemplazo

- Reúne la población actual y los hijos válidos.
- Elimina los cromosomas repetidos.
- Dos individuos son clones si tienen exactamente la misma secuencia de ciudades.
- Ordena de menor a mayor distancia total.
- En caso de empate, puedes conservar cualquier orden.
- Conserva exactamente la cantidad inicial de individuos.
- Los individuos originales permanecen entre los candidatos al reemplazo.
- La mejor distancia no debe aumentar entre generaciones.

### 🛠️ Organización y finalización

- Separa la generación de permutaciones, la detección de aberraciones y el cálculo de distancia.
- Reutiliza la selección por torneo, la eliminación de clones y el reemplazo.
- Implementa el cruce de un punto y la mutación por intercambio.
- Inicializa la semilla aleatoria una sola vez al comenzar la ejecución.
- Ejecuta todas las generaciones indicadas.
- Al finalizar, muestra el cromosoma, el recorrido completo y la distancia total.
- No se permite resolver mediante fuerza bruta, backtracking ni programación dinámica.
- No se utilizan cruces especiales como OX en este ejercicio.

El algoritmo busca recorridos cortos, pero **no garantiza encontrar el de menor distancia posible**.

⬅️ [Volver al nivel intermedio](..)