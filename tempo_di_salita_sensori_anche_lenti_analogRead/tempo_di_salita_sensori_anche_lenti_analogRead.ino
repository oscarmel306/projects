
unsigned long start, fin, t, finlento;



void setup() {
  //pinMode (3, INPUT); // sensore laser
  pinMode (2, OUTPUT); // emettitore laser
  Serial.begin(9600);
  digitalWrite(2, LOW);
}

void loop() {
  digitalWrite(2, HIGH);
  start=micros();
  //while(!digitalRead(3)) {
  while(analogRead(A0)<1000) {    
    Serial.println("in attesa");
    Serial.println();  
    Serial.println(analogRead(A0));
    Serial.println();
  }
  fin=micros();
  t = fin - start;
  Serial.print(t);
  Serial.println("microsec");
  Serial.print(start);
  Serial.print(" ");
  Serial.println(fin);
  Serial.println();  
  //Serial.println(impulso);
  //Serial.println();  
  digitalWrite(2, LOW);
  

  delay(1000);

}
