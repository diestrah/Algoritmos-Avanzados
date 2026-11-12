# ▶️ Compilación y ejecución

Cada ejercicio es un proyecto independiente de C++ y contiene su propio `CMakeLists.txt`.

## 🧰 Requisitos

- Un compilador de C++ compatible con el estándar indicado en el proyecto.
- CMake, con la versión mínima especificada en `CMakeLists.txt`.

## 💻 Desde CLion

1. Abre la carpeta del ejercicio como proyecto.
2. Espera a que CLion configure CMake.
3. Selecciona el ejecutable en el menú de configuraciones.
4. Pulsa **Ejecutar**.

Si el ejercicio incluye varias versiones, cada una aparecerá como un ejecutable independiente.

## ⌨️ Desde la terminal

Ubícate en la carpeta del ejercicio y ejecuta:

```sh
cmake -S . -B build
cmake --build build
```

Los ejecutables se generan en la carpeta `build` o en una subcarpeta de configuración, como `build/Debug`, según el entorno.

Para el ejercicio de mochila con dos versiones, puedes compilar cada una por separado:

```sh
cmake --build build --target mochila_rcl_indices
cmake --build build --target mochila_ordenamiento
```

Desde PowerShell, si los ejecutables están directamente en `build`:

```powershell
.\build\mochila_rcl_indices.exe
.\build\mochila_ordenamiento.exe
```

En Linux o macOS:

```sh
./build/mochila_rcl_indices
./build/mochila_ordenamiento
```

Sustituye los nombres por los destinos definidos en el `CMakeLists.txt` del ejercicio.

## 🧩 Ejercicios con varias versiones

Cada archivo que contiene `main()` corresponde a un ejecutable diferente. Las versiones se ejecutan por separado; no deben combinarse en un único ejecutable.

Consulta el README del ejercicio para conocer las diferencias entre implementaciones.
