int volatile Pulses_left;
int volatile Pulses_right;
int volatile Object_detected;
const int triggerPin = 5;
const int echoPin = 4;
void setup() {
  Serial.begin(115200);
  pinMode(2, INPUT); // Left Moter (Feedback)
  pinMode(3, INPUT); // Right Moter (Feedback)
  // -pinMode(4, OUTPUT); //Trigger pin for left sensor
  // pinMode(5, INPUT); //Echo pin for left sensor
  pinMode(A3, INPUT);//Trigger pin for right sensor
  pinMode(7, OUTPUT); // Left Moter (Backwards)
  pinMode(8, OUTPUT); // Left Moter (Forwards)
  pinMode(9, OUTPUT); // Left Moter (Enable)
  pinMode(10, OUTPUT);// Right Moter (Enable)
  pinMode(11, OUTPUT);// Right Moter (Backwards)
  pinMode(12, OUTPUT);// Right Moter (Forwards)
  pinMode(13, OUTPUT);// GREEN LED
  pinMode(6, OUTPUT); // RED LED
  attachInterrupt(digitalPinToInterrupt(2), left_Pulses, RISING); 
  attachInterrupt(digitalPinToInterrupt(3), right_Pulses, RISING); 
  attachInterrupt(digitalPinToInterrupt(5), ping1, CHANGE);
}

void loop() {
  dance();
  delay(1000);
  Story_4();
  delay(2000);
  Story_5();
  delay(4000);
  square_story7();
  delay(2000);
  eight_story8();
  delay(2000);
  nine_story9();
  delay(1000);
  Hard_Stop();
  delay(1000);  
}


void ping1() {
  
  // establish variables for duration of the ping, and the distance result
  // in inches and centimeters:
  long duration, inches, cm;
  cm = 50;
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(100);
  if (cm > 10){
    Forward1();
  }
  else if(cm <= 10){
    Hard_Stop();
    delay(1000); 
    turn_left();
    delay(1000);
    Hard_Stop();
    Serial.print("i work");
    digitalWrite(6, HIGH);
    delay(10000);
     
  }

 /*
 if (cm <= 10){
  Hard_Stop();
  delay(1000);
  turn_left();
  delay(1000);
  Hard_Stop();
  Serial.print("i work");
  digitalWrite(6, HIGH);
  delay(10000);
 } */
}

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
 void Forward1() {
 analogWrite(9, 170);
 analogWrite(10, 170);
 analogWrite(13,200);//LED
 digitalWrite(8, HIGH);
 digitalWrite(12, HIGH);
 digitalWrite(7, LOW);
 digitalWrite(11, LOW);
 digitalWrite(13, HIGH);
 Serial.println("im going looking for objects");
 
}
  void ten_story10(){
    analogWrite(13,200);
    analogWrite(6,200);
    digitalWrite(13, HIGH);
    digitalWrite(6, HIGH);
  }
  void nine_story9() {
  Reverse();  //1st straight
  delay(1000);
  Hard_Stop();
  delay(1000);
  turn_leftbackwards(); //1st turn
  delay(900);
  Hard_Stop();
  delay(1000);
  Reverse();  //2nd straight
  delay(1000);
  Hard_Stop();
  delay(1000);
  turn_leftbackwards2(); //2nd turn
  delay(1200);
  Hard_Stop();
  delay(1000);
  Reverse(); //3rd straight
  delay(1000);
  Hard_Stop();
  delay(1000);
  turn_leftbackwards1(); //3rd turn
  delay(1075);
  Hard_Stop();
  delay(1000);
  Reverse(); //4th straight to lead to the 2nd square
  delay(1750);
  Hard_Stop();
  delay(1000);
  turn_rightbackwards();// start of 2nd square++
  delay(900);
  Hard_Stop();
  delay(1000);
  Reverse(); //5th straight
  delay(850);
  Hard_Stop();
  delay(1000);
  turn_rightbackwards1(); //1st turn for left
  delay(900);
  Hard_Stop();
  delay(1000);
  Reverse(); //6th straight
  delay(1000);
  Hard_Stop();
  delay(1000);
  turn_rightbackwards2(); //2nd turn for left
  delay(1000);
  Hard_Stop();
  delay(1000);
  Reverse(); //7th straight
  delay(800);  
  }
  void eight_story8() {
  Forward();  //1st straight
  delay(1000);
  Hard_Stop();
  delay(1000);
  turn_right(); //1st turn
  delay(1000);
  Hard_Stop();
  delay(1000);
  Forward();  //2nd straight
  delay(1000);
  Hard_Stop();
  delay(1000);
  turn_right1(); //2nd turn
  delay(1000);
  Hard_Stop();
  delay(1000);
  Forward(); //3rd straight
  delay(1000);
  Hard_Stop();
  delay(1000);
  turn_right2(); //3rd turn
  delay(1075);
  Hard_Stop();
  delay(1000);
  Forward(); //4th straight to lead to the 2nd square
  delay(1750);
  Hard_Stop();
  delay(1000);
  turn_left();// start of 2nd square++
  delay(900);
  Hard_Stop();
  delay(1000);
  Forward(); //5th straight
  delay(750);
  Hard_Stop();
  delay(1000);
  turn_left1(); //1st turn for left
  delay(900);
  Hard_Stop();
  delay(1000);
  Forward(); //6th straight
  delay(1250);
  Hard_Stop();
  delay(1000);
  turn_left2(); //2nd turn for left
  delay(1000);
  Hard_Stop();
  delay(1000);
  Forward(); //7th straight
  delay(1150);
} 

void square_story7() {
  Forward();
  delay(1000);
  Hard_Stop();
  delay(1000);
  turn_right();
  delay(1000);
  Hard_Stop();
  delay(1000);
  Forward();
  delay(1000);
  Hard_Stop();
  delay(1000);
  turn_right1();
  delay(1000);
  Hard_Stop();
  delay(1000);
  Forward();
  delay(1000);
  Hard_Stop();
  delay(1000);
  turn_right2();
  delay(1050);
  Hard_Stop();
  delay(1000);
  Forward();
  delay(750);
  Hard_Stop();
  delay(1000);
  turn_right2();
  delay(1250);
}
void dance(){
  turn_left3();
  delay(700);
  turn_right3();
  delay(1000);
  turn_left3();
  delay(700);
  turn_right3();
  delay(1000);
}
void turn_left() {
  analogWrite(10,220);
  analogWrite(9,220);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  Serial.println("Im turning");
}
void turn_leftbackwards(){
  analogWrite(10,220);
  analogWrite(9,220);
  digitalWrite(11,HIGH); //right moter backwards
  digitalWrite(8,HIGH); //left moter forwards
  digitalWrite(7,LOW); //left moter backwards
  digitalWrite(12,LOW);//right moter forwards
}
void turn_leftbackwards1(){
  analogWrite(10,200);
  analogWrite(9,200);
  digitalWrite(11,HIGH); //right moter backwards
  digitalWrite(8,HIGH); //left moter forwards
  digitalWrite(7,LOW); //left moter backwards
  digitalWrite(12,LOW);//right moter forwards
}
void turn_leftbackwards2(){
  analogWrite(10,160);
  analogWrite(9,160);
  digitalWrite(11,HIGH); //right moter backwards
  digitalWrite(8,HIGH); //left moter forwards
  digitalWrite(7,LOW); //left moter backwards
  digitalWrite(12,LOW);//right moter forwards
}
void turn_rightbackwards(){
  analogWrite(10,220);
  analogWrite(9,220);
  digitalWrite(11,LOW); //right moter backwards
  digitalWrite(8,LOW); //left moter forwards
  digitalWrite(7,HIGH); //left moter backwards
  digitalWrite(12,HIGH );//right moter forwards
}
void turn_rightbackwards1(){
  analogWrite(10,200);
  analogWrite(9,200);
  digitalWrite(11,LOW); //right moter backwards
  digitalWrite(8,LOW); //left moter forwards
  digitalWrite(7,HIGH); //left moter backwards
  digitalWrite(12,HIGH );//right moter forwards
}
void turn_rightbackwards2(){
  analogWrite(10,160);
  analogWrite(9,160);
  digitalWrite(11,LOW); //right moter backwards
  digitalWrite(8,LOW); //left moter forwards
  digitalWrite(7,HIGH); //left moter backwards
  digitalWrite(12,HIGH );//right moter forwards
}
void turn_left1() {
  analogWrite(10,200);
  analogWrite(9,200);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  Serial.println("Im turning -20");
}
void turn_left2() {
  analogWrite(10,160);
  analogWrite(9,160);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  Serial.println("Im turning-40");
}
void turn_left3(){
  analogWrite(10,250);
  analogWrite(9,250);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  Serial.println("Im turning-40");
}
void turn_right() {
  analogWrite(10,220);
  analogWrite(9,220);
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  Serial.println("Im turning");
}
void turn_right1() {
  analogWrite(10,200);
  analogWrite(9,200);
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  Serial.println("Im turning -20");
}
void turn_right2() {
  analogWrite(10,160);
  analogWrite(9,160);
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  Serial.println("Im turning-40");
}
void turn_right3() {
  analogWrite(10,250);
  analogWrite(9,250);
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  Serial.println("Im turning-40");
}

void left_Pulses(){
  Pulses_left++;
  Serial.println("Im working left");
}
void right_Pulses(){
  Pulses_right++;
  Serial.println("Im working right");
}
void Forward() {
 analogWrite(9, 170);
 analogWrite(10, 170);
 analogWrite(13,200);//LED
 digitalWrite(8, HIGH);
 digitalWrite(12, HIGH);
 digitalWrite(7, LOW);
 digitalWrite(11, LOW);
 digitalWrite(13, HIGH);
 Serial.println("im going");
}
void Reverse() {
 analogWrite(9, 170);
 analogWrite(10, 170);
 digitalWrite(8, LOW);
 digitalWrite(12, LOW);
 digitalWrite(7, HIGH);
 digitalWrite(11, HIGH);
 Serial.println("im going");
}
void Hard_Stop() {
 digitalWrite(7, HIGH);
 digitalWrite(8, HIGH);
 digitalWrite(9, HIGH);
 digitalWrite(10, HIGH);
 digitalWrite(11, HIGH);
 digitalWrite(12, HIGH);
}

void Story_2() {
  digitalWrite(2, HIGH);                     
  digitalWrite(3, LOW);
  delay(1000);
  digitalWrite(3, HIGH);                     
  digitalWrite(2, LOW);
  delay(1000);                       
}

void Story_3() {
  digitalWrite(2, HIGH);                     
  digitalWrite(3, LOW);
  delay(10000);
  digitalWrite(3, LOW);                     
  digitalWrite(2, LOW);
  delay(1000);         
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  delay(1000);
}
void Story_4() {
 Forward();
 delay(1000);
 Hard_Stop();
 delay(1000);
 Reverse();
 delay(1000);
 Hard_Stop();
 delay(1000);
  
}
void Straight() {
    if ((Pulses_left) == (Pulses_right))
  { 
    Forward();
    Serial.println("I'm moving forward");
    delay(100);
  }    
  else if((Pulses_left) > (Pulses_right))
  {
    Forward();
     analogWrite(9,160);
     Serial.println("Im reducing Left Moter");
     delay(100);
  }
  else if((Pulses_left) < (Pulses_right))
  {
    Forward();
     analogWrite(10,160);
     Serial.println("I'm reducing Right Moter");
     delay(100);
  }
}

void Story_5() {
  Straight();
  delay(9000);
  Hard_Stop();
  delay(1000);
  
}

