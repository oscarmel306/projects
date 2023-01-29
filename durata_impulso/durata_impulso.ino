// test test tempo di risposta di un sensore laser o ir o luce

#define sensore 7

void setup() {
  Serial.begin(9600);
  pinMode(sensore, INPUT); //imposto il pin come input 
}

void loop() {
  unsigned long t = pulseIn(sensore, LOW,10000000); //se dopo  secondi non succede nulla, 
                                      //esco dal comando pulseIn 
                                      //e mi ritorna 0
  //Serial.println();
  Serial.print(t); // visualizzo la durata dell'impulso in microsecondi 
  Serial.println(" microsecondi");
  unsigned long msec = t / 1000;
  //Serial.println();
  Serial.print(msec);
  Serial.println(" millisecondi");


}
