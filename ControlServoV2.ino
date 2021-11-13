#include <Servo.h>
Servo myservo; // create servo object to control a servo
int potpin0 = A0; // analog pin used to connect the potentiometer GRADE
int potpin1 = A1; // analog pin used to connect the potentiometer
int potpin9 = 9; // digital pin used to connect the control servo
int val; // variable to read the value from the analog pin
int posActual;
int posFinal;
int velocidad;
 int timeSpeed;
 int timeSpeedPrevious;
void setup() {
  myservo.attach(9);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  // attaches the servo on pin 9 to the servo object
}
void loop(){
  // obtenemos la posicion actual del servo 
  posActual = map(analogRead(potpin0), 0, 1023, 0, 180);
  delay(15);

  // obtenemos la posicion final del servo 
  posFinal = map(analogRead(potpin0), 0, 1023, 0, 180);
  for(int pos = posActual; pos <= posFinal; pos++){
    myservo.write(pos);
    // waits for the servo to get there
    delay(wait());
  }
}

int wait(){
 
  velocidad = map(analogRead(1), 0, 1023, 1000, 5000);
  if (posFinal > posActual) { // el grado de posicion es mayor 
    timeSpeed = round(velocidad/(posFinal-posActual));
  } else if (posFinal < posActual) {
    timeSpeed = round(velocidad/(posActual-posFinal));
  } else{
    timeSpeed = timeSpeedPrevious;
  }
  timeSpeedPrevious = timeSpeed;
  Serial.println(timeSpeed);
  return timeSpeed;
  
}
