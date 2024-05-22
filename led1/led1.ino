#define PIN_LED 13
#define PIN_POT A0
int16_t vFactor = 1;
void setup() {
  char tmp[32] = "";
  char aChar = '\0';
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_LED, OUTPUT);
  Serial.println("facteur de grandisement de V ?");
  while (Serial.available() <= 0) {
    delay(500);
  }
  uint8_t i = 0;
  while (Serial.available()) {
    aChar = (char)Serial.read();
    tmp[i++] = aChar;
  }
  tmp[i] = '\0';

  vFactor = atoi(tmp);

  Serial.print("Votre choix : ");
  Serial.println(vFactor);
}

void loop() {

  //lecture analogique
  uint16_t A0Value = analogRead(A0);
  Serial.print("can value:");
  Serial.print(A0Value);
  Serial.print(",");

  const float ratio = 5.0F / 1024.0F;
  Serial.print("volt:");
  Serial.println(A0Value * ratio * vFactor);


  uint16_t delaytime = map(A0Value, 0, 1023, 500, 1500);
  //blink
  digitalWrite(PIN_LED, HIGH);
  delay(delaytime);
  digitalWrite(PIN_LED, LOW);
  delay(delaytime);
}
