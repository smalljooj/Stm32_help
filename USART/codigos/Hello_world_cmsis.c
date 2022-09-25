#include "main.h"                         // Biblioteca da IDE

void usart_init(void);                    // Iniciar a usart
int usart2_read(void);                    // ler da usart
void usart2_write(char);                  // escrever um caracter na usart
void usart2_text(char *);                 // escrever um texto na usart

void delay(int x)                         // delay qualquer
{
	int i = 799995 * x;
	while(--i);
}

int main(void)
{
	usart_init();                           //iniciando usart
	while (1)
	{
		usart2_text("Hello World\r\n");       // escrevendo hello world
		delay(1);
	}
}

void usart_init(void)
{
	RCC->APB1ENR |= 0x20000;                // ativando clock da USART2
	RCC->AHB1ENR |= 0x01;                   // ativando clock do GPIOA
	GPIOA->MODER |= 0x00A0;                 // definindo como função auxiliar nos pinos PA2 e PA3
	GPIOA->AFR[0] |= 0x7700;                // definindo como USART os pinos PA2 e PA3


	double div = 16000000 / (16.0 * 9600);  // definindo o baud rate
	USART2->BRR |= (int) div << 4;
	USART2->BRR |= (int) (((div - (int) div) * 16) + 0.5);


	USART2->CR1 |= 0x200C;                  // ligando a USART2
}

int usart2_read(void)
{
	while(!(USART2->SR & 0x10));            // esperando o dado estar pronto
	return USART2->DR;                      // lendo o dado
}

void usart2_write(char c)
{
	while(!(USART2->SR & 0x80));            // esperando o dado ir para o registrador de bit shift e liberar o data register
	USART2->DR = c & 0xFF;                  // escrevendo o dado
}

void usart2_text(char * text)             // escreve o texto usando as funcões acima
{
	while(*text)
	{
		usart2_write(*text++);
	}
}
