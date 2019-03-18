#include <Servo.h>
#define potent_pin 5   // сюда подключена средняя нога потенциометра
int val;               // переменная для хранения значения с потенциометра
Servo servo1;

void setup() {
  servo1.attach(6);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(potent_pin);     // запомнить показания с потенциометра
  val = map(val, 0, 1023, 0, 180);   // перевести в диапазон 0.. 10
  val = constrain(val, 0, 180);      // ограничить диапазон 0.. 10

  int potent = analogRead(5);
  potent = map(potent, 0, 1023, 0, 180);
  servo1.write(potent);
  delay(2);
  Serial.println(potent);
  Serial.println(val);

}
