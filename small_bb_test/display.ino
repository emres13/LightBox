


int debug() {
  Serial.print("caseState =\t");
  Serial.print(caseState);
  //Serial.print("\ttouchVar =\t");
  //Serial.print(touchVar);
  Serial.print("\tfadeLevel =\t");
  Serial.print(fadeLevel / 2);
  Serial.print("\tdarkState =\t");
  Serial.print(darkState);
  Serial.print("\tnightLevel =\t");
  Serial.print(nightLevel);
  Serial.print("\tcounter = \t");
  Serial.print(counter);
  Serial.println();
}

