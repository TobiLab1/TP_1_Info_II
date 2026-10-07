#include "mylib.h"
#include "avr_api.h"

volatile unsigned int tiempo_restante = 0;
volatile int timer_activo = 0;

void init_driver(void) {
    // Configura los LEDs como salida
    GpiolnitStructure_AVR leds;
    leds.port = avr_GPIO_A;
    leds.modo = avr_GPIO_mode_Output;
    leds.pines = avr_GPIO_PIN_0 | avr_GPIO_PIN_1 | avr_GPIO_PIN_2; // A0, A1, A2
    init_gpio(leds);

    // Configura el sensor IR como entrada
    GpiolnitStructure_AVR sensor;
    sensor.port = avr_GPIO_B;
    sensor.modo = avr_GPIO_mode_Input;
    sensor.pines = avr_GPIO_PIN_0;
    init_gpio(sensor);

    // Configura la bomba como salida
    GpiolnitStructure_AVR bomba;
    bomba.port = avr_GPIO_B;
    bomba.modo = avr_GPIO_mode_Output;
    bomba.pines = avr_GPIO_PIN_1;
    init_gpio(bomba);
    
}

// LEDs
void driver_led_verde_on(void) { set_pin(avr_GPIO_A, 0); }
void driver_led_verde_off(void) { clear_pin(avr_GPIO_A, 0); }

void driver_led_amarillo_on(void) { set_pin(avr_GPIO_A, 1); }
void driver_led_amarillo_off(void) { clear_pin(avr_GPIO_A, 1); }

void driver_led_rojo_on(void) { set_pin(avr_GPIO_A, 2); }
void driver_led_rojo_off(void) { clear_pin(avr_GPIO_A, 2); }

// Sensores
int driver_mano_detectada(void) {
    return avr_GPIOB_IN_0;
}

int driver_nivel_ok(void) {
    // Devuelve 1 (nivel correcto). (implementar la lectura real del pin)
    return 1;
}

// Bomba
void driver_bomba_on(void) { set_pin(avr_GPIO_B, 1); }
void driver_bomba_off(void) { clear_pin(avr_GPIO_B, 1); }

// Temporizadores
void driver_iniciar_timer(unsigned int ms) {
    tiempo_restante = ms;
    timer_activo = 1;
}

int driver_timer_termino(void) {
    // Verifica si el tiempo llego a cero
    if (timer_activo && tiempo_restante == 0) {
        timer_activo = 0;
        return 1;
    }
    return 0;
}


void driver_tick_1ms(void) {
    if (timer_activo && tiempo_restante > 0) {
        tiempo_restante--;
    }
}