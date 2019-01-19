void setup() {
  deklarasi_setup();

  kp = EEPROM.read(0);
  kd = EEPROM.read(1);

  for (int i = 0; i < 8; i++) {
    sensorCenterPoint[i] = EEPROM.read(2 + i) * 4;
  }
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Muchlis Kurnia");
  lcd.setCursor(0, 1);
  lcd.print(" Line Follower!");
  delay(1000);
  lcdMenu = 1;

  digitalWrite(OUT1, HIGH);
  digitalWrite(OUT2, LOW);
  digitalWrite(OUT3, HIGH);
  digitalWrite(OUT4, LOW);
}
