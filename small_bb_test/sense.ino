int touchSense() {
  long start = millis();
  long touchVar = cs_4_2.capacitiveSensor(30);
  darkState = analogRead(photoPin);
  delay(10);
  switch (caseState) {
    case 0:
      digitalWrite(redPin, HIGH);
      if (touchVar >= 1000) {
        digitalWrite(redPin, LOW);
        caseState = 1;
      }
      break;
    case 1:
      digitalWrite(greenPin, HIGH);
      digitalWrite(nightPin,HIGH);
      if (touchVar >= 1000) {
        digitalWrite(greenPin, LOW);
        digitalWrite(nightPin,LOW);
        caseState = 2;
      }
      break;
    case 2:
      analogWrite(fadePin, fadeLevel / 2);
      fadeLevel++;
      if (fadeLevel == 40) caseState = 3;
      if (darkState < 250) {
        fadeLevel = 0;
        analogWrite(fadePin, fadeLevel);
        caseState = 4;
      }
      if (touchVar >= 1000) {
        fadeLevel = 0;
        analogWrite(fadePin, fadeLevel);
        caseState = 6;
      }
      break;
    case 3:
      analogWrite(fadePin, fadeLevel / 2);
      fadeLevel--;
      if (fadeLevel == 0) caseState = 2;
      if (darkState < 250) {
        fadeLevel = 0;
        analogWrite(fadePin, fadeLevel);
        caseState = 4;
      }
      if (touchVar >= 1000) {
        fadeLevel = 0;
        analogWrite(fadePin, fadeLevel);
        caseState = 6;
      }
      break;
    case 4:
      analogWrite(nightPin, nightLevel);
      fadeUp = true;
      if (fadeUp == true) nightLevel++;
      if (nightLevel == 100) {
        fadeUp = false;
        caseState = 5;
      }
      if (darkState > 250) {
        nightLevel = 0;
        analogWrite(nightPin, nightLevel);
        caseState = 2;
      }
      break;
    case 5:
      analogWrite(nightPin, nightLevel);
      counter++;
      if (counter == 3000) {
        nightLevel = 0;
        analogWrite(nightPin, nightLevel);
        caseState = 7;
      }
      if (darkState > 250) {
        nightLevel = 0;
        analogWrite(nightPin, nightLevel);
        caseState = 2;
      }
      break;
    case 6:
      caseState = 0;
      break;
      case 7:
      if(darkState >250) {
        counter = 0;
        caseState = 2;
      }
      break;
  }
}

