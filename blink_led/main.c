#include <rtthread.h>
#include <rtdevice.h>
#include <board.h>

/* defined the LED0 pin: PC13 */
#define LED_PC13    GET_PIN(C, 13)

int main(void)
{
    /* set LED0 pin mode to output */
    rt_pin_mode(LED_PC13, PIN_MODE_OUTPUT);

    while (1)
    {
        rt_pin_write(LED_PC13, PIN_HIGH);
        rt_thread_mdelay(500);
        rt_pin_write(LED_PC13, PIN_LOW);
        rt_thread_mdelay(500);
    }
    return 0;
}




