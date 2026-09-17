# 🎯 Data Structures Exercises (C++)

Bienvenido a **Data Structures Exercises**. Este repositorio es un laboratorio de prácticas y evaluación en C++ enfocado en la resolución de problemas de estructuras de datos y la depuración de errores de memoria.

---

## 📌 Tipos de Problemas

Los ejercicios están divididos en dos categorías principales según su sufijo:

1. **`_sol.cpp` (Implementación)**:

   * **Objetivo:** Construir desde cero la lógica o completar funciones faltantes indicadas por marcadores `// TODO:` o `// pon tu codigo aqui`.
   * **Enfoque:** Correcto manejo de memoria dinámica, destructores, reasignación de punteros y algoritmos clásicos.

2. **`_correg.cpp` (Depuración / Bug Fix)**:

   * **Objetivo:** Identificar y reparar un fallo sutil en un código parcialmente funcional.
   * **Enfoque:** Resolver fugas de memoria (*Memory Leaks*), copias superficiales (*Shallow Copy*), liberaciones dobles (*Double Free*) o accesos fuera de rango (*Underflow/Overflow*).

---

> ℹ️ **Nota sobre la estructura de directorios (`.gitkeep`):**
> Dado que Git no rastrea carpetas vacías por defecto, las subcarpetas destinadas a almacenar soluciones (`01_Prob1Sol/`, `03A_Prob1Sol/`, etc.) contienen un archivo oculto `.gitkeep`. Su única función es preservar la jerarquía de directorios en el repositorio remoto mientras se agregan los archivos `.cpp`.

---

## ⚙️ Compilación y Verificación de Ejercicios

Cada archivo `.cpp` puede verificarse para comprobar que su sintaxis y tipos sean correctos. Si el código compila correctamente sin errores, la terminal no mostrará ningún mensaje.

### 1. Verificación desde la raíz del proyecto

```bash
# Formato general:
g++ -std=c++17 -fsyntax-only ruta/al/archivo.cpp

# Ejemplos:
g++ -std=c++17 -fsyntax-only 01_Especificaciones_y_Reglas/01_regla_de_tres_correg.cpp
g++ -std=c++17 -fsyntax-only 02_Stack_y_Colas/01_stack_underflow_correg.cpp
g++ -std=c++17 -fsyntax-only 03_Listas_Enlazadas/A_Listas_Simples/01_sorted_insert_soluc.cpp
```

`-fsyntax-only` verifica el código sin generar archivos objeto (`.o`) ni ejecutables.

---

## 📁 Estructura del Repositorio

```text
.
├── 📁 01_Especificaciones_y_Reglas/
│   ├── 01_Prob1Sol/
│   ├── 02_Prob2Sol/
│   ├── 03_Prob3Sol/
│   ├── 04_Prob4Sol/
│   ├── 01_regla_de_tres_correg.cpp
│   ├── 02_regla_de_cinco_movimiento_soluc.cpp
│   ├── 03_copia_superficial_double_free_correg.cpp
│   └── 04_ejercicio_regla_de_cinco_sol.cpp
├── 📁 02_Stack_y_Colas/
│   ├── 01_stack_underflow_correg.cpp
│   ├── 02_Prob1Sol/
│   ├── 02_Prob2Sol/
│   ├── 02_Prob3Sol/
│   ├── 02_Prob4Sol/
│   ├── 02_stack_dynamic_resize_soluc.cpp
│   ├── 03_queue_circular_reallocate_soluc.cpp
│   └── 04_queue_head_tail_bug_correg.cpp
├── 📁 03_Listas_Enlazadas/
│   ├── 📁 A_Listas_Simples/
│   │   ├── 01_sorted_insert_soluc.cpp
│   │   ├── 02_singly_pop_back_soluc.cpp
│   │   ├── 03A_Prob1Sol/
│   │   ├── 03A_Prob2Sol/
│   │   ├── 03A_Prob3Sol/
│   │   ├── 03A_Prob4Sol/
│   │   ├── 03_detect_cycle_floyd_soluc.cpp
│   │   └── 04_wrong_push_leak_correg.cpp
│   └── 📁 B_Listas_Dobles/
│       ├── 01_lista_doble_prev_correg.cpp
│       ├── 02_doubly_erase_node_soluc.cpp
│       ├── 03B_Prob1Sol/
│       ├── 03B_Prob2Sol/
│       ├── 03B_Prob3Sol/
│       └── 03_doubly_insert_before_soluc.cpp
└── 📄 README.md
```

