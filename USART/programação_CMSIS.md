# Programação em CMSIS 

- [Configurar o Usart](#Configurando-o-Usart)
- [Usar o Usart](#Usando-o-Usart)

# Configurando o Usart

Para configurar o Usart para o uso, seguimos os seguinte passos:

- [Habilitar o clock dos_barramentos](#Habilitando-o-Clock-dos_barramentos)
- [Configurar o Modo do Pino](#Configurando-o-Modo) (lembrando que são do 0 ao 15)
- [Definir velocidade de Saída](#Definindo-a-velocidade-da-saída) (caso o modo for de saída)
- [Definir o tipo de saída](#Definindo-o-tipo-da-saída) (novamente se o modo for de saída)
- [Definir o resistor de pull up/down](#Configurando-o-Resistor-de-Pull-Up/Down)

## Habilitando o Clock do GPIO

É feito usando o Módulo RCC(Reset and clock control) e o registrador que habilita o clock
no barramento AHB1 que é o barramento de alta velocidade onde os GPIOs estão conectados.

O Registrador é chamado de AHB1ENR e com ele podemos habilitar e configurar alguns periféricos.
Os GPIOs são habilitados em ordem alfabetica do bit 0 ao bit 8.

![AHB1ENR](../imagens/HB1ENR.PNG)

Para por exemplo habilitar o GPIOA, podemos escrever o seguinte:  
`RCC->AHB1ENR |= 0x1`

Isso irá habilitar apenas o GPIOA sem interferir em nenhuma outra configuração.

## Configurando o Modo

É feito usando o modulo do GPIO em questão, e o registrador MODER

![MODER](../imagens/MODER.PNG)

Nesse registrador cada par de bits representa o modo do bit em questão, estes modos
podem ser:

- 00 -> INPUT (Entrada)
- 01 -> OUTPUT (Saída)
- 10 -> FUNCTION (Função)
- 11 -> ANALOG (Analógica)

Para definir o pino 2 do GPIOA como saida, pode ser feito da seguinte forma:  
`GPIOA->MODER |= 0x0010 // em binário ficaria assim -> 0b00010000`

## Definindo a velocidade da saída
