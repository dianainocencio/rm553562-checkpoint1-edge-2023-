int ledvermelho = 11;
int ledamarelo = 10;
int ledverde = 9;
int LDR = A0;
int buzzer = 7; 
int valorLDR = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledvermelho, OUTPUT);
  pinMode(ledverde, OUTPUT);
  pinMode(ledamarelo, OUTPUT);
  pinMode(LDR, INPUT);
  pinMode(buzzer, OUTPUT); 
}

void loop() {
  int Valorldr = analogRead(LDR);
  
  // Luminosidade Baixa - Crítico 
  if (Valorldr < 100){
    apagaLeds();
    digitalWrite(ledvermelho, HIGH);
  } 
  // Luminosidade Média - Alerta 
  else if (Valorldr >= 100 && Valorldr < 150) {
    apagaLeds();
    digitalWrite(ledamarelo, HIGH);
    tocarBuzzer(3000); // Toca o buzzer por 3 segundos
  } 
  // Luminosidade Alta - Ideal 
  else if (Valorldr >= 150) {
    apagaLeds();
    digitalWrite(ledverde, HIGH);
  }
  
  Serial.println(Valorldr);
  delay(1000);  
}

void apagaLeds() {
  digitalWrite(ledvermelho, LOW);
  digitalWrite(ledverde, LOW);
  digitalWrite(ledamarelo, LOW);
}

// Função para tocar o buzzer por um tempo especificado
void tocarBuzzer(int tempo) {
  digitalWrite(buzzer, HIGH);
  delay(tempo);
  digitalWrite(buzzer, LOW);
}
