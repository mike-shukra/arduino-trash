int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;
const int dl = 1;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  digitalWrite( in1, HIGH ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in4, LOW );
  delay(dl);

  digitalWrite( in1, HIGH ); 
  digitalWrite( in2, HIGH ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in4, LOW );
  delay(dl);

  digitalWrite( in1, LOW ); 
  digitalWrite( in2, HIGH ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in4, LOW );
  delay(dl);

  digitalWrite( in1, LOW ); 
  digitalWrite( in2, HIGH ); 
  digitalWrite( in3, HIGH ); 
  digitalWrite( in4, LOW );
  delay(dl);

  digitalWrite( in1, LOW ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in3, HIGH ); 
  digitalWrite( in4, LOW );
  delay(dl);

  digitalWrite( in1, LOW ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in3, HIGH ); 
  digitalWrite( in4, HIGH );
  delay(dl);

  digitalWrite( in1, LOW ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in4, HIGH );
  delay(dl);

  digitalWrite( in1, HIGH ); 
  digitalWrite( in2, LOW ); 
  digitalWrite( in3, LOW ); 
  digitalWrite( in4, HIGH );
  delay(dl);
}
