/*
 * Скетч, моргающий встроенным светодиодом на плате Arduino.
 * Может служить проверочным скетчем для проерки Arduino
 */

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
}
