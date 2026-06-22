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
#define TOTAL 4

// estructuras
typedef struct { 
    char descripcion[90]; 
    int cantidad_sucursal[3];
    int total; 
} articulos_t;

// funciones 
void cargar_articulos(articulos_t *articulos, int *cantidad_articulos);
void inicializar_articulos(articulos_t *articulos, int cant_max);
void calcular_total(articulos_t *articulos, int cant_max);
void imprimir_tabla(articulos_t *articulos, int cant_max);
void ordenar_por_total(articulos_t *articulos, int cant_max);

#endif