//int vSpeed      = 110;        // MAX 255 //declarar cuando se usen los pines de enable desde un pin del arduino.
//int turn_speed  = 230;        // MAX 255 

int turn_delay  = 50;

//L293D   
const int motorA1           = 2;  
const int motorA2           = 3; 
//const int motorAspeed     = 9;   //mirar de conectar
const int motorB1           = 4; 
const int motorB2           = 5; 
//const int motorBspeed     = 11;  //mirar de conectar

//Sensores
const int left_sensor_pin   = 7;
const int right_sensor_pin  = 6;
const int back_sensor_pin   = 8;

//estado de los sensores
int left_ss;
int right_ss;
int back_ss;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);

  Serial.begin(9600);
  delay(3000);
}

void loop() {
  left_ss   = digitalRead(left_sensor_pin);
  right_ss  = digitalRead(right_sensor_pin);
  back_ss   = digitalRead(back_sensor_pin);
  
  if(left_ss == 0 && right_ss == 0 && back_ss == 0){ 
    izquierda();
    delay(50);
    adelante();
  }
  if(left_ss == 0 && right_ss == 0 && back_ss == 1){
    adelante();
  }
  if(left_ss == 0 && right_ss == 1 && back_ss == 0){
    derecha();
    delay(50);
    adelante();
  }
  if(left_ss == 0 && right_ss == 1 && back_ss == 1){
    derecha();
    delay(50);
    adelante();
    delay(50);
  }
  if(left_ss == 1 && right_ss == 0 && back_ss == 0){
    izquierda();
    delay(50);
    adelante();
  }
  if(left_ss == 1 && right_ss == 1 && back_ss == 0){
    derecha();
    delay(50);
    adelante();
    delay(50);
  }
  if(left_ss == 1 && right_ss == 0 && back_ss == 1){
    izquierda();
    delay(50);
    adelante();
    delay(50);
  }
  if(left_ss == 1 && right_ss == 1 && back_ss == 1){
    parar();
  }
}

void izquierda(){
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);

  //analogWrite (motorAspeed, vSpeed);
  //analogWrite (motorBspeed, turn_speed);
  delay(turn_delay);
}

void derecha(){
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);

  //analogWrite (motorAspeed, turn_speed);
  //analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
}

void adelante(){
  digitalWrite (motorA2,LOW);
  digitalWrite(motorA1,HIGH);                       
  digitalWrite (motorB2,HIGH);
  digitalWrite(motorB1,LOW);

  //analogWrite (motorAspeed, vSpeed);
  //analogWrite (motorBspeed, vSpeed);

  delay(turn_delay);
}

void parar(){
  digitalWrite (motorA2,LOW);
  digitalWrite(motorA1,LOW);                       
  digitalWrite (motorB2,LOW);
  digitalWrite(motorB1,LOW);
  
  //analogWrite (motorAspeed, 0);
  //analogWrite (motorBspeed, 0);
}
