void loop() {
  lcd_display();
  readSensor();
  read_button();

  //  if (btn1Val == 0) {
  //    pwmValue++;
  //    while(!btn1Val) {
  //      read_button();
  //    }
  //  }
  //  else if(btn2Val == 0) {
  //    pwmValue--;
  //    while(!btn2Val) {
  //      read_button();
  //    }
  //  }

  //  Serial.print(biner);
  //  Serial.print("\t");
  //  Serial.print(error);
  //  Serial.print("\t");
  //  Serial.println(String(btn1Val) + "," + String(btn2Val));
  //    printSensorVal();

  PD();


  if (sensorError == 13) {
    digitalWrite(OUT1, LOW);
    digitalWrite(OUT2, HIGH);
    digitalWrite(OUT3, HIGH);
    digitalWrite(OUT4, LOW);
    analogWrite(PWM1, 100);
    analogWrite(PWM2, pwmValue);
  }
  else if (sensorError == -13) {
    digitalWrite(OUT1, HIGH);
    digitalWrite(OUT2, LOW);
    digitalWrite(OUT3, LOW);
    digitalWrite(OUT4, HIGH);
    analogWrite(PWM1, pwmValue);
    analogWrite(PWM2, 100);
  }
  else if (P_Value > 0 ) {
    digitalWrite(OUT1, HIGH);
    digitalWrite(OUT2, LOW);
    digitalWrite(OUT3, HIGH);
    digitalWrite(OUT4, LOW);
    analogWrite(PWM2, pwmValue + PD_Value);
    analogWrite(PWM1, pwmValue - PD_Value);
  }
  else if (P_Value < 0) {
    digitalWrite(OUT1, HIGH);
    digitalWrite(OUT2, LOW);
    digitalWrite(OUT3, HIGH);
    digitalWrite(OUT4, LOW);
    analogWrite(PWM2, pwmValue - PD_Value * -1);
    analogWrite(PWM1, pwmValue + PD_Value * -1);
  }
  else {
    digitalWrite(OUT1, HIGH);
    digitalWrite(OUT2, LOW);
    digitalWrite(OUT3, HIGH);
    digitalWrite(OUT4, LOW);
    analogWrite(PWM1, pwmValue);
    analogWrite(PWM2, pwmValue);
  }
}
