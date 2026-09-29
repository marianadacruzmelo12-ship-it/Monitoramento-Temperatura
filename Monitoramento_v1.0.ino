const int sensor = A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int leitura = analogRead(sensor);

  float tensao = leitura * (5.0 / 1023.0);
  float temperatura = (tensao - 0.5) * 100.0;

  Serial.print("Temperatura: ");
  Serial.print(temperatura, 1);
  Serial.println(" C");

  delay(500);
}
