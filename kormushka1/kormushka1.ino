/*
Youtube video: https://youtu.be/dKjynl9-9s0
Youtube channel:  https://www.youtube.com/channel/UC82y1uu7k08kq9SMpckNRoA
*/

// библиотека с командами для сервоприводов
#include <Servo.h> 

Servo servo1;  // servo /объект сервопривод 
 
int servoPIN=6; //Servo pin /контакт сервопривода

unsigned long Pause=(long)1*60*60*1000;//feeding delay, ms/ 12h*60min*60sec*1000 // время между кормлением в мс = 12ч*60мин*60сек*1000

// int Pause=5000; // fot test

int Y0=0; // close angle /угол сервы в закрытом положении
int Y1=40; // close angle /угол сервы в открытом положении
int t=100; // delay for shake mode /приостановка в промежуточных положениях при открытии, мс (режим тряски)
 
void setup()
{

  // Serial.begin(9600); //test последовательный порт для отображения данных
}
 
void loop()
{
 // time=millis();
  
  Open () ;//open function/ функция открытия крышки
 // Serial.println(Pause); //test
 
  delay(Pause); // wait next feeding //ждем до следующего кормления
 
} //loop



//********************** ФУНКЦИИ *****************************************
//***************************************************************

void Open() //open function //функция открытия крышки
{
  servo1.attach(servoPIN); // подкючаем сервопривод к цифровому выходу Х
  int pos; // position/ положение сервы
    
//----  open//цикл плавного открытия с шагом Х град.
  for(pos = Y0; pos < Y1; pos += 5) // шаг=угол
  {
    servo1.write(pos);  // передвинься на следующую позицию
    delay(20);               // небольшой перерыв чтобы он успел передвинуться
  }
     delay(110);               // небольшой перерыв 
//---- 
  
  
//---- close- shake mode / цикл зкрытия с потрясыванием
  for(pos = Y1; pos >= Y0; pos -= 8) //шаг=угол
  {                               
    servo1.write(pos);  // передвинься на следующую позицию
    delay(t);               // небольшой перерыв чтобы он успел передвинуться
    servo1.write(pos-5);  // чуть призакроем
    delay(t);
    servo1.write(pos);  // передвинься на следующую позицию
    delay(t);  
  }

//----  additional shaking /цикл дополнительной тряски в конце
  for(int i = 0; i <= 3; i += 1) //
  {
    servo1.write(14);  // передвинься на следующую позицию
    delay(400);
    servo1.write(Y0);     // повернись до уровня закрытия
        delay(200);
  }  
 //----  
 
    delay(1500); // пауза перед расслаблением

    servo1.detach(); //отключаем сервопривод
 
}
