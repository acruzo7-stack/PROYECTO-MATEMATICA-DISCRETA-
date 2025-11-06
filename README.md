# PROYECTO-MATEMATICA-DISCRETA-

=====================================================
DOCUMENTACIÓN FORMAL DEL PROYECTO: SISTEMA DE ÁRBOLES GENERALES
=====================================================

I. INTRODUCCIÓN

Este documento formaliza la estructura, el diseño y la operatividad de un sistema desarrollado en **C++** para la gestión de **Árboles Generales (N-arios)**. El alcance del proyecto incluye la implementación de la estructura de datos fundamental, algoritmos recursivos esenciales (recorridos, búsqueda, cálculo de altura) y la verificación de propiedades estructurales (si es binario). El sistema utiliza una interfaz de consola interactiva.

---

## II. ARQUITECTURA DEL CÓDIGO Y ESTRUCTURAS DE DATOS

El proyecto se organiza bajo un paradigma de programación orientada a objetos (POO), con la lógica distribuida en tres componentes.

### A. Estructura de Componentes

| ARCHIVO       | ROL PRINCIPAL             | DESCRIPCIÓN FORMAL
|---------------|---------------------------|------------------------------------------------------------------
| arbol.h       | **Definición Estructural**| Contrato de las clases 'Nodo' y 'Arbol', declarando atributos y métodos.
| arbol.cpp     | **Implementación Algorítmica**| Cuerpo de todos los métodos, incluyendo lógica recursiva y gestión de memoria.
| main.cpp      | **Control y Ejecución** | Punto de entrada. Gestiona el bucle principal, la interfaz de usuario y orquesta las llamadas al objeto 'Arbol'.

### B. Estructuras Clave

| ESTRUCTURA    | FUNCIÓN ESENCIAL          | ATRIBUTOS CRÍTICOS
|---------------|---------------------------|------------------------------------------------------------------
| Clase Nodo    | Unidad Fundamental (TDV)  | **ValNodo** (valor). **Hnodo** (vector de punteros a N hijos).
| Clase Arbol   | Administrador del Sistema | **NodoRa** (puntero a la raíz).

---

## III. ALGORITMOS CLAVE

### A. Búsqueda de Nodos (Busca)

El método privado 'Busca(Nodo* NodoAct, int ValB)' implementa un algoritmo de **Búsqueda en Profundidad (DFS - Depth-First Search)**.

* **Principio:** Si el nodo actual no es el buscado, realiza llamadas recursivas a **cada uno de sus hijos** hasta encontrar el valor o agotar la rama.
* **Parada de Éxito:** Retorna el puntero del nodo inmediatamente si el valor coincide.
* **Gestión de Memoria (ArbolElim):** El destructor invoca la función de limpieza, la cual ejecuta un recorrido en **Postorden** para liberar cada nodo con 'delete', asegurando la ausencia de fugas de memoria.

---

## IV. GUÍA DE COMPILACIÓN Y EJECUCIÓN

Los siguientes comandos deben ejecutarse en la terminal (PowerShell o CMD) para compilar y ejecutar el programa con el soporte correcto para caracteres especiales (UTF-8).

| PASO | COMANDO DE TERMINAL | PROPÓSITO Y FUNCIÓN
| :---: | :--- | :--- |
| **1.** | [Console]::OutputEncoding = [System.Text.Encoding]::UTF8 | **Configuración de PowerShell.** Establece la codificación de salida a UTF-8.
| **2.** | chcp 65001 | **Configuración de CMD/PowerShell.** Cambia la página de códigos activa a UTF-8 (65001).
| **3.** | **g++ -o arbol.exe main.cpp arbol.cpp** | **Compilación.** Enlaza los archivos fuente y genera el archivo ejecutable 'arbol.exe'.
| **4.** | **.\arbol.exe** | **Ejecución.** Inicia el programa y despliega el menú interactivo para la manipulación del árbol.
