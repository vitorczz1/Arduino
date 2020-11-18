// Programa : Contador utilizando display 7 segmentos e TCRT5000  
// Alterações e adaptações : Arduino e Cia  
//  
// Baseado no exemplo da biblioteca SevSeg, de Dean Reading  
// deanreading@hotmail.com  
   
#include "SevSeg.h" //Carrega a biblioteca SevSeg  
   
SevSeg sevseg;  

int pino_led_verde = 15;
int pino_led_vermelho = 14;
int contador1 = 0;
int divisao = 2;

//Ligado ao pino "coletor" do sensor Infra - Porta A5 ao Arduino  
int pinosensor = 19; 
int estado_sensor; //Armazena o valor lido pelo sensor  


void setup() 
{  
  pinMode(pino_led_verde, OUTPUT);
  pinMode(pino_led_vermelho, OUTPUT);

  //Utilizando display de anodo comum, pinos dos digitos : 10 a 13  
  //Pino dos segmentos : 2 a 9  
  sevseg.Begin(1,13,10,11,12,2,3,4,5,6,7,8,9);  
  //Controla a luminosidade - 0 a 100  
  sevseg.Brightness(20);  
  //Define o pino do sensor optico como entrada 
  pinMode(pinosensor, INPUT);
}  
   
void loop() 
{  
  //Produce an output on the display  
  sevseg.PrintOutput();  
  sevseg.NewNum(contador1,(byte) 2);

  //Le as informações do pino do sensor  
  estado_sensor = digitalRead(pinosensor);   
  if (estado_sensor !=1) //Verifica se o objeto foi detectado  
  {
  digitalWrite(pino_led_verde, LOW);
  digitalWrite(pino_led_vermelho, HIGH);
  {  
    Serial.println(contador1++);
    delay(001);
     if (contador1 == 2)
   {
      contador1 = contador1+1;
  }}}
     else
  {
    // Sem movimento, mantem led verde ligado
    digitalWrite(pino_led_verde, HIGH);
    digitalWrite(pino_led_vermelho, LOW);

  }
//Loop caso o objeto pare sobre o sensor 
    while(digitalRead(pinosensor) != 1)     
    {  
      sevseg.PrintOutput();  
     sevseg.NewNum(contador1,(byte) 2);  
    }  
   } 
