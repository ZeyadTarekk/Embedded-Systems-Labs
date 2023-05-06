void main()
{
  unsigned int period;
  int i;
  period = PWM_TIM1_Init(3800);
  while (1)
  {
    for (i = 0; i <= 100; i++)
    {
      PWM_TIM1_Set_Duty((i / 100.0) * period, _PWM_NON_INVERTED, _PWM_CHANNEL4);
      PWM_TIM1_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM1_CH4_PE14);
      Delay_us(1000000);
    }

    for (i = 100; i >= 0; i--)
    {
      PWM_TIM1_Set_Duty((i / 100.0) * period, _PWM_NON_INVERTED, _PWM_CHANNEL4);
      PWM_TIM1_Start(_PWM_CHANNEL4, &_GPIO_MODULE_TIM1_CH4_PE14);
      Delay_us(1000000);
    }
  }
}
