


void serialDisplay() {
  Serial.print("caseState =\t");
  Serial.print(caseState);
  Serial.print("\tfadeLevel =\t");
  Serial.print(fadeLevel*5);
  Serial.print("\tdarkState =\t");
  Serial.print(darkState);
  Serial.print("\tnightLevel =\t");
  Serial.print(nightLevel);
  Serial.print("\tcounter = \t");
  Serial.print(counter);
  Serial.println();
}

