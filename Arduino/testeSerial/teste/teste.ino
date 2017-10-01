
int counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  counter++;
  Serial.println(counter);
  Serial.flush();
}
