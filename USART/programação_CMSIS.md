# Programação em CMSIS 

- [Configurar o Usart](#Configurando-o-Usart)
- [Usar o Usart](#Usando-o-Usart)

# Configurando o Usart

Para configurar o Usart para o uso, seguimos os seguinte passos:

- [Habilitar o clock da_Usart](#Habilitando-o-Clock-da_Usart)
- [Configurar o Modo do Pino](#Configurando-o-Modo)
- [Configurar Baud rate](#Configurando-Baud-rate)
- [Iniciar Usart](#Iniciando-Usart) 


## Habilitando o Clock da Usart

É feito usando o Módulo RCC(Reset and clock control) e o registrador que habilita o clock
no barramento APB1 que é o barramento de baixa velocidade onde as Usarts estão conectadas.

O Registrador é chamado de APB1ENR e com ele podemos habilitar e configurar alguns periféricos.
As Usarts são habilitados do bit 17 ao bit 20.

![APB1ENR](../imagens/APB1ENR.PNG)

Para por exemplo habilitar a Usart 2, podemos escrever o seguinte:  
`RCC->APB1ENR |= 0x20000`

Isso irá habilitar apenas a Usart 2 sem interferir em nenhuma outra configuração.

## Configurando o Modo

É feito usando o modulo do GPIO em questão, e o registrador MODER. Mas antes precisamos abilitar o clock
do GPIO em questão.

![AHB1ENR](../imagens/HB1ENR.PNG)

Depois configuramos o Modo.

![MODER](../imagens/MODER.PNG)

No registrador Moder cada par de bits representa o modo do bit em questão, estes modos
podem ser:

- 00 -> INPUT (Entrada)
- 01 -> OUTPUT (Saída)
- 10 -> FUNCTION (Função)
- 11 -> ANALOG (Analógica)

Devemos colocar como função auxiliar e com o registrador AFR[] iremos configurar como USART.



Para definir o pino 2 e 3 do como saida, pode ser feito da seguinte forma:  
`GPIOA->MODER |= 0x0010 // em binário ficaria assim -> 0b00010000`

## Definindo a velocidade da saída
