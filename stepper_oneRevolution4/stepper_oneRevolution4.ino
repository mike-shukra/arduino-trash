#include<AccelStepper.h>
 
#define HALFSTEP 8   
 
// Определение пинов для управления двигателем
#define motorPin1  11 // IN1 на 1-м драйвере ULN2003
#define motorPin2  10 // IN2 на 1-м драйвере ULN2003
#define motorPin3  9 // IN3 на 1-м драйвере ULN2003
#define motorPin4  8 // IN4 на 1-м драйвере ULN2003
 
// Инициализируемся с последовательностью выводов IN1-IN3-IN2-IN4 
// для использования AccelStepper с 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
 
void setup(){
  stepper1.setMaxSpeed(1000.0);
  stepper1.setAcceleration(100.0);
  stepper1.setSpeed(200);
  stepper1.moveTo(20000);
}
 
void loop(){
  // Изменяем направление, если шаговик достигает заданного положения
  if(stepper1.distanceToGo()==0)
    stepper1.moveTo(-stepper1.currentPosition());
  stepper1.run();
}
