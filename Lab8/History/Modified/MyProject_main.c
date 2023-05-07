/*
 * Project name:
     MyProject.mcpar
 * Generated by:
     Visual TFT
 * Date of creation
     5/8/2023
 * Test configuration:
     MCU:             STM32F407VG
     Dev.Board:       EasyMx_PRO_v7_for_STM32_ARM_9A
     Oscillator:      16000000 Hz
     SW:              mikroC PRO for ARM
                      http://www.mikroe.com/mikroc/arm/
 */

#include "MyProject_objects.h"

void main() {
     int screenNumber = 1;

  Start_TP();
              GPIO_Digital_Input(&GPIOC_BASE, _GPIO_PINMASK_0 );
  GPIO_Digital_Output(&GPIOD_BASE, _GPIO_PINMASK_ALL);
  GPIOD_ODR = 0x0000;
  while (1) {
    Check_TP();

    if( Button(&GPIOC_IDR, 0, 2, 1)){
        if(screenNumber == 1){
        DrawScreen(&Screen2);
        screenNumber = 2;
        }else{
        DrawScreen(&Screen1);
        screenNumber = 1;
        }
        

    }
      while( Button(&GPIOC_IDR, 0, 2, 1)){}
  }
}
