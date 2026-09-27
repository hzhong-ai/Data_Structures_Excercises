# 🎯 Data Structures Exercises (C / C++)

Bienvenido a **Data Structures Exercises**. Este repositorio es un laboratorio de prácticas y evaluación en C/C++ enfocado en la resolución de problemas de estructuras de datos y la depuración de errores de memoria.

---

## 📌 Tipos de Problemas

Los ejercicios están divididos en tres categorías principales según su sufijo:

1. **`_soluc.cpp` / `_soluc.c` (Implementación)**:

   * **Objetivo:** Construir desde cero la lógica o completar funciones faltantes indicadas por marcadores `// TODO:` o `// Hint:`.
   * **Enfoque:** Correcto manejo de memoria dinámica, destructores, reasignación de punteros y algoritmos clásicos.

2. **`_correg.cpp` / `_correg.c` (Depuración / Bug Fix)**:

   * **Objetivo:** Identificar y reparar un fallo sutil en un código parcialmente funcional.
   * **Enfoque:** Resolver fugas de memoria (*Memory Leaks*), copias superficiales (*Shallow Copy*), liberaciones dobles (*Double Free*) o accesos fuera de rango (*Underflow/Overflow*).

3. **`C_Parlante_Problems/` (Problemas de Nick Parlante — C puro)**:

   * **Objetivo:** 18 ejercicios clásicos de manipulación de listas enlazadas en C, basados en el documento *"Linked List Problems"* de Stanford CS Education Library.
   * **Enfoque:** Dominar punteros dobles (`**headRef`), reconexión de nodos, algoritmos de merge/split y recursión sobre listas.

---

> ℹ️ **Nota sobre la estructura de directorios (`.gitkeep`):**
> Dado que Git no rastrea carpetas vacías por defecto, las subcarpetas destinadas a almacenar soluciones (`01_Prob1Sol/`, `03A_Prob1Sol/`, etc.) contienen un archivo oculto `.gitkeep`. Su única función es preservar la jerarquía de directorios en el repositorio remoto mientras se agregan los archivos de solución.

---

## ⚙️ Compilación y Testing

Cada sección del repositorio cuenta con un **`Makefile`** preconfigurado que permite compilar y ejecutar las pruebas automáticamente.

### Comandos disponibles

| Comando | Descripción |
|---|---|
| `make` | Compila todos los ejercicios de la sección |
| `make test` | Compila y ejecuta todos los ejercicios (verifica que los `assert` pasen) |
| `make valgrind` | *(Solo C_Parlante_Problems)* Ejecuta Valgrind para detectar fugas de memoria |
| `make clean` | Elimina los binarios generados |

### Ejemplo de uso

```bash
# Entrar a cualquier sección
cd 01_Especificaciones_y_Reglas

# Compilar y correr todas las pruebas
make test

# Si todo pasa, verás:
# Running 01_regla_de_tres_correg...
# Running 03_copia_superficial_double_free_correg...
# All tests passed!
```

Para la sección de **Parlante Problems** (C puro):

```bash
cd 03_Listas_Enlazadas/C_Parlante_Problems

# Compilar y testear los 18 problemas
make test

# Verificar que no haya memory leaks
make valgrind
```

### Verificación individual (sin Makefile)

También puedes compilar y ejecutar un solo archivo manualmente:

```bash
# C++ (secciones 01, 02, 03-A, 03-B)
g++ -std=c++17 -Wall -Wextra archivo.cpp -o run && ./run

# C (sección C_Parlante_Problems)
gcc -std=c17 -Wall -Wextra archivo.c -o run && ./run
```

Si los `assert()` no fallan y el programa termina sin errores, tu solución es correcta.

---

## 🛠️ Flujo de Trabajo: Resolver, Testear y Subir Soluciones

### 1. Configuración Inicial (solo la primera vez)

```bash
# Clonar el repositorio
git clone https://github.com/TU_USUARIO/Data_Structures_Exercises.git
cd Data_Structures_Exercises
```

### 2. Resolver un ejercicio

```bash
# Navegar a la sección
cd 03_Listas_Enlazadas/B_Listas_Dobles

# Abrir el ejercicio en tu editor favorito
nvim 01_lista_doble_prev_correg.cpp
```

### 3. Testear tu solución

```bash
# Opción A: Correr TODOS los tests de la sección con el Makefile
make test

# Opción B: Compilar y ejecutar solo tu archivo
g++ -std=c++17 -Wall -Wextra 01_lista_doble_prev_correg.cpp -o run && ./run
```

### 4. Copiar la solución a la carpeta de entrega

```bash
# Copiar el archivo resuelto a la carpeta correspondiente
cp 01_lista_doble_prev_correg.cpp 03B_Prob1Sol/
```

### 5. Subir tus cambios

```bash
# Crear una rama para tu solución
git checkout -b solucion-03B-prob1

# Agregar la carpeta de solución (evita subir binarios)
git add 03B_Prob1Sol/

# Crear el commit
git commit -m "soluc: corrección de punteros prev en 03B_Prob1Sol"

# Subir al remoto
git push origin solucion-03B-prob1

# Crear el Pull Request (opcional, requiere GitHub CLI)
gh pr create --title "soluc: entrega ejercicio 03B Prob1" \
  --body "Solución validada con assert y make test."
```

---

## 🤝 Contribuciones

¡Las contribuciones son bienvenidas! Si deseas agregar nuevas soluciones o corregir algún error:

1. Haz un **Fork** de este repositorio.
2. Crea una rama para tu aporte (`git checkout -b feature/nueva-solucion`).
3. Asegúrate de que **`make test` pase sin errores** en la sección correspondiente.
4. Haz un **Commit** de tus cambios (`git commit -m "feat: agrega solucion X"`).
5. Haz un **Push** a la rama (`git push origin feature/nueva-solucion`).
6. Abre un **Pull Request**.

## 📁 Estructura del Repositorio

```text
.
├── 📁 01_Especificaciones_y_Reglas/
│   ├── Makefile
│   ├── 01_Prob1Sol/
│   ├── 02_Prob2Sol/
│   ├── 03_Prob3Sol/
│   ├── 04_Prob4Sol/
│   ├── 01_regla_de_tres_correg.cpp
│   ├── 02_regla_de_cinco_movimiento_soluc.cpp
│   ├── 03_copia_superficial_double_free_correg.cpp
│   └── 04_ejercicio_regla_de_cinco_sol.cpp
├── 📁 02_Stack_y_Colas/
│   ├── Makefile
│   ├── 02_Prob1Sol/
│   ├── 02_Prob2Sol/
│   ├── 02_Prob3Sol/
│   ├── 02_Prob4Sol/
│   ├── 01_stack_underflow_correg.cpp
│   ├── 02_stack_dynamic_resize_soluc.cpp
│   ├── 03_queue_circular_reallocate_soluc.cpp
│   └── 04_queue_head_tail_bug_correg.cpp
├── 📁 03_Listas_Enlazadas/
│   ├── 📁 A_Listas_Simples/
│   │   ├── Makefile
│   │   ├── 03A_Prob1Sol/ ... 03A_Prob4Sol/
│   │   ├── 01_sorted_insert_soluc.cpp
│   │   ├── 02_singly_pop_back_soluc.cpp
│   │   ├── 03_detect_cycle_floyd_soluc.cpp
│   │   └── 04_wrong_push_leak_correg.cpp
│   ├── 📁 B_Listas_Dobles/
│   │   ├── Makefile
│   │   ├── 03B_Prob1Sol/ ... 03B_Prob3Sol/
│   │   ├── 01_lista_doble_prev_correg.cpp
│   │   ├── 02_doubly_erase_node_soluc.cpp
│   │   └── 03_double_insert_sort_correg.cpp
│   └── 📁 C_Parlante_Problems/
│       ├── Makefile
│       ├── Node.h
│       ├── 01_count_correg.c
│       ├── 02_get_nth_correg.c
│       ├── 03_delete_list_correg.c
│       ├── ...
│       └── 18_recursive_reverse_correg.c
└── 📄 README.md
```
