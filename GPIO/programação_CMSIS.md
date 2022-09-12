# A programação em CMSIS é feita nas seguintes etapas

- Habilitar o clock do GPIO
- Configurar o Modo do Pino (lembrando que são do 0 ao 15)
- Definir velocidade de Saída (caso o modo for de saída)
- Definir o tipo de saída (novamente se o modo for de saída)

## Habilitando o Clock do GPIO

É feito usando o Módulo RCC(Reset and clock control) e o registrador que habilita o clock
no barramento HB1 que é o barramento de alta velocidade onde os GPIOs estão conectados.

O Registrador é chamado de HB1ENR e com ele podemos habilitar e configurar alguns periféricos.
Os GPIOs são habilitados em ordem alfabetica do bit 0 ao bit 8.

![HB1ENR](../imagens/HB1ENR.png)

Para por exemplo habilitar o GPIOA, podemos escrever o seguinte:  
`RCC->HB1ENR |= 0x1`

Isso irá habilitar apenas o GPIOA sem interferir em nenhuma outra configuração.

