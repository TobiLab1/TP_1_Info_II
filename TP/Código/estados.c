#include "mylib.h"
#include <stdio.h>

// Estado de inicio: inicializa sistema y enciende LED verde
estados_t f_inicio(void) {
    driver_led_verde_on();
    driver_led_amarillo_off();
    driver_led_rojo_off();
    return ESPERA;
}

// Estado de espera: aguarda deteccion de mano o falta de stock
estados_t f_espera(void) {
    if (!driver_nivel_ok()) {
        driver_led_verde_off();
        driver_led_rojo_on();
        return SIN_STOCK;
    }
    
    if (driver_mano_detectada()) {
        driver_led_verde_off();
        driver_led_amarillo_on();
        driver_bomba_on(); // Activa la bomba
        driver_iniciar_timer(600); // Inicia temporizador
        return DISPENSA;
    }
    
    return ESPERA;
}

// Estado de dispensado: bomba activa hasta que se cumpla el tiempo
estados_t f_dispensa(void) {
    // Verifica si el timer por ya termino 
    if (driver_timer_termino()) { 
        driver_bomba_off();
        driver_led_amarillo_off();
        driver_iniciar_timer(1500); // Inicia cooldown
        return ESPERA_RETIRO;
    }
    
    // Si no terminó el tiempo, mantiene el estado actual
    return DISPENSA;
}

// Espera que la mano se retire
estados_t f_espera_retiro(void) {
    if (driver_timer_termino()) { 
        driver_led_verde_on();
        return ESPERA;
    }
    
    return ESPERA_RETIRO;
}

// Estado sin stock: espera hasta que se recargue el tanque
estados_t f_sin_stock(void) {
    // Si no hay nivel, retorna el mismo estado
    if (!driver_nivel_ok()) {
        return SIN_STOCK;
    }
    
    // Si el sensor detecta nivel nuevamente, actualiza LEDs y cambia de estado
    driver_led_rojo_off();
    driver_led_verde_on();
    return ESPERA;
}