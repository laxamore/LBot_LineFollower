void deklarasi_setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);

  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);

  pinMode(muxSelectPin1, OUTPUT);
  pinMode(muxSelectPin2, OUTPUT);
  pinMode(muxSelectPin3, OUTPUT);

  pinMode(muxOutput, INPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT);
}
