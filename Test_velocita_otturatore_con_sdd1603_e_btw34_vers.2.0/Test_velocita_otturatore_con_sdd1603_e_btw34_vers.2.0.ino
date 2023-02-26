/*
 * test tempo di scatto macchina fotografica analogica
 * uso un display oled ssd1306 e un 
 * il comando di arduino pulseIn fornisce la durata di in impulso in microsecondi. 
 */
#include <U8x8lib.h>
#include <Wire.h>

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);         

#define sensore 2       //dove leggo il fotodiodo
#define timeout 5000000 // aspetto 5 secondi per atendere un segnale da pulseIn
unsigned long tusec; // variabile durata impulso 
float tmsec;
float t;



void setup() {
  pinMode(sensore, INPUT);
  tusec = 0;
  Serial.begin(9600);
  u8x8.begin();
  u8x8.setPowerSave(0);
  u8x8.setFont(u8x8_font_8x13B_1x2_f);
  }

void loop() {
    do {
    tusec = pulseIn(sensore, HIGH, timeout);
    tmsec = float (tusec) / 1000;
    t = 1 / float (tmsec/1000);
    //u8x8.clearDisplay();
    } while  (tusec == 0);
    
    Serial.println(" ");
    Serial.print("durata impulso: ");
    Serial.print(tmsec);
    Serial.println(" millisecondi");
    
    u8x8.setCursor(0, 0);
    u8x8.print(tusec);  
    u8x8.drawString(8,0,"usec");

    u8x8.setCursor(0, 3);
    u8x8.print(tmsec);  
    u8x8.drawString(8,3,"msec");

    u8x8.setCursor(2, 6);
    u8x8.print(t);  
    u8x8.drawString(0,6,"1/");
    u8x8.drawString(8,6,"di sec");
  
}
