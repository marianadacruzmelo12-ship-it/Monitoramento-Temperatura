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

void setup()
{
  // Inicia o LCD com 16 colunas e 2 linhas
  lcd.begin(16, 2);

  // Inicia o Monitor Serial
  Serial.begin(9600);
}

void loop()
{
  // Faz a leitura do sensor TMP36
  int leitura = analogRead(sensor);

  // Converte a leitura para tensão
  float tensao = leitura * (5.0 / 1023.0);

  // Converte a tensão para temperatura em graus Celsius
  float temperatura = (tensao - 0.5) * 100.0;

  // Limpa o LCD
  lcd.clear();

  // Mostra a temperatura no LCD
  lcd.setCursor(0, 0);
  lcd.print("Temperatura:");

  lcd.setCursor(0, 1);
  lcd.print(temperatura, 1);
  lcd.write(223);
  lcd.print("C");

  // Mostra a temperatura no Monitor Serial
  Serial.print("Temperatura: ");
  Serial.print(temperatura, 1);
  Serial.println(" C");

  // Aguarda 500 milissegundos
  delay(500);
}
