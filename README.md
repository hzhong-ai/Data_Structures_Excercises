# 🎯 Data Structures Exercises (C++)

Bienvenido a **Data Structures Exercises**. Este repositorio es un laboratorio de prácticas y evaluación en C++ enfocado en la resolución de problemas de estructuras de datos y la depuración de errores de memoria.
##**Nota sobre la estructura:** Las subcarpetas contienen un archivo oculto `.gitkeep` únicamente para preservar la jerarquía del directorio en Git mientras se agregan los ejercicios.
---

## 📌 Tipos de Problemas

Los ejercicios están divididos en dos categorías principales según su sufijo:

1. **`_soluc.cpp` / `_sol.cpp` (Implementación)**:
   * **Objetivo:** Construir desde cero la lógica o completar funciones faltantes indicadas por marcadores `// TODO:` o `// pon tu codigo aqui`.
   * **Enfoque:** Correcto manejo de memoria dinámica, destructores, reasignación de punteros y algoritmos clásicos.

2. **`_correg.cpp` (Depuración / Bug Fix)**:
   * **Objetivo:** Identificar y reparar un fallo sutil en un código parcialmente funcional.
   * **Enfoque:** Resolver fugas de memoria (*Memory Leaks*), copias superficiales (*Shallow Copy*), liberaciones dobles (*Double Free*) o accesos fuera de rango (*Underflow/Overflow*).

---

## 📚 Temario y Estructura del Repositorio

```text
.
├── 📁 01_Especificaciones_y_Reglas/
│   ├── 01_Prob1Sol
│   ├── 01_Prob2Sol
│   ├── 01_Prob3Sol
│   ├── 01_Prob4Sol
│   ├── 01_regla_de_tres_correg.cpp
│   ├── 02_regla_de_cinco_movimiento_soluc.cpp
│   ├── 03_copia_superficial_double_free_correg.cpp
│   └── 04_ejercicio_regla_de_cinco_sol.cpp
├── 📁 02_Stack_y_Colas/
│   ├── 01_stack_underflow_correg.cpp
│   ├── 02_Prob1Sol
│   ├── 02_Prob2Sol
│   ├── 02_Prob3Sol
│   ├── 02_Prob4Sol
│   ├── 02_stack_dynamic_resize_soluc.cpp
│   ├── 03_queue_circular_reallocate_soluc.cpp
│   └── 04_queue_head_tail_bug_correg.cpp
├── 📁 03_Listas_Enlazadas/
│   ├── 📁 A_Listas_Simples/
│   │   ├── 01_sorted_insert_soluc.cpp
│   │   ├── 02_singly_pop_back_soluc.cpp
│   │   ├── 03A_Prob1Sol
│   │   ├── 03A_Prob2Sol
│   │   ├── 03A_Prob3Sol
│   │   ├── 03A_Prob4Sol
│   │   ├── 03_detect_cycle_floyd_soluc.cpp
│   │   └── 04_wrong_push_leak_correg.cpp
│   └── 📁 B_Listas_Dobles/
│       ├── 01_lista_doble_prev_correg.cpp
│       ├── 02_doubly_erase_node_soluc.cpp
│       ├── 03B_Prob1Sol
│       ├── 03B_Prob2Sol
│       ├── 03B_Prob3Sol
│       └── 03_doubly_insert_before_soluc.cpp
└── 📄 README.md
