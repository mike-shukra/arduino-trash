/*
  Кнопка
  
 Включаем и выключаем светодиод нажатием кнопки.
  
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 28 Oct 2010
 by Tom Igoe
  
 This example code is in the public domain.
 */
 
// задаем константы
const int buttonPin = 2;     // номер входа, подключенный к кнопке
const int ledPin =  13;      // номер выхода светодиода
 
// переменные
int buttonState = 0;         // переменная для хранения состояния кнопки
 
void setup() {
  // инициализируем пин, подключенный к светодиоду, как выход
  pinMode(ledPin, OUTPUT);     
  // инициализируем пин, подключенный к кнопке, как вход
  pinMode(buttonPin, INPUT);   
}
 
void loop(){
  // считываем значения с входа кнопки
  buttonState = digitalRead(buttonPin);
 
  // проверяем нажата ли кнопка
  // если нажата, то buttonState будет HIGH:
  if (buttonState == HIGH) {   
    // включаем светодиод   
    digitalWrite(ledPin, HIGH); 
  }
  else {
    // выключаем светодиод
    digitalWrite(ledPin, LOW);
  }
}
