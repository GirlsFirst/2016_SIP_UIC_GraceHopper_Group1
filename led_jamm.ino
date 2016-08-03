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
  delay(600); //If doesn't work, take out delay(600); and just keep it on low until the loop repeats
  digitalWrite(5, HIGH);
  delay(200);
  digitalWrite(5, LOW);
  delay(600);
  digitalWrite(6, HIGH);
  delay(200);
  digitalWrite(6, LOW);
  delay(600);
  digitalWrite(7, HIGH);
  delay(200);
  digitalWrite(7, LOW);
  delay(600);
}
