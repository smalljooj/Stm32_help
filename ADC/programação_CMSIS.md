# Programação em CMSIS

- [Configurar o ADC](#Configurando-o-ADC)
- [Usar o ADC](#Usando-o-ADC)

# Configurando o ADC

Para configurar o ADC para o uso, seguimos os seguinte passos:

- [Habilitar o clock do ADC](#Habilitando-o-Clock-do-ADC)
- [Configurar o Modo do Pino](#Configurando-o-Modo) (lembrando que são do 0 ao 15)
- [](#Definindo-a-velocidade-da-saída) (caso o modo for de saída)
- [](#Definindo-o-tipo-da-saída) (novamente se o modo for de saída)
- [](#Configurando-o-Resistor-de-Pull-Up/Down)

## Habilitando o Clock do ADC

É feito usando o Módulo RCC(Reset and clock control) e o registrador que habilita o clock
no barramento APB2 que é o barramento de alta velocidade, porém mais lento que o AHB1, nele
é onde os ADCs estão conectados.

O Registrador é chamado de APB2ENR e com ele podemos habilitar e configurar alguns periféricos.
Os ADCs são habilitados em ordem alfabetica do bit 8 ao bit 10.

![APB2ENR](../imagens/APB2ENR.PNG)

Para por exemplo habilitar o ADC1, podemos escrever o seguinte:
`RCC->APB2ENR |= 0x0100`

Isso irá habilitar apenas o ADC1 sem interferir em nenhuma outra configuração.

## Configurando o Modo

É necessario configurar o Pino do GPIO para Analogico, para isso devemos habilitar
o clock no GPIOx e depois colocar usando o registrador MODER o pino como Analogico.

![AHB1ENR](../imagens/HB1ENR.PNG)

Exemplo de código:
´RCC->AHB1ENR |= 0x01´

![MODER](../imagens/MODER.PNG)

Nesse registrador cada par de bits representa o modo do bit em questão, estes modos
podem ser:

- 00 -> INPUT (Entrada)
- 01 -> OUTPUT (Saída)
- 10 -> FUNCTION (Função)
- 11 -> ANALOG (Analógica)

Para definir o pino 0 do GPIOA como Analógico, pode ser feito da seguinte forma:
`GPIOA->MODER |= 0x0003 // em binário ficaria assim -> 0b00000011`

##

# Usando o GPIO
