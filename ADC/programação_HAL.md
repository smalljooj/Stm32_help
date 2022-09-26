# Programação em HAL 

- [Configurar o ADC](#Configurando-o-ADC)
- [Usar o ADC](#Usando-o-ADC)

# Configurando o ADC

Para configurar o ADC para o uso, seguimos os seguinte passos:
- [Habilitar o clock do GPIO](#Habilitando-o-Clock-do-GPIO)
- [Configurar o ADC](#Configurando-o-ADC)
- [Inicializar o ADC](#Inicializando-o-ADC)

## Habilitando o Clock do GPIO

Para habilitar o clock do GPIO em questão utilizamos o seguinte código:  
`__HAL_RCC_GPIOx_CLK_ENABLE()`

Onde o 'x' do código é substituido pela letra do GPIO em questão, para
habilitar o clock do GPIOA por exemplo usamos o seguinte código:  
`__HAL_RCC_GPIOA_CLK_ENABLE()`

## Configurando o ADC

Para configurarmos a adc usando a HAL assim como para configurar o GPIO
iremos utilizar uma estrutura, mas agora chamada de ADC_HandleTypeDef.
Essa estrutura irá ser utilizada tanto para configurar e inicializar como
para utilizar o ADC, por isso é interessante declarar no topo do programa.

`ADC_HandleTypeDef adc = {0}`

Para configurarmos iremos seguir os seguintes passos:

- Atribuir a Instancia
- Atribuir o Preescaler
- Atribuir a resolução
- Definir o Scan Mode
- Definir conversão contínua
- Definir o alinhamento de dados
- Atribuir o número de Conversões
- Definir EOC

Todos são campos da estrutura que definimos. Lembrando que no final estará 
as macros para configurar os campos. [Clique Aqui](#Macros).

### Atribuir a Instancia

Usaremos o campo Instance da estrutura e diremos qual o adc que usaremos.

Ex : `adc.Instance = ADC2`

### Atribuir o Preescaler

Usaremos o campo ClockPrescaler que faz parte do Atributo Init que é onde possui 
todas as configurações de Inicialização.

Ex: `adc.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2`

### Atribuir a resolução

Usaremos o campo Resolution que faz parte do Atributo Init.

Ex `adc.Init.Resolution = ADC_RESOLUTION_12B`

### Definir o Scan Mode

Usaremos o campo ScanConvMode que faz parte do Atributo Init.

Ex `adc.Init.ScanConvMode = DISABLE // Para habilitar é so usar o ENABLE` 

### Definir conversão contínua

Usaremos o campo ContinuousConvMode que faz parte do Atributo Init.

Ex `adc.Init.ContinuousConvMode = DISABLE // Para habilitar é so usar o ENABLE`

### Definir o alinhamento de dados

Usaremos o campo DataAlign que faz parte do Atributo Init.

Ex `adc.Init.DataAlign = ADC_DATAALIGN_RIGHT // Pode ser usado o ADC_DATAALIGN_LEFT, para alinhamento a esquerda`

### Atribuir o número de Conversões

Usaremos o campo NbrOfConversion que faz parte do Atributo Init.

Ex `adc.Init.NbrOfConversion = 1`

### Definir EOC

Usaremos o campo EOCSelection que faz parte do Atributo Init.

Ex `adc.Init.EOCSelection = ADC_EOC_SINGLE_CONV`

## Inicializando o ADC

Para inicializar o ADC utilizaremos a função HAL_ADC_Init, em
que passaremos o endereço da estrutura que criamos e configuramos.

Ex: `HAL_ADC_Init(&adc)`

## Configurando o canal

Precisamos definir outra estrutura, essa pode ser local, e será do tipo
ADC_ChannelConfTypeDef.

Com ela definiremos o canal, o rank o Sampling Time.

Ex:

    ADC_ChannelConfTypeDef adc_channel;
    adc_channel.Channel = ADC_CHANNEL_0;
    adc_channel.Rank = 1;
    adc_channel.SamplingTime = ADC_SAMPLETIME_3CYCLES

E por fim usamos a Função HAL_ADC_ConfigChannel passando a estrutura adc, e 
estrutura de configuração de canal.

# Usando o ADC

Iniciamos o ADC usando a função HAL_ADC_Start passando a estrutura do ADC:  
`HAL_ADC_Start(&adc);`

E para iniciar uma conversão única podemos usar a função HAL_ADC_PollForConversion, passando
a estrutura do adc e o tempo de timeout:  
`int leitura = HAL_ADC_PollForConversion(&adc, 100);`

Por fim para pegar a leitura usamos a função HAL_ADC_GetValue, passando o adc:  
`int leitura = HAL_ADC_GetValue(&adc)`

# Macros

## ADC Clock Prescaler

- ADC_CLOCK_SYNC_PCLK_DIV2 
- ADC_CLOCK_SYNC_PCLK_DIV4 
- ADC_CLOCK_SYNC_PCLK_DIV6
- ADC_CLOCK_SYNC_PCLK_DIV8

## EOC Selection

- ADC_EOC_SEQ_CONV 
- ADC_EOC_SINGLE_CONV
- ADC_EOC_SINGLE_SEQ_CONV

## ADC Resolution

- ADC_RESOLUTION_12B
- ADC_RESOLUTION_10B
- ADC_RESOLUTION_8B
- ADC_RESOLUTION_6B

## ADC SamplingTime

- ADC_SAMPLETIME_3CYCLES
- ADC_SAMPLETIME_15CYCLES
- ADC_SAMPLETIME_28CYCLES
- ADC_SAMPLETIME_56CYCLES
- ADC_SAMPLETIME_84CYCLES
- ADC_SAMPLETIME_112CYCLES
- ADC_SAMPLETIME_144CYCLES
- ADC_SAMPLETIME_480CYCLES
