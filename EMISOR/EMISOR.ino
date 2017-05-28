#include <VirtualWire.h>


int EjeX = 0;
int EjeY = 0;
int Boton = 0;
 
const int dataPin = 9;
 
void setup()
{
    Serial.begin(9600);   
    vw_setup(2000);  //Se inicia la comunicacion
    vw_set_tx_pin(dataPin); //Se declara el pin de trasmisor, este caso TX = 9
    pinMode(A0,INPUT); //Eje X
    pinMode(A1,INPUT); // Eje Y
    pinMode(8,INPUT_PULLUP); // Boton central
    pinMode(A4,OUTPUT); //Led de ARMADO
}
 
void loop()
{
    // Se transmiten 3 bytes: Eje X, Eje Y, Pulsador ON/OF

    EjeX = analogRead(A0)/4;
    EjeY = analogRead(A1)/4;
    Boton = digitalRead(8);
    digitalWrite(A4,HIGH);
    //delay(500);
    //digitalWrite(A4,LOW);
    //delay(500);

   // while (Serial.available() > 0) 
   // {
       EjeX = analogRead(A0)/4;
       EjeY = analogRead(A1)/4;
       Boton = digitalRead(8);

       Serial.print(EjeX);
       Serial.print(" ");
       Serial.print(EjeY);
       Serial.print(" ");
       Serial.print(Boton);
       Serial.println(" ");
      
      uint8_t data[3]; //Vector de 1 byte de longitud 3
      
      data[0] = EjeX;
      data[1] = EjeY;
      data[2] = Boton;
      
      // (cadena, numero de bytes)
      // En este caso se pasan 3 byte sin signo (255 valores) Solo se pasa el nombre  del vector con un puntero
      
      vw_send((uint8_t*)data, sizeof(data) );
      vw_wait_tx();   // Espera a que el mensaje en vw_send se termine de transmitir    
      
  //  }
 //   delay(100);
}
