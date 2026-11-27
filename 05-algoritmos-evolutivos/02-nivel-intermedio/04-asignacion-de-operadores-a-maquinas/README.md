# 🏭 Asignación de Operadores a Máquinas

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Algoritmo genético · 📐 **Representación:** Vector de asignaciones enteras

## 📝 Enunciado

Una empresa dispone de varios operadores y máquinas. La ganancia que produce cada operador depende de la máquina en la que trabaja.

Debes asignar cada operador a una única máquina para maximizar la ganancia total, cumpliendo que:

- Cada máquina tenga al menos un operador.
- Ninguna máquina supere su cantidad máxima de operadores.

Representa cada individuo mediante un vector de enteros. La posición representa al operador y el valor almacenado indica el índice de la máquina asignada.

Por ejemplo, para cinco operadores y tres máquinas:

```text
Cromosoma: [0, 2, 1, 0, 2]

Operador 1 → Maquina 1
Operador 2 → Maquina 3
Operador 3 → Maquina 2
Operador 4 → Maquina 1
Operador 5 → Maquina 3
```

Los índices internos comienzan en cero. **Una máquina puede aparecer varias veces** en el cromosoma: no es una permutación.

Implementa un algoritmo genético con selección por ruleta, cruce uniforme, mutación de una asignación, eliminación de clones y reemplazo de los mejores individuos.

Al finalizar, muestra únicamente la mejor asignación encontrada.

## 🧪 Ejemplo de ejecución

Para los siguientes rendimientos:

| Operador / Máquina | 1 | 2 | 3 |
|---|---:|---:|---:|
| 1 | 9 | 4 | 6 |
| 2 | 5 | 8 | 3 |
| 3 | 7 | 6 | 9 |
| 4 | 8 | 5 | 4 |
| 5 | 3 | 7 | 8 |

Y las capacidades:

| Máquina | 1 | 2 | 3 |
|---|---|---|---|
| Máximo de operadores | 2 | 2 | 2 |

Con los parámetros:

```text
Cantidad de individuos: 6
Cantidad de generaciones: 100
Tasa de seleccion: 0.8
Probabilidad de mutacion: 0.1
```

Una posible salida es:

```text
Mejor cromosoma encontrado: 0 1 2 0 2

Asignaciones:
Operador 1 -> Maquina 1 | Ganancia: 9
Operador 2 -> Maquina 2 | Ganancia: 8
Operador 3 -> Maquina 3 | Ganancia: 9
Operador 4 -> Maquina 1 | Ganancia: 8
Operador 5 -> Maquina 3 | Ganancia: 8

Ocupacion por maquina:
Maquina 1: 2 de 2 operadores
Maquina 2: 1 de 2 operadores
Maquina 3: 2 de 2 operadores

Ganancia total: 42
```

Los resultados pueden variar según la semilla y las elecciones aleatorias. No se exige obtener exactamente esta asignación.

## 🚧 Restricciones y suposiciones

- Hay al menos dos máquinas.
- La cantidad de operadores es mayor o igual que la cantidad de máquinas.
- La matriz de ganancias tiene una fila por operador y una columna por máquina.
- Las ganancias son enteros positivos.
- Las capacidades de las máquinas son enteros positivos.
- La suma de capacidades es suficiente para asignar a todos los operadores.
- Cada cromosoma tiene exactamente un gen por operador.
- Los valores permitidos van de `0` a `cantidadMaquinas - 1`.
- El tamaño de población es mayor o igual que dos.
- Existen suficientes asignaciones válidas distintas para completar la población.
- La población inicial y cada población resultante del reemplazo deben contener individuos válidos y distintos.

### 🌱 Población inicial

- Genera para cada operador un índice aleatorio de máquina.
- Comprueba la validez del cromosoma completo.
- Descarta las aberraciones y los cromosomas repetidos.
- Continúa hasta completar el tamaño de población indicado.

### 🚧 Aberraciones

Un individuo es una aberración si:

- Algún gen contiene un índice de máquina fuera del rango permitido.
- Alguna máquina no tiene operadores.
- Alguna máquina supera su capacidad máxima de operadores.

Comprueba los índices antes de utilizarlos para acceder a la matriz o al vector de capacidades.

### 🎯 Fitness y selección

- El fitness es la ganancia total de las asignaciones.
- Para cada operador, consulta la ganancia correspondiente a la máquina indicada por su gen.
- Selecciona padres mediante ruleta proporcional al fitness, utilizando acumulados.
- La selección es con reemplazo.
- Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion`.
- Elige una tasa en `(0, 1]` que produzca al menos dos padres.
- Todos los individuos válidos tienen fitness positivo.

### 🎲 Cruce uniforme

- Genera un hijo por cada pareja ordenada de índices distintos del vector de padres.
- Siempre se aplica el cruce.
- Para cada posición, el hijo recibe la asignación del primer o del segundo padre con probabilidad `0.5`.
- Realiza una decisión independiente por posición.
- No modifiques los padres originales.

El cruce mantiene los genes dentro del rango, pero puede dejar máquinas vacías o superar sus capacidades.

### 🔄 Mutación y validación

- Realiza una única decisión de mutación por hijo.
- Si ocurre, elige un operador al azar y cambia su asignación por otra máquina.
- La nueva máquina debe ser distinta de la actual y estar dentro del rango permitido.
- Cada hijo cambia como máximo una asignación.
- La probabilidad de mutación pertenece a `[0, 1]`.
- Para sorteos con `rand() % 100`, utiliza probabilidades expresables en pasos de `0.01`.
- No utilices la negación `!` para mutar: los genes representan índices de máquinas, no bits.
- Comprueba la validez después de mutar.
- Descarta los hijos inválidos sin repararlos ni generar reemplazos.

### 🧬 Clones y reemplazo

- Reúne la población actual y los hijos válidos.
- Elimina los cromosomas repetidos, conservando una copia de cada uno.
- Ordena de mayor a menor ganancia total.
- En caso de empate, puedes conservar cualquier orden.
- Conserva exactamente la cantidad inicial de individuos.
- Los individuos originales permanecen entre los candidatos al reemplazo.
- La mejor ganancia no debe disminuir entre generaciones.

### 🛠️ Organización y finalización

- Utiliza un vector para las capacidades y una matriz para las ganancias.
- Separa el cálculo de ocupación, la detección de aberraciones y la evaluación.
- Reutiliza y adapta la ruleta, el cruce uniforme, la eliminación de clones y el reemplazo.
- Inicializa la semilla aleatoria una sola vez al comenzar la ejecución.
- Ejecuta todas las generaciones indicadas.
- Al finalizar, muestra el cromosoma, la asignación de cada operador, la ocupación de las máquinas y la ganancia total.
- No se permite resolver mediante fuerza bruta, backtracking ni programación dinámica.

El algoritmo busca buenas asignaciones, pero **no garantiza encontrar la de mayor ganancia posible**.

⬅️ [Volver al nivel intermedio](..)