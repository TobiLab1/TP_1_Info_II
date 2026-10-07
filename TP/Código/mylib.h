#ifndef MYLIB_H
#define MYLIB_H

#include "avr_api.h"

// Estados de la maquina
typedef enum {
    INICIO = 0,
    ESPERA,
    DISPENSA,
    ESPERA_RETIRO,
    SIN_STOCK
} estados_t;

// Prototipos 
void init_driver(void);

estados_t f_inicio(void);
estados_t f_espera(void);
estados_t f_dispensa(void);
estados_t f_espera_retiro(void);
estados_t f_sin_stock(void);

// Funciones de driver
void driver_led_verde_on(void);
void driver_led_verde_off(void);
void driver_led_amarillo_on(void);
void driver_led_amarillo_off(void);
void driver_led_rojo_on(void);
void driver_led_rojo_off(void);

int driver_mano_detectada(void);
int driver_nivel_ok(void);

void driver_bomba_on(void);
void driver_bomba_off(void);

void driver_iniciar_timer(unsigned int ms);
int driver_timer_termino(void);
void driver_tick_1ms(void);

#endif