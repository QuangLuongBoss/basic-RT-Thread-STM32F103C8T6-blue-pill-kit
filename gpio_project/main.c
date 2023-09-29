#include "gpio.h"



void Read_All_Button(void);

int main(void)
{
    Gpio_Init();

    while (1)
    {
        Read_All_Button();
    }

    return 0;
}



void Read_All_Button(void){
    if( !rt_pin_read(BUTTON_A0) ){
        rt_pin_write(LED_PC13, PIN_LOW);
    }
    if( !rt_pin_read(BUTTON_A1)){
        rt_pin_write(LED_PC13, PIN_HIGH);
    }
}


