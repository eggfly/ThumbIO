
int led_red = 9;           // the PWM pin the LED is attached to
int led_green = 10;           // the PWM pin the LED is attached to

int MAX_BRIGHTNESS = 230;
int MIN_BRIGHTNESS = 255;

int brightness = MAX_BRIGHTNESS;    // how bright the LED is


int fadeAmount = 1;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  // declare pin 9 to be an output:
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led_red, brightness);
  analogWrite(led_green, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  Serial.println(brightness);

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= MAX_BRIGHTNESS || brightness >= MIN_BRIGHTNESS) {
    fadeAmount = -fadeAmount;
  }
  delay(50);
}
