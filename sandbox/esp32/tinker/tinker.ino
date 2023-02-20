
void setup() {
  Serial.begin(115200);
  while (!Serial);
}

void loop() {
  Serial.println( "Welcome to PiDiDah!" );
  exit(0);
}
