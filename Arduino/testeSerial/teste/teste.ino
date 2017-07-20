
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  counter++;
  Serial.print(counter);
  delay(100);
  Serial.print(counter * 2);
  delay(100);
}
