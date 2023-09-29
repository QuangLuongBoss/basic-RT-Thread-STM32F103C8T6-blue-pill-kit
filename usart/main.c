#include <rtthread.h>
#include "usart.h"
#include "string_lib.h"

#define LED_PC13    GET_PIN(C, 13)

int main(void){
    Usart1_Init(115200);
    rt_pin_mode(LED_PC13, PIN_MODE_OUTPUT);

    while(1){

      if(usart1_readreceiveddata_flag){
          if( String_Compare((char*)usart1_receivedchar_arr, "bat") ){
              rt_pin_write(LED_PC13, PIN_LOW);
              Usart1_SendString("da bat\n");
          }
          if( String_Compare((char*)usart1_receivedchar_arr, "tat") ){
            rt_pin_write(LED_PC13, PIN_HIGH);
            Usart1_SendString("da tat\n");
          }
          usart1_readreceiveddata_flag = 0;
      }
    }
}
