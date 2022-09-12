#include "main.h" // Include da biblioteca, varia de IDE para IDE

void delay(int);
void gpio_init(void);

int main(void)
{
	gpio_init();
	while(1)
	{
		GPIOA->BSRR = 0x0040; // pino 6 em estado logico alto
		GPIOA->BSRR = 0x00800000; // pino 7 em estado logico baixo
		delay(500);
		GPIOA->BSRR = 0x0080; // pino 7 em estado logico alto
		GPIOA->BSRR = 0x00400000; // pino 6 em estado logico baixo
		delay(500);
	}
	return 0;
}

/* funcao para inicializar os pinos de gpio*/
void gpio_init(void)
{
	RCC->AHB1ENR |= 1; // habilita o clock no GPIOA
	GPIOA->MODER |= 0x5000; // define saída nos pinos 6 e 7
	GPIOA->OSPEEDR |= 0x5000; // define velocidade média nos pinos 6 e 7
	GPIOA->OTYPER &= ~0x00C0; // define como push pull os pinos 6 e 7;
}

/* funcao para delay */
void delay(int n)
{
	int i;
	for (; n > 0; n--)
	for (i = 0; i < 3195; i++);
}
