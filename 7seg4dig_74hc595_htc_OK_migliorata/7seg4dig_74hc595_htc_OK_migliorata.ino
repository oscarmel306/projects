#include <DHT.h> // include DHT library
#define DHTPIN 6 // define DHT11 sensor pin
#define DHTTYPE DHT11 // define DHT sensor type
DHT dht(DHTPIN, DHTTYPE); // initialize DHT sensor


int latch=9;  //74HC595  pin 9 STCP
int clock=10; //74HC595  pin 10 SHCP
int data=8;   //74HC595  pin 8 DS

int i=0;

int d1, d2, d3, d4, tempint, humint;

unsigned char table[]= {
  0x3f, // 0
  0x06, // 1 
  0x5b, // 2 
  0x4f, // 3
  0x66, // 4
  0x6d, // 5
  0x7d, // 6
  0x07, // 7
  0x7f, // 8
  0x6f, // 9
  0x77, // A
  0x7c, // B
  0x39, // C
  0x5e, // D
  0x79, // E
  0x71, // F
  0x00  // cifra spenta
  };

unsigned char tabledot[]= {
  0xbf, // 0.
  0x86, // 1.
  0xdb, // 2.
  0xcf, // 3.
  0xe6, // 4.
  0xed, // 5.
  0xfd, // 6.
  0x87, // 7.
  0xff, // 8.
  0xef, // 9.
  0x63, // °
  0x5c, // o
  0x39, // C
  0x74  // h
  };

void setup() {
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  dht.begin(); // initialize DHT sensor

  Serial.begin(9600); //inizializzo la seriale perchè voglio visualizzare i dati anche sullo schermo
}
void Display(unsigned char num)    /* 
                                   procedura che traduce il numero num 
                                   in valori binari per il display a 7 segmenti
                                   */
{
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,table[num]);
  digitalWrite(latch,HIGH);
  
}

void Displaydot(unsigned char num)  /* 
                                    procedura che traduce il numero num 
                                    in valori binari con il punto 
                                    per il display a 7 segmenti
                                    */
{
  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,tabledot[num]);
  digitalWrite(latch,HIGH);
  
}
void loop() {
  // spengo tutte le cifre del display:
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  
  // leggo la temperatura e l'umidità dal sensore
  float temp = dht.readTemperature(); 
  float hum = dht.readHumidity(); 

  // visualizzo temperatura e umidità sullo schermo del pc
  Serial.print(temp);
  Serial.print(" °C; ");
  Serial.print(hum);
  Serial.println(" %");

  // visualizzo la temperatura sul display:
  for (i=0; i<1000; i++) {
    
  //trasformo il numero con una cifra decimale in numero intero a 3 cifre
  tempint = temp*10;

  // estraggo le decine da visualizzare sulla cifra più significativa del display
  d1 = (int)(tempint/100);

  // estraggo le unità
  d2 = (int)((tempint-(d1*100))/10);

  // estraggo i decimi di grado
  d3 = (int)(tempint-(d1*100)-(d2*10));

  // visualizzo C sulla cifra più a destra
  Displaydot(12);
  digitalWrite(2, LOW);
  delay(1);
  digitalWrite(2, HIGH);

  // visualizzo i decimi di grado
  Display(d3);
  digitalWrite(3, LOW); 
  delay(1);
  digitalWrite(3, HIGH);

  // visualizzo le unità
  Displaydot(d2);
  digitalWrite(4, LOW); 
  delay(1);
  digitalWrite(4, HIGH);
  
  // visualizzo le decine
  Display(d1);
  digitalWrite(5, LOW); 
  delay(1);
  digitalWrite(5, HIGH);

  }

//dopo aver mostrato la temperatura, passo a visualizzare l'umidità
//l'umidità è visualizzata a cifra intera, senza decimali.Simulo il simbolo %

for (i=0; i<1000; i++) {

  humint = hum;

  d1 = (int)(humint/10);

  d2 = (int)(humint-(d1*10));


    
  Displaydot(11);
  digitalWrite(2, LOW);
  delay(1);
  digitalWrite(2, HIGH);
  
  Displaydot(10);
  digitalWrite(3, LOW); 
  delay(1);
  digitalWrite(3, HIGH);
  
  Display(d2);
  digitalWrite(4, LOW); 
  delay(1);
  digitalWrite(4, HIGH);

  Display(d1);
  digitalWrite(5, LOW); 
  delay(1);
  digitalWrite(5, HIGH);

  }

}
