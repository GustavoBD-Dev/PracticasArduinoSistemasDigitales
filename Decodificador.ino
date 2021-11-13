//Entradas: 9,10,11,12
//Salidas: 1,2,3,4,5,6,7,8
//Pass: 13
// Pines para entrada de datos
int inputPin [] = {
  10, 11, 12, 13
};
int countInput = 4;
// Pines para salida de datos
int outputPIN[] = {
  2, 3, 4, 5, 6, 7, 8, 9
};
int countOutput = 8;
// pushBoton
int pass = 13;
int HEXA [][8] = {
  {1, 0, 0, 0, 1, 1, 1, 1},
  {1, 0, 0, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 0, 1, 1},
  {0, 0, 0, 1, 1, 0, 1, 1},
  {0, 0, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 0, 0, 0, 1, 0},
  {1, 0, 1, 1, 1, 1, 1, 0},
  {1, 0, 1, 1, 0, 1, 1, 0},
  {0, 1, 1, 0, 0, 1, 1, 0},
  {1, 1, 1, 1, 0, 0, 1, 0},
  {1, 1, 0, 1, 1, 0, 1, 0},
  {0, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 0, 0}
};


int NAME [][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {1, 0, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 1, 1, 1, 0, 0},
  {1, 0, 1, 1, 0, 1, 1, 0},
  {1, 1, 1, 0, 0, 0, 0, 0},
  {1, 1, 1, 0, 1, 1, 1, 0},
  {0, 1, 1, 1, 1, 1, 0, 0},
  {1, 1, 1, 1, 1, 1, 0, 1}
};
void setup() {
  Serial.begin(9600);
  for (int i = 0; i < countInput; i++) {
    pinMode(inputPin[i], INPUT);
  }
  for (int i = 0; i < countOutput; i++) {
    pinMode(outputPIN[i], OUTPUT);
  }
  pinMode(pass, INPUT);
}
void loop() {
  if (digitalRead(0) == 0) {
    Serial.println(digitalRead(0));
    for (int k = 0; k < 8; k++) {
      //recorremos cada uno de las salidas para el display
      for (int i = 0; i < 8; i++) {
        digitalWrite(outputPIN[i], NAME[k][i]);
      }
      delay(600);
    }
  } else {
    // lectura de pines declarados como entrada
    int A0 = digitalRead(10);
    int A1 = digitalRead(11);
    int A2 = digitalRead(12);
    int A3 = digitalRead(13);
    // obtenemos el valor de la entrada y convertimos a decimal
    int value = ((A3 * 8) + (A2 * 4) + (A1 * 2) + (A0 * 1));
    Serial.print("Value input: ");
    Serial.println(value);

    for (int k = 0; k < 16; k++) {
      if (k == value) {
        //recorremos cada uno de las salidas para el display
        for (int i = 0; i < countOutput; i++) {
          digitalWrite(outputPIN[i], HEXA[k][i]);
          Serial.print(value);
          Serial.print(" - ");
          Serial.print(k);
          Serial.print(" - ");
          Serial.print(i);
          Serial.print(" - ");
          Serial.print(outputPIN[i]);
          Serial.print(" -> ");
          Serial.println(HEXA[k][i]);
        }
      }
      Serial.println(k);
    }
  }


}
