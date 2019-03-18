// Порты, на которых висят светодиоды и кнопка.
byte pinBtn   = 2; // Кнопка на 2 пине.
byte pinRed   = 5;  // Красные светодиоды на 5 пине.
byte pinGreen = 6;  // Зеленые светодиоды на 6 пине.
byte pinBlue  = 3;  // Синие светодиоды на 3 пине.

// Номер текущего эффекта.
static byte mode = 1;

// Для работы кнопки (анти дребезг).
static byte tempButton = LOW;
static byte button = LOW;

// Дополнительные переменные.
static int state = 0;
static int index = 0;

void setup()
{
  // Настраиваем порт кнопки.
  pinMode(pinBtn, INPUT);
  // Т.к. мы используем ШИМ, то настраивать порты для ленты не надо.
}

void loop()
{

  // Отлавливаем нажатие кнопки.
  button = digitalRead(pinBtn);
  if (tempButton && !button)
  {
    // Небольшой анти дребезг.
    tempButton = button;
    delay(10);
    button = digitalRead(pinBtn);
    // Все хорошо, меняем эффект.
    if (button == tempButton)
    {
      // Переключаем на следующий эффект.
      mode++;
      if (mode > 6) mode = 1; // Зацикливаем эффекты по кругу.
      // Сбрасываем дополнительные переменные.
      state = 0;
      index = 0;
      // Выключаем все светодиоды.
      analogWrite(pinRed,   255);
      analogWrite(pinGreen, 255);
      analogWrite(pinBlue,  255);
    }
  }
  tempButton = button;
  
  // Обработка наших эффектов.
  switch (mode)
  {
    case 1: // Эффект №1: Все решает случай.
            analogWrite(pinRed,   random(0, 255));
            analogWrite(pinGreen, random(0, 255));
            analogWrite(pinBlue,  random(0, 255));
            break;
    
    case 2: // Эффект №2: Бегущий огонек. 
            if (state == 3)
            {
              analogWrite(pinRed,   255);
              analogWrite(pinGreen, 0);
            }
            if (state == 6)
            {
              analogWrite(pinBlue, 255);
              analogWrite(pinRed,  0);
            }
            if (state == 9)
            {
              analogWrite(pinGreen, 255);
              analogWrite(pinBlue,  0);
            }
            state--;
            if (state < 1) state = 9;
            break;
    
    case 3: // Эффект №3: Бегущий огонек (В обратную сторону).
            if (state == 1)
            {
              analogWrite(pinBlue,  255);
              analogWrite(pinGreen, 0);
            }
            if (state == 4)
            {
              analogWrite(pinGreen, 255);
              analogWrite(pinRed,   0);
            }
            if (state == 7)
            {
              analogWrite(pinRed,  255);
              analogWrite(pinBlue, 0);
            }
            state++;
            if (state > 9) state = 1;
            break;
    
    case 4: // Эффект №4: Затухание.
            if (state == 0)
            {  
               analogWrite(pinBlue, index);
               analogWrite(pinGreen, 255 - index);
            }
            if (state == 1)
            {
               analogWrite(pinGreen, index);
               analogWrite(pinRed, 255 - index);
            }
            if (state == 2)
            {
               analogWrite(pinRed, index);
               analogWrite(pinBlue, 255 - index);
            }
            index += 5;
            if (index > 255)
            {
              state++;
              index = 0;
              if (state > 2) state = 0;
            }
            break;
    
    case 5: // Включить ленту.
            analogWrite(pinRed,   0);
            analogWrite(pinGreen, 0);
            analogWrite(pinBlue,  0);
            break;
            
    case 6: // Выключить ленту.
            analogWrite(pinRed,   255);
            analogWrite(pinGreen, 255);
            analogWrite(pinBlue,  255);
            break;                
  }

  // Задержка в 50мс.
  delay(50);
}
