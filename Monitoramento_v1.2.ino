#include <LiquidCrystal.h>

// Define os pinos do LCD
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

// Inicializa o LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Define o pino do sensor TMP36
const int sensor = A0;

// Define os pinos dos LEDs
const int ledVerde = 8;
const int ledAmarelo = 9;
const int ledVermelho = 10;

void setup()
{
  // Inicia o LCD
  lcd.begin(16, 2);

  // Define os LEDs como saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  // Inicia o Monitor Serial
  Serial.begin(9600);
}

void loop()
{
  // Faz a leitura do sensor TMP36
  int leitura = analogRead(sensor);

  // Converte a leitura para tensão
  float tensao = leitura * (5.0 / 1023.0);

  // Converte a tensão para temperatura
  float temperatura = (tensao - 0.5) * 100.0;

  // Desliga todos os LEDs antes de verificar a temperatura
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);

  // Limpa o LCD
  lcd.clear();

  // Mostra a temperatura no LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperatura, 1);
  lcd.write(223);
  lcd.print("C");

  // Temperatura abaixo de 20°C = FRIO
  if (temperatura < 20.0)
  {
    digitalWrite(ledAmarelo, HIGH);

    lcd.setCursor(0, 1);
    lcd.print("FRIO");
  }

  // Temperatura de 20°C até 29,9°C = NORMAL
  else if (temperatura < 30.0)
  {
    digitalWrite(ledVerde, HIGH);

    lcd.setCursor(0, 1);
    lcd.print("NORMAL");
  }

  // Temperatura igual ou acima de 30°C = ALERTA
  else
  {
    digitalWrite(ledVermelho, HIGH);

    lcd.setCursor(0, 1);
    lcd.print("ALERTA");
  }

  // Mostra a temperatura no Monitor Serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura, 1);
  Serial.println(" C");

  // Aguarda meio segundo para fazer uma nova leitura
  delay(500);
}
