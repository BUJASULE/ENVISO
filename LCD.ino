#include <LiquidCrystal_I2C.h>

// Configuración del LCD
LiquidCrystal_I2C lcd(0x27, 20, 4);

void setupLCD(){
  pinMode(joystickX, INPUT);
  pinMode(joystickY, INPUT);
  pinMode(botonEnter, INPUT);
  pinMode(33,OUTPUT); //3.3_Rojo
  pinMode(32,OUTPUT); //GND_marrón
  pinMode(33,OUTPUT); //3.3_Rojo
  digitalWrite(32,LOW);   //GND_marrón
  digitalWrite(33,HIGH);  //3.3_Rojo

  ///// INICIO LCD /////
  lcd.init(); //INICIALIZACIÓN DE LA PANTALLA LCD.
  lcd.backlight(); //SE ENCIENDE LA LUZ DE FONDO.
  lcd.setCursor(0,0);//SE CONFIGA EL MENSAJE CON LA SIGUIENTE CONFIGURACIÓN: COLUMNAS - FILAS.
  lcd.print("ENTERNADOR VISOMOTOR"); //ESCRIBIR MENSAJE EN EL LCD.
  lcd.setCursor(4,2);
  lcd.print("SEMILLERO ZION"); //ESCRIBIR MENSAJE EN EL LCD.
  lcd.setCursor(9, 3); //SE CONFIGA EL MENSAJE CON LA SIGUIENTE CONFIGURACIÓN: COLUMNAS - FILAS.
  lcd.print("UDI"); //ESCRIBIR MENSAJE EN EL LCD.
  delay(2000);
  lcd.clear();
  ////////////////////  
}

void LCD(){
  int x = analogRead(joystickX);
  int y = analogRead(joystickY);
  int enter = digitalRead(botonEnter);
  if (x > 3500 && x < 4096) {
    if (m != 3 && m != 4 && m != 5){ 
    menu++;
    }
    if(m == 3){
      tiempo = tiempo - 10;
      if(tiempo < 0){tiempo = 0;}
    }
    if(m == 4){
      puntos = puntos - 10;
      if(puntos < 0){puntos = 0;}
    }
    lcd.clear();
    delay(100);
  }
  if (x==0) {
    if (m != 3 && m != 4 && m != 5){ 
    menu--;
    if(menu < 0){menu = 0;}
    }
    if(m == 3){
      tiempo = tiempo + 10;
      if(tiempo > 999){tiempo = 999;}
    }
    if(m == 4){
      puntos = puntos + 10;
      if(puntos > 999){puntos = 999;}
    }
    lcd.clear();
    delay(100);
  }
  if (enter==0) {
    if(m == 6 && menu == 0){idioma=0;} //Idioma español
    if(m == 6 && menu == 1){idioma=1;} //Idioma Ingles
    
    if(m == 7 && menu == 0){menu=0; m=5; etapa=6;} //Acceder a la pantalla de preparados
    if(m == 3 && menu == 0){menu=0; m=7; p=3; totalInterruptCounter=tiempo+1;} //Acceder a la pantalla de confirmacion desde la pantalla Tiempo
    if(m == 4 && menu == 0){menu=0; m=7; p=4;} //Acceder a la pantalla de confirmacion desde la pantalla Puntos
    
    if(m == 2 && menu == 0){menu=0; m=3; mo=0;} //Aceder a la pantalla de Tiempo modo Contratiempo
    if(m == 2 && menu == 2){menu=0; m=3; mo=2;} //Acceder a la pantalla de Tiempo modo Dos manos
    if(m == 2 && menu == 4){menu=0; m=3; mo=4;} //Acceder a la pantalla de Tiempo modo Apagado
    if(m == 2 && menu == 3){menu=0; m=3; mo=3;} //Acceder a la pantalla de Tiempo modo Velocidad
    if(m == 2 && menu == 1){menu=0; m=4; mo=1;} //Acceder a la pantalla de Puntos modo Puntos
    
    if(m == 1 && menu == 0){menu=0; m=2; deportistas=1;} //Acceder a la pantalla de entrenamientos con 1 deportista
    if(m == 1 && menu == 1){menu=0; m=2; deportistas=2;} //Acceder a la pantalla de entrenamientos con 2 deportistas
    
    if(m == 0 && menu == 0){menu=0; m=1;} //Acceder a la pantalla de deportistas
    if(m == 0 && menu == 1){menu=0; m=6;} //Acceder a la pantalla de Idiomas
    
    if(m == 6 && menu == 2){menu=0; m=0;} //Volver a la pantalla principal desde la pantalla de Idiomas 
    if(m == 1 && menu == 2){menu=0; m=0;} //Volver a la pantalla principal desde la pantalla de Deportistas
    if(m == 2 && menu == 5){menu=0; m=1;} //Volver a la pantalla Deportistas desde la pantalla de Entrenamientos
    if(m == 7 && menu == 1){menu=0; m=2; p=0; tiempo=60; puntos=60; mo=0;} //Volver a la pantalla Entrenamientos desde la pantalla Confirmacion
    
    lcd.clear();
    delay(200);
  }
  mostrarMenu();
}

void mostrarMenu() {
  switch (m) {
    case 0:
      pantallaPrincipal();
      break;
    case 1:
      pantallaDeportistas();
      break;
    case 2:
      pantallaEntrenamientos();
      break;
    case 3:
      pantallaTiempo();
      break;
    case 4:
      pantallaPuntos();
      break;
    case 5:
      pantallaPreparados();
      break;
    case 6:
      pantallaIdiomas();
      break;
    case 7:
      pantallaConfirmacion();
      break;
  }
}

void pantallaPrincipal() {
  switch (idioma){
    case 0:
    switch (menu){
      case 0:
      lcd.setCursor(0, 0);
      lcd.print(">> Iniciar");
      lcd.setCursor(0, 1);
      lcd.print("Idioma");
      lcd.setCursor(5, 3);
      lcd.print("ZION 2023");
      break;
      case 1:
      lcd.setCursor(0, 0);
      lcd.print("Iniciar");
      lcd.setCursor(0, 1);
      lcd.print(">> Idioma");
      lcd.setCursor(5, 3);
      lcd.print("ZION 2023");
      break;
      case 2:
      menu = 1;
      break;
    }
    break;
    case 1:
    switch (menu){
      case 0:
      lcd.setCursor(0, 0);
      lcd.print(">> Start");
      lcd.setCursor(0, 1);
      lcd.print("Language");
      lcd.setCursor(5, 3);
      lcd.print("ZION 2023");
      break;
      case 1:
      lcd.setCursor(0, 0);
      lcd.print("Start");
      lcd.setCursor(0, 1);
      lcd.print(">> Language");
      lcd.setCursor(5, 3);
      lcd.print("ZION 2023");
      break;
      case 2:
      menu = 1;
      break;
    }
   break;
  }
}

void pantallaDeportistas() {
  switch (idioma){
    case 0:
    switch (menu){
      case 0:
      lcd.setCursor(4, 0);
      lcd.print("Deportistas");
      lcd.setCursor(0, 1);
      lcd.print("      >> 1      ");
      lcd.setCursor(0, 2);
      lcd.print("         2      ");
      lcd.setCursor(14, 3);
      lcd.print("Volver");
      break;
      case 1:
      lcd.setCursor(4, 0);
      lcd.print("Deportistas");
      lcd.setCursor(0, 1);
      lcd.print("         1      ");
      lcd.setCursor(0, 2);
      lcd.print("      >> 2      ");
      lcd.setCursor(14, 3);
      lcd.print("Volver");
      break;
      case 2:
      lcd.setCursor(4, 0);
      lcd.print("Deportistas");
      lcd.setCursor(0, 1);
      lcd.print("         1      ");
      lcd.setCursor(0, 2);
      lcd.print("         2      ");
      lcd.setCursor(10, 3);
      lcd.print("Volver <<");      
      break;
      case 3:
      menu = 2;
      break;
    }
    break;
    case 1:
    switch (menu){
      case 0:
      lcd.setCursor(6, 0);
      lcd.print("Athletes");
      lcd.setCursor(0, 1);
      lcd.print("      >> 1      ");
      lcd.setCursor(0, 2);
      lcd.print("         2      ");
      lcd.setCursor(14, 3);
      lcd.print("Back");
      break;
      case 1:
      lcd.setCursor(6, 0);
      lcd.print("Athletes");
      lcd.setCursor(0, 1);
      lcd.print("         1      ");
      lcd.setCursor(0, 2);
      lcd.print("      >> 2      ");
      lcd.setCursor(14, 3);
      lcd.print("Back");
      break;
      case 2:
      lcd.setCursor(6, 0);
      lcd.print("Athletes");
      lcd.setCursor(0, 1);
      lcd.print("         1      ");
      lcd.setCursor(0, 2);
      lcd.print("         2      ");
      lcd.setCursor(13, 3);
      lcd.print("Back <<");      
      break;
      case 3:
      menu = 2;
      break;
    }
    break;
  }
}

void pantallaEntrenamientos() {
  switch (idioma){
    case 0:
    switch (menu){
      case 0:
      lcd.setCursor(4, 0);
      lcd.print("Entrenamiento");
      lcd.setCursor(0, 1);
      lcd.print(">> Contratiempo");
      lcd.setCursor(0, 2);
      lcd.print("Puntos");
      lcd.setCursor(0, 3);
      lcd.print("Dos Manos");
      break;
      case 1:
      lcd.setCursor(4, 0);
      lcd.print("Entrenamiento");
      lcd.setCursor(0, 1);
      lcd.print("Contratiempo");
      lcd.setCursor(0, 2);
      lcd.print(">> Puntos");
      lcd.setCursor(0, 3);
      lcd.print("Dos Manos");
      break;
      case 2:
      lcd.setCursor(4, 0);
      lcd.print("Entrenamiento");
      lcd.setCursor(0, 1);
      lcd.print("Contratiempo");
      lcd.setCursor(0, 2);
      lcd.print("Puntos");
      lcd.setCursor(0, 3);
      lcd.print(">> Dos Manos");    
      break;
      case 3:
      lcd.setCursor(4, 0);
      lcd.print("Entrenamiento");
      lcd.setCursor(0, 1);
      lcd.print("Puntos");
      lcd.setCursor(0, 2);
      lcd.print("Dos Manos");
      lcd.setCursor(0, 3);
      lcd.print(">> Velocidad");
      break;
      case 4:
      lcd.setCursor(4, 0);
      lcd.print("Entrenamiento");
      lcd.setCursor(0, 1);
      lcd.print("Dos Manos");
      lcd.setCursor(0, 2);
      lcd.print("Velocidad");
      lcd.setCursor(0, 3);
      lcd.print(">> Apagado");
      break;
      case 5:
      lcd.setCursor(4, 0);
      lcd.print("Entrenamiento");
      lcd.setCursor(0, 1);
      lcd.print("Velocidad");
      lcd.setCursor(0, 2);
      lcd.print("Apagado");
      lcd.setCursor(10, 3);
      lcd.print("Volver <<");
      break;
      case 6:
      menu = 5;
      break;
    }
    break;
    case 1:
    switch (menu){
      case 0:
      lcd.setCursor(6, 0);
      lcd.print("Training");
      lcd.setCursor(0, 1);
      lcd.print(">> Setback");
      lcd.setCursor(0, 2);
      lcd.print("Points");
      lcd.setCursor(0, 3);
      lcd.print("Two hands");
      break;
      case 1:
      lcd.setCursor(6, 0);
      lcd.print("Training");
      lcd.setCursor(0, 1);
      lcd.print("Setback");
      lcd.setCursor(0, 2);
      lcd.print(">> Points");
      lcd.setCursor(0, 3);
      lcd.print("Two hands");
      break;
      case 2:
      lcd.setCursor(6, 0);
      lcd.print("Training");
      lcd.setCursor(0, 1);
      lcd.print("Setback");
      lcd.setCursor(0, 2);
      lcd.print("Points");
      lcd.setCursor(0, 3);
      lcd.print(">> Two hands");     
      break;
      case 3:
      lcd.setCursor(6, 0);
      lcd.print("Training");
      lcd.setCursor(0, 1);
      lcd.print("Points");
      lcd.setCursor(0, 2);
      lcd.print("Two hands");
      lcd.setCursor(0, 3);
      lcd.print(">> Speed");  
      break;
      case 4:
      lcd.setCursor(6, 0);
      lcd.print("Training");
      lcd.setCursor(0, 1);
      lcd.print("Two hands");
      lcd.setCursor(0, 2);
      lcd.print("Speed");
      lcd.setCursor(0, 3);
      lcd.print(">> Turned off");  
      break;
      case 5:
      lcd.setCursor(6, 0);
      lcd.print("Training");
      lcd.setCursor(0, 1);
      lcd.print("Speed");
      lcd.setCursor(0, 2);
      lcd.print("Turned off");
      lcd.setCursor(13, 3);
      lcd.print("Back <<");  
      break;
      case 6:
      menu = 5;
      break;
    }
    break;
  }
}

void pantallaTiempo() {
switch (idioma){
    case 0:
      lcd.setCursor(7, 0);
      lcd.print("Tiempo");
      if(tiempo > 99){lcd.setCursor(8, 2);}
      if(tiempo < 99){lcd.setCursor(9, 2);}
      lcd.print(tiempo);
      break;
    break;
    case 1:
      lcd.setCursor(8, 0);
      lcd.print("Time");
      if(tiempo > 99){lcd.setCursor(9, 2);}
      if(tiempo < 99){lcd.setCursor(9, 2);}
      lcd.print(tiempo);
    break;
  }
}

void pantallaPuntos() {
switch (idioma){
    case 0:
      lcd.setCursor(7, 0);
      lcd.print("Puntos");
      if(puntos > 99){lcd.setCursor(8, 2);}
      if(puntos < 99){lcd.setCursor(9, 2);}
      lcd.print(puntos);
      break;
    break;
    case 1:
      lcd.setCursor(7, 0);
      lcd.print("Points");
      if(puntos > 99){lcd.setCursor(8, 2);}
      if(puntos < 99){lcd.setCursor(9, 2);}
      lcd.print(puntos);
    break;
  }  
}

void pantallaPreparados() {
switch (idioma){
    case 0:
    if(i > 1){
    for (i=3; i>=1; i--){
    lcd.clear();
    lcd.setCursor(5, 1);
    lcd.print("PREPARADOS");    
    lcd.setCursor(9, 2);
    lcd.print(i);
    Matrices();
    delay(1000);
    lcd.clear();}
    }
    lcd.setCursor(0, 0);
    lcd.print("Modo: ");
    if(mo == 0){lcd.print("Contratiempo"); etapa = 1;}
    if(mo == 1){lcd.print("Puntos"); totalInterruptCounter=0; etapa = 2;}
    if(mo == 2){lcd.print("Dos Manos"); etapa = 3;}
    if(mo == 3){lcd.print("Velocidad"); etapa = 4;}
    if(mo == 4){lcd.print("Apagado"); etapa = 5;}
    lcd.setCursor(0, 1);
    lcd.print("Deportistas: ");
    lcd.print(deportistas);
    lcd.setCursor(5, 3);
    lcd.print("ZION 2023");
    break;
    case 1:
    if(i > 1){
    for (i=3; i>=1; i--){
    lcd.clear();
    lcd.setCursor(8, 1);
    lcd.print("READY");    
    lcd.setCursor(10, 2);
    lcd.print(i);
    Matrices();
    delay(1000);
    lcd.clear();}
    }
    lcd.setCursor(0, 0);
    lcd.print("Mode: ");
    if(mo == 0){lcd.print("Setback"); etapa = 1;}
    if(mo == 1){lcd.print("Points"); totalInterruptCounter=0; etapa = 2;}
    if(mo == 2){lcd.print("Two hands"); etapa = 3;}
    if(mo == 3){lcd.print("Speed");  etapa = 4;}
    if(mo == 4){lcd.print("Turned off"); etapa = 5;}
    lcd.setCursor(0, 1);
    lcd.print("Athletes: ");
    lcd.print(deportistas);
    lcd.setCursor(5, 3);
    lcd.print("ZION 2023");
    }
}

void pantallaIdiomas() {
  switch (idioma){
    case 0:
    switch (menu){
      case 0:
      lcd.setCursor(0, 0);
      lcd.print(">> Espanol");
      lcd.setCursor(0, 1);
      lcd.print("Ingles");
      lcd.setCursor(14, 3);
      lcd.print("Volver");
      break;
      case 1:
      lcd.setCursor(0, 0);
      lcd.print("Espanol");
      lcd.setCursor(0, 1);
      lcd.print(">> Ingles");
      lcd.setCursor(14, 3);
      lcd.print("Volver");
      break;
      case 2:
      lcd.setCursor(0, 0);
      lcd.print("Espanol");
      lcd.setCursor(0, 1);
      lcd.print("Ingles");
      lcd.setCursor(10, 3);
      lcd.print("Volver <<");
      break;
      case 3:
      menu = 2;
      break;
    }
    break;
    case 1:
    switch (menu){
      case 0:
      lcd.setCursor(0, 0);
      lcd.print(">> Spanish");
      lcd.setCursor(0, 1);
      lcd.print("English");
      lcd.setCursor(14, 3);
      lcd.print("Back");
      break;
      case 1:
      lcd.setCursor(0, 0);
      lcd.print("Spanish");
      lcd.setCursor(0, 1);
      lcd.print(">> English");
      lcd.setCursor(14, 3);
      lcd.print("Back");
      break;
      case 2:
      lcd.setCursor(0, 0);
      lcd.print("Spanish");
      lcd.setCursor(0, 1);
      lcd.print("English");
      lcd.setCursor(13, 3);
      lcd.print("Back <<");
      break;
      case 3:
      menu = 2;
      break;
    }
  }
}

void pantallaConfirmacion() {
switch (idioma){
    case 0:
    switch (menu){
      case 0:
      if (p == 3){ 
        lcd.setCursor(7, 0);
        lcd.print("Tiempo");
      }
      if (p == 4){ 
        lcd.setCursor(7, 0);
        lcd.print("Puntos");
      }
      lcd.setCursor(5, 2);
      lcd.print(">> Confirmar");
      lcd.setCursor(5, 3);
      lcd.print("Volver");
      break;
      case 1:
      if (p == 3){ 
        lcd.setCursor(7, 0);
        lcd.print("Tiempo");
      }
      if (p == 4){ 
        lcd.setCursor(7, 0);
        lcd.print("Puntos");
      }
      lcd.setCursor(5, 2);
      lcd.print("Confirmar");
      lcd.setCursor(5, 3);
      lcd.print(">> Volver");
      break;
      case 2:
      menu = 1;   
      break;
    }
    break;
    case 1:
    switch (menu){
      case 0:
      if (p == 3){ 
        lcd.setCursor(7, 0);
        lcd.print("Time");
      }
      if (p == 4){ 
        lcd.setCursor(7, 0);
        lcd.print("Points");
      }
      lcd.setCursor(5, 2);
      lcd.print(">> To confirm");
      lcd.setCursor(5, 3);
      lcd.print("Back");
      break;
      case 1:
      if (p == 3){ 
        lcd.setCursor(7, 0);
        lcd.print("Time");
      }
      if (p == 4){ 
        lcd.setCursor(7, 0);
        lcd.print("Points");
      }
      lcd.setCursor(5, 2);
      lcd.print("To confirm");
      lcd.setCursor(5, 3);
      lcd.print(">> Back");
      break;
    }
    break;
  }  
}


void porcentaje(){
switch (idioma){
    case 0:
    switch (deportistas){
      case 1:
      if(mo == 0 || mo == 2 || mo == 3 || mo == 4){
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Deportista 1");
        lcd.setCursor(1, 2);
        lcd.print("Aciertos: ");
        lcd.print(successRate);
        lcd.print("%");
        lcd.setCursor(1, 3);
        lcd.print("Errores:  ");
        lcd.print(errorRate);
        lcd.print("%");
        delay(10000);
        lcd.clear();
      }
      if(mo == 1){
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Deportista 1");
        lcd.setCursor(1, 1);
        lcd.print("Tiempo: ");
        lcd.print(totalInterruptCounter);
        lcd.print(" Seg");
        lcd.setCursor(1, 2);
        lcd.print("Aciertos: ");
        lcd.print(successRate);
        lcd.print("%");
        lcd.setCursor(1, 3);
        lcd.print("Errores:  ");
        lcd.print(errorRate);
        lcd.print("%");
        delay(10000);
        lcd.clear();
      }
      break;  
      case 2:
        if(mo == 0 || mo == 2 || mo == 3 || mo == 4){
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Deportista 1");
        lcd.setCursor(1, 2);
        lcd.print("Aciertos: ");
        lcd.print(successRate2);
        lcd.print("%");
        lcd.setCursor(1, 3);
        lcd.print("Errores:  ");
        lcd.print(errorRate2);
        lcd.print("%");
        delay(8000);
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Deportista 2");
        lcd.setCursor(1, 2);
        lcd.print("Aciertos: ");
        lcd.print(successRate);
        lcd.print("%");
        lcd.setCursor(1, 3);
        lcd.print("Errores:  ");
        lcd.print(errorRate);
        lcd.print("%");
        delay(8000);
        lcd.clear();
        }
        if(mo == 1){
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Deportista 1");
        lcd.setCursor(1, 1);
        lcd.print("Tiempo: ");
        lcd.print(totalInterruptCounter);
        lcd.print(" Seg");
        lcd.setCursor(1, 2);
        lcd.print("Aciertos: ");
        lcd.print(successRate2);
        lcd.print("%");
        lcd.setCursor(1, 3);
        lcd.print("Errores:  ");
        lcd.print(errorRate2);
        lcd.print("%");
        delay(8000);
        lcd.clear();
        lcd.setCursor(4, 0);
        lcd.print("Deportista 2");
        lcd.setCursor(1, 1);
        lcd.print("Tiempo: ");
        lcd.print(totalInterruptCounter);
        lcd.print(" Seg");
        lcd.setCursor(1, 2);
        lcd.print("Aciertos: ");
        lcd.print(successRate);
        lcd.print("%");
        lcd.setCursor(1, 3);
        lcd.print("Errores:  ");
        lcd.print(errorRate);
        lcd.print("%");
        delay(8000);
        lcd.clear();
        }
      break;
    }
    break;
    case 1:
    switch (deportistas){
      case 1:
      if(mo == 0 || mo == 2 || mo == 3 || mo == 4){
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("Athlete 1");
        lcd.setCursor(0, 2);
        lcd.print("Success Rate:");
        lcd.print(successRate);
        lcd.print("%");
        lcd.setCursor(0, 3);
        lcd.print("Error Rate:  ");
        lcd.print(errorRate);
        lcd.print("%");
        delay(10000);
        lcd.clear();
      }
      if(mo == 1){
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("Athlete 1");
        lcd.setCursor(0, 1);
        lcd.print("Time: ");
        lcd.print(totalInterruptCounter);
        lcd.print(" Sec");
        lcd.setCursor(0, 2);
        lcd.print("Success Rate:");
        lcd.print(successRate);
        lcd.print("%");
        lcd.setCursor(0, 3);
        lcd.print("Error Rate:  ");
        lcd.print(errorRate);
        lcd.print("%");
        delay(10000);
        lcd.clear();
      }
      break;
      case 2:
      if(mo == 0 || mo == 2 || mo == 3 || mo == 4){
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("Athlete 1");
        lcd.setCursor(0, 2);
        lcd.print("Success Rate:");
        lcd.print(successRate2);
        lcd.print("%");
        lcd.setCursor(0, 3);
        lcd.print("Error Rate:  ");
        lcd.print(errorRate2);
        lcd.print("%");
        delay(8000);
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("Athlete 2");
        lcd.setCursor(0, 2);
        lcd.print("Success Rate:");
        lcd.print(successRate);
        lcd.print("%");
        lcd.setCursor(0, 3);
        lcd.print("Error Rate:  ");
        lcd.print(errorRate);
        lcd.print("%");
        delay(8000);
        lcd.clear();
      }
      if (mo == 1){
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("Athlete 1");
        lcd.setCursor(0, 1);
        lcd.print("Time: ");
        lcd.print(totalInterruptCounter);
        lcd.print(" Sec");
        lcd.setCursor(0, 2);
        lcd.print("Success Rate:");
        lcd.print(successRate2);
        lcd.print("%");
        lcd.setCursor(0, 3);
        lcd.print("Error Rate:  ");
        lcd.print(errorRate2);
        lcd.print("%");
        delay(8000);
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("Athlete 2");
        lcd.setCursor(0, 1);
        lcd.print("Time: ");
        lcd.print(totalInterruptCounter);
        lcd.print(" Sec");
        lcd.setCursor(0, 2);
        lcd.print("Success Rate:");
        lcd.print(successRate);
        lcd.print("%");
        lcd.setCursor(0, 3);
        lcd.print("Error Rate:  ");
        lcd.print(errorRate);
        lcd.print("%");
        delay(8000);
        lcd.clear();       
      }
      break;
    }
    break;
}
tiempo = 60; puntos = 60; m=0; menu=0; i=3; puntos1=0; puntos2=0; correctRounds=0; incorrectRounds=0; correctRounds2=0; incorrectRounds2=0; 
successRate=0; successRate2=0; errorRate=0; errorRate2=0; totalPresses=0; totalPresses2=0; generar=0; generar2=0; etapa=0;
}
