////ENTRENAMIENTO CONTRATIEMPO PARA 1 DEPORTISTA.////
void Contratiempo1(){
  // Generar un LED aleatorio
  if(!generar){
  do {
    randomLed = random(0, 16);
    generar = true;
  } while (randomLed == lastLed);
  lastLed = randomLed; 
  }
  
  if(randomLed < 8){
    pcf85743.digitalWrite(leds1[randomLed], HIGH);
  } else {
    pcf85744.digitalWrite(leds2[randomLed-8], HIGH);
  }
  
  // Esperar a que el jugador presione el pulsador correspondiente
    timerAlarmEnable(timer);
    Matrices ();
    
    bool buttonPressedC = false;
    bool buttonPressedI = false;
    
    if(pcf85741.digitalRead(entradas[randomLed]) == HIGH){
      delay(50); // Debouncing delay
      if(pcf85741.digitalRead(entradas[randomLed]) == HIGH){ // Check again after delay
        correctRounds++;
        puntos1++;
        generar = false;
        buttonPressedC = true;
        }
    }
    
    if(pcf85742.digitalRead(entradas[randomLed]) == HIGH){
      delay(50); // Debouncing delay
      if(pcf85742.digitalRead(entradas[randomLed]) == HIGH){ // Check again after delay
        correctRounds++;
        puntos1++;
        generar = false;
        buttonPressedC = true;
        }
    }
    
    for(int i = 0; i < 8; i++){
    if(i != randomLed && pcf85741.digitalRead(entradas[i]) == HIGH){
        delay(50); // Debouncing delay
      if(pcf85741.digitalRead(entradas[i]) == HIGH){
          incorrectRounds++;
          // Evitar puntos negativos
          if(puntos1 < 0){puntos1=0;}
          buttonPressedI = true;
      }
    }
    
    if(i+8 != randomLed && pcf85742.digitalRead(entradas[i]) == HIGH){
        delay(50); // Debouncing delay
      if(pcf85742.digitalRead(entradas[i]) == HIGH){
          incorrectRounds++;
          // Evitar puntos negativos
          if(puntos1 < 0){puntos1=0;}     
          buttonPressedI = true;
      }
    }
  }
    
    if(buttonPressedC || buttonPressedI ){
      totalPresses++;
    }

  if (!generar || totalInterruptCounter == 0){
    // Apagar el LED
    if(randomLed < 8){
      pcf85743.digitalWrite(leds1[randomLed], LOW);
    } else {
      pcf85744.digitalWrite(leds2[randomLed-8], LOW);
    }
  }
 

  Serial.print(totalInterruptCounter);
  Serial.print(totalPresses);
   if(totalInterruptCounter == 0 ){
    successRate = ((float)correctRounds / totalPresses) * 100;
    errorRate = ((float)incorrectRounds / totalPresses) * 100;
    timerAlarmDisable(timer);
    etapa = 7;
  }  
}

////ENTRENAMIENTO CONTRATIEMPO PARA 2 DEPORTISTAS.////

void Contratiempo2(){
  
  // Generar un LED aleatorio para el deportista 1
  if(!generar){
  do {
    randomLed = random(0, 8);
    generar = true;
  } while (randomLed == lastLed);
  lastLed = randomLed; 
  }

  // Generar un LED aleatorio para el deportista 2
  if(!generar2){
  do {
    randomLed2 = random(0, 8);
    generar2 = true;
  } while (randomLed2 == lastLed2);
  lastLed2 = randomLed2;   
  }
  
  // Encender los LEDS
  pcf85743.digitalWrite(leds1[randomLed], HIGH);
  pcf85744.digitalWrite(leds2[randomLed2], HIGH);
  
    timerAlarmEnable(timer);
    Matrices ();

    bool buttonPressedC = false;
    bool buttonPressedI = false;
    bool buttonPressedC2 = false;
    bool buttonPressedI2 = false;
    
  // Check buttons for player 1 and 2 simultaneously
  if(pcf85741.digitalRead(entradas[randomLed]) == HIGH || pcf85742.digitalRead(entradas[randomLed2]) == HIGH){
    delay(50); // Debouncing delay
    // Check again after delay
    if(pcf85741.digitalRead(entradas[randomLed]) == HIGH){ 
      correctRounds++;
      puntos1++;
      buttonPressedC = true;
      generar = false;
    }
    if(pcf85742.digitalRead(entradas[randomLed2]) == HIGH){ 
      correctRounds2++;
      puntos2++;
      buttonPressedC2 = true;
      generar2 = false;
    }
  }
    
  for(int i = 0; i < 8; i++){
    // Check buttons for player 1 and 2 simultaneously
    if((i != randomLed && pcf85741.digitalRead(entradas[i]) == HIGH) || (i != randomLed2 && pcf85742.digitalRead(entradas[i]) == HIGH)){
      delay(50); // Debouncing delay
      // Check again after delay
      if(i != randomLed && pcf85741.digitalRead(entradas[i]) == HIGH){
        incorrectRounds++;
        puntos1--;
        // Evitar puntos negativos
        if(puntos1 < 0){puntos1=0;}
        buttonPressedI = true;
      }
      if(i != randomLed2 && pcf85742.digitalRead(entradas[i]) == HIGH){
        incorrectRounds2++;
        puntos2--;
        // Evitar puntos negativos
        if(puntos2 < 0){puntos2=0;}     
        buttonPressedI2 = true;
      }
    }
  }
    
  // Update total presses
  if(buttonPressedC || buttonPressedI){
    totalPresses++;
  }
  if(buttonPressedC2 || buttonPressedI2){
    totalPresses2++;
  }

  if (!generar || !generar2 || totalInterruptCounter == 0){
    // Apagar el LED
    if (!generar  ||totalInterruptCounter == 0 ){pcf85743.digitalWrite(leds1[randomLed], LOW);}
    if (!generar2 ||totalInterruptCounter == 0 ){pcf85744.digitalWrite(leds2[randomLed2], LOW);}
  }


  Serial.print(totalInterruptCounter);

   if(totalInterruptCounter == 0 ){
    successRate = ((float)correctRounds / totalPresses) * 100;
    errorRate = ((float)incorrectRounds / totalPresses) * 100;
    successRate2 = ((float)correctRounds2 / totalPresses2) * 100;
    errorRate2 = ((float)incorrectRounds2 / totalPresses2) * 100;
    timerAlarmDisable(timer);
    etapa = 7;
  }  
}

////ENTRENAMIENTO PUNTOS PARA 1 DEPORTISTA.////

void Puntos1(){
  
  // Generar un LED aleatorio
  if(!generar){
  do {
    randomLed = random(0, 16);
    generar = true;
  } while (randomLed == lastLed);
  lastLed = randomLed; 
  }
  
  if(randomLed < 8){
    pcf85743.digitalWrite(leds1[randomLed], HIGH);
  } else {
    pcf85744.digitalWrite(leds2[randomLed-8], HIGH);
  }
  
  // Esperar a que el jugador presione el pulsador correspondiente
    timerAlarmEnable(timer);
    Matrices ();
    bool buttonPressedC = false;
    bool buttonPressedI = false;
    if(pcf85741.digitalRead(entradas[randomLed]) == HIGH){
      delay(50); // Debouncing delay
      if(pcf85741.digitalRead(entradas[randomLed]) == HIGH){ // Check again after delay
        correctRounds++;
        puntos1++;
        generar = false;
        buttonPressedC = true;
        }
    }
    
    if(pcf85742.digitalRead(entradas[randomLed]) == HIGH){
      delay(50); // Debouncing delay
      if(pcf85742.digitalRead(entradas[randomLed]) == HIGH){ // Check again after delay
        correctRounds++;
        puntos1++;
        generar = false;
        buttonPressedC = true;
        }
    }
    
    for(int i = 0; i < 8; i++){
    if(i != randomLed && pcf85741.digitalRead(entradas[i]) == HIGH){
        delay(50); // Debouncing delay
      if(pcf85741.digitalRead(entradas[i]) == HIGH){
          incorrectRounds++;
          puntos1--;
          // Evitar puntos negativos
          if(puntos1 < 0){puntos1=0;}
          buttonPressedI = true;
      }
    }
    
    if(i+8 != randomLed && pcf85742.digitalRead(entradas[i]) == HIGH){
        delay(50); // Debouncing delay
      if(pcf85742.digitalRead(entradas[i]) == HIGH){
          incorrectRounds++;
          puntos1--;
          // Evitar puntos negativos
          if(puntos1 < 0){puntos1=0;}     
          buttonPressedI = true;
      }
    }
  }
    
    if(buttonPressedC || buttonPressedI ){
      totalPresses++;
    }
   
if (!generar || puntos1 == puntos){
  // Apagar el LED
  if(randomLed < 8){
    pcf85743.digitalWrite(leds1[randomLed], LOW);
  } else {
    pcf85744.digitalWrite(leds2[randomLed-8], LOW);
  }
}

  Serial.print(totalInterruptCounter);
  Serial.print(totalPresses);
   if(puntos1 == puntos){
    Matrices ();
    successRate = ((float)correctRounds / totalPresses) * 100;
    errorRate = ((float)incorrectRounds / totalPresses) * 100;
    timerAlarmDisable(timer);
    etapa = 7;
  }  
}

////ENTRENAMIENTO PUNTOS PARA 2 DEPORTISTAS.///

void Puntos2(){
  
  // Generar un LED aleatorio para el deportista 1
  if(!generar){
  do {
    randomLed = random(0, 8);
    generar = true;
  } while (randomLed == lastLed);
  lastLed = randomLed; 
  }

  // Generar un LED aleatorio para el deportista 2
  if(!generar2){
  do {
    randomLed2 = random(0, 8);
    generar2 = true;
  } while (randomLed2 == lastLed2);
  lastLed2 = randomLed2;   
  }
  
  // Encender los LEDS
  pcf85743.digitalWrite(leds1[randomLed], HIGH);
  pcf85744.digitalWrite(leds2[randomLed2], HIGH);
  
    timerAlarmEnable(timer);
    Matrices ();

    bool buttonPressedC = false;
    bool buttonPressedI = false;
    bool buttonPressedC2 = false;
    bool buttonPressedI2 = false;
    
  // Check buttons for player 1 and 2 simultaneously
  if(pcf85741.digitalRead(entradas[randomLed]) == HIGH || pcf85742.digitalRead(entradas[randomLed2]) == HIGH){
    delay(50); // Debouncing delay
    // Check again after delay
    if(pcf85741.digitalRead(entradas[randomLed]) == HIGH){ 
      correctRounds++;
      puntos1++;
      buttonPressedC = true;
      generar = false;
    }
    if(pcf85742.digitalRead(entradas[randomLed2]) == HIGH){ 
      correctRounds2++;
      puntos2++;
      buttonPressedC2 = true;
      generar2 = false;
    }
  }
    
  for(int i = 0; i < 8; i++){
    // Check buttons for player 1 and 2 simultaneously
    if((i != randomLed && pcf85741.digitalRead(entradas[i]) == HIGH) || (i != randomLed2 && pcf85742.digitalRead(entradas[i]) == HIGH)){
      delay(50); // Debouncing delay
      // Check again after delay
      if(i != randomLed && pcf85741.digitalRead(entradas[i]) == HIGH){
        incorrectRounds++;
        puntos1--;
        // Evitar puntos negativos
        if(puntos1 < 0){puntos1=0;}
        buttonPressedI = true;
      }
      if(i != randomLed2 && pcf85742.digitalRead(entradas[i]) == HIGH){
        incorrectRounds2++;
        puntos2--;
        // Evitar puntos negativos
        if(puntos2 < 0){puntos2=0;}     
        buttonPressedI2 = true;
      }
    }
  }
    
  // Update total presses
  if(buttonPressedC || buttonPressedI){
    totalPresses++;
  }
  if(buttonPressedC2 || buttonPressedI2){
    totalPresses2++;
  }

  if (!generar || puntos1 == puntos || puntos2 == puntos){
    // Apagar el LED
    pcf85743.digitalWrite(leds1[randomLed], LOW);
    pcf85744.digitalWrite(leds2[randomLed2], LOW);
  }


  Serial.print(totalInterruptCounter);

   if(puntos1 == puntos || puntos2 == puntos){
    Matrices();
    successRate = ((float)correctRounds / totalPresses) * 100;
    errorRate = ((float)incorrectRounds / totalPresses) * 100;
    successRate2 = ((float)correctRounds2 / totalPresses2) * 100;
    errorRate2 = ((float)incorrectRounds2 / totalPresses2) * 100;
    timerAlarmDisable(timer);
    etapa = 7;
  }  
}

////ENTRENAMIENTO DOS MANOS PARA 1 DEPORTISTA.////

void Dosmanos1(){
  // Generar dos LEDs aleatorios
  if(!generar){
    do {
      randomLed = random(0, 8);
      randomLed_1 = random(0, 8);
    } while (randomLed == lastLed || randomLed_1 == lastLed_1);
    lastLed = randomLed; 
    lastLed_1 = randomLed_1;
    generar = true;
  }

  // Encender los LEDs
    pcf85743.digitalWrite(leds1[randomLed], HIGH);
    pcf85744.digitalWrite(leds2[randomLed_1], HIGH);
    
  // Esperar a que el jugador presione el pulsador correspondiente
    timerAlarmEnable(timer);
    Matrices ();
    
    bool buttonPressedC = false;
    bool buttonPressedI = false;

  if(pcf85741.digitalRead(entradas[randomLed]) == HIGH && pcf85742.digitalRead(entradas[randomLed_1]) == HIGH){
    delay(50); // Debouncing delay
    if(pcf85741.digitalRead(entradas[randomLed]) == HIGH && pcf85742.digitalRead(entradas[randomLed_1]) == HIGH){ // Check again after delay
      correctRounds++;
      puntos1++;
      generar = false;
      buttonPressedC = true;
    }
  }
    
for(int i = 0; i < 8; i++){
  if(i != randomLed && pcf85741.digitalRead(entradas[i]) == HIGH || i != randomLed_1 && pcf85742.digitalRead(entradas[i]) == HIGH){
    delay(50); // Debouncing delay
    if(pcf85741.digitalRead(entradas[i]) == HIGH || pcf85742.digitalRead(entradas[i]) == HIGH){
      incorrectRounds++;
      puntos1--;
      // Evitar puntos negativos
      if(puntos1 < 0){puntos1=0;}
      buttonPressedI = true;
    }
  }
}

if(buttonPressedC || buttonPressedI ){totalPresses++;}

// Apagar el LED
if (!generar || totalInterruptCounter == 0){
  pcf85743.digitalWrite(leds1[randomLed], LOW);
  pcf85744.digitalWrite(leds2[randomLed_1], LOW);
}
  
  Serial.print(totalInterruptCounter);
  Serial.print(totalPresses);
  
   if(totalInterruptCounter == 0 ){
    successRate = ((float)correctRounds / totalPresses) * 100;
    errorRate = ((float)incorrectRounds / totalPresses) * 100;
    timerAlarmDisable(timer);
    etapa = 7;
  }  
}

////ENTRENAMIENTO DOS MANOS PARA 2 DEPORTISTAS.////

void Dosmanos2(){
  // Generar dos LEDs aleatorios
  if(!generar){
    do {
      randomLed = random(0, 4);
      randomLed_1 = random(4, 8);
    } while (randomLed == lastLed || randomLed_1 == lastLed_1);
    lastLed = randomLed; 
    lastLed_1 = randomLed_1;
    generar = true;
  }

  if(!generar2){
    do {
      randomLed2 = random(0, 4);
      randomLed2_1 = random(4, 8);
    } while (randomLed2 == lastLed2 || randomLed2_1 == lastLed2_1);
    lastLed2 = randomLed2; 
    lastLed2_1 = randomLed2_1;
    generar2 = true;
  }

  // Encender los LEDs
    pcf85743.digitalWrite(leds1[randomLed], HIGH);
    pcf85743.digitalWrite(leds1[randomLed_1], HIGH);
    pcf85744.digitalWrite(leds2[randomLed2], HIGH);
    pcf85744.digitalWrite(leds2[randomLed2_1], HIGH);
    
  // Esperar a que el jugador presione el pulsador correspondiente
    timerAlarmEnable(timer);
    Matrices ();
    

    bool buttonPressedC = false;
    bool buttonPressedI = false;
    bool buttonPressedC2 = false;
    bool buttonPressedI2 = false;

  if(pcf85741.digitalRead(entradas[randomLed]) == HIGH && pcf85741.digitalRead(entradas[randomLed_1]) == HIGH || pcf85742.digitalRead(entradas[randomLed2]) == HIGH && pcf85742.digitalRead(entradas[randomLed2_1]) == HIGH  ){
    delay(50); // Debouncing delay
    if(pcf85741.digitalRead(entradas[randomLed]) == HIGH && pcf85741.digitalRead(entradas[randomLed_1]) == HIGH){ // Check again after delay
      correctRounds++;
      puntos1++;
      generar = false;
      buttonPressedC = true;
    }
    if(pcf85742.digitalRead(entradas[randomLed2]) == HIGH && pcf85742.digitalRead(entradas[randomLed2_1]) == HIGH){ // Check again after delay
      correctRounds2++;
      puntos2++;
      generar2 = false;
      buttonPressedC2 = true;
    }
  }
    
for(int i = 0; i < 8; i++){
  if(i != randomLed && pcf85741.digitalRead(entradas[i]) == HIGH && i != randomLed_1 || i != randomLed2 && pcf85742.digitalRead(entradas[i]) == HIGH && i != randomLed2_1){
    delay(50); // Debouncing delay
    if(pcf85741.digitalRead(entradas[i]) == HIGH){
      incorrectRounds++;
      puntos1--;
      // Evitar puntos negativos
      if(puntos1 < 0){puntos1=0;}
      buttonPressedI = true;
    }
    if(pcf85742.digitalRead(entradas[i]) == HIGH){
      incorrectRounds2++;
      puntos2--;
      // Evitar puntos negativos
      if(puntos2 < 0){puntos2=0;}
      buttonPressedI2 = true;
    }
  }
}

if(buttonPressedC || buttonPressedI ){totalPresses++;}
if(buttonPressedC2 || buttonPressedI2 ){totalPresses2++;}

// Apagar el LED
if (!generar || totalInterruptCounter == 0){
  pcf85743.digitalWrite(leds1[randomLed], LOW);
  pcf85743.digitalWrite(leds2[randomLed_1], LOW);
}

// Apagar el LED
if (!generar2 || totalInterruptCounter == 0){
  pcf85744.digitalWrite(leds1[randomLed2], LOW);
  pcf85744.digitalWrite(leds2[randomLed2_1], LOW);
}
  
  Serial.print(totalInterruptCounter);
  Serial.print(totalPresses);
  
   if(totalInterruptCounter == 0 ){
    successRate = ((float)correctRounds / totalPresses) * 100;
    errorRate = ((float)incorrectRounds / totalPresses) * 100;
    successRate2 = ((float)correctRounds2 / totalPresses2) * 100;
    errorRate2 = ((float)incorrectRounds2 / totalPresses2) * 100;
    timerAlarmDisable(timer);
    etapa = 7;
  }  
}

////ENTRENAMIENTO VELOCIDAD PARA 1 DEPORTISTA.////
void Velocidad1(){
  // Generar un LED aleatorio
  if(!generar){
  do {
    randomLed = random(0, 16);
    generar = true;
  } while (randomLed == lastLed);
  lastLed = randomLed; 
  }
  
  if(randomLed < 8){
    pcf85743.digitalWrite(leds1[randomLed], HIGH);
  } else {
    pcf85744.digitalWrite(leds2[randomLed-8], HIGH);
  }
  
  // Esperar a que el jugador presione el pulsador correspondiente
  // Iniciar el temporizador
    startTime = millis();
    
    bool buttonPressedC = false;
    bool buttonPressedI = false;
  
  // Esperar a que el jugador presione el pulsador correspondiente
  while(millis() - startTime < TIME_LIMIT || generar == false){
    timerAlarmEnable(timer);
    Matrices ();
    if(pcf85741.digitalRead(entradas[randomLed]) == HIGH || pcf85742.digitalRead(entradas[randomLed]) == HIGH){
      delay(50); // Debouncing delay
      if(pcf85741.digitalRead(entradas[randomLed]) == HIGH || pcf85742.digitalRead(entradas[randomLed]) == HIGH){ // Check again after delay
        correctRounds++;
        puntos1++;
        buttonPressedC = true;
        generar = false;
        break;
      }
    }
    
    for(int i = 0; i < 8; i++){
      if(i != randomLed && (pcf85741.digitalRead(entradas[i]) == HIGH || pcf85742.digitalRead(entradas[i]) == HIGH)){
        delay(50); // Debouncing delay
        if(pcf85741.digitalRead(entradas[i]) == HIGH || pcf85742.digitalRead(entradas[i]) == HIGH){
          incorrectRounds++;
          buttonPressedI = true;
          puntos1--;
          // Evitar puntos negativos
          if(puntos1 < 0){puntos1=0;}
          break;
        }
      }
    }
  }
  
  // Apagar el LED
  if(randomLed < 8){
    pcf85743.digitalWrite(leds1[randomLed], LOW);
    generar = false;
  } else {
    pcf85744.digitalWrite(leds2[randomLed-8], LOW);
    generar = false;
  }
  
   if(buttonPressedC || buttonPressedI ){
      totalPresses++;
   }
   
   if(totalInterruptCounter == 0 ){
    timerAlarmDisable(timer);
    successRate = ((float)correctRounds / totalPresses) * 100;
    errorRate = ((float)incorrectRounds / totalPresses) * 100;
    etapa = 7;
  }  
}

void Velocidad2(){
  
  // Generar un LED aleatorio para el deportista 1
  if(!generar){
  do {
    randomLed = random(0, 8);
    generar = true;
  } while (randomLed == lastLed);
  lastLed = randomLed; 
  }

  // Generar un LED aleatorio para el deportista 2
  if(!generar2){
  do {
    randomLed2 = random(0, 8);
    generar2 = true;
  } while (randomLed2 == lastLed2);
  lastLed2 = randomLed2;   
  }
  
  // Encender los LEDS
  pcf85743.digitalWrite(leds1[randomLed], HIGH);
  pcf85744.digitalWrite(leds2[randomLed2], HIGH);

    // Iniciar el temporizador
    startTime = millis();
            
    bool buttonPressedC = false;
    bool buttonPressedI = false;
    bool buttonPressedC2 = false;
    bool buttonPressedI2 = false;

  while(millis() - startTime < TIME_LIMIT || generar == false){
    timerAlarmEnable(timer);
    Matrices ();
  // Check buttons for player 1 and 2 simultaneously
  if(pcf85741.digitalRead(entradas[randomLed]) == HIGH || pcf85742.digitalRead(entradas[randomLed2]) == HIGH){
    delay(50); // Debouncing delay
    // Check again after delay
    if(pcf85741.digitalRead(entradas[randomLed]) == HIGH){ 
      correctRounds++;
      puntos1++;
      buttonPressedC = true;
      generar = false;
      break;
    }
    if(pcf85742.digitalRead(entradas[randomLed2]) == HIGH){ 
      correctRounds2++;
      puntos2++;
      buttonPressedC2 = true;
      generar2 = false;
      break;
    }
  }
    
  for(int i = 0; i < 8; i++){
    // Check buttons for player 1 and 2 simultaneously
    if((i != randomLed && pcf85741.digitalRead(entradas[i]) == HIGH) || (i != randomLed2 && pcf85742.digitalRead(entradas[i]) == HIGH)){
      delay(50); // Debouncing delay
      // Check again after delay
      if(i != randomLed && pcf85741.digitalRead(entradas[i]) == HIGH){
        incorrectRounds++;
        puntos1--;
        // Evitar puntos negativos
        if(puntos1 < 0){puntos1=0;}
        buttonPressedI = true;
        break;
      }
      if(i != randomLed2 && pcf85742.digitalRead(entradas[i]) == HIGH){
        incorrectRounds2++;
        puntos2--;
        // Evitar puntos negativos
        if(puntos2 < 0){puntos2=0;}     
        buttonPressedI2 = true;
        break;
      }
    }
  }
  }
  generar   = false;
  generar2 = false;
  // Update total presses
  if(buttonPressedC || buttonPressedI){
    totalPresses++;
  }
  if(buttonPressedC2 || buttonPressedI2){
    totalPresses2++;
  }

  if (!generar || !generar2 || totalInterruptCounter == 0){
    // Apagar el LED
    if (!generar  ||totalInterruptCounter == 0 ){pcf85743.digitalWrite(leds1[randomLed], LOW);}
    if (!generar2 ||totalInterruptCounter == 0 ){pcf85744.digitalWrite(leds2[randomLed2], LOW);}
  }

  Serial.print(totalInterruptCounter);

   if(totalInterruptCounter == 0 ){
    successRate = ((float)correctRounds / totalPresses) * 100;
    errorRate = ((float)incorrectRounds / totalPresses) * 100;
    successRate2 = ((float)correctRounds2 / totalPresses2) * 100;
    errorRate2 = ((float)incorrectRounds2 / totalPresses2) * 100;
    timerAlarmDisable(timer);
    etapa = 7;
  }  
}

////ENTRENAMIENTO APAGADO PARA 1 DEPORTISTA.////
void Apagado1(){
  // Generar un LED aleatorio
  if(!generar){
  do {
    randomLed = random(0, 16);
    generar = true;
  } while (randomLed == lastLed);
  lastLed = randomLed; 
  }
  
  // Encender todos los LEDs excepto el randomLed
  for(int i = 0; i < 16; i++){
    if(i != randomLed){
      if(i < 8){
        pcf85743.digitalWrite(leds1[i], HIGH);
      } else {
        pcf85744.digitalWrite(leds2[i-8], HIGH);
      }
    }
  }
  
  // Esperar a que el jugador presione el pulsador correspondiente
  timerAlarmEnable(timer);
  Matrices ();
    
  bool buttonPressedC = false;
  bool buttonPressedI = false;
    
  if(pcf85741.digitalRead(entradas[randomLed]) == HIGH){
    delay(50); // Debouncing delay
    if(pcf85741.digitalRead(entradas[randomLed]) == HIGH){ // Check again after delay
      correctRounds++;
      puntos1++;
      generar = false;
      buttonPressedC = true;
      }
  }
    
  if(pcf85742.digitalRead(entradas[randomLed]) == HIGH){
    delay(50); // Debouncing delay
    if(pcf85742.digitalRead(entradas[randomLed]) == HIGH){ // Check again after delay
      correctRounds++;
      puntos1++;
      generar = false;
      buttonPressedC = true;
      }
  }
    
  for(int i = 0; i < 16; i++){
    if(i != randomLed && (pcf85741.digitalRead(entradas[i]) == HIGH || pcf85742.digitalRead(entradas[i]) == HIGH)){
      delay(50); // Debouncing delay
      if(pcf85741.digitalRead(entradas[i]) == HIGH || pcf85742.digitalRead(entradas[i]) == HIGH){
        incorrectRounds++;
        puntos1--;
        // Evitar puntos negativos
        if(puntos1 < 0){puntos1=0;}
        buttonPressedI = true;
      }
    }
  }
    
  if(buttonPressedC || buttonPressedI ){
    totalPresses++;
  }

  if (!generar || totalInterruptCounter == 0){
    // Apagar todos los LEDs
    for(int i = 0; i < 16; i++){
      if(i < 8){
        pcf85743.digitalWrite(leds1[i], LOW);
      } else {
        pcf85744.digitalWrite(leds2[i-8], LOW);
      }
    }
  }
 
  Serial.print(totalInterruptCounter);
  Serial.print(totalPresses);
  if(totalInterruptCounter == 0 ){
    successRate = ((float)correctRounds / totalPresses) * 100;
    errorRate = ((float)incorrectRounds / totalPresses) * 100;
    timerAlarmDisable(timer);
    etapa = 7;
  }  
}

////ENTRENAMIENTO APAGADO PARA 2 DEPORTISTAS.////
void Apagado2(){
  
  // Generar un LED aleatorio para el deportista 1
  if(!generar){
  do {
    randomLed = random(0, 8);
    generar = true;
  } while (randomLed == lastLed);
  lastLed = randomLed; 
  }

  // Generar un LED aleatorio para el deportista 2
  if(!generar2){
  do {
    randomLed2 = random(0, 8);
    generar2 = true;
  } while (randomLed2 == lastLed2);
  lastLed2 = randomLed2;   
  }
  
  // Encender todos los LEDS excepto los seleccionados
  for(int i = 0; i < 8; i++){
    if(i != randomLed){
      pcf85743.digitalWrite(leds1[i], HIGH);
    }
    if(i != randomLed2){
      pcf85744.digitalWrite(leds2[i], HIGH);
    }
  }
  
  timerAlarmEnable(timer);
  Matrices ();

  bool buttonPressedC = false;
  bool buttonPressedI = false;
  bool buttonPressedC2 = false;
  bool buttonPressedI2 = false;
    
  // Check buttons for player 1 and 2 simultaneously
  if(pcf85741.digitalRead(entradas[randomLed]) == HIGH || pcf85742.digitalRead(entradas[randomLed2]) == HIGH){
    delay(50); // Debouncing delay
    // Check again after delay
    if(pcf85741.digitalRead(entradas[randomLed]) == HIGH){ 
      correctRounds++;
      puntos1++;
      buttonPressedC = true;
      generar = false;
    }
    if(pcf85742.digitalRead(entradas[randomLed2]) == HIGH){ 
      correctRounds2++;
      puntos2++;
      buttonPressedC2 = true;
      generar2 = false;
    }
  }
    
  for(int i = 0; i < 8; i++){
    // Check buttons for player 1 and 2 simultaneously
    if((i != randomLed && pcf85741.digitalRead(entradas[i]) == HIGH) || (i != randomLed2 && pcf85742.digitalRead(entradas[i]) == HIGH)){
      delay(50); // Debouncing delay
      // Check again after delay
      if(i != randomLed && pcf85741.digitalRead(entradas[i]) == HIGH){
        incorrectRounds++;
        puntos1--;
        // Evitar puntos negativos
        if(puntos1 < 0){puntos1=0;}
        buttonPressedI = true;
      }
      if(i != randomLed2 && pcf85742.digitalRead(entradas[i]) == HIGH){
        incorrectRounds2++;
        puntos2--;
        // Evitar puntos negativos
        if(puntos2 < 0){puntos2=0;}     
        buttonPressedI2 = true;
      }
    }
  }
    
  // Update total presses
  if(buttonPressedC || buttonPressedI){
    totalPresses++;
  }
  if(buttonPressedC2 || buttonPressedI2){
    totalPresses2++;
  }

  if (!generar || !generar2 || totalInterruptCounter == 0){
    // Apagar todos los LEDs excepto el seleccionado
    for(int i = 0; i < 8; i++){
        pcf85743.digitalWrite(leds1[i], LOW);
        pcf85744.digitalWrite(leds2[i], LOW);
      }
  }

  Serial.print(totalInterruptCounter);

   if(totalInterruptCounter == 0 ){
    successRate = ((float)correctRounds / totalPresses) * 100;
    errorRate = ((float)incorrectRounds / totalPresses) * 100;
    successRate2 = ((float)correctRounds2 / totalPresses2) * 100;
    errorRate2 = ((float)incorrectRounds2 / totalPresses2) * 100;
    timerAlarmDisable(timer);
    etapa = 7;
  }  
}
