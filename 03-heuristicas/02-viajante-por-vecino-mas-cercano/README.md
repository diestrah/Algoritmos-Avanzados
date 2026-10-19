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

## 🗺️ Mapa de ciudades

```mermaid
flowchart TB
    C0((Ciudad 0))
    C1((Ciudad 1))
    C2((Ciudad 2))
    C3((Ciudad 3))
    C4((Ciudad 4))
    C5((Ciudad 5))

    C0 ---|10| C1
    C0 ---|15| C2
    C0 ---|20| C3
    C0 ---|25| C4
    C0 ---|30| C5

    C1 ---|35| C2
    C1 ---|12| C3
    C1 ---|28| C4
    C1 ---|40| C5

    C2 ---|30| C3
    C2 ---|9| C4
    C2 ---|11| C5

    C3 ---|8| C4
    C3 ---|22| C5

    C4 ---|18| C5

    classDef ciudad fill:#a9d7f5,stroke:#263238,stroke-width:2px,color:#000
    classDef origen fill:#f5a9a9,stroke:#263238,stroke-width:2px,color:#000

    class C1,C2,C3,C4,C5 ciudad
    class C0 origen

    linkStyle default stroke:#555,stroke-width:1px
```

- 🔴 **Ciudad roja:** punto de partida y regreso.
- 🔵 **Ciudades azules:** las demás ciudades que deben visitarse.
- **Líneas sin flechas:** conexiones que pueden recorrerse en ambos sentidos.
- **Número sobre cada conexión:** distancia entre las dos ciudades.

⬅️ [Volver al índice](..)
