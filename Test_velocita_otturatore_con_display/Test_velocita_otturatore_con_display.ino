// test tempo di scatto macchina fotografica analogica
// i valori di pulseIn sono in microsecondi 
// il comando pulseIn fornisce la durata di in impulso. 

/* utilizzo un display 16x2 per visualizzare i risultati
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K trimmer
 * wiper to LCD VO pin (pin 3)
 * 
 * This example code is in the public domain. 
 * http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);


void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  float t = pulseIn(2, LOW,60000000);
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
