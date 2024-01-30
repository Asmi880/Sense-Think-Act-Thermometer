// Declare variables for baseline temperature, Celsius, and Fahrenheit
int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;

// Setup function runs once when the Arduino starts
void setup() {
  // Set A0 pin as INPUT for temperature sensor
  pinMode(A0, INPUT);
  
  // Start serial communication at a baud rate of 9600
  Serial.begin(9600);

  // Set pins 2, 3, and 4 as OUTPUT for LEDs
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

// Loop function runs repeatedly after setup
void loop() {
  // Set threshold temperature to activate LEDs
  baselineTemp = 40;

  // Measure temperature in Celsius using the analog sensor
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);

  // Convert Celsius to Fahrenheit
  fahrenheit = ((celsius * 9) / 5 + 32);

  // Print temperature values to Serial Monitor
  Serial.print(celsius);
  Serial.print(" C, ");
  Serial.print(fahrenheit);
  Serial.println(" F");

  // Control LEDs based on temperature conditions
  if (celsius < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (celsius >= baselineTemp && celsius < baselineTemp + 10) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  if (celsius >= baselineTemp + 10 && celsius < baselineTemp + 20) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  if (celsius >= baselineTemp + 20 && celsius < baselineTemp + 30) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  if (celsius >= baselineTemp + 30) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  // Delay for 1000 milliseconds (1 second)
  delay(1000);
}
