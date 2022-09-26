#include "main.h"

UART_HandleTypeDef usart = {0};

void usart_init(void);

int main(void)
{
  HAL_Init();
  usart_init();
  while (1)
  {
	  char * msg = "Hello World\r\n";
	  HAL_UART_Transmit(&usart, (int8_t *) msg, 20, 100);
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

