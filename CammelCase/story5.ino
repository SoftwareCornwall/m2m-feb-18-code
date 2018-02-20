
void setup() {
    #define left 8 //yellow left LED pin 5
    #define right 12 //green LED pin 4
    #define leftb 7
    #define rightb 11
    #define lefta 9
    #define righta 10
    
    pinMode(leftb, OUTPUT);
    pinMode(rightb, OUTPUT);
    pinMode(left,OUTPUT);   
    pinMode(right, OUTPUT);
    pinMode(lefta, OUTPUT);
    pinMode(righta, OUTPUT); 

    attachInterupt(attachPinToInterupt(2), function counting, RISING);
    attachInterupt(attachPinToInterupt(3), function counting, RISING);
}

void counter_left(){
    counter.left++;
}

void counter_right(){
    counter.right++;
}

void foward(){
  if (counter_right == counter_left){
    digitalWrite(lefta, HIGH);
    digitalWrite(righta, HIGH);
    digitalWrite(left, HIGH);
    digitalWrite(right, HIGH);
  }
  else if (counter_right < counter_left){
    digitalWrite(lefta, HIGH);
    digitalWrite(righta, HIGH);
    digitalWrite(left, LOW);
    digitalWrite(right, HIGH);
  }
   else if (counter_right > counter_left){
    digitalWrite(lefta, HIGH);
    digitalWrite(righta, HIGH);
    digitalWrite(left, HIGH);
    digitalWrite(right, LOW);
  }
}

void reverse(){
    if (counter_right == counter_left){
      digitalWrite(lefta, HIGH);
      digitalWrite(righta, HIGH);
      digitalWrite(leftb, HIGH);
      digitalWrite(rightb, HIGH);
    }
    else if (counter_right < counter_left){
    digitalWrite(lefta, HIGH);
    digitalWrite(righta, HIGH);
    digitalWrite(leftb, LOW);
    digitalWrite(rightb, HIGH);
  }
   else if (counter_right > counter_left){
    digitalWrite(lefta, HIGH);
    digitalWrite(righta, HIGH);
    digitalWrite(leftb, HIGH);
    digitalWrite(rightb, LOW);
  }
}

void loop() {

}

/*void foward_back_foward() {
   digitalWrite(lefta, HIGH);
   digitalWrite(righta, HIGH);
   digitalWrite(left, HIGH);
   digitalWrite(right, HIGH);
   delay(1000);
   digitalWrite(lefta, LOW);
   digitalWrite(righta, LOW);
   digitalWrite(left, LOW);
   digitalWrite(right, LOW);
   delay(1000);
   digitalWrite(lefta, HIGH);
   digitalWrite(righta, HIGH);
   digitalWrite(leftb, HIGH);
   digitalWrite(rightb, HIGH);     
   delay(1000);
   digitalWrite(lefta, LOW);
   digitalWrite(righta, LOW);
   digitalWrite(leftb, LOW);
   digitalWrite(rightb, LOW);
   delay(1000);
}*/

/*void setup() {
    #define red 4 //red LED pin 3
    #define yellow 5 //yellow left LED pin 5
    #define green 3 //green LED pin 4
    #define yellow2 2 //yellow right LED pin 2 
    pinMode(red, OUTPUT);
    pinMode(yellow,OUTPUT);
    pinMode(yellow2,OUTPUT);
    pinMode(green, OUTPUT);
}*/

/*void reverse_lights{
   digitalWrite(green, HIGH);
   delay(10000);
   digitalWrite(green, LOW);
   digitalWrite(red, HIGH);
   delay(1000);
   digitalWrite(red, LOW);
   digitalWrite(yellow, HIGH);
   digitalWrite(yellow2, HIGH);
   delay(1000);
   digitalWrite(yellow, LOW);
   digitalWrite(yellow2, LOW);
   digitalWrite(red, HIGH);
   delay(1000);
   digitalWrite(red, LOW);
}*/

/*void LED_Blink (){
  //setup
  #define LED_1 3 // 
  #define LED_2 4 //
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  //loop
  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, LOW);   
  delay(1000);                       
  digitalWrite(LED_1, LOW);
  digitalWrite(LED_2, HIGH);     
  delay(1000); 
}*/

