# Trabajo Práctico Nº 1 - Informática II

## Descripción General
Este repositorio contiene la entrega del **Trabajo Práctico Nº 1**, el cual consiste en la refracción del código original correspondiente a "Resolucion_Final_Informatica_1". 

El objetivo de este trabajo práctico fue refraccionar el Final de informatica 1 utilizando:
* Uso de **Estructuras** (`struct`) para agrupar y organizar los datos de los artículos.
* **Modularización** mediante la separación de la lógica en la mayor cantidad de funciones posibles.
* **Separación de archivos** modularizando el código en sus respectivos archivos `.c` y `.h`.

## Estructura de Archivos

El proyecto se dividió en tres archivos principales para cumplir con los requerimientos técnicos:

### 1. `funciones.h`
Es el archivo de cabecera principal del proyecto. Aquí se alojan:
* Las definiciones de constantes (como la cantidad máxima de artículos o índices de sucursales).
* La declaración de la estructura de datos `articulos_t`, que agrupa la descripción, un arreglo con las cantidades de cada sucursal y la variable del total de cada artículo.
* Los prototipos de todas las funciones utilizadas en el programa.

### 2. `funciones.c`
En este archivo se encuentra el desarrollo lógico de todas las funciones que le dan vida al programa.

### 3. `main.c`
Actúa como el punto de entrada del programa.
