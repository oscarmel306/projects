
void setup() {
  // put your setup code here, to run once:
    pinMode(11,OUTPUT);
    pinMode(7,INPUT);
   


}

void loop() {
  // put your main code here, to run repeatedly:
  int tasto1 = digitalRead(7);
  if (tasto1 == HIGH) {
    digitalWrite(11,HIGH);
    delay(1000);
  }
  digitalWrite(11,LOW);
}
