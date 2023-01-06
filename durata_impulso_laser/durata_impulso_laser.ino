// misura impulso di un laser in millisecondi
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  unsigned long t = pulseIn(2, LOW,60000000);
  if (t == 0) {
    Serial.println("in attesa");
  } else {
    Serial.print("durata impulso: ");
    Serial.print(t/1000); 
    Serial.println(" ms");
  }
}
