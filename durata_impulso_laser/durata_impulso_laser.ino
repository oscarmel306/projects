// test test tempo di risposta di un sensore laser o ir o luce

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT); //imposto il pin7 come input (il 7 è digitale e non pwm)
}

void loop() {
  unsigned long t = pulseIn(7, LOW,10000000); //se dopo  secondi non succede nulla, 
                                      //esco dal comando pulseIn 
                                      //e mi ritorna 0
                                     
  if (t != 0) { // se il comando mi ha ritornato 0 
    Serial.println("in attesa");
  }
  else{
  Serial.println("");
  Serial.print(t); // visualizzo la durata dell'impulso in microsecondi 
  Serial.println(" microsecondi");
  Serial.println("");

  }
}
