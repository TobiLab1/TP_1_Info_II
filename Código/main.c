#include "mylib.h"

int main(void) {
    init_driver();
    estados_t estado = INICIO;
    
    estados_t (*fsm[])(void) = {
        f_inicio,
        f_espera,
        f_dispensa,
        f_espera_retiro,
        f_sin_stock
    };
    
    // Bucle infinito
    while (1) {
        // Ejecuta la funcion del indice del estado actual y retorna el nuevo estado.
        estado = (*fsm[estado])();
    }
    
    return 0;
}