void readSensor() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(muxSelectPin1, bitRead(i, 0));
    digitalWrite(muxSelectPin2, bitRead(i, 1));
    digitalWrite(muxSelectPin3, bitRead(i, 2));

    sensorVal[i] = analogRead(muxOutput);
  }

  convertDigital();
}

void convertDigital() {
  for (int i = 0; i < 8; i++) {
    if (sensorVal[i] > sensorCenterPoint[i]) {
      sensorValDigital[i] = 1;
    }
    else {
      sensorValDigital[i] = 0;
    }
  }

  convertBiner();
}

void convertBiner() {
  biner = String(sensorValDigital[0]) + String(sensorValDigital[1]) +
          String(sensorValDigital[2]) + String(sensorValDigital[3]) +
          String(sensorValDigital[4]) + String(sensorValDigital[5]) +
          String(sensorValDigital[6]) + String(sensorValDigital[7]);
  readError();
}

void findError() {
  if (biner == "00000001") {
    sensorError = 4;
  }
  else if (biner == "00000011") {
    sensorError = 3;
  }
  else if (biner == "00000111") {
    sensorError = 2;
  }
  else if (biner == "00001100" || biner == "00001110") {
    sensorError = 1;
  }
  else if (biner == "00011000" || biner == "00011100" || biner == "00111000") {
    sensorError = 0;
  }
  else if (biner == "00110000" || biner == "01110000") {
    sensorError = -1;
  }
  else if (biner == "11100000") {
    sensorError = -2;
  }
  else if (biner == "11000000") {
    sensorError = -3;
  }
  else if (biner == "10000000") {
    sensorError = -4;
  }
  else if (biner == "00000000") {
    if (sensorError < 0) {
      sensorError = -4;
    }
    else {
      sensorError = 4;
    }
  }
}

void readError() {
  int multiplierLeft = 0, multiplierRight = 0, adderLeft = 0, adderRight = 0;

  if (sensorValDigital[3] == 1) {
    multiplierLeft = 1;
  }
  else if (sensorValDigital[2] == 1 && sensorValDigital[3] == 0) {
    multiplierLeft = 2;
  }
  else if (sensorValDigital[1] == 1 && sensorValDigital[2] == 0 && sensorValDigital[3] == 0) {
    multiplierLeft = 3;
  }
  else if (sensorValDigital[0] == 1 && sensorValDigital[1] == 0 && sensorValDigital[2] == 0 && sensorValDigital[3] == 0) {
    multiplierLeft = 4;
  }

  if (sensorValDigital[0] == 1) {
    adderLeft = 4 + 3 + 2;
  }
  else if (sensorValDigital[1] == 1 && sensorValDigital[0] == 0) {
    adderLeft = 3 + 2;
  }
  else if (sensorValDigital[2] == 1 && sensorValDigital[1] == 0 && sensorValDigital[0] == 0) {
    adderLeft = 2;
  }

  if (sensorValDigital[4] == 1) {
    multiplierRight = 1;
  }
  else if (sensorValDigital[5] == 1 && sensorValDigital[4] == 0) {
    multiplierRight = 2;
  }
  else if (sensorValDigital[6] == 1 && sensorValDigital[5] == 0 && sensorValDigital[4] == 0) {
    multiplierRight = 3;
  }
  else if (sensorValDigital[7] == 1 && sensorValDigital[6] == 0 && sensorValDigital[5] == 0 && sensorValDigital[4] == 0) {
    multiplierRight = 4;
  }

  if (sensorValDigital[7] == 1) {
    adderRight = 4 + 3 + 2;
  }
  else if (sensorValDigital[6] == 1 && sensorValDigital[7] == 0) {
    adderRight = 3 + 2;
  }
  else if (sensorValDigital[5] == 1 && sensorValDigital[6] == 0 && sensorValDigital[7] == 0) {
    adderRight = 2;
  }

  if (multiplierRight == 1 || multiplierLeft == 1) {
    sensorError = (adderRight + (multiplierRight * 1)) - (adderLeft + (multiplierLeft * 1));
  }
  else {
    if (sensorError > 0) {
      sensorError = 13;
    }
    else if (sensorError < 0) {
      sensorError = -13;
    }
  }

  for (int i = 0; i < 8; i++) {
    Serial.print(sensorValDigital[i]);
  }
  Serial.print("\t");

  Serial.print(multiplierLeft);
  Serial.print(" , ");
  Serial.print(multiplierRight);
  Serial.print(" , ");
  Serial.println(sensorError);
}

void printSensorVal() {
  //  Serial.print(String(sensorVal[0]) + " , ");
  //  Serial.print(String(sensorVal[1]) + " , ");
  //  Serial.print(String(sensorVal[2]) + " , ");
  //  Serial.print(String(sensorVal[3]) + " , ");
  //  Serial.print(String(sensorVal[4]) + " , ");
  //  Serial.print(String(sensorVal[5]) + " , ");
  //  Serial.print(String(sensorVal[6]) + " , ");
  //  Serial.println(String(sensorVal[7]));
}
