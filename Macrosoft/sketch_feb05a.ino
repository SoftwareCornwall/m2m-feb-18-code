bool is_a_leap_year(int year){
  if (((year%4)==0 and (year%100)!0) or (year%400)==0){
    Serial.print(year);
    Serial.println(" is a leap year");
    return true;
  }
  else{
    Serial.print(year);
    Serial.println(" is not a leap year");
    return false;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  is_a_leap_year(
}

void loop() {
  // put your main code here, to run repeatedly:

}
