void main()
{
     int i;
     unsigned int period;
     period = PWM_TIM4_Init(4000);
     while (1)
     {
          for (i = 0; i <= 100; i++)
          {
               PWM_TIM4_Set_Duty((i / 100.0) * period, _PWM_NON_INVERTED, _PWM_CHANNEL1);
               PWM_TIM4_Start(_PWM_CHANNEL1, &_GPIO_MODULE_TIM4_CH1_PD12);
               Delay_us(3000);
          }

          for (i = 0; i <= 100; i++)
          {
               PWM_TIM4_Set_Duty((i / 100.0) * period, _PWM_NON_INVERTED, _PWM_CHANNEL2);
               PWM_TIM4_Start(_PWM_CHANNEL2, &_GPIO_MODULE_TIM4_CH2_PD13);
               Delay_us(3000);
          }
          for (i = 0; i <= 100; i++)
          {
               PWM_TIM4_Set_Duty((i / 100.0) * period, _PWM_NON_INVERTED, _PWM_CHANNEL3);
               PWM_TIM4_Start(_PWM_CHANNEL3, &_GPIO_MODULE_TIM4_CH3_PD14);
               Delay_us(3000);
          }
          for (i = 0; i <= 100; i++)
          {
               PWM_TIM4_Set_Duty((i / 100.0) * period, _PWM_NON_INVERTED, _PWM_CHANNEL4);
               PWM_TIM4_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM4_CH4_PD15);
               Delay_us(3000);
          }

          for (i = 100; i >= 0; i--)
          {
               PWM_TIM4_Set_Duty((i / 100.0) * period, _PWM_NON_INVERTED, _PWM_CHANNEL1);
               PWM_TIM4_Start(_PWM_CHANNEL1, &_GPIO_MODULE_TIM4_CH1_PD12);
               Delay_us(3000);
               //              PWM_TIM4_Stop(_PWM_CHANNEL1);
          }

          for (i = 100; i >= 0; i--)
          {
               PWM_TIM4_Set_Duty((i / 100.0) * period, _PWM_NON_INVERTED, _PWM_CHANNEL2);
               PWM_TIM4_Start(_PWM_CHANNEL2, &_GPIO_MODULE_TIM4_CH2_PD13);
               Delay_us(3000);
          }
          for (i = 100; i >= 0; i--)
          {
               PWM_TIM4_Set_Duty((i / 100.0) * period, _PWM_NON_INVERTED, _PWM_CHANNEL3);
               PWM_TIM4_Start(_PWM_CHANNEL3, &_GPIO_MODULE_TIM4_CH3_PD14);
               Delay_us(3000);
          }
          for (i = 100; i >= 0; i--)
          {
               PWM_TIM4_Set_Duty((i / 100.0) * period, _PWM_NON_INVERTED, _PWM_CHANNEL4);
               PWM_TIM4_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM4_CH4_PD15);
               Delay_us(3000);
          }
     }
}
