void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT); //red
  pinMode(5, OUTPUT); //green
  pinMode(6, OUTPUT); //blue
  pinMode(7, OUTPUT); //yellow
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(4, HIGH);
  delay(200);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  delay(200);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  delay(200);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  delay(200);
  digitalWrite(7, LOW);
}
