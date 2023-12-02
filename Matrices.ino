#include <MD_Parola.h> //Libreria MD_Parola para posicionamiento y efectos de la matrices
#include <MD_MAX72xx.h> //Libreria para los MAX72zz

//#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW    //DESCOMENTAR PARA USO DE MATRICES EN EL SIMULADOR PROTEUS.
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW   //DESCOMENTAR PARA USO DE MATRICES REALES.
#define MAX_DEVICES 16 // CANTIDAD DE MATRICES 8X8 A USAR.
#define CLK_PIN 18 //PIN 18 ESP32
#define DATA_PIN 23 //PIN 23 ESP32
#define CS_PIN 15 //PIN15 ESP32
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES); //SE LE INDICA A LA LIBRERIA LAS CARECTERISTICAS ANTERIORES. 

void setupMatrices(){
  P.begin(4); //INICIALIZACIÓN DE LOS MAX72XX Y CANTIDAD DE ZONAS QUE SE VA A TRABAJAR.
  P.setZone(0,0,3);   //NÚMERO DE LA ZONA Y CANTIDAD DE MATRICES QUE CORRESPONDE A ESA ZONA.
  P.setZone(1,4,7);   //NÚMERO DE LA ZONA Y CANTIDAD DE MATRICES QUE CORRESPONDE A ESA ZONA.
  P.setZone(2,8,11);  //NÚMERO DE LA ZONA Y CANTIDAD DE MATRICES QUE CORRESPONDE A ESA ZONA.
  P.setZone(3,12,15); //NÚMERO DE LA ZONA Y CANTIDAD DE MATRICES QUE CORRESPONDE A ESA ZONA.
}

void Matrices (){
  if (mo == 0 || mo == 2 || mo == 3 || mo == 4){
    if (interruptCounter > 0) {
    portENTER_CRITICAL(&timerMux);
    interruptCounter--;
    portEXIT_CRITICAL(&timerMux);
    totalInterruptCounter--;
    }
  }

  if (mo == 1){
    if (interruptCounter > 0) {
    portENTER_CRITICAL(&timerMux);
    interruptCounter--;
    portEXIT_CRITICAL(&timerMux);
    totalInterruptCounter++;
    }
  }


  if (etapa == 0){
      sprintf(time1, "%d", totalInterruptCounter);
      sprintf(score1, "%d", puntos1);
      P.setZoneEffect(0, true, PA_FLIP_UD);
      P.setZoneEffect(0, true, PA_FLIP_LR);
      P.setZoneEffect(1, true, PA_FLIP_UD);
      P.setZoneEffect(1, true, PA_FLIP_LR);
      P.setZoneEffect(2, true, PA_FLIP_UD);
      P.setZoneEffect(2, true, PA_FLIP_LR);
      P.displayZoneText(0,  "------", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayZoneText(1,  "------", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayZoneText(2,  "------", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayAnimate();
  }
    
  if (etapa == 1 || etapa == 3 || etapa == 4 || etapa == 5){
    if (deportistas == 1){
      sprintf(time1, "%d", totalInterruptCounter);
      sprintf(score1, "%d", puntos1);
      P.setZoneEffect(0, true, PA_FLIP_UD);
      P.setZoneEffect(0, true, PA_FLIP_LR);
      P.setZoneEffect(1, true, PA_FLIP_UD);
      P.setZoneEffect(1, true, PA_FLIP_LR);
      P.setZoneEffect(2, true, PA_FLIP_UD);
      P.setZoneEffect(2, true, PA_FLIP_LR);
      P.displayZoneText(0,  mostrarT[0], PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayZoneText(1,  mostrarT1[0], PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayZoneText(2,  "------", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayAnimate();
    }
    if (deportistas == 2){
      sprintf(time1, "%d", totalInterruptCounter);
      sprintf(score1, "%d", puntos1);
      sprintf(score2, "%d", puntos2);
      P.setZoneEffect(0, true, PA_FLIP_UD);
      P.setZoneEffect(0, true, PA_FLIP_LR);
      P.setZoneEffect(1, true, PA_FLIP_UD);
      P.setZoneEffect(1, true, PA_FLIP_LR);
      P.setZoneEffect(2, true, PA_FLIP_UD);
      P.setZoneEffect(2, true, PA_FLIP_LR);
      P.displayZoneText(0,  mostrarT2[0], PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayZoneText(1,  mostrarT1[0], PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayZoneText(2,  mostrarT[0], PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayAnimate();
    }
  }

  if (etapa == 2){
    if (deportistas == 1){
      if (etapa == 2){sprintf(time1, "%d", puntos);} 
      sprintf(score1, "%d", puntos1);
      P.setZoneEffect(0, true, PA_FLIP_UD);
      P.setZoneEffect(0, true, PA_FLIP_LR);
      P.setZoneEffect(1, true, PA_FLIP_UD);
      P.setZoneEffect(1, true, PA_FLIP_LR);
      P.setZoneEffect(2, true, PA_FLIP_UD);
      P.setZoneEffect(2, true, PA_FLIP_LR);
      P.displayZoneText(0,  mostrarT[0], PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayZoneText(1,  mostrarT1[0], PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayZoneText(2,  "------", PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayAnimate();
    }
    if (deportistas == 2){
      if (etapa == 2){sprintf(time1, "%d", puntos);} 
      sprintf(score1, "%d", puntos1);
      sprintf(score2, "%d", puntos2);
      P.setZoneEffect(0, true, PA_FLIP_UD);
      P.setZoneEffect(0, true, PA_FLIP_LR);
      P.setZoneEffect(1, true, PA_FLIP_UD);
      P.setZoneEffect(1, true, PA_FLIP_LR);
      P.setZoneEffect(2, true, PA_FLIP_UD);
      P.setZoneEffect(2, true, PA_FLIP_LR);
      P.displayZoneText(0,  mostrarT2[0], PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayZoneText(1,  mostrarT1[0], PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayZoneText(2,  mostrarT[0], PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
      P.displayAnimate();
    }
  }

  if (etapa == 6){
  sprintf(time1, "%d", i);
  P.setZoneEffect(0, true, PA_FLIP_UD);
  P.setZoneEffect(0, true, PA_FLIP_LR);
  P.setZoneEffect(1, true, PA_FLIP_UD);
  P.setZoneEffect(1, true, PA_FLIP_LR);
  P.setZoneEffect(2, true, PA_FLIP_UD);
  P.setZoneEffect(2, true, PA_FLIP_LR);
  P.displayZoneText(0,  mostrarT1[0], PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
  P.displayZoneText(1,  mostrarT1[0], PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
  P.displayZoneText(2,  mostrarT1[0], PA_CENTER, 0, 0, PA_PRINT, PA_NO_EFFECT);
  P.displayAnimate();
  }
  
}
