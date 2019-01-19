unsigned long waktuPencet = millis();
bool changeMenu = false;

void lcd_display() {
  if (lcdMenu == 1) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Display  ");
    lcd.setCursor(0, 1);
    lcd.print(String(sensorValDigital[0]) + " " + String(sensorValDigital[1]) + " " +
              String(sensorValDigital[2]) + " " + String(sensorValDigital[3]) + " " +
              String(sensorValDigital[4]) + " " + String(sensorValDigital[5]) + " " +
              String(sensorValDigital[6]) + " " + String(sensorValDigital[7]));

    if (changeMenu) {
      while (!btn2Val) {
        read_button();
      }
      changeMenu = false;
    }

    waktuPencet = millis();
    while (!btn1Val) {
      read_button();
      if ((millis() - waktuPencet) > 1500) {
        lcdMenu = 2;
        changeMenu = true;
        break;
      }
    }

    while (!btn2Val) {
      read_button();
      if ((millis() - waktuPencet) > 1500) {
        lcdMenu = 4;
        changeMenu = true;
        break;
      }
    }
  }
  else if (lcdMenu == 2) {
    lcd.setCursor(0, 0);
    lcd.print("Set KP           ");
    lcd.setCursor(0, 1);
    lcd.print("                 ");
    lcd.setCursor(0, 1);
    lcd.print(kp);

    waktuPencet = millis();
    if (!btn1Val) {
      if (!changeMenu) {
        kp++;
      }
      changeMenu = false;
      while (!btn1Val) {
        read_button();
        if ((millis() - waktuPencet) > 1500) {
          kp--;
          lcdMenu = 3;
          changeMenu = true;
          break;
        }
      }
    }

    if (!btn2Val) {
      if (!changeMenu) {
        kp--;
      }
      changeMenu = false;
      while (!btn2Val) {
        read_button();
        if ((millis() - waktuPencet) > 1500) {
          kp++;
          EEPROM.write(0, kp);
          EEPROM.write(1, kd);
          lcdMenu = 1;
          changeMenu = true;
          break;
        }
      }
    }
  }
  else if (lcdMenu == 3) {
    lcd.setCursor(0, 0);
    lcd.print("Set KD           ");
    lcd.setCursor(0, 1);
    lcd.print("                 ");
    lcd.setCursor(0, 1);
    lcd.print(kd);

    waktuPencet = millis();
    if (!btn1Val) {
      if (!changeMenu) {
        kd++;
      }
      changeMenu = false;
      while (!btn1Val) {
        read_button();
        if ((millis() - waktuPencet) > 1500) {
          kd--;
          lcdMenu = 2;
          changeMenu = true;
          break;
        }
      }
    }

    if (!btn2Val) {
      if (!changeMenu) {
        kd--;
      }
      changeMenu = false;
      while (!btn2Val) {
        read_button();
        if ((millis() - waktuPencet) > 1500) {
          kd++;
          EEPROM.write(0, kp);
          EEPROM.write(1, kd);
          lcdMenu = 1;
          changeMenu = true;
          break;
        }
      }
    }
  }
  else if (lcdMenu == 4) {
    kalib = false;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   Kalibrasi!   ");
    lcd.setCursor(0, 1);
    lcd.print("     Sensor     ");

    kalibrasi();
    for (int i = 0; i < 8; i++) {
      EEPROM.write(2 + i, (sensorCenterPoint[i] / 4));
    }

    lcdMenu = 1;
  }
}
