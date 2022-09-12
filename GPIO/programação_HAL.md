# A programação em HAL é feita nas seguintes etapas

- Habilitar o clock do GPIO
- Configurar o Pino do GPIO
- Inicializar o Pino

## Habilitando o Clock do GPIO

Para habilitar o clock do GPIO em questão utilizamos o seguinte código:  
`__HAL_RCC_GPIOx_CLK_ENABLE()`

Onde o 'x' do código é substituido pela letra do GPIO em questão, para
habilitar o clock do GPIOA por exemplo usamos o seguinte código:  
`__HAL_RCC_GPIOA_CLK_ENABLE()`

## Configurando o Pino do GPIO

Para configurar o Pino do GPIO a HAL usa uma estrutura em específico que 
possui as configurações que serão executadas no pino em questão.  
Essa estrutura é a GPIO_InitTypeDef e criamos uma assim:  
`GPIO_InitTypeDef gpio_struct = {0} // cria a estrutura para configuração e inicializa de forma vazia`

Essa estrutura possui diversos campos:

- [Pin](#Expecificando-o-Pino) -> Define o Pino
- [Mode](#Expecificando-o-Modo) -> O modo do Pino
- [Pull](#Expecificando-o-Resistor-Pull-UpDown) -> O resistor de Pull Up/Down
- [Speed](#Expecificando-a-Velocidade) -> A velocidade da saída
- [Alternate](#Expecificando-a-Função) -> A função alternativa

A HAL possui diversos defines já prontos para ajudar na configuração, eles estarão descritos 
ao final do arquivo, para melhor navegação utilize os tópicos que estão acima.

## Expecificando o Pino

Para definir o pino podemos utilizar o código abaixo apenas colocando o número do pino no lugar do 'x':  
`GPIO_Pin_x`

Configurando o pino 6 e o 7:  
`gpio_struct.Pin = GPIO_Pin_6 | GPIO_Pin_7`

## Expecificando o Modo

Para definir o modo podemos utilizar as seguintes macros: 

- GPIO_MODE_INPUT -> Entrada
- GPIO_MODE_OUTPUT_PP -> Saída do tipo Push Pull
- GPIO_MODE_OUTPUT_OD -> Saída do tipo Open Drain
- GPIO_MODE_AF_PP -> Função alternativa modo Push Pull
- GPIO_MODE_AF_OD -> Função alternativa modo Open Drain
- GPIO_MODE_ANALOG -> Modo Analógico(ADC e DAC) 
- GPIO_MODE_IT_RISING -> Entrada, porém gera interrupção ao trocar de estado 0 para 1 
- GPIO_MODE_IT_FALLING -> Entrada, porém gera interrupção ao trocar de estado 1 para 0 
- GPIO_MODE_IT_RISING_FALLING -> Entrada, porém gera interrupção ao trocar de qualquer estado  
- GPIO_MODE_EVT_RISING -> Entrada, porém gera um evento ao trocar de estado 0 para 1 
- GPIO_MODE_EVT_FALLING -> Entrada, porém gera um evento ao trocar de estado 1 para 0 
- GPIO_MODE_EVT_RISING_FALLING -> Entrada, porém gera um evento ao trocar de qualquer estado

Configurando o modo para saida Push Pull:  
`gpio_struct.Mode = GPIO_MODE_OUTPUT_PP`

## Expecificando o Resistor Pull Up/Down

Para definir o resitor de Pull Up/Down podemos utilizar as seguintes macros: 

- GPIO_NOPULL -> Sem Resistor de Pull Up/Down
- GPIO_PULLUP -> Resistor de Pull Up
- GPIO_PULLDOWN -> Resistor de Pull Down

Configurando o Resitor para Resitor de Pull Up:  
`gpio_struct.Pull = GPIO_PULLUP`

## Expecificando a Velocidade

Para definir a velocidade podemos utilizar as seguintes macros: 

- GPIO_SPEED_FREQ_LOW -> Baixa velocidade
- GPIO_SPEED_FREQ_MEDIUM -> Média Velocidade
- GPIO_SPEED_FREQ_HIGH -> Alta Velocidade
- GPIO_SPEED_FREQ_VERY_HIGH -> Extrema Velocidade

Configurando a velocidade para Extrema:  
`gpio_struct.Speed = GPIO_SPEED_FREQ_VERY_HIGH`

## Expecificando a Função

Para definir a função alternativa podemos utilizar as seguintes macros, porém
para utilizar devemos ver qual a função que é permitida naquele pino que vamos
configurar.

- GPIO_AF0_RTC_50Hz 
- GPIO_AF0_MCO 
- GPIO_AF0_TAMPER 
- GPIO_AF0_SWJ 
- GPIO_AF0_TRACE 
- GPIO_AF1_TIM1 
- GPIO_AF1_TIM2 
- GPIO_AF2_TIM3 
- GPIO_AF2_TIM4 
- GPIO_AF2_TIM5 
- GPIO_AF3_TIM8 
- GPIO_AF3_TIM9 
- GPIO_AF3_TIM10 
- GPIO_AF3_TIM11 
- GPIO_AF4_I2C1 
- GPIO_AF4_I2C2 
- GPIO_AF4_I2C3
- GPIO_AF5_SPI1 
- GPIO_AF5_SPI2 
- GPIO_AF5_SPI3 
- GPIO_AF5_SPI4 
- GPIO_AF5_SPI5 
- GPIO_AF5_SPI6 
- GPIO_AF5_I2S3ext 
- GPIO_AF6_SPI3 
- GPIO_AF6_I2S2ext 
- GPIO_AF6_SAI1 
- GPIO_AF7_USART1 
- GPIO_AF7_USART2 
- GPIO_AF7_USART3 
- GPIO_AF7_I2S3ext 
- GPIO_AF8_UART4 
- GPIO_AF8_UART5 
- GPIO_AF8_USART6 
- GPIO_AF8_UART7 
- GPIO_AF8_UART8 
- GPIO_AF9_CAN1 
- GPIO_AF9_CAN2 
- GPIO_AF9_TIM12 
- GPIO_AF9_TIM13 
- GPIO_AF9_TIM14 
- GPIO_AF9_LTDC 
- GPIO_AF9_QSPI 
- GPIO_AF10_OTG_FS 
- GPIO_AF10_OTG_HS
