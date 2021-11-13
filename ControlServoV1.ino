#include <Servo.h>
Servo servo1;
int pinControl = 9;
int posicionFinal = 0;
int posicionActual = 0;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  servo1.attach(pinControl);
}

void loop() {
  posicionFinal = map(analogRead(A1), 0, 1023, 0, 180);
 /* if (posicionActual < posicionFinal) {
    iteracion = 1;
  } else if (posicionActual > posicionFinal) {
    iteracion = -1;
  } else {
    iteracion = 0;
  }*/
  
  do {
    servo1.write(posicionActual);
    if (posicionActual < posicionFinal){
      posicionActual++;
    }else if (posicionActual > posicionFinal){
      posicionActual--;
    } 
    delay(map(analogRead(A0), 0, 1023, 15, 2000));
  } while (posicionActual != posicionFinal);
  posicionActual = posicionFinal;
  /*
  posicionFinal = map(analogRead(A1), 0, 1023, 0, 180);
  if (posicionActual < posicionFinal) {
    iteracion = 1;
  } else if (posicionActual > posicionFinal) {
    iteracion = -1;
  } else {
    iteracion = 0;
  }
  
  do {
    servo1.write(posicionActual);
    posicionActual = posicionActual + iteracion;
    delay(map(analogRead(A0), 0, 1023, 15, 2000));
  } while (posicionActual != posicionFinal);
  posicionActual = posicionFinal;*/
}
