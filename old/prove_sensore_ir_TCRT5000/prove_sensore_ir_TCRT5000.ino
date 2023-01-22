void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT); //imposto il pin come input 
 
}

void loop() {

  int digital = digitalRead (2);
  int analog = analogRead(A0);
  Serial.print("digitale= ");
  Serial.println(digital);
  Serial.print("analogico= ");
  Serial.println(analog);
  Serial.println("");

  delay(500);
}
  
