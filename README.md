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
```

`-fsyntax-only` verifica el código sin generar archivos objeto (`.o`) ni ejecutables.

## 🛠️ Flujo de Trabajo Completo desde Terminal (Vim + Git + GitHub CLI)

Guía completa desde cero para clonar, resolver, validar y enviar soluciones o propuestas mediante Pull Request utilizando exclusivamente la terminal de Linux:

### 1. Configuración Única Inicial (Solo la primera vez)
Si es la primera vez que usas la CLI de GitHub (`gh`), debes vincular tu cuenta:

```bash
# Iniciar sesión en GitHub desde la terminal
gh auth login

# Clonar el repositorio central
git clone [https://github.com/TU_USUARIO/Data_Structures_Exercises.git](https://github.com/TU_USUARIO/Data_Structures_Exercises.git)

# Entrar al directorio del proyecto
cd Data_Structures_Exercises

# Navegar a la sección a trabajar
cd 03_Listas_Enlazadas/B_Listas_Dobles

# Ver archivos del directorio
ls -la

# Crear y cambiar a la nueva rama
git checkout -b solucion-03B-prob1
# Abrir el ejercicio en Vim/Nvim
nvim 01_lista_doble_prev_correg.cpp
vim 01_lista_doble_prev_correg.cpp

#Compilar
:!g++ -Wall -Wextra -std=c++17 01_lista_doble_prev_correg.cpp -o run && ./run

#Copiar la resolucion de la carpeta
cp 01_lista_doble_prev_correg.cpp 03B_Prob1Sol/

### 2.Sugerir cambios y enviar Pull request
# Confirmar que la solución está en la carpeta de destino
ls -l 03B_Prob1Sol/

# Agregar únicamente la carpeta de soluciones (evita subir binarios)
git add 03B_Prob1Sol/

# Crear el commit
git commit -m "soluc: corrección de punteros prev en 03B_Prob1Sol"

# Subir la rama local al repositorio remoto
git push origin solucion-03B-prob1

# Crear el Pull Request directamente desde la terminal
gh pr create --title "soluc: entrega ejercicio 03B Prob1" --body "Solución validada con cassert y sin leaks en Valgrind."

---

## 🤝 Contribuciones

¡Las contribuciones son bienvenidas! Si deseas agregar nuevas soluciones o corregir algún error:

1. Haz un **Fork** de este repositorio.
2. Crea una rama para tu aporte (`git checkout -b feature/nueva-solucion`).
3. Asegúrate de que los archivos compilen correctamente (`g++ -c archivo.cpp`).
4. Haz un **Commit** de tus cambios (`git commit -m "feat: agrega solucion X"`).
5. Haz un **Push** a la rama (`git push origin feature/nueva-solucion`).
6. Abre un **Pull Request**.

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

