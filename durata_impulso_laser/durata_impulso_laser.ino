// test tempo di scatto macchina fotografica analogica
// i valori di pulseIn sono in microsecondi 
// il comando pulseIn fornisce la durata di in impulso. 

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
}

void loop() {
  float t = pulseIn(7, LOW,60000000);
  Serial.println("");
  Serial.print(t);
  Serial.println(" microsecondi");
  if (t == 0) {
    Serial.println("in attesa");
  } else if (t > 1000000) {
    t= t/1000000;
    Serial.print("tempo di scatto: ");
    Serial.print(t);
    Serial.println(" sec");
  } else {
  float tmillisec=t;
    tmillisec=tmillisec/1000;
    t=t/1000000;
    t=1/t;
    Serial.print("tempo di scatto: ");
    Serial.print("1/"); 
    Serial.print(t);
    Serial.print(" di secondo  (");
    Serial.print(tmillisec);
    Serial.println(" msec)");

  }
}
