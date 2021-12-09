//#include <stdlib.h>
//#include <stdio.h>
//#include <piratesOfTheCaribbean>

int estadoButtonVerde = 0;
int estadoButtonAmarelo = 0;

//Pinos na conexão digital do botão
int buttonPinVerde = 6;
int buttonPinAmarelo = 7;

// contadores
int ultimoClickButton = 0;
int buttonPushCounter = 0;
int controleEstadoButton = 0;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(buttonPinVerde, INPUT_PULLUP);
  pinMode(buttonPinAmarelo, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Test");
}

void loop() {
  estadoButtonVerde = digitalRead(buttonPinVerde);
  estadoButtonAmarelo = digitalRead(buttonPinAmarelo);

  Serial.println(estadoButtonAmarelo);
  if (digitalRead(buttonPinAmarelo) == LOW) {
    delay(100);
    playSongPirates();
  }

  if (digitalRead(buttonPinVerde) == LOW){
    delay(100);
    playSongStarWazz();
  }
}
