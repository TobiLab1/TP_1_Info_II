#include "funciones.h"

int mostrar_menu() {
    int opcion;
    printf("\n--- Menú Principal ---\n");
    printf("1. Cargar fichas de artículos\n");
    printf("2. Emitir listado ordenado por totales\n");
    printf("3. Salir\n");
    printf("Ingrese una opción: ");
    scanf("%d", &opcion);
    return opcion;
}
void cargar_fichas(articulos_t articulos[]) {
    int numero_articulo, sucursal, cantidad;
    char descripcion_temp;
    char continuar = 's';

    printf("\n--- Carga de Fichas ---\n");

    while (continuar == 's' || continuar == 'S') {
        // 1. Pedir el número de artículo (1 a 60)
        printf("\nIngrese numero de articulo (1 a 60): ");
        scanf("%d", &numero_articulo);
        int index = numero_articulo - 1;

        // 2. Comprobar si ya tiene descripción
        if (strlen(articulos[index].descripcion) == 0) {
            printf("Ingrese la descripcion del articulo: ");
            scanf(" %[^\n]", descripcion_temp); 
            strcpy(articulos[index].descripcion, descripcion_temp);
        } else {
            printf("Articulo ya registrado. Descripcion: %s\n", articulos[index].descripcion);
        }

        // 3. Pedir sucursal y cantidad
        printf("Ingrese la sucursal (1, 2 o 3): ");
        scanf("%d", &sucursal);

        printf("Ingrese la cantidad: ");
        scanf("%d", &cantidad);

        // 4. Actualizar cantidades
        articulos[index].cantidad_sucursal[sucursal - 1] += cantidad;
        articulos[index].total += cantidad; 

        // 5. Preguntar si desea continuar
        printf("\n¿Desea cargar otra ficha? (s/n): ");
        scanf(" %c", &continuar);
    }
}
void emitir_listado(articulos_t articulos[]) {
    articulos_t aux;
    for (int i = 0; i < CANT_ARTICULOS - 1; i++) {
        for (int j = 0; j < CANT_ARTICULOS - i - 1; j++) {
            if (articulos[j].total < articulos[j+1].total) {
                aux = articulos[j];
                articulos[j] = articulos[j+1];
                articulos[j+1] = aux;
            }
        }
    }

    printf("\n--- Listado Ordenado por Totales ---\n");
    printf("Descripción\tSucursal 1\tSucursal 2\tSucursal 3\tTotal\n");
    
    for (int i = 0; i < CANT_ARTICULOS; i++) {
        if (articulos[i].total > 0) {
            printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                   articulos[i].descripcion, 
                   articulos[i].cantidad_sucursal, 
                   articulos[i].cantidad_sucursal[1], 
                   articulos[i].cantidad_sucursal[2], 
                   articulos[i].total);
        }
    }
}