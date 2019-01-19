void read_button() {
  btn1Val = digitalRead(button1);
  if (analogRead(button2) > 500) {
    btn2Val = 1;
  }
  else {
    btn2Val = 0;
  }
}
