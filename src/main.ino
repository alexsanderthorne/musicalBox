// incluindo a biblioteca do LCD
#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int estadoButtonVerde = 0;
int estadoButtonAmarelo = 0;

//Pinos na conexão digital do botão
int buttonPinVerde = 6;
int buttonPinAmarelo = 7;

// contadores
int ultimoClickButton = 0;
int buttonPushCounter = 0;
int controleEstadoButton = 0;

//count = 0;

void setup() {
  pinMode(10, OUTPUT);
  pinMode(buttonPinVerde, INPUT_PULLUP);
  pinMode(buttonPinAmarelo, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Test");
  lcd.begin(16, 2);
  lcd.setCursor(3, 0);
  lcd.print("Music Box");
}

void loop() {
  estadoButtonVerde = digitalRead(buttonPinVerde);
  estadoButtonAmarelo = digitalRead(buttonPinAmarelo);

  Serial.println(estadoButtonAmarelo);
  for (int count = 0; count < 5; ++count) {
    if (digitalRead(buttonPinAmarelo) == LOW) {
      delay(100);
      //playSongPirates();
    }

    if (digitalRead(buttonPinVerde) == LOW and count == 1) {
      delay(100);
      //playSongMarioBross();
      playSongPirates();
    }
    if (digitalRead(buttonPinVerde) == LOW and count == 2) {
      noTone(10);
      delay(100);
      //playSongMarioBross();
      playSongStarWazz();

    }
    if (digitalRead(buttonPinVerde) == LOW and count == 3) {
      noTone(10);
      delay(100);
      playSongAsaBranca();
    }
    ++count;
  }

}
