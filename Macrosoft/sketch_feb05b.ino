
int leftfeedback = 2;
int rightfeedback = 3;
int rightpwm = 10;
int leftpwm = 9;
int leftforwards = 8;
int leftbackwards = 7;
int rightforwards = 12;
int rightbackwards = 11;
int countNumberLeft = 0;
int countNumberRight = 0;
int ultraTrigger = 4;
int ultraEcho = 5; 
int DUtrigger = 13; //13
int downEcho = 17; //17

long int distance, timeTaken;
void countLeft() {
  countNumberLeft++;
  Serial.println(countNumberLeft);
}

void countRight() {
  countNumberRight++;
  Serial.println(countNumberRight);
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(downEcho, INPUT);
  pinMode(leftfeedback, INPUT);
  pinMode(rightfeedback, INPUT);
  pinMode(leftbackwards, OUTPUT);
  pinMode(leftforwards, OUTPUT);
  pinMode(leftpwm, OUTPUT);
  pinMode(rightpwm, OUTPUT);
  pinMode(rightbackwards, OUTPUT);
  pinMode(rightforwards, OUTPUT);
  pinMode(ultraEcho, INPUT);
  pinMode(ultraTrigger, OUTPUT);
  pinMode(DUtrigger, OUTPUT);
  
  digitalWrite(leftfeedback, HIGH);
  digitalWrite(rightfeedback, HIGH);
  attachInterrupt(digitalPinToInterrupt(leftfeedback), countLeft, RISING);
  attachInterrupt(digitalPinToInterrupt(rightfeedback), countRight, RISING);
  analogWrite(leftpwm, 150);
  analogWrite(rightpwm, 150);
}

void forwardsMovement() {
  ultraDown();
  Serial.println("forwards");
  digitalWrite(leftbackwards, LOW);
  digitalWrite(rightbackwards, LOW);
  digitalWrite(leftforwards, HIGH);
  digitalWrite(rightforwards, HIGH);
  analogWrite(leftpwm, 120);
  analogWrite(rightpwm, 120);
  
//  if (countNumberLeft == countNumberRight) {
//    analogWrite(leftpwm, 150);
//    analogWrite(rightpwm, 150);
//    Serial.println("They are the same");
//  }
//  else if (countNumberLeft > countNumberRight) {
//    Serial.println("Left is greater than the right");
//    if ((countNumberLeft - countNumberRight) < 2) {
//      Serial.println("Decrease speed of left by 20 speed, set to 235");
//      analogWrite(leftpwm, 100);
//      analogWrite(rightpwm, 150);
//    }
//  }
//  else if (countNumberRight > countNumberLeft) {
//    Serial.println("Right is greater than the left");
//    if ((countNumberLeft - countNumberRight) < 2) {
//      Serial.println("Decrease speed of the right by 20 speed, set to 235");
//      analogWrite(rightpwm, 95);
//      analogWrite(leftpwm, 109);
//    }
//  }
}


void forwardsMovement_end() {
  Serial.println("forwards");
  digitalWrite(leftbackwards, LOW);
  digitalWrite(rightbackwards, LOW);
  digitalWrite(leftforwards, HIGH);
  digitalWrite(rightforwards, HIGH);
  analogWrite(leftpwm, 150);
  analogWrite(rightpwm, 150);
  
  delay(3000);
  offMovement();
}

void backwardsMovement() {
  Serial.println("backwards");
  digitalWrite(leftforwards, LOW);
  digitalWrite(rightforwards, LOW);
  digitalWrite(leftbackwards, HIGH);
  digitalWrite(rightbackwards, HIGH);
  analogWrite(leftpwm, 150);
  analogWrite(rightpwm, 150);
}

void backwardsMovement_end() {
  Serial.println("backwards");
  digitalWrite(leftforwards, LOW);
  digitalWrite(rightforwards, LOW);
  digitalWrite(leftbackwards, HIGH);
  digitalWrite(rightbackwards, HIGH);
  analogWrite(leftpwm, 150);
  analogWrite(rightpwm, 150);
  delay(1800);
  offMovement();
}

void backwardsMovement_1end() {
  Serial.println("backwards");
  digitalWrite(leftforwards, LOW);
  digitalWrite(rightforwards, LOW);
  digitalWrite(leftbackwards, HIGH);
  digitalWrite(rightbackwards, HIGH);
  analogWrite(leftpwm, 150);
  analogWrite(rightpwm, 150);
  delay(2200);
  offMovement();
}

void offMovement() {
  digitalWrite(leftforwards, LOW);
  digitalWrite(rightforwards, LOW);
  digitalWrite(leftbackwards, LOW);
  digitalWrite(rightbackwards, LOW);
  analogWrite(leftpwm, 0);
  analogWrite(rightpwm, 0);
  delay(1000);
  Serial.println("stopped");
}

void rightTurn() {
  Serial.println("rightTurn");
  analogWrite(leftpwm, 152);
  analogWrite(rightpwm, 150);
  digitalWrite(leftforwards, HIGH);
  digitalWrite(rightforwards, LOW);
  digitalWrite(leftbackwards, LOW);
  digitalWrite(rightbackwards, HIGH);
  delay(1220);
  offMovement();
  }

void leftTurn() {
  Serial.println("leftTurn");
  analogWrite(leftpwm, 150);
  analogWrite(rightpwm, 152);
  digitalWrite(leftforwards, LOW);
  digitalWrite(rightforwards, HIGH);
  digitalWrite(leftbackwards, HIGH);
  digitalWrite(rightbackwards, LOW);
  delay(1220);
  Serial.println("turned for 2 seconds");
  offMovement();
  }

void leftTurn1() {
  Serial.println("leftTurn1");
  analogWrite(leftpwm, 120);
  analogWrite(rightpwm, 122);
  digitalWrite(leftforwards, LOW);
  digitalWrite(rightforwards, HIGH);
  digitalWrite(leftbackwards, HIGH);
  digitalWrite(rightbackwards, LOW);
  delay(1180);
  offMovement();
  }

//void ultra(){
//  digitalWrite(ultraTrigger, LOW);
//  delayMicroseconds(2);
//
//  digitalWrite(ultraTrigger, HIGH);
//  delayMicroseconds(2);
//
//  digitalWrite(ultraTrigger, LOW);
//
//  timeTaken = pulseIn(ultraEcho, HIGH);
//
//  distance = timeTaken/58.2;
//
//  //if (distance > 4){
//    //Serial.println("Detected");
//    //offMovement();
//    //backwardsMovement();
//    //delay(5000);
//    //offMovement();
//    //delay(100000);
//  }

void ultraDown(){
  //digitalWrite(ultraTrigger, LOW);
  digitalWrite(DUtrigger, LOW);
  delayMicroseconds(2);

  //digitalWrite(ultraTrigger, HIGH);
  digitalWrite(DUtrigger, HIGH);
  delayMicroseconds(2);

  digitalWrite(ultraTrigger, LOW);

  timeTaken = pulseIn(downEcho, HIGH);

  distance = timeTaken/58.2;

  if (distance > 13  ){
    Serial.println("Detected");
    offMovement();
    backwardsMovement();
    delay(8000);
    offMovement();
    delay(100000);
  }
}

//void flashingLights(int seconds){
//digitalWrite(3,HIGH);
//digitalWrite(2,LOW);
//delay(seconds);
//digitalWrite(3,LOW);
//digitalWrite(2,HIGH);
//delay(seconds);
//}

/* void story3 () {
//  digitalWrite(3, LOW);
//  digitalWrite(2, HIGH);
//  delay(10000);
//  digitalWrite(3,LOW);
//  digitalWrite(2, LOW);
//  delay(1000);
//  digitalWrite(3, HIGH);
//  digitalWrite(2, LOW);
//  delay(1000);
//  digitalWrite(3,LOW);
//  digitalWrite(2, LOW);
//  delay(500);
}

  for(int i = 0; i < 3; i++){
    forwardsMovement();
    rightTurn();
  }
  forwardsMovement();
  for(int i = 0; i < 2; i++){
    forwardsMovement();
    leftTurn();
  }
  forwardsMovement();
  leftTurn1();
  forwardsMovement_end();
  
  for(int i = 0; i < 3; i++){
    backwardsMovement();
    rightTurn();
  }
  backwardsMovement();
  for(int i = 0; i < 2; i++){
  backwardsMovement();
  leftTurn();
  }
  backwardsMovement_1end();
  leftTurn();  
  backwardsMovement_end();
*/

void loop() {
  // put your main code here, to run repeatedly:
  forwardsMovement();
}

