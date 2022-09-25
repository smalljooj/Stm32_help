# Programação em HAL 

- [Configurar a Usart](#Configurando o GPIO)
- [Usar o GPIO](#Usando a GPIO)

# Configurando a Usart

Para configurar a Usart para o uso, seguimos os seguinte passos:
- [Habilitar o clock do GPIO](#Habilitando-o-Clock-do-GPIO)
- [Configurar a Usart](#Configurando-a-Usart)
- [Inicializar a Usart](#Inicializando-o-Pino)

## Habilitando o Clock do GPIO

Para habilitar o clock do GPIO em questão utilizamos o seguinte código:  
`__HAL_RCC_GPIOx_CLK_ENABLE()`

Onde o 'x' do código é substituido pela letra do GPIO em questão, para
habilitar o clock do GPIOA por exemplo usamos o seguinte código:  
`__HAL_RCC_GPIOA_CLK_ENABLE()`

## Configurando a Usart

# Usando a Usart

- [Escrever no Pino](#Escrevendo-no-Pino)
- [Ler o Pino](#Lendo-o-Pino)
- [Exceções](#Exceções)

