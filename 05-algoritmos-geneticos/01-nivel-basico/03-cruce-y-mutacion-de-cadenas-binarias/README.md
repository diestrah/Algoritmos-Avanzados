# 🧬 Cruce y Mutación de Cadenas Binarias

🟢 **Dificultad:** Básica · 🧠 **Técnica:** Operadores genéticos · 📐 **Representación:** Vectores binarios

## 📝 Enunciado

Una vez seleccionados los padres, un algoritmo genético puede combinar sus genes para producir hijos y modificar algunos genes para introducir diversidad.

Dados dos cromosomas binarios de igual longitud, implementa los siguientes operadores:

- **Cruce de un punto:** elige aleatoriamente un punto de corte y genera un hijo con el segmento inicial del padre y el segmento final de la madre.
- **Cruce uniforme:** genera un hijo eligiendo aleatoriamente, para cada posición, si hereda el gen del padre o de la madre.
- **Mutación de bits:** recorre un cromosoma e invierte cada gen con una probabilidad determinada.

Aplica cada tipo de cruce por separado sobre los **mismos padres**. Cada llamada debe realizar el cruce y devolver un único hijo. Después, aplica la mutación al hijo obtenido.

El programa debe mostrar los padres y, para cada tipo de cruce, el hijo antes y después de mutar. Para el cruce de un punto, muestra también el punto de corte utilizado.

## 🧪 Ejemplo de ejecución

Para los siguientes padres:

```text
Padre: 1 1 0 0 1 0
Madre: 0 0 1 1 0 1
```

Con `PROB_MUTAR = 0.1`, una posible salida es:

```text
Cruce de un punto:
Punto de corte: 2

Antes de mutar:
1 1 1 1 0 1

Despues de mutar:
1 1 1 0 0 1

Cruce uniforme:

Antes de mutar:
1 0 0 1 1 1

Despues de mutar:
1 0 0 1 1 1
```

Un punto de corte igual a `2` significa que los primeros dos genes se toman del padre y los restantes de la madre.

Los resultados pueden variar según la semilla y las elecciones aleatorias. La mutación puede cambiar varios genes, uno solo o ninguno.

## 🚧 Restricciones y suposiciones

- Los padres tienen la misma longitud y contienen únicamente valores `0` o `1`.
- La cantidad de genes es mayor o igual que dos.
- Puedes definir los padres directamente en el programa para facilitar las pruebas.
- Los operadores no deben modificar los cromosomas originales de los padres.
- Cada llamada a una función de cruce devuelve exactamente un hijo con la misma longitud que sus padres.
- Siempre se aplica el cruce: en este ejercicio no se utiliza una probabilidad para decidir si ocurre.
- El hijo puede coincidir con alguno de los padres; no se exige que sea diferente.
- `PROB_MUTAR` pertenece al intervalo `[0, 1]`.
- Para los sorteos con `rand() % 100`, utiliza probabilidades expresables en pasos de `0.01`.

### 🧩 Cruce de un punto

- El punto de corte se elige uniformemente entre `1` y `cantidadGenes - 1`, inclusive.
- El hijo recibe los genes anteriores al corte del padre y los genes desde el corte de la madre.

### 🎲 Cruce uniforme

- Para cada posición, elige con probabilidad `0.5` si el hijo recibe el gen del padre o de la madre.
- Realiza una decisión nueva para cada posición.
- Esta probabilidad determina el origen de cada gen; el operador de cruce siempre se aplica.

### 🔄 Mutación

- Evalúa cada gen del hijo de manera independiente.
- Si un gen muta, cambia `0` por `1` o `1` por `0`.
- Con probabilidad `0`, ningún gen cambia.
- Con probabilidad `1`, todos los genes se invierten.
- Una probabilidad de `0.1` no obliga a modificar exactamente el 10 % de los genes.

### 🛠️ Organización

- Implementa funciones separadas para el cruce de un punto, el cruce uniforme y la mutación.
- Reutiliza la función de impresión de individuos.
- Mantén la impresión separada de la mutación.
- Inicializa la semilla aleatoria una sola vez al comenzar el programa.
- En este ejercicio no se aplican selección de padres, reemplazo ni evolución por generaciones.

Los operadores introducen nuevas combinaciones, pero **no garantizan que el hijo tenga mejor fitness que sus padres**.

⬅️ [Volver al nivel básico](..)