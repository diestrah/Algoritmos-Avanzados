# 🚚 Distribución de Paquetes en Camiones

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Algoritmo genético · 📐 **Representación:** Bloques binarios de asignación

## 📝 Enunciado

Una empresa dispone de **tres camiones**, cada uno con capacidad máxima `N`, para transportar un conjunto de paquetes.

Debes asignar **todos los paquetes**, cada uno a un único camión, sin superar la capacidad de ninguno.

El objetivo es **minimizar la cantidad de camiones utilizados**. Un camión se considera utilizado si tiene al menos un paquete asignado.

Representa cada individuo mediante un vector binario dividido en bloques de **dos bits por paquete**:

```text
00 → Camion 1
01 → Camion 2
10 → Camion 3
11 → Codigo invalido
```

Implementa un algoritmo genético con selección por torneo, cruce de un punto entre bloques, mutación de un bit, eliminación de clones y reemplazo de los mejores individuos.

Al finalizar, muestra la mejor distribución encontrada.

## 🧪 Ejemplo de ejecución

Para una capacidad por camión de `N = 15` y los siguientes paquetes:

| Paquete | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| Peso | 4 | 6 | 3 | 5 | 2 | 4 |

Con los parámetros:

```text
Cantidad de camiones disponibles: 3
Capacidad por camion: 15
Cantidad de individuos: 6
Cantidad de generaciones: 100
Tasa de seleccion: 0.8
Tamano de torneo: 3
Probabilidad de mutacion: 0.1
```

Una posible salida es:

```text
Mejor cromosoma encontrado:
00 | 00 | 00 | 01 | 01 | 01

Camion 1:
Paquetes: 1 2 3
Carga: 13
Capacidad restante: 2

Camion 2:
Paquetes: 4 5 6
Carga: 11
Capacidad restante: 4

Camion 3:
Paquetes: Ninguno
Carga: 0
Capacidad restante: 15

Camiones utilizados: 2
```

Los resultados pueden variar según la semilla y las elecciones aleatorias. No se exige obtener exactamente esta distribución.

## 🚧 Restricciones y suposiciones

- Hay al menos dos paquetes.
- Existen exactamente tres camiones disponibles.
- Todos los camiones tienen la misma capacidad `N`.
- Los pesos y `N` son enteros positivos.
- Cada paquete pesa como máximo `N`.
- Los paquetes son indivisibles.
- Cada paquete debe asignarse exactamente a un camión.
- Los datos admiten una distribución factible utilizando como máximo tres camiones.
- La suma de los pesos no supera `3 × N`, aunque esta condición por sí sola no garantiza una distribución factible.
- Existen al menos tantos cromosomas válidos distintos como individuos se requieren en la población.
- La población inicial y cada población resultante del reemplazo deben contener individuos válidos y distintos.

### 🔢 Codificación y decodificación

- Cada paquete ocupa un bloque de dos genes.
- El primer bit del bloque es el más significativo.
- Para un bloque `[a, b]`, calcula el índice del camión mediante:

  ```text
  indiceCamion = 2 × a + b
  ```

- Los índices válidos son `0`, `1` y `2`.
- El código `11` produce el índice `3` y es inválido.
- Para mostrar los identificadores al usuario, suma uno al índice.
- Cada cromosoma contiene exactamente `2 × cantidadPaquetes` genes binarios.

### 🌱 Población inicial

- Genera cromosomas binarios aleatorios.
- Decodifica la asignación de cada paquete.
- Descarta las aberraciones y los cromosomas repetidos.
- Continúa hasta completar el tamaño de población indicado.

### 🚧 Aberraciones

Un individuo es una aberración si:

- Algún paquete tiene el código `11`.
- La carga acumulada de algún camión supera `N`.

Comprueba cada código antes de utilizarlo como índice.

La representación asigna un único camión a cada paquete. Se permite que uno o dos camiones queden vacíos.

### 🎯 Evaluación y selección

- La evaluación es la cantidad de camiones que tienen carga.
- **Una cantidad menor representa una solución mejor.**
- Selecciona padres mediante torneo.
- Para cada padre, sortea `tamanoTorneo` participantes con reemplazo.
- Gana el participante que utiliza menos camiones.
- En caso de empate, conserva al primero sorteado en ese torneo.
- Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion`.
- Elige una tasa en `(0, 1]` que produzca al menos dos padres.

### ✂️ Cruce de un punto por bloques

- Genera un hijo por cada pareja ordenada de índices distintos del vector de padres.
- Siempre se aplica el cruce.
- Elige una cantidad de paquetes de corte entre `1` y `cantidadPaquetes - 1`, inclusive.
- Calcula la posición de corte:

  ```text
  posicionDeCorte = paquetesDeCorte × 2
  ```

- El hijo recibe el segmento inicial del primer padre y el segmento final del segundo.
- No dividas el bloque de un paquete.
- No modifiques los padres originales.

Aunque ambos padres sean válidos, el hijo puede superar la capacidad de algún camión.

### 🔄 Mutación y validación

- Realiza una única decisión de mutación por hijo.
- Si ocurre, elige un gen al azar e invierte su bit.
- Cada hijo cambia como máximo un gen durante la mutación.
- La probabilidad de mutación pertenece a `[0, 1]`.
- Para sorteos con `rand() % 100`, utiliza probabilidades expresables en pasos de `0.01`.
- Comprueba la validez después de mutar.
- Descarta los hijos inválidos sin repararlos ni generar reemplazos.

La mutación puede producir el código inválido `11` o una asignación que exceda la capacidad.

### 🧬 Clones y reemplazo

- Reúne la población actual y los hijos válidos.
- Elimina los cromosomas repetidos.
- Dos cromosomas son clones si coinciden en todos sus genes.
- Las distribuciones que solo intercambian los identificadores de camiones se consideran cromosomas distintos en este ejercicio.
- Ordena de menor a mayor cantidad de camiones utilizados.
- En caso de empate, puedes conservar cualquier orden.
- Conserva exactamente la cantidad inicial de individuos.
- Los individuos originales permanecen entre los candidatos al reemplazo.
- La mejor cantidad de camiones utilizados no debe aumentar entre generaciones.

### 🛠️ Organización y finalización

- Implementa una función para decodificar los bloques binarios.
- Separa la detección de aberraciones del cálculo de camiones utilizados.
- Reutiliza la selección por torneo y adapta los operadores de los ejercicios anteriores.
- Inicializa la semilla aleatoria una sola vez al comenzar la ejecución.
- Ejecuta todas las generaciones indicadas.
- Al finalizar, muestra el cromosoma, los paquetes de cada camión, su carga, su capacidad restante y la cantidad de camiones utilizados.
- No se permite resolver mediante fuerza bruta, backtracking ni programación dinámica.

El algoritmo busca distribuciones que utilicen pocos camiones, pero **no garantiza encontrar la cantidad mínima posible**.

⬅️ [Volver al nivel intermedio](..)