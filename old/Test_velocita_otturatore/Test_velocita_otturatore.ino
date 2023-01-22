/*test tempo di scatto macchina fotografica analogica
 */

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT); //imposto il pin come input 
}

void loop() {
  unsigned long t = pulseIn(2, LOW,60000000); //se dopo 60 secondi non succede nulla, esco dal comando pulseIn, che mi da' 0
  //unsigned long tl = pulseIn(2, LOW,60000000); //se dopo 60 secondi non succede nulla, esco dal comando pulseIn, che mi da' 0
  //unsigned long tusec=tl;
  //float t = (float) tl;
  //Serial.println("");
  Serial.print(t); // visualizzo la durata dell'impulso in microsecondi (tempo di apertura dell'otturatore)
  Serial.println(" microsecondi");
  Serial.println();
 /*
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print(tusec);
  lcd.setCursor(10,0);
  lcd.print(" usec");
  
    // se il comando mi ha dato 0
  if (t == 0) { 
    Serial.println("in attesa");
   
    lcd.setCursor(0, 0);
    lcd.print("in attesa       ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    
    
    // per comodità, se il tempo di scatto è superiore a 1 secondo, riporto il risultato in secondi
    // altrimenti in frazione
    
  } else if (t > 1000000) { 
    t= t/1000000;
    Serial.print("tempo di scatto: ");
    Serial.print(t);
    Serial.println(" sec");

    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print(tusec);
    lcd.setCursor(10,0);
    lcd.print(" usec");
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print(t);
    lcd.setCursor(11, 1);
    lcd.print(" sec");
    
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

    lcd.setCursor(0,0);
    lcd.print("                ");
    lcd.setCursor(0,0);
    lcd.print(tusec);
    lcd.setCursor(10,0);
    lcd.print(" usec");
    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print("1/");
    lcd.setCursor(2, 1);
    lcd.print(t);
    lcd.setCursor(11, 1);
    lcd.print(" sec");
  }
*/
}
