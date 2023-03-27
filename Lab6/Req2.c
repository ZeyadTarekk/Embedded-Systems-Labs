/*int counter = 0;
int i,j;

void main() {
            int values []= {4369, 8738, 17476,34952}  ;

       GPIO_Digital_Output(&GPIOD_BASE, 0xFFFF);
       GPIO_Digital_Output(&GPIOE_BASE, 0xFFFF);
        counter = 0;
       while(1){


        for( i = 0 ; i < 5; i++){
                  GPIOD_ODR|=values[i];
                  GPIOE_ODR |=values[i];
        Delay_ms(500);
        }
        for(     j=0;j<5;j++){
                  GPIOD_ODR&=(~values[j]);
                  GPIOE_ODR&=(~values[j]);
                  Delay_ms(500);
        }

       }
}

*/
