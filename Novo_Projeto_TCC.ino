// 
//

int pino_led_verde = 3;
int pino_led_vermelho = 5;
int pino_buzzer = 7;
int pino_sensor = 9;
int estado_sensor = 0;
int contador = 1;
int divisao = 2;

void setup()
{
  Serial.begin(9600);
  // Define o pino do sensor como entrada
  pinMode(pino_sensor, INPUT);
  // Define os pinos dos leds e buzzer como saida
  pinMode(pino_led_verde, OUTPUT);
  pinMode(pino_led_vermelho, OUTPUT);
  pinMode(pino_buzzer, OUTPUT);
  Serial.println("Contador de Pessoas");
}

void loop()
{
  estado_sensor = digitalRead(pino_sensor);
  if (estado_sensor == 0)
  {
    // Desliga o led verde e acende o vermelho
    digitalWrite(pino_led_verde, LOW);
    digitalWrite(pino_led_vermelho, HIGH);
    // Aciona o buzzer 3 vezes
    for (int i = 1; i <= 3; i++)
    {
      digitalWrite(pino_buzzer, HIGH);
      delay(100);
      digitalWrite(pino_buzzer, LOW);
      delay(100);
    }
    // Envia mensagem para o Serial Monitor
    Serial.println(divisao + contador++ - 2);
    delay(001);
  }
  else
  {
    // Sem movimento, mantem led verde ligado
    digitalWrite(pino_led_verde, HIGH);
    digitalWrite(pino_led_vermelho, LOW);
    digitalWrite(pino_buzzer, LOW);
  }
}
