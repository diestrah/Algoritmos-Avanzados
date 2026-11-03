# 💽 Asignación de Tablas a Discos

🟡 **Dificultad:** Intermedia · 🧠 **Técnica:** Construcción voraz aleatorizada con múltiples inicios · 📐 **Representación:** Vectores de tablas y discos

## 📝 Enunciado

Un administrador de bases de datos debe distribuir un conjunto de tablas entre varios discos.

Cada tabla requiere espacio de almacenamiento y una cantidad de operaciones de entrada/salida por segundo (**IOPS**). 
Cada disco dispone de espacio e IOPS disponibles. Al asignar una tabla, ambos recursos disminuyen según sus 
requerimientos.

Se busca distribuir las tablas evitando que algún disco quede con muy pocos IOPS disponibles. Para evaluar una 
asignación completa, se toma **la menor cantidad de IOPS restantes entre todos los discos**. Cuanto mayor sea ese 
valor, mejor será la asignación.

Por ejemplo:

| Asignación | IOPS restantes por disco | Valor de evaluación |
|---|---|---|
| A | `[30, 60, 50]` | 30 |
| B | `[50, 50, 40]` | 40 |

**Se prefiere B:** todos sus discos conservan al menos `40` IOPS, mientras que en A uno de ellos solo conserva `30`.

Implementa un procedimiento que construya distintas asignaciones mediante **dos listas restringidas de candidatos (RCL)**: una para seleccionar la tabla y otra para seleccionar el disco que la recibirá.

Debes identificar y justificar el criterio de evaluación de cada lista. Ambas elecciones deben realizarse aleatoriamente entre sus respectivos candidatos, utilizando el mismo parámetro de relajación `α`.

Realiza varias construcciones y conserva la asignación completa con el **mayor valor de evaluación**, sin aplicar búsqueda local.

## 🧪 Ejemplo de ejecución

Para las siguientes tablas:

| Tabla | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|
| Espacio requerido (GB) | 20 | 10 | 15 | 100 | 50 | 100 |
| IOPS requeridos | 150 | 100 | 80 | 50 | 120 | 10 |

Y los siguientes discos:

| Disco | 1 | 2 | 3 |
|---|---|---|---|
| Capacidad (GB) | 800 | 750 | 850 |
| IOPS disponibles | 250 | 200 | 200 |

Con `α = 0.5` y `1000` iteraciones, una posible salida es:

```text
Alfa: 0.5
Iteraciones: 1000

Disco 1:
Tablas asignadas: [3, 5]
Espacio disponible: 735 GB
IOPS restantes: 50

Disco 2:
Tablas asignadas: [1]
Espacio disponible: 730 GB
IOPS restantes: 50

Disco 3:
Tablas asignadas: [2, 4, 6]
Espacio disponible: 640 GB
IOPS restantes: 40

Menor cantidad de IOPS restantes: 40
```

El resultado y el orden de asignación pueden variar según el criterio, la semilla y el generador aleatorio utilizados.

## 🚧 Restricciones y suposiciones

- Identifica y justifica los **criterios de evaluación de ambas RCL**.
- Hay al menos un disco; los requerimientos y recursos iniciales son enteros positivos.
- Cada tabla es indivisible y debe asignarse exactamente una vez, respetando espacio e IOPS disponibles.
- La RCL de tablas solo incluye pendientes que quepan en algún disco; la de discos, destinos factibles para la tabla elegida.
- Cada construcción comienza con los recursos originales y actualiza ambas RCL según el estado actual.
- `α` pertenece a `[0, 1]`; las iteraciones son positivas y la semilla se inicializa una sola vez.
- Descarta asignaciones incompletas y conserva la de mayor valor de evaluación; en empate, mantén la primera.
- Si no encuentras una asignación completa, informa ese resultado.
- No se permite fuerza bruta, backtracking, programación dinámica ni búsqueda local.

⬅️ [Volver al índice](..)