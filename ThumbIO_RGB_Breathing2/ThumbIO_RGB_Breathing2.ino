int blue = 12;
int max_value = 255;

void setup() {
  pinMode(9, OUTPUT); // set up LEDs as outputs.
  pinMode(10, OUTPUT);
  // pinMode(blue, OUTPUT);
}
void loop() {
  // startup animation
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  // digitalWrite(blue, HIGH);
  unsigned int thisBlip = 1; // 1 to begin the loop
  byte fadeDirection = 1;
  while (thisBlip) {
    if (thisBlip > 0 && thisBlip <= 255) analogWrite(9, constrain(max_value - thisBlip, 0, max_value));
    else if (thisBlip > 255 && thisBlip < 511) analogWrite(9, constrain(thisBlip - max_value, 0, max_value));
    if (thisBlip > 127 && thisBlip <= 383) analogWrite(10, constrain(max_value - (thisBlip - 128), 0, max_value));
    else if (thisBlip > 383 && thisBlip < 638) analogWrite(10, constrain(thisBlip - 383, 0, max_value));
    //if (thisBlip > 255 && thisBlip <= 511) analogWrite(blue, constrain(max_value - (thisBlip - 256), 0, max_value));
    //else if (thisBlip > 511 && thisBlip < 766) analogWrite(blue, constrain(thisBlip - 511, 0, max_value));
    if (fadeDirection) thisBlip++;
    else thisBlip--;
    if (thisBlip > 766) {
      delay(1000); // hold 1 second at one end of the sequence
      fadeDirection = 0; // you can adjust 638 to change the ending point, goes up to 766 to make the last LED fade completely out at the end before going back "up" and going back through the sequence to the top again. at 638 it reverses when the last LED is full brightness.
    }
    delay(1);
  }
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  //digitalWrite(blue, HIGH);
  delay(1000); // hold 1 second at the beginning of the sequence before looping
}
