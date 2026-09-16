# 🎯 Simulacro Parcial de Estructuras de Datos (C++)

Bienvenido al **Simulacro Parcial Práctico de Estructuras de Datos**. Este repositorio es un laboratorio de evaluación de código en C++17 enfocado en la resolución de problemas (`_soluc.cpp`) y la depuración de errores sutiles de memoria (`_correg.cpp`).

---

## 📚 Temario y Organización de Ejercicios

```text
Simulacro_Parcial_Estructuras/
├── 📄 README.md
├── 📁 01_Especificaciones_y_Reglas/
│   ├── 01_regla_de_tres_soluc.cpp                   # Implementación Deep Copy (Destructor, Copia, Asignación)
│   ├── 02_regla_de_cinco_movimiento_soluc.cpp       # Move Semantics (Move Constructor, Move Assignment)
│   └── 03_copia_superficial_double_free_correg.cpp  # Corrección de Shallow Copy & Double Free
├── 📁 02_Stack_y_Colas/
│   ├── 01_stack_underflow_correg.cpp                # Corrección de Underflow en pop()
│   ├── 02_stack_dynamic_resize_soluc.cpp            # Redimensionamiento dinámico al doble en Stack
│   ├── 03_queue_circular_reallocate_soluc.cpp       # Reallocate y des-circularización en Cola
│   └── 04_queue_head_tail_bug_correg.cpp            # Depuración de actualización de size_ en Cola
└── 📁 03_Listas_Enlazadas/
    ├── 📁 A_Listas_Simples/
    │   ├── 01_sorted_insert_soluc.cpp               # Inserción ordenada en Lista Simple
    │   ├── 02_singly_pop_back_soluc.cpp              # SinglyLinkedList pop_back() e invariantes
    │   ├── 03_detect_cycle_floyd_soluc.cpp          # Detección de ciclos (Algoritmo de Floyd)
    │   └── 04_wrong_push_leak_correg.cpp            # Corrección de paso por valor y fugas en Push
    └── 📁 B_Listas_Dobles/
        ├── 01_lista_doble_prev_correg.cpp           # Corrección de enlaces hacia atrás (prev)
        ├── 02_doubly_erase_node_soluc.cpp           # Eliminación O(1) de nodo conocido
        └── 03_doubly_insert_before_soluc.cpp        # Inserción general insert_before()
```

---

## 🛠️ Convención de Nombres

* **`_soluc.cpp`**: Ejercicios de desarrollo donde debes implementar funciones o clases respondiendo a un TODO.
* **`_correg.cpp`**: Ejercicios de depuración donde debes localizar un error sutil de lógica o memoria y repararlo.

---

## ⚙️ Compilación y Ejecución

Cada ejercicio incluye una suite de pruebas automáticas con `assert()`. Si el ejercicio es resuelto o corregido con éxito, imprimirá `✅ [PASS]`.

### Ejemplo de compilación en consola:
```bash
# Compilar ejercicio de la Sección 01
g++ -std=c++17 -Wall -Wextra 01_Especificaciones_y_Reglas/01_regla_de_tres_soluc.cpp -o ex1 && ./ex1

# Compilar ejercicio de la Sección 02
g++ -std=c++17 -Wall -Wextra 02_Stack_y_Colas/01_stack_underflow_correg.cpp -o ex2 && ./ex2

# Compilar ejercicio de la Sección 03-A
g++ -std=c++17 -Wall -Wextra 03_Listas_Enlazadas/A_Listas_Simples/01_sorted_insert_soluc.cpp -o ex3a && ./ex3a

# Compilar ejercicio de la Sección 03-B
g++ -std=c++17 -Wall -Wextra 03_Listas_Enlazadas/B_Listas_Dobles/01_lista_doble_prev_correg.cpp -o ex3b && ./ex3b
```
