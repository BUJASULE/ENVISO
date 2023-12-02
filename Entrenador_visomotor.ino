#include <SPIFFS.h>

#include <Wire.h>
#include <SPI.h>
#include "Pulsadores.h"   

// Configuración del joystick y el botón
const int joystickX = 25;
const int joystickY = 26;
const int botonEnter = 13;

//Variable para las etapa
int etapa = 0;

// Variables para el menú
int menu = 0;
int m = 0, p = 0, i=3, mo=0; //Variables auxiliares
int idioma = 0; // 0: Español, 1: Inglés
int deportistas = 0;
int tiempo = 60, puntos = 60;

// Variables para las matrices
char time1[255]; 
char score1[255]; 
char score2[255]; //ALMACENA LOS DATOS DE TIEMPO Y PUNTAJE EN FORMA DE CARACTERES.
char * mostrarT[] = {score1};
char * mostrarT1[] = {time1};
char * mostrarT2[] = {score2};

// Configuracion para el temporizador
hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

// Variable para el temporizador
volatile int interruptCounter; //VARIABLE QUE CUENTA LA CANTIDAD DE INTERRUPCIONES 
int totalInterruptCounter; //VARIABLE QUE CUENTA LA CANTIDAD TOTAL DE INTERRUPCIONES REALIZADAS

// Variable para los entrenamientos
bool generar = false; bool generar2 = false;
int correctRounds = 0; // Rondas correctas del jugador
int incorrectRounds = 0; // Rondas incorrectas del jugador
int correctRounds2 = 0; // Rondas correctas del jugador
int incorrectRounds2 = 0; // Rondas incorrectas del jugador
float successRate = 0;
float errorRate = 0;
float successRate2 = 0;
float errorRate2 = 0;
int totalPresses = 0;
int totalPresses2 = 0;
int puntos1 = 0;
int puntos2 = 0;
int randomLed;
int randomLed_1;
int lastLed = -1;
int lastLed_1 = -1;
int randomLed2;
int randomLed2_1;
int lastLed2 = -1;
int lastLed2_1 = -1;
// Definir el límite de tiempo en milisegundos
#define TIME_LIMIT 750
// Registrar el tiempo de inicio
unsigned long startTime;

void IRAM_ATTR onTimer() {
  portENTER_CRITICAL_ISR(&timerMux);
  interruptCounter++;
  portEXIT_CRITICAL_ISR(&timerMux);
}

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(1));
  //CONFIGURACIÓN PRINCIPAL PARA QUE LAS INTERUPCIONES SE GENEREN CADA SEGUNDO
  timer = timerBegin(0, 80, true);
  timerAttachInterrupt(timer, &onTimer, true);
  timerAlarmWrite(timer, 1000000, true);
  setupPulsadores();
  setupMatrices(); //Configuración principal de las matrices
  setupLCD(); //Configuración principal LCD
}

void loop() {
  if (etapa == 0){
    Matrices();
    LCD();
  }
  if (etapa == 1){
    if (deportistas == 1){Contratiempo1();} 
    if (deportistas == 2){Contratiempo2();}
  }
  if (etapa == 2){
    if (deportistas == 1){Puntos1();} 
    if (deportistas == 2){Puntos2();}
  }
  if (etapa == 3){
    if (deportistas == 1){Dosmanos1();} 
    if (deportistas == 2){Dosmanos2();}
  }
  if (etapa == 4){
    if (deportistas == 1){Velocidad1();} 
    if (deportistas == 2){Velocidad2();}
  }
  if (etapa == 5){
    if (deportistas == 1){Apagado1();} 
    if (deportistas == 2){Apagado2();}
  }
  if (etapa == 6){
     Matrices();
  }

  if (etapa == 7){
    porcentaje();
  }
}
