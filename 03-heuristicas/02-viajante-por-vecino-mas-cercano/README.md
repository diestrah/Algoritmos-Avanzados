## 🧪 Ejemplo de ejecución

Para la siguiente matriz de distancias entre 6 ciudades (`0` a `5`), partiendo de la ciudad `0`:

```text
     0   1   2   3   4   5
0    0  10  15  20  25  30
1   10   0  35  12  28  40
2   15  35   0  30   9  11
3   20  12  30   0   8  22
4   25  28   9   8   0  18
5   30  40  11  22  18   0
```

Los números de la primera fila y de la primera columna identifican las ciudades; no forman parte de la matriz.

El programa debería imprimir:

```text
Ruta: 0 -> 1 -> 3 -> 4 -> 2 -> 5 -> 0
Distancia total: 80
```

## 🗺️ Mapa del recorrido

```mermaid
flowchart LR
    C0((0)) ---|10| C1((1))
    C1 ---|12| C3((3))
    C3 ---|8| C4((4))
    C4 ---|9| C2((2))
    C2 ---|11| C5((5))
    C5 ---|30| C0

    classDef ciudad fill:#a9d7f5,stroke:#263238,color:#000
    classDef origen fill:#f5a9a9,stroke:#263238,color:#000
    class C1,C2,C3,C4,C5 ciudad
    class C0 origen
```

El nodo rojo indica la ciudad inicial. Se muestran únicamente las conexiones del recorrido; la matriz contiene todas las distancias.

⬅️ [Volver al índice](..)
