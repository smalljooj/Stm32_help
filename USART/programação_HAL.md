# Programação em HAL 

- [Configurar a Usart](#Configurando-a-Usart)
- [Usar a Usart](#Usando-a-Usart)

# Configurando a Usart

Para configurar a Usart para o uso, seguimos os seguinte passos:
- [Habilitar o clock do GPIO](#Habilitando-o-Clock-do-GPIO)
- [Configurar a Usart](#Configurando-a-Usart)
- [Inicializar a Usart](#Inicializando-a-Usart)

## Habilitando o Clock do GPIO

Para habilitar o clock do GPIO em questão utilizamos o seguinte código:  
`__HAL_RCC_GPIOx_CLK_ENABLE()`

Onde o 'x' do código é substituido pela letra do GPIO em questão, para
habilitar o clock do GPIOA por exemplo usamos o seguinte código:  
`__HAL_RCC_GPIOA_CLK_ENABLE()`

## Configurando a Usart

Para configurarmos a usart usando a HAL assim como para configurar o GPIO
iremos utilizar uma estrutura, mas agora chamada de USART_HandleTypeDef.
Essa estrutura irá ser utilizada tanto para configurar e inicializar como
para utilizar a USART, por isso é interessante declarar no topo do programa.

`USART_HandleTypeDef usart;`

Para configurarmos iremos seguir os seguintes passos:

- Atribuir a Instancia
- Atribuir o Baud rate
- Descrever o tamanho da palavra
- Especificar a quantidade de bits de parada
- Determinar se vai ou não ter bit de paridade
- Definir o modo de operação
- Determinar o oversampling

Todos são campos da estrutura que definimos. Lembrando que no final estará 
as macros para configurar os campos. Clique Aqui.

### Atribuir a Instancia

Usaremos o campo Instance da estrutura e diremos qual a usart que usaremos.

Ex : `usart.Instance = USART2`

### Atribuir o Baud rate

Usaremos o campo BaudRate que faz parte do Atributo Init que é onde possui 
todas as configurações de Inicialização.

Ex: `usart.Init.BaudRate = 9600`

### Descrever o tamanho da palavra

Usaremos o campo WordLength que faz parte do Atributo Init.

Ex `usart.Init.WordLength = UART_WORDLENGTH_8B`

### Especificar a quantidade de bits de parada.

Usaremos o campo StopBits que faz parte do Atributo Init.

Ex `usart.Init.StopBits = UART_STOPBITS_1`

### Determinar se vai ou não ter bit de paridade

Usaremos o campo Parity que faz parte do Atributo Init.

Ex `usart.Init.Parity = UART_PARITY_NONE`

### Definir o modo de operação

Usaremos o campo Mode que faz parte do Atributo Init.

Ex `usart.Init.Mode = UART_MODE_TX_RX`

### Determinar o oversampling

Usaremos o campo OverSampling que faz parte do Atributo Init.

Ex `usart.Init.OverSampling = UART_OVERSAMPLING_16`

## Inicializando a Usart

Para inicializar a Usart utilizaremos a função HAL_UART_Init, em
que passaremos o endereço da estrutura que criamos e configuramos.

Ex: `HAL_UART_Init(&usart)`

# Usando a Usart

- [Escrever na Usart](#Escrevendo-no-Pino)
- [Ler da Usart](#Lendo-o-Pino)

