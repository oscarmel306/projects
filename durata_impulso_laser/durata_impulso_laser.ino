// misura impulso di un laser in millisecondi
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  float t = pulseIn(2, LOW,60000000);
  if (t == 0) {
    Serial.println("in attesa");
  } else {
  float tmillisec=t;
    tmillisec=tmillisec/1000;
    t=t/1000000;
    t=1/t;
    Serial.print("tempo di scatto: ");
    Serial.print(" 1/"); 
    Serial.print(t);
    Serial.print(" di secondo; in millisecondi: ");
    Serial.println(tmillisec);
    

  }
}
