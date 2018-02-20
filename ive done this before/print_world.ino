const int left_light = 14;    
const int right_light = 15;
 
const int right_activate = 10;
const int right_forward = 12;
const int right_reverse = 11;

const int left_activate = 9;
const int left_forward = 8;
const int left_reverse = 7;

const int left_pulse = 2;

const int right_pulse = 3;

int counter_l;
int counter_r;


void setup() {
  Serial.begin(115200);
  
  attachInterrupt(digitalPinToInterrupt(left_pulse), counter_left, RISING);
  attachInterrupt(digitalPinToInterrupt(right_pulse), counter_right, RISING);
}
  
void loop() { 

}

void counter_left() {
  digitalRead(left_pulse);
  counter_l ++;
  Serial.println("left");
  Serial.println(counter_l);
}

void counter_right() {
  digitalRead(right_pulse);
  counter_r ++;
   Serial.println("right");
  Serial.println(counter_r);
}

void storyFour(){
  forwardMotion();
  delay(1000);

  hardStop();
  delay(1000);

  backwardMotion();
  delay(1000);

  hardStop();
  delay(1000);
}

void forwardMotion(){

}

void backwardMotion(){
  digitalWrite(right_activate, HIGH);
  digitalWrite(left_activate, HIGH);

  digitalWrite(right_reverse, HIGH);
  digitalWrite(left_reverse, HIGH);
  
}

void hardStop(){
  digitalWrite(right_activate, HIGH);
  digitalWrite(left_activate, HIGH);

  digitalWrite(right_forward, HIGH);
  digitalWrite(left_forward, HIGH);

  digitalWrite(right_reverse, HIGH);
  digitalWrite(left_reverse, HIGH);

  digitalWrite(right_activate, LOW);
  digitalWrite(left_activate, LOW);

  digitalWrite(right_forward, LOW);
  digitalWrite(left_forward, LOW);

  digitalWrite(right_reverse, LOW);
  digitalWrite(left_reverse, LOW);
}

void story_three(){
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

void story_four (){

}

