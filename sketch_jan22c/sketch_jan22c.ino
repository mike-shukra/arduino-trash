/*
  Пример использования тактовой кнопки в ардуино.
  Кнопка подключена к пину 2.
*/
 
const int PIN_BUTTON = 2;
 
void setup() {
  Serial.begin(9600);
  
}
 
void loop() {
  // Получаем состояние кнопки и выводим в мониторе порта
  int buttonState = digitalRead(PIN_BUTTON);
  Serial.println(buttonState);
  delay(50);
}
