bool kalib = false;

int maxSensor[8];
int minSensor[8] = {1023, 1023, 1023, 1023, 1023, 1023, 1023, 1023};

void kalibrasi() {
  while (!kalib) {
    readSensor();
    read_button();

    for (int i = 0; i < 8; i++) {
      if (sensorVal[i] >= maxSensor[i]) {
        maxSensor[i] = sensorVal[i];
      }
      else if (sensorVal[i] < minSensor[i]) {
        minSensor[i] = sensorVal[i];
      }

      Serial.print(sensorVal[i]);
      Serial.print(" ");
    }
    Serial.println();

    if (btn1Val == 0) {
      for (int i = 0; i < 8; i++) {
        deteksiPutih[i] = sensorVal[i];
        sensorCenterPoint[i] = (maxSensor[i] + minSensor[i]) / 2;
      }

      kalib = true;
    }

    while (!btn1Val) {
      read_button();
    }
  }
}
