/*
  Скетч для схемы с использованием тактовой кнопки и светодиода
  Светодиод мигает, пока нажата кнопка.
  Кнопка подтянута к земле, нажатию соответствует HIGH на входе
*/
 
const int PIN_BUTTON = 2;
const int PIN_LED = 13;
 
void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
}
 
void loop() {
  // Получаем состояние кнопки
  int buttonState = digitalRead(PIN_BUTTON);
  Serial.println(buttonState);
  // Если кнопка не нажата, то ничего не делаем
  if (!buttonState) {
    delay(50);
    return;
  }
 
  // Этот блок кода будет выполняться, если кнопка нажата
  // Мигаем светодиодом
  digitalWrite(PIN_LED, HIGH);
  delay(1000);
  digitalWrite(PIN_LED, LOW);
  delay(1000);
}
