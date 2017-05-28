#include <SoftwareSerial.h>

// Bajo esta configuración:
// TX controlador al pin 3
// RX controlador al pin 2

SoftwareSerial mySerial(3, 2); // RX, TX

int anguloA = 2450;
int anguloB = 2390;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);

}

void loop() {
/*    
     // PRIMER MODO
    Serial.println("#1P500T500\r\n");  //Entre 500 y 2000 
    mySerial.println("#1P500T500\r\n");  //Entre 500 y 2000 
    delay(1000);
    Serial.println("#1P2000T500\r\n");  //Entre 500 y 2000 
    mySerial.println("#1P2000T500\r\n");  //Entre 500 y 2000 
    delay(1000);
    */


    Serial.print("#1P");
    Serial.print(anguloA);
    Serial.println("T500\r\n");
    
    mySerial.print("#1P");
    mySerial.print(anguloA);
    mySerial.println("T500\r\n");

    delay(500);

    Serial.print("#1P");
    Serial.print(anguloB);
    Serial.println("T500\r\n");
    
    mySerial.print("#1P");
    mySerial.print(anguloB);
    mySerial.println("T500\r\n");

    delay(500);
   
    
    
}
