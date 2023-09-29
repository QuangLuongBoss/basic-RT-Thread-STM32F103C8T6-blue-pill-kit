#include "gpio.h"

void Gpio_Init(void){
    rt_pin_mode(LED_PC13, PIN_MODE_OUTPUT);
    rt_pin_mode(BUTTON_A0 | BUTTON_A1, PIN_MODE_INPUT_PULLUP);
}


