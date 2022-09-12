#include "main.h" // Include da biblioteca, varia de IDE para IDE

void delay(int);
void gpio_init(void);

/*
 * Mude os pinos para os quais possui os led/s.
 */

int main(void)
{
	HAL_Init(); // Inicia a HAL
	gpio_init(); // Configura os pinos de gpio
	while(1)
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET); // pino 6 em estado lógico alto
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET); // pino 7 em estado lógico baixo
		HAL_Delay(500); // delay de 500ms
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET); // pino 6 em estado lógico baixo
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET); // pino 7 em estado lógico alto
		HAL_Delay(500); // delay de 500ms
	}
	return 0;
}

/* funcao para inicializar os pinos de gpio*/
void gpio_init(void)
{
	__HAL_RCC_GPIOA_CLK_ENABLE(); // habilita o clock no GPIOA
	GPIO_InitTypeDef gpio_struct = {0}; // struct de configuracao do pino

	gpio_struct.Pin = GPIO_PIN_6 | GPIO_PIN_7; // pino 6 e 7
	gpio_struct.Mode = GPIO_MODE_OUTPUT_PP; // modo saida push pull
	gpio_struct.Pull = GPIO_NOPULL; // sem resistores de pull up/down
	gpio_struct.Speed = GPIO_SPEED_FREQ_LOW; // velocidade de saída baixa

	HAL_GPIO_Init(GPIOA, &gpio_struct); // inicializa os pinos
}


