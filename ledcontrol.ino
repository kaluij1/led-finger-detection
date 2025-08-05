const int ledPins[] = {8, 9, 10, 11, 12};
const int numLeds = 5;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < numLeds; i++){
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();  // remove whitespace/newlines

    // Expected format: "LED8 ON" or "LED9 OFF"
    if (command.startsWith("LED")) {
      int pin = command.substring(3, command.indexOf(' ', 3)).toInt();
      String state = command.substring(command.indexOf(' ') + 1);

      for (int i = 0; i < numLeds; i++) {
        if (ledPins[i] == pin) {
          if (state == "ON") {
            digitalWrite(pin, HIGH);
          } else if (state == "OFF") {
            digitalWrite(pin, LOW);
          }
          break;
        }
      }
    }
  }
}
