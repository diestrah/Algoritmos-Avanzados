# 🚚 Rutas de Reparto con Múltiples Vehículos

🔴 **Dificultad:** Avanzada · 🧠 **Técnica:** Algoritmo genético · 📐 **Representación:** Permutación de clientes y puntos de corte

## 📝 Enunciado

Una empresa dispone de `K` vehículos para atender un conjunto de clientes. Todos los vehículos salen del mismo depósito y regresan a él.

Cada cliente debe visitarse exactamente una vez y cada vehículo debe atender al menos un cliente.

Debes encontrar un conjunto de rutas que **minimice la distancia total recorrida por los vehículos**.

Representa cada individuo mediante:

- Una permutación con todos los clientes.
- Un vector de `K - 1` puntos de corte que separa las rutas.

El depósito tiene índice `0` y no aparece en el cromosoma.

Por ejemplo:

```text
Clientes: [1, 3, 2, 5, 4, 6]
Cortes:   [2, 4]
```

Los cortes indican posiciones donde comienza la siguiente ruta:

```text
Vehiculo 1: 0 -> 1 -> 3 -> 0
Vehiculo 2: 0 -> 2 -> 5 -> 0
Vehiculo 3: 0 -> 4 -> 6 -> 0
```

Implementa selección por torneo, cruce de un punto con descarte de aberraciones, mutación, eliminación de clones y reemplazo elitista.

Al finalizar, muestra únicamente las mejores rutas encontradas.

## 🧪 Ejemplo de ejecución

Para seis clientes, dos vehículos y la siguiente matriz:

```text
0 4 6 8 7 3 5
4 0 3 5 6 4 7
6 3 0 4 5 7 6
8 5 4 0 3 6 4
7 6 5 3 0 4 5
3 4 7 6 4 0 3
5 7 6 4 5 3 0
```

Con los parámetros:

```text
Cantidad de vehiculos: 2
Cantidad de individuos: 10
Cantidad de generaciones: 200
Tasa de seleccion: 0.8
Tamano de torneo: 3
Probabilidad de mutacion: 0.2
```

Una posible solución es:

```text
Mejor cromosoma encontrado: 1 2 3 4 5 6
Puntos de corte: 2

Vehiculo 1:
Ruta: 0 -> 1 -> 2 -> 0
Distancia: 13

Vehiculo 2:
Ruta: 0 -> 3 -> 4 -> 5 -> 6 -> 0
Distancia: 23

Distancia total: 36
```

Los resultados pueden variar según la semilla y las elecciones aleatorias. No se exige obtener exactamente estas rutas.

## 🚧 Restricciones y suposiciones

- Hay al menos dos clientes.
- `2 <= K <= cantidadClientes`.
- Se utilizan exactamente `K` vehículos y ninguno puede tener una ruta vacía.
- Todos los pares de ubicaciones tienen conexión directa.
- Las distancias entre ubicaciones distintas son enteros positivos.
- La diagonal de la matriz contiene ceros.
- La matriz puede ser asimétrica.
- Los clientes tienen índices de `1` a `cantidadClientes`.
- Los cortes son posiciones internas del vector, entre `1` y `cantidadClientes - 1`.
- Los cortes están ordenados de menor a mayor y no se repiten.
- Existen suficientes individuos válidos distintos para completar la población.

### 🌱 Población inicial

Para construir cada individuo:

1. Genera una permutación aleatoria de todos los clientes.
2. Elige `K - 1` posiciones de corte distintas.
3. Ordena los cortes.
4. Rechaza el individuo si ya está presente en la población.

Continúa hasta completar el tamaño indicado.

### 🚧 Aberraciones

Un individuo es una aberración si:

- Repite u omite clientes.
- Contiene índices de cliente fuera de rango.
- No tiene exactamente `K - 1` cortes.
- Los cortes están repetidos, desordenados o fuera del rango permitido.

Estas condiciones garantizan que cada cliente pertenezca a una ruta y que ninguna ruta esté vacía.

### 🎯 Evaluación y selección

- Separa las rutas utilizando los cortes.
- Para cada vehículo, suma la salida del depósito, los desplazamientos entre clientes y el regreso al depósito.
- La evaluación es la suma de distancias de todos los vehículos.
- Una distancia total menor representa una solución mejor.
- Selecciona padres mediante torneo con reemplazo.
- En caso de empate, conserva al primer participante sorteado.
- Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion`.
- Utiliza parámetros que produzcan al menos dos padres.

### ✂️ Cruce de un punto

- Genera un hijo por cada pareja ordenada de índices distintos del vector de padres.
- Aplica siempre cruce de un punto sobre el vector de clientes.
- Elige el corte entre `1` y `cantidadClientes - 1`, inclusive.
- El hijo recibe el segmento inicial del primer padre y el final del segundo.
- Para el vector de cortes, copia completo el del primer o del segundo padre con probabilidad `0.5`.
- No modifiques los padres originales.
- No repares clientes repetidos.

El punto de cruce entre padres y los puntos que separan vehículos cumplen funciones diferentes.

### 🔄 Mutación

Realiza una única decisión de mutación por hijo. Si ocurre, elige con probabilidad `0.5` una de estas operaciones:

- **Intercambio de clientes:** intercambia dos posiciones distintas de la permutación.
- **Cambio de separación:** elige uno de los cortes y reemplázalo por otra posición interna que no esté ocupada; después ordena los cortes.

Si todas las posiciones internas ya están ocupadas por cortes, aplica intercambio de clientes.

Valida el individuo después de mutar y descarta los hijos inválidos. El intercambio no corrige las repeticiones producidas por el cruce.

### 🧬 Clones y reemplazo

- Dos individuos son clones si coinciden tanto en la permutación como en los cortes.
- Reúne la población actual y los hijos válidos.
- Elimina clones.
- Ordena de menor a mayor distancia total.
- Conserva exactamente el tamaño inicial de población.
- En caso de empate, puedes conservar cualquier orden.
- Los individuos originales permanecen disponibles para el reemplazo.
- La mejor distancia no debe aumentar entre generaciones.

### 🛠️ Organización y finalización

- Utiliza una estructura con el cromosoma y el vector de cortes.
- Implementa una función para separar las rutas.
- Reutiliza esa separación para evaluar y mostrar los resultados.
- Inicializa la semilla aleatoria una sola vez.
- Ejecuta todas las generaciones indicadas.
- Muestra la permutación, los cortes, cada ruta con su distancia y la distancia total.
- Para sorteos con `rand() % 100`, utiliza probabilidades en pasos de `0.01`.
- No se permite fuerza bruta, backtracking ni programación dinámica.
- No se utilizan cruces especiales como OX.

## 🧩 Ampliación: reparto con restricciones

Una vez completada la versión principal, incorpora progresivamente:

- **Capacidad:** cada cliente tiene una demanda y cada vehículo una capacidad máxima.
- **Duración de jornada:** cada ruta tiene un tiempo máximo de operación.
- **Ventanas de atención:** calcula llegadas, esperas y retrasos.
- **Cadena de frío:** cada ruta tiene una duración térmica máxima.

Define explícitamente qué condiciones son obligatorias y cuáles generan penalizaciones. Una condición no debe tratarse simultáneamente como prohibida y permitida con penalización.

Si combinas distancia y penalizaciones monetarias, establece una conversión de distancia a costo y explica la función de evaluación.

La versión principal busca rutas cortas, pero **no garantiza encontrar la distancia mínima posible**.

⬅️ [Volver al nivel avanzado](..)