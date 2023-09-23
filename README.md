# Controle de Iluminação com Sensor LDR e LEDs

Este é um código para um projeto de controle de iluminação usando um sensor de luz LDR (Light-Dependent Resistor) e LEDs. O projeto monitora a luminosidade do ambiente usando o sensor LDR e ajusta a iluminação com base nessa medida, acendendo diferentes LEDs em resposta aos níveis de luminosidade detectados. Além disso, um buzzer é usado para fornecer alertas sonoros em determinadas condições.

## Componentes Necessários
- Arduino (ou outra placa compatível)
- Sensor de luz LDR
- LEDs (vermelho, amarelo e verde)
- Buzzer
- Resistor (para o sensor LDR)
- Cabos e breadboard (para a montagem do circuito)

## Como Funciona
O código define a configuração e o comportamento do projeto. Aqui está uma visão geral das principais partes do código:

### Variáveis e Pinos
- `ledvermelho`, `ledamarelo`, `ledverde`, `LDR`, e `buzzer` são variáveis que representam os pinos usados para conectar os LEDs, o sensor LDR e o buzzer.
- `valorLDR` é uma variável que armazena a leitura do sensor LDR.

### Setup
O método `setup()` é chamado uma vez quando o Arduino é inicializado. Ele configura os pinos como saídas ou entradas, dependendo de sua função no circuito.

### Loop
O método `loop()` é executado repetidamente após a configuração inicial. Aqui está o que acontece no loop:

1. Lê o valor do sensor LDR usando `analogRead(LDR)` e armazena-o em `valorLDR`.
2. Com base no valor lido do sensor, o código toma decisões sobre como controlar os LEDs e o buzzer para ajustar a iluminação.

#### Luminosidade Baixa - Crítico
- Se `valorLDR` for menor que 100, todos os LEDs são apagados e o LED vermelho é aceso, indicando condições críticas de baixa luminosidade.

#### Luminosidade Média - Alerta
- Se `valorLDR` estiver entre 100 e 150, todos os LEDs são apagados, o LED amarelo é aceso e o buzzer é ativado por 3 segundos. Isso indica uma situação de alerta.

#### Luminosidade Alta - Ideal
- Se `valorLDR` for maior ou igual a 150, todos os LEDs são apagados e o LED verde é aceso, indicando condições ideais de alta luminosidade.

### Funções Adicionais
- `apagaLeds()`: Uma função que apaga todos os LEDs.
- `tocarBuzzer(int tempo)`: Uma função que ativa o buzzer por um período de tempo especificado.

## Uso
Este projeto é útil para automatizar a iluminação com base na luminosidade do ambiente. Ele pode ser implementado em ambientes como salas, corredores ou espaços externos para economizar energia ou fornecer alertas visuais e sonoros quando as condições de luminosidade não são ideais.

**Nota:** Certifique-se de conectar os componentes corretamente ao Arduino antes de carregar este código. Ajuste os limiares de luminosidade nos condicionais (`if`) conforme necessário para se adequarem às suas preferências ou necessidades específicas.
