<<<<<<< HEAD
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
=======
# Trabajo Practico

## Memoria descriptiva
El sistema desarrollado corresponde a un dispensador automático de alcohol en gel. Su funcionamiento comienza en un estado de inicialización, donde se cargan los parámetros de configuración (tiempo de dispensado, tiempos de espera y sensores).

Luego pasa al estado de espera, en el cual el sistema está listo para operar. Si se detecta una mano frente al sensor y hay suficiente alcohol disponible, la bomba se activa durante un tiempo definido para entregar una dosis.

Una vez finalizado el ciclo de dispensado, el sistema pasa a un estado de espera de retiro, donde se bloquea por un período breve para evitar que la misma detección de mano genere múltiples dosis consecutivas.

El dispensador además cuenta con un indicador visual de nivel mediante tres LEDs:

* Verde: nivel alto (funcionamiento normal).

* Amarillo: nivel bajo, pronto a agotarse.

* Rojo: nivel crítico o vacío (en este caso no se dispensa y se queda en estado de “sin stock” hasta recarga).

De esta forma, el sistema garantiza la entrega controlada y segura de alcohol en gel, evitando desperdicio y brindando información clara sobre el nivel disponible.

## Diagrama de estados

<img width="361" height="511" alt="Diagrama de estado drawio (1)" src="https://github.com/user-attachments/assets/df4ec0aa-a5b2-420a-a5f7-a5a0dfc7a125" />

*El estado Cooldown impide que el dispensador entregue más de una dosis por la misma detección de mano. Durante este estado, se espera un tiempo mínimo hasta permitir un nuevo ciclo de dispensado.
>>>>>>> 0a7f45df87bf228130d0f2429bd5bbb4ee16382e
