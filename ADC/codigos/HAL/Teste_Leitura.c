#include "main.h"

UART_HandleTypeDef usart = {0};
ADC_HandleTypeDef adc = {0};

void usart_init(void);

void adc_init(void);

int main(void)
{
  HAL_Init();
  usart_init();
  adc_init();
  char imprimir[30];
  while (1)
  {
	  HAL_ADC_Start(&adc);
	  HAL_ADC_PollForConversion(&adc, 100);
	  int leitura = HAL_ADC_GetValue(&adc);

	  sprintf(imprimir, "leitura = %d\r\n", leitura);

	  HAL_UART_Transmit(&usart, (int8_t *) imprimir, 20, 100);
	  HAL_Delay(500);
  }
}


void usart_init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE();

	usart.Instance = USART2;
	usart.Init.BaudRate = 9600;
	usart.Init.WordLength = UART_WORDLENGTH_8B;
	usart.Init.StopBits = UART_STOPBITS_1;
	usart.Init.Parity = UART_PARITY_NONE;
	usart.Init.Mode = UART_MODE_TX_RX;
	usart.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&usart);
}


void adc_init(void)
{
  ADC_ChannelConfTypeDef adc_channel = {0};

  adc.Instance = ADC2;
  adc.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  adc.Init.Resolution = ADC_RESOLUTION_12B;
  adc.Init.ScanConvMode = DISABLE;
  adc.Init.ContinuousConvMode = DISABLE;
  adc.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  adc.Init.NbrOfConversion = 1;
  adc.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  HAL_ADC_Init(&adc);

  adc_channel.Channel = ADC_CHANNEL_0;
  adc_channel.Rank = 1;
  adc_channel.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  HAL_ADC_ConfigChannel(&adc, &adc_channel);
}
