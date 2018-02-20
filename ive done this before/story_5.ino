const int left_light =   13;    //14;
const int right_light =  14;    //15;

const int right_activate = 10; // Right activate motor pin
const int right_forward =  12;  // Right forward motor pin
const int right_reverse =  11;  // Right reverse motor pin

const int left_activate =  9;   // Left activate motor pin
const int left_forward =   8;    // Left forward
const int left_reverse =   7;    // Left Reverse

const int left_pulse = 2;

const int right_pulse = 3;

int counter_l; //left counter
int counter_r; //right counter


void setup() {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(left_pulse), counter_left, RISING);
  attachInterrupt(digitalPinToInterrupt(right_pulse), counter_right, RISING);
  figureEight();

}

void loop() {

}

void rightTurn() {
  analogWrite(right_activate, 175);
  analogWrite(left_activate, 175);

  digitalWrite(left_forward, HIGH);
  digitalWrite(right_reverse, HIGH);
  Serial.println("rightturn");

  delay(1050);

  hardStop();
}

void leftTurn() {
  analogWrite(right_activate, 175);
  analogWrite(left_activate, 175);
  
  digitalWrite(right_forward, HIGH);
  digitalWrite(left_reverse, HIGH);

  delay(1000);

  hardStop();
}

void counter_left() {
  digitalRead(left_pulse);
  counter_l ++;
  //Serial.println("left");
  //Serial.println(counter_l);
}

void counter_right() {
  digitalRead(right_pulse);
  counter_r ++;
  //Serial.println("right");
  //Serial.println(counter_r);
}


void straight_line() {
  ratio_calc();



}


void forwardMotion() {
  digitalWrite(right_activate, HIGH);
  digitalWrite(left_activate, HIGH);

  digitalWrite(right_forward, HIGH);
  digitalWrite(left_forward, HIGH);
}

void backwardMotion() {
  digitalWrite(right_activate, HIGH);
  digitalWrite(left_activate, HIGH);

  digitalWrite(right_reverse, HIGH);
  digitalWrite(left_reverse, HIGH);

}

void hardStop() {
  digitalWrite(right_activate, HIGH); //activates the right motor
  digitalWrite(left_activate, HIGH);  //activates the left motor

  digitalWrite(right_forward, HIGH); //Gives power to pin on the right
  digitalWrite(left_forward, HIGH);  // Gives power to pin on the left

  digitalWrite(right_reverse, HIGH); // Gives power to pin on right
  digitalWrite(left_reverse, HIGH);  // Gives power to pin on left
  delay(1000);
  digitalWrite(right_activate, LOW); // De-activates right
  digitalWrite(left_activate, LOW);  // De-activates left

  digitalWrite(right_forward, LOW); // De-activates right
  digitalWrite(left_forward, LOW);  // De-activates left

  digitalWrite(right_reverse, LOW); // De-activates right
  digitalWrite(left_reverse, LOW);  // De-activates left
}

void analogForward(float motorpwm_l, float motorpwm_r) {
  digitalWrite(right_forward, HIGH);
  digitalWrite(left_forward, HIGH);
  Serial.println("right");
  Serial.println(motorpwm_r);
  Serial.println("left");
  Serial.println(motorpwm_l);
  analogWrite(right_activate, motorpwm_r);
  analogWrite(left_activate, motorpwm_l);
}

void ratio_calc() {

  if (counter_l > counter_r) {
    float pulse, motor_l;

    pulse = ((float)counter_r / (float)counter_l);
    motor_l = ((float)pulse * (float)175);
    Serial.println(motor_l);
    analogForward(motor_l, 175);


  }

  if (counter_r > counter_l) {
    float pulse, motor_r;

    pulse = ((float)counter_l / (float)counter_r);
    motor_r = ((float)pulse * (float)175);
    Serial.println(motor_r);
    analogForward(175, motor_r);
  }
}

void story_three() {
  digitalWrite(left_light , HIGH);
  digitalWrite(right_light , LOW);
  delay(10000);

  digitalWrite(left_light , HIGH);
  digitalWrite(right_light , HIGH);
  delay(1000);

  digitalWrite(left_light , LOW);
  digitalWrite(left_forward , HIGH);
  delay(1000);

  digitalWrite(left_light , HIGH);
  digitalWrite(right_light , HIGH);
  delay(1000);
}

void story_four () {
  forwardMotion();
  delay(1000);

  hardStop();
  delay(1000);

  backwardMotion();
  delay(1000);

  hardStop();
  delay(1000);
}

void story_five() {
  analogForward(175, 175);
  delay(1000);
  straight_line();
  delay(4000);
  straight_line();
  delay(4000);
  hardStop();
  while (true);
}

void rightSquare () {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(left_pulse), counter_left, RISING);
  attachInterrupt(digitalPinToInterrupt(right_pulse), counter_right, RISING);
  Serial.println("hello");
  for (int i = 4; i > 0; i--) {
    forwardMotion();
    delay(1000);
    hardStop();
    rightTurn();
    delay(1000);
  }

}

void leftSquare () {
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(left_pulse), counter_left, RISING);
  attachInterrupt(digitalPinToInterrupt(right_pulse), counter_right, RISING);
  for (int i = 4; i > 0; i--) {
    analogForward(175,175);
    delay(1000);
    hardStop();
    leftTurn();
    delay(1000);
  }



}


void figureEight() {
  Serial.println("hello");
  for (int i = 3; i > 0; i--) {
    Serial.println("test");
    analogForward(175,175);
    delay(1000);
    hardStop();
    delay(1000);
    leftTurn();
    delay(1000);
  }
  analogForward(175,175);
  delay(1000);
  hardStop();

  for (int i = 3; i > 0; i--) {
    analogForward(175,175);
    delay(1000);
    hardStop();
    delay(1000);
    rightTurn();
    delay(1000);
  }
  analogForward(175,175);
  delay(1410);
  hardStop();
}

