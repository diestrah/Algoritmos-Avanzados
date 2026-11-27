# 🪚 Corte de Barras con Prioridades de Desperdicio

🔴 **Dificultad:** Avanzada · 🧠 **Técnica:** GRASP construcción y algoritmo genético · 📐 **Representación:** Vector entero de asignación de piezas a barras

## 📝 Enunciado

Una empresa debe cortar un conjunto de piezas utilizando barras de longitud `L`. Dispone de `cantidadBarras` barras completas.

Cada pieza debe obtenerse de una única barra y la suma de longitudes asignadas a una barra no puede superar `L`.

Debes encontrar una distribución que priorice:

1. **Minimizar la cantidad de barras utilizadas que quedan incompletas.**
2. En caso de empate, **minimizar el desperdicio total de las barras utilizadas**.

Representa cada individuo mediante un vector de enteros. La posición identifica una pieza y el valor indica la barra de la que se obtiene.

Implementa un algoritmo genético con inicialización mediante GRASP, selección por torneo, cruce uniforme, mutación de una asignación, eliminación de clones y reemplazo elitista.

Al finalizar, muestra únicamente la mejor distribución encontrada.

## 🧪 Ejemplo de ejecución

Para barras de longitud `10`, seis barras disponibles y las piezas:

```text
Pieza:     1  2  3  4  5  6
Longitud:  6  4  7  3  5  2
```

Con los parámetros:

```text
Cantidad de individuos: 10
Cantidad de generaciones: 100
Alfa: 0.3
Tasa de seleccion: 0.8
Tamano de torneo: 3
Probabilidad de mutacion: 0.1
```

Una posible salida es:

```text
Mejor cromosoma encontrado: 0 0 1 1 2 2

Barra 1:
Piezas: 1 2
Longitud utilizada: 10
Desperdicio: 0

Barra 2:
Piezas: 3 4
Longitud utilizada: 10
Desperdicio: 0

Barra 3:
Piezas: 5 6
Longitud utilizada: 7
Desperdicio: 3

Barras sin utilizar: 4 5 6
Barras utilizadas: 3
Barras incompletas: 1
Desperdicio total: 3
```

Los resultados pueden variar según la semilla y las elecciones aleatorias.

## 🚧 Restricciones y suposiciones

- Hay al menos dos piezas y dos barras.
- Las longitudes son enteros positivos.
- Cada pieza tiene longitud menor o igual que `L`.
- Las piezas son indivisibles y deben atenderse todas.
- No se considera el grosor perdido por el corte.
- Los sobrantes no se reutilizan en pedidos posteriores.
- Una barra vacía no se considera incompleta y no aporta desperdicio.
- Una barra es incompleta si su longitud utilizada está estrictamente entre `0` y `L`.
- Los datos admiten una distribución factible.
- Utiliza datos y un tamaño de población que permitan obtener suficientes construcciones GRASP distintas.

### 🌱 Inicialización mediante GRASP

Construye cada individuo desde cero:

1. Mantén las piezas pendientes y la capacidad restante de cada barra.
2. Forma candidatos `(pieza, barra)` que respeten la capacidad.
3. Evalúa cada candidato mediante el espacio que quedaría en la barra después de asignar la pieza:

   ```text
   espacioRestante = capacidadRestante - longitudPieza
   ```

4. Favorece los candidatos con menor espacio restante:

   ```text
   umbral = espacioMinimo + alfa × (espacioMaximo - espacioMinimo)

   RCL = candidatos con espacioRestante <= umbral
   ```

5. Elige un candidato aleatorio de la RCL.
6. Asigna la pieza y actualiza la capacidad.
7. Repite hasta asignar todas las piezas.

Si quedan piezas pendientes y no existen candidatos factibles, descarta la construcción completa y comienza otra.

Rechaza cromosomas repetidos hasta completar la población. No se aplica búsqueda local.

### 🚧 Aberraciones

Un individuo es una aberración si:

- Algún gen contiene un índice de barra fuera de rango.
- La suma de longitudes de alguna barra supera `L`.

Cada posición representa una pieza, por lo que su asignación es única por construcción.

### 🎯 Evaluación y selección

Para cada barra utilizada, calcula:

```text
desperdicioBarra = L - longitudUtilizada
```

La evaluación contiene:

- Cantidad de barras incompletas.
- Suma del desperdicio de las barras utilizadas.

Compara ambos valores por prioridad:

- Primero gana la menor cantidad de barras incompletas.
- Si empatan, gana el menor desperdicio.
- En un empate completo, puedes conservar cualquier orden.

No sumes ambos criterios sin justificar sus prioridades.

Selecciona padres mediante torneo con reemplazo, utilizando este mismo comparador. En un empate completo dentro del torneo, conserva al primer participante sorteado.

Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion` y utiliza parámetros que produzcan al menos dos padres.

### 🎲 Cruce y mutación

- Genera un hijo por cada pareja ordenada de índices distintos del vector de padres.
- Aplica siempre cruce uniforme.
- Cada gen se hereda del primer o del segundo padre con probabilidad `0.5`.
- Con la probabilidad de mutación indicada, elige una pieza y asígnala a otra barra distinta.
- Cada hijo cambia como máximo una asignación.
- Comprueba la validez después de mutar.
- Descarta los hijos inválidos sin repararlos ni generar reemplazos.

### 🧬 Clones y reemplazo

- Reúne la población actual y los hijos válidos.
- Elimina cromosomas idénticos.
- Las distribuciones que intercambian identificadores de barras se consideran cromosomas distintos.
- Ordena utilizando las dos prioridades de evaluación.
- Conserva exactamente el tamaño inicial de población.
- Los individuos originales permanecen disponibles para el reemplazo.
- La mejor evaluación no debe empeorar entre generaciones.

### 🛠️ Organización y finalización

- Separa el cálculo de carga por barra, la detección de aberraciones y la evaluación.
- Utiliza una estructura para guardar ambos criterios de evaluación.
- Reutiliza el comparador en el torneo y el reemplazo.
- Inicializa la semilla aleatoria una sola vez.
- Ejecuta todas las generaciones indicadas.
- Muestra las piezas por barra, las longitudes utilizadas, los sobrantes y los dos criterios finales.
- Para sorteos con `rand() % 100`, utiliza probabilidades en pasos de `0.01`.
- No se permite fuerza bruta, backtracking ni programación dinámica.

El algoritmo busca buenas distribuciones, pero **no garantiza encontrar la mejor según ambas prioridades**.

⬅️ [Volver al nivel avanzado](..)