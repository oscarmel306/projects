
unsigned long start, fin, t;



void setup() {
  pinMode (3, INPUT); // sensore laser
  pinMode (2, OUTPUT); // emettitore laser
  Serial.begin(9600);
  digitalWrite(2, LOW);

  
}

void loop() {
  digitalWrite(2, HIGH);
  start=micros();
  if(!digitalRead(3)) {fin=micros();
  t = fin - start;
  Serial.print(t);
  Serial.println("microsec");
  Serial.print(start);
  Serial.print(" ");
  Serial.println(fin);
  Serial.println();  
  digitalWrite(2, LOW);
  }
  else {Serial.println("in attesa");
  digitalWrite(2, LOW); // se il sensore particolarmente lento, lasciare acceso il laser
  

  }
  delay(1000);

}
