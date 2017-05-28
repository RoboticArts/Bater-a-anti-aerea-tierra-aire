#include <VirtualWire.h>
#include <SoftwareSerial.h>

const int dataPin = 9;
const int ledPin = A3;

const int rele = A0;

int anguloX = 2000;
int anguloY = 2000;

// Bajo esta configuración:
// TX controlador al pin 3
// RX controlador al pin 2

SoftwareSerial mySerial(3, 2); // RX, TX



void setup()
{
  
   
     
    vw_setup(2000);
    vw_set_rx_pin(dataPin);
    vw_rx_start();

    Serial.begin(9600);
    mySerial.begin(9600);
    
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, false);
    
    pinMode(rele,OUTPUT);
    digitalWrite(rele,true);
}
 
void loop()
{

/*
   pinMode(rele,HIGH);
   delay(3000);
   pinMode(rele,LOW);
   delay(3000);
*/
 
    uint8_t data[VW_MAX_MESSAGE_LEN];
    uint8_t dataLength = VW_MAX_MESSAGE_LEN;

 //  (variable donde se guardara, tamaño de la variable)
 // La funcion devuelve FALSE si se corrompe el mensaje y TRUE si ha llegado bien
 
 // data = el vector que se ha enviado
 // dataLenght = el numero de bins o la longitud del vector 

    if (vw_get_message(data,&dataLength)) 
    {
        
        for(int i = 0; i< dataLength; i++){

          Serial.print(data[i]); //Se muestra como un numero de 0 a 255;
          Serial.print(" ");
         
         }

        Serial.print("          ");

        if(data[2] == 1){
            digitalWrite(ledPin,HIGH);
            digitalWrite(rele,LOW);
          }
        else{
            digitalWrite(ledPin,LOW);
            digitalWrite(rele,HIGH);
          }

    delay(50);

    anguloX = map (data[1],0,255,550,2450);
    anguloY = map (data[0],0,255,550,2450);
    Serial.print("#1P");
    Serial.print(anguloX);
    Serial.print("T100");
    Serial.print("#2P");
    Serial.print(anguloY);
    Serial.print("T100");
    Serial.println("\r\n");

    int limMinY = 1200; // Calibracion para Servo 2 entre 135 y 180 grados 
    int limMaxY = 400; 

    int limMinX = 300; // Calibracion para Servo 1 entre 135 y 45 grados
    int limMaxX = 300;

    anguloX = map (data[1],0,255,550 + limMinX,2200 - limMaxX); // 1º servo: Calibrado para Servo MG996R
    anguloY = map (data[0],0,255,550 + limMinY ,2450 - limMaxY ); // 2º servo: Calibrado para Servo Futaba
    mySerial.print("#1P");
    mySerial.print(anguloX);
    mySerial.print("T100");
    mySerial.print("#2P");
    mySerial.print(anguloY);
    mySerial.print("T100");
    
    mySerial.println("\r\n");

    delay(50);

  }
}
