#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    articulos_t articulos[CANT_ARTICULOS];
    int cantidad_articulos = 0;
    int opcion = 1;
    char descripcion[90];
    int index, sucursal;

    inicializar_articulos(articulos, CANT_ARTICULOS);

    printf("Bienvenido al Final de Informatica I (Refaccionado)\n");

    cargar_articulos(articulos, &cantidad_articulos);

    calcular_total(articulos, cantidad_articulos);

    printf("\n### Datos Ingresados ###\n");
    imprimir_tabla(articulos, cantidad_articulos);

    ordenar_por_total(articulos, cantidad_articulos);

    printf("\n### Ordenado por Totales Descendentes ###\n");
    imprimir_tabla(articulos, cantidad_articulos);

    return 0;
}