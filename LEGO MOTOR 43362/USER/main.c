#include "uart_lib.h"
#include "lego_motor_43362.h"

void Delay(uint32_t t){
	uint32_t i, j;
	for(i=0 ; i<t ; i++){
		for(j=0 ; j<7999 ; j++);
	}
}

int main(void){
	Pwm_Init();
	
	while(1){
		LegoMotor_SetForward(MOTOR_A);
		LegoMotor_SetLevel(MOTOR_A,50);
		LegoMotor_SetForward(MOTOR_B);
		LegoMotor_SetLevel(MOTOR_B,50);
		Delay(2000);
//		LegoMotor_SetBackward(MOTOR_A);
//		LegoMotor_SetLevel(MOTOR_A,10);
//		Delay(2000);
//		LegoMotor_SetLevel(MOTOR_A,50);
//		Delay(2000);
//		LegoMotor_SetLevel(MOTOR_A,100);
//		Delay(2000);
//		LegoMotor_SetLevel(MOTOR_A,10);
//		Delay(2000);
//		LegoMotor_SetForward(MOTOR_A);
//		Delay(2000);
//		LegoMotor_SetLevel(MOTOR_A,50);
//		Delay(2000);
//		LegoMotor_SetLevel(MOTOR_A,100);
//		Delay(2000);
//		LegoMotor_SetLevel(MOTOR_A,10);
//		Delay(2000);
	}
}



