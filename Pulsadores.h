#include "PCF8574.h"
    
PCF8574 pcf85741(0x21);
PCF8574 pcf85742(0x22);
PCF8574 pcf85743(0x20);
PCF8574 pcf85744(0x24);

uint8_t leds1[8]= {P0, P1, P2, P3, P4, P5, P6, P7}; 
uint8_t leds2[8]= {P0, P1, P2, P3, P4, P5, P6, P7};
uint8_t entradas[8]= {P0, P1, P2, P3, P4, P5, P6, P7}; 
uint8_t salidas[8]= {P0, P1, P2, P3, P4, P5, P6, P7};
uint8_t rebote = 0;

void setupPulsadores(){
  pcf85741.begin(); // INICIALIZACIÓN DE LA COMUNICACIÓN ENTRE EL UC Y EL CI PCF85741.
  pcf85742.begin(); // INICIALIZACIÓN DE LA COMUNICACIÓN ENTRE EL UC Y EL CI PCF85742.
  pcf85743.begin(); // INICIALIZACIÓN DE LA COMUNICACIÓN ENTRE EL UC Y EL CI PCF85743.
  pcf85744.begin(); // INICIALIZACIÓN DE LA COMUNICACIÓN ENTRE EL UC Y EL CI PCF85744.
  for(int i=0;i<=7;i++){
  pcf85741.pinMode(entradas[i], INPUT); //SE DECLARÁ LOS PINES DEL CI PCF85741 COMO ENTRADAS.
  pcf85742.pinMode(entradas[i], INPUT); //SE DECLARÁ LOS PINES DEL CI PCF85742 COMO ENTRADAS.
  pcf85743.pinMode(salidas[i], OUTPUT); //SE DECLARÁ LOS PINES DEL CI PCF85743 COMO SALIDAS.
  pcf85744.pinMode(salidas[i], OUTPUT);}//SE DECLARÁ LOS PINES DEL CI PCF85744 COMO SALIDAS.

  for(int i=0;i<=7;i++){
  pcf85743.digitalWrite(leds1[i], HIGH); //ENCENDIDO DE LOS LEDS PARA COMPROBAR FUNCIONAMIENTO.
  pcf85744.digitalWrite(leds2[i], HIGH); //ENCENDIDO DE LOS LEDS PARA COMPROBAR FUNCIONAMIENTO.
  delay(100);
  }

  for(int i=0;i<=7;i++){
  pcf85743.digitalWrite(leds1[i], LOW); //ENCENDIDO DE LOS LEDS PARA COMPROBAR FUNCIONAMIENTO.
  pcf85744.digitalWrite(leds2[i], LOW); //ENCENDIDO DE LOS LEDS PARA COMPROBAR FUNCIONAMIENTO.
  delay(100);
  }
}

void pulsadores(){
  uint8_t PIN_P0 =  pcf85741.digitalRead(P0); //LEE EL VALOR DEL PIN P0
  uint8_t PIN_P1 =  pcf85741.digitalRead(P1); //LEE EL VALOR DEL PIN P1      
  uint8_t PIN_P2 =  pcf85741.digitalRead(P2); //LEE EL VALOR DEL PIN P2
  uint8_t PIN_P3 =  pcf85741.digitalRead(P3); //LEE EL VALOR DEL PIN P3
  uint8_t PIN_P4 =  pcf85741.digitalRead(P4); //LEE EL VALOR DEL PIN P4      
  uint8_t PIN_P5 =  pcf85741.digitalRead(P5); //LEE EL VALOR DEL PIN P5
  uint8_t PIN_P6 =  pcf85741.digitalRead(P6); //LEE EL VALOR DEL PIN P6
  uint8_t PIN_P7 =  pcf85741.digitalRead(P7); //LEE EL VALOR DEL PIN P7
  uint8_t PIN_P8 =  pcf85742.digitalRead(P0); //LEE EL VALOR DEL PIN P0
  uint8_t PIN_P9 =  pcf85742.digitalRead(P1); //LEE EL VALOR DEL PIN P1      
  uint8_t PIN_P10 = pcf85742.digitalRead(P2); //LEE EL VALOR DEL PIN P2
  uint8_t PIN_P11 = pcf85742.digitalRead(P3); //LEE EL VALOR DEL PIN P3
  uint8_t PIN_P12 = pcf85742.digitalRead(P4); //LEE EL VALOR DEL PIN P4    
  uint8_t PIN_P13 = pcf85742.digitalRead(P5); //LEE EL VALOR DEL PIN P5
  uint8_t PIN_P14 = pcf85742.digitalRead(P6); //LEE EL VALOR DEL PIN P6
  uint8_t PIN_P15 = pcf85742.digitalRead(P7); //LEE EL VALOR DEL PIN P7
  delay(10);
  uint8_t  pulsadores1 [8] = {PIN_P0, PIN_P1, PIN_P2, PIN_P3, PIN_P4, PIN_P5, PIN_P6, PIN_P7};
  uint8_t  pulsadores2 [8] = {PIN_P8, PIN_P9, PIN_P10, PIN_P11, PIN_P12, PIN_P13, PIN_P14, PIN_P15};
}
