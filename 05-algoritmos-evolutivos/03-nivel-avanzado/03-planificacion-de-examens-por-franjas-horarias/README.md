# 📅 Planificación de Exámenes por Franjas Horarias

🔴 **Dificultad:** Avanzada · 🧠 **Técnica:** GRASP construcción y algoritmo genético · 📐 **Representación:** Bloques binarios de asignación

## 📝 Enunciado

Una universidad debe asignar sus exámenes a un conjunto de franjas horarias. Dos exámenes tienen conflicto si comparten al menos un estudiante.

Debes asignar cada examen a una única franja, buscando **minimizar la cantidad de pares de exámenes conflictivos programados en la misma franja**.

Representa cada individuo mediante un vector binario dividido en bloques. Cada bloque codifica la franja asignada a un examen:

```text
bitsPorExamen = ceil(log2(cantidadFranjas))
```

Implementa un algoritmo genético cuya población inicial provenga de construcciones GRASP. Utiliza torneo, cruce por bloques, mutación de un bit, eliminación de clones y reemplazo elitista.

Al finalizar, muestra únicamente la mejor planificación encontrada.

## 🧪 Ejemplo de ejecución

Para cinco exámenes, tres franjas y la siguiente matriz de conflictos:

```text
0 1 1 0 0
1 0 1 0 0
1 1 0 1 0
0 0 1 0 1
0 0 0 1 0
```

La codificación utiliza dos bits por examen:

```text
00 → Franja 0
01 → Franja 1
10 → Franja 2
11 → Codigo invalido
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
Mejor cromosoma encontrado:
00 | 01 | 10 | 00 | 01

Asignaciones:
Examen 1 -> Franja 0
Examen 2 -> Franja 1
Examen 3 -> Franja 2
Examen 4 -> Franja 0
Examen 5 -> Franja 1

Pares de examenes en conflicto: 0
```

Los resultados pueden variar según la semilla y las elecciones aleatorias.

## 🚧 Restricciones y suposiciones

- Hay al menos dos exámenes y dos franjas.
- La matriz de conflictos es simétrica, binaria y tiene diagonal cero.
- Cada examen se asigna a exactamente una franja.
- Las franjas tienen capacidad ilimitada y no se consideran aulas.
- Los conflictos son parte de la evaluación; no invalidan el cromosoma.
- Cada cromosoma contiene `cantidadExamenes × bitsPorExamen` genes binarios.
- Utiliza datos y un tamaño de población que permitan obtener suficientes construcciones GRASP distintas.

### 🌱 Inicialización mediante GRASP

Construye cada planificación desde cero:

1. Mantén una lista de exámenes pendientes.
2. Evalúa cada examen pendiente mediante su cantidad total de conflictos con los demás exámenes.
3. Forma una RCL con los exámenes de mayor evaluación:

   ```text
   umbral = evaluacionMaxima - alfa × (evaluacionMaxima - evaluacionMinima)
   ```

4. Elige aleatoriamente un examen de la RCL.
5. Para cada franja, cuenta cuántos conflictos produciría asignarle ese examen respecto a los exámenes ya programados.
6. Escoge una franja que produzca el menor incremento de conflictos; desempata aleatoriamente.
7. Repite hasta asignar todos los exámenes.
8. Convierte las asignaciones a bloques binarios.

Repite las construcciones y rechaza cromosomas repetidos hasta completar la población. No se aplica búsqueda local.

### 🚧 Aberraciones

Un individuo es una aberración si:

- Su longitud no corresponde a la codificación.
- Contiene valores diferentes de `0` y `1`.
- Algún bloque representa una franja inexistente.

Comprueba los códigos antes de utilizarlos como índices.

### 🎯 Evaluación y selección

- Cuenta cada par conflictivo una sola vez, recorriendo pares de exámenes con `i < j`.
- Un par suma un conflicto si ambos exámenes comparten estudiantes y están en la misma franja.
- Una cantidad menor de conflictos representa una solución mejor.
- Selecciona padres mediante torneo con reemplazo.
- En caso de empate, conserva al primer participante sorteado.
- Calcula la cantidad de padres redondeando `cantidadIndividuos × tasaSeleccion`.
- Elige parámetros que produzcan al menos dos padres.

### ✂️ Cruce y mutación

- Genera un hijo por cada pareja ordenada de índices distintos del vector de padres.
- Aplica siempre cruce de un punto entre bloques completos.
- Elige el corte después de al menos un examen y antes del último:

  ```text
  posicionDeCorte = examenesDeCorte × bitsPorExamen
  ```

- El hijo recibe el segmento inicial del primer padre y el final del segundo.
- Con la probabilidad de mutación indicada, elige un bit del hijo e inviértelo.
- Cada hijo cambia como máximo un bit durante la mutación.
- Valida después de mutar y descarta los hijos inválidos.

### 🧬 Clones y reemplazo

- Reúne la población actual y los hijos válidos.
- Elimina cromosomas idénticos.
- Las asignaciones que solo intercambian los identificadores de franjas se consideran cromosomas distintos.
- Ordena de menor a mayor cantidad de conflictos.
- Conserva exactamente el tamaño inicial de población.
- En caso de empate, puedes conservar cualquier orden.
- Los individuos originales permanecen disponibles para el reemplazo.
- La mejor cantidad de conflictos no debe aumentar entre generaciones.

### 🛠️ Organización y finalización

- Separa la construcción GRASP, la codificación, la decodificación y la evaluación.
- Inicializa la semilla aleatoria una sola vez.
- Ejecuta todas las generaciones indicadas.
- Muestra el cromosoma, la franja de cada examen y la cantidad total de conflictos.
- Si existen conflictos, muestra también los pares de exámenes involucrados.
- Para sorteos con `rand() % 100`, utiliza probabilidades en pasos de `0.01`.
- No se permite fuerza bruta, backtracking ni programación dinámica.

El algoritmo busca reducir conflictos, pero **no garantiza encontrar una planificación sin conflictos**, aunque exista.

⬅️ [Volver al nivel avanzado](..)