#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// constantes
#define CANT_ARTICULOS 60
#define SUCURSAL_1 0 
#define SUCURSAL_2 1 
#define SUCURSAL_3 2 

// estructuras
typedef struct { 
    char descripcion[90]; 
    int cantidad_sucursal[3];
    int total; 
} articulos_t;

// funciones 
void cargar_articulos(articulos_t *articulos, int *cantidad_articulos); // Funcion nueva
void inicializar_articulos(articulos_t articulos[], int n);
int buscar_o_agregar_articulo(articulos_t articulos[], int* cantidad_actual, char descripcion[]);
void cargar_cantidad(articulos_t articulos[], int index, int sucursal);
void calcular_total(articulos_t articulos[], int cantidad);
void imprimir_tabla(articulos_t articulos[], int cantidad);
void ordenar_por_total(articulos_t articulos[], int cantidad);

#endif