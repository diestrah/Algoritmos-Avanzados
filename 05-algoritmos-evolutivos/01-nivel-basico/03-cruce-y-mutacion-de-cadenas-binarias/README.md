# 🧬 Cruce y Mutación de Cadenas Binarias

🟢 **Dificultad:** Básica · 🧠 **Técnica:** Operadores genéticos · 📐 **Representación:** Vectores binarios

## 📝 Enunciado

Una vez seleccionados los padres, un algoritmo genético puede combinar sus genes para producir hijos y modificar algunos genes para introducir diversidad.

Dados dos cromosomas binarios de igual longitud, implementa los siguientes operadores:

- **Cruce de un punto:** elige aleatoriamente un punto de corte e intercambia los segmentos finales de los padres para generar dos hijos.
- **Cruce uniforme:** para cada posición, decide aleatoriamente qué padre aporta el gen al primer hijo. El segundo hijo recibe el gen del otro padre.
- **Mutación de bits:** recorre un cromosoma e invierte cada gen con una probabilidad determinada.

Aplica cada tipo de cruce por separado sobre los **mismos padres**. Después, aplica la mutación a los hijos obtenidos.

El programa debe mostrar los padres, los hijos antes de mutar y los hijos después de mutar. Para el cruce de un punto, muestra también el punto de corte utilizado.

## 🧪 Ejemplo de ejecución

Para los siguientes padres:

```text
Padre 1: 1 1 0 0 1 0
Padre 2: 0 0 1 1 0 1
```

Con `probabilidadCruce = 1.0` y `probabilidadMutacion = 0.1`, una posible salida es:

```text
Cruce de un punto:

Punto de corte: 2

Hijo 1 antes de mutar:   1 1 1 1 0 1
Hijo 2 antes de mutar:   0 0 0 0 1 0

Hijo 1 despues de mutar: 1 1 1 0 0 1
Hijo 2 despues de mutar: 0 0 0 0 1 0

Cruce uniforme:

Hijo 1 antes de mutar:   1 0 0 1 1 1
Hijo 2 antes de mutar:   0 1 1 0 0 0

Hijo 1 despues de mutar: 1 0 0 1 1 1
Hijo 2 despues de mutar: 0 1 0 0 0 0
```

Un punto de corte igual a `2` significa que los primeros dos genes se conservan del padre correspondiente y los restantes se toman del otro.

Los resultados pueden variar según la semilla y las elecciones aleatorias. La mutación puede cambiar varios genes, uno solo o ninguno.

## 🚧 Restricciones y suposiciones

- Los padres tienen la misma longitud y contienen únicamente valores `0` o `1`.
- La cantidad de genes es mayor o igual que dos.
- Puedes definir los padres directamente en el programa para facilitar las pruebas.
- Los operadores no deben modificar los cromosomas originales de los padres.
- Cada cruce produce exactamente dos hijos con la misma longitud que sus padres.
- `probabilidadCruce` y `probabilidadMutacion` pertenecen al intervalo `[0, 1]`.

### ✂️ Probabilidad de cruce

- Realiza una decisión aleatoria por pareja para determinar si ocurre el cruce.
- Si no ocurre, los hijos son copias de sus respectivos padres.
- Con probabilidad `0`, nunca se realiza el cruce; con probabilidad `1`, siempre se realiza.
- Aplica la mutación a los hijos incluso si no hubo cruce.

### 🧩 Cruce de un punto

- El punto de corte se elige uniformemente entre `1` y `cantidadGenes - 1`, inclusive.
- El primer hijo recibe el segmento inicial del primer padre y el segmento final del segundo.
- El segundo hijo recibe los segmentos complementarios.

### 🎲 Cruce uniforme

- Para cada posición, elige con probabilidad `0.5` cuál de los padres aporta su gen al primer hijo.
- El segundo hijo recibe, en esa posición, el gen del otro padre.
- Realiza una decisión nueva para cada posición.
- Esta probabilidad de herencia es distinta de la probabilidad de que ocurra el cruce.

### 🔄 Mutación

- Evalúa cada gen de cada hijo de manera independiente.
- Si un gen muta, cambia `0` por `1` o `1` por `0`.
- Con probabilidad `0`, ningún gen cambia.
- Con probabilidad `1`, todos los genes se invierten.
- Una probabilidad de `0.1` no obliga a modificar exactamente el 10 % de los genes.

### 🛠️ Organización

- Implementa funciones separadas para el cruce de un punto, el cruce uniforme y la mutación.
- Reutiliza la función de impresión de individuos.
- Inicializa la semilla aleatoria una sola vez al comenzar el programa.
- En este ejercicio no se aplican selección de padres, reemplazo ni evolución por generaciones.

Los operadores introducen nuevas combinaciones, pero **no garantizan que los hijos tengan mejor fitness que sus padres**.

⬅️ [Volver al nivel básico](..)