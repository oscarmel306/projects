// test tempo di scatto macchina fotografica analogica
// il comando di arduino pulseIn fornisce la durata di in impulso in microsecondi. 

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT); //imposto il pin7 come input (il 7 è un in digitale e non pwm)
}

void loop() {
  float t = pulseIn(7, LOW,60000000); //se dopo 6 secondi non succede nulla, esco dal comando pulseIn che mi ritorna 0
  Serial.println("");
  Serial.print(t); // visualizzo la durata dell'impulso in microsecondi (tempo di apertura dell'otturatore)
  Serial.println(" microsecondi");
  if (t == 0) { // se il comando mi ha ritornato 0
    Serial.println("in attesa");
    
    // per comodità, se il tempo di scatto è superiore a 1 secondo, riporto il risultato in secondi
    // altrimenti in frazione
    
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
