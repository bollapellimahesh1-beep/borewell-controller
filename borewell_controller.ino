
// ======================================================
// AUTOMATIC BOREWELL PUMP CONTROLLER
// Arduino UNO
// ======================================================

// -------- Pin Configuration --------
const int borewellSensor = 2;
const int tankLowSensor  = 3;
const int tankFullSensor = 4;

const int pumpRelay = 8;
const int buzzer    = 9;

const int pumpLED = 10;
const int faultLED = 11;

// -------- Settings --------
// Change HIGH/LOW if your sensor works opposite
const int WATER_DETECTED = HIGH;
const int WATER_PRESENT  = HIGH;
const int TANK_FULL      = HIGH;

// Pump state
bool pumpRunning = false;
bool fault = false;


// ======================================================
// SETUP
// ======================================================
void setup() {

  pinMode(borewellSensor, INPUT);
  pinMode(tankLowSensor, INPUT);
  pinMode(tankFullSensor, INPUT);

  pinMode(pumpRelay, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(pumpLED, OUTPUT);
  pinMode(faultLED, OUTPUT);

  // Pump OFF at startup
  digitalWrite(pumpRelay, LOW);
  digitalWrite(buzzer, LOW);
  digitalWrite(pumpLED, LOW);
  digitalWrite(faultLED, LOW);

  Serial.begin(9600);

  Serial.println("================================");
  Serial.println(" AUTOMATIC BOREWELL CONTROLLER ");
  Serial.println("================================");
}


// ======================================================
// LOOP
// ======================================================
void loop() {

  int borewellWater = digitalRead(borewellSensor);
  int tankLow       = digitalRead(tankLowSensor);
  int tankFull      = digitalRead(tankFullSensor);

  Serial.println("-------------------------------");

  Serial.print("Borewell Water: ");
  Serial.println(borewellWater);

  Serial.print("Tank Low: ");
  Serial.println(tankLow);

  Serial.print("Tank Full: ");
  Serial.println(tankFull);


  // ----------------------------------------------------
  // 1. DRY RUN PROTECTION
  // ----------------------------------------------------
  if (borewellWater != WATER_DETECTED) {

    stopPump();

    fault = true;

    digitalWrite(buzzer, HIGH);
    digitalWrite(faultLED, HIGH);

    Serial.println("WARNING: BOREWELL WATER LOW!");
    Serial.println("PUMP STOPPED - DRY RUN PROTECTION");

    delay(1000);
    return;
  }


  // ----------------------------------------------------
  // Water available - clear fault
  // ----------------------------------------------------
  fault = false;

  digitalWrite(buzzer, LOW);
  digitalWrite(faultLED, LOW);


  // ----------------------------------------------------
  // 2. TANK FULL
  // ----------------------------------------------------
  if (tankFull == TANK_FULL) {

    stopPump();

    Serial.println("TANK FULL");
    Serial.println("PUMP OFF");
  }


  // ----------------------------------------------------
  // 3. TANK LOW
  // ----------------------------------------------------
  else if (tankLow == WATER_PRESENT) {

    startPump();

    Serial.println("TANK LOW");
    Serial.println("PUMP ON");
  }


  // ----------------------------------------------------
  // 4. NORMAL CONDITION
  // ----------------------------------------------------
  else {

    Serial.println("NORMAL WATER LEVEL");

    // Keep current pump state
    if (pumpRunning) {
      startPump();
    }
    else {
      stopPump();
    }
  }


  delay(1000);
}


// ======================================================
// START PUMP
// ======================================================
void startPump() {

  if (!fault) {

    digitalWrite(pumpRelay, HIGH);
    digitalWrite(pumpLED, HIGH);

    pumpRunning = true;
  }
}


// ======================================================
// STOP PUMP
// ======================================================
void stopPump() {

  digitalWrite(pumpRelay, LOW);
  digitalWrite(pumpLED, LOW);

  pumpRunning = false;
}
