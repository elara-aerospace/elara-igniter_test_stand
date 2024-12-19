// Pin assignments
const int ignitionPin = 2; // Ignition ON/OFF
const int valve1Pin = 3; // Valve 1 control
const int valve2Pin = 4; // Valve 2 control
const int valve3Pin = 5; // Valve 3 control
const int pressurePins[] = {A0, A1, A2, A3}; // Pressure sensors

// Safety thresholds
const float pressureSafetyMin = 10.0; // Minimum safe pressure
const float pressureSafetyMax = 50.0; // Maximum safe pressure

void setup() {
  // Initialize digital pins as outputs
  pinMode(ignitionPin, OUTPUT);
  pinMode(valve1Pin, OUTPUT);
  pinMode(valve2Pin, OUTPUT);
  pinMode(valve3Pin, OUTPUT);

  // For initializing serial communication
  Serial.begin(9600);
}

void loop() {
  // Read pressures
  float pressures[4];
  for (int i = 0; i < 4; i++) {
    pressures[i] = analogRead(pressurePins[i]) * (5.0 / 1023.0); // Convert from ADC value to voltage
}

// Check safety conditions
  for (int i = 0; i < 4; i++) {
    if (pressures[i] < pressureSafetyMin || pressures[i] > pressureSafetyMax) {
      // Execute safety protocol
      digitalWrite(valve2Pin, LOW);
      digitalWrite(valve3Pin, LOW);
      digitalWrite(valve1Pin, HIGH);
      delay(500); // Open Valve 1 for 0.5 seconds
      digitalWrite(ignitionPin, LOW); // Turn off ignition
      Serial.println("Safety Shutdown");
      return; // Stop further execution
    }
  }

  // Control ignition sequence
  digitalWrite(ignitionPin, HIGH); // Ignition on
  delay(500); // Ignition duration
  digitalWrite(ignitionPin, LOW); // Ignition off
  digitalWrite(valve1Pin, LOW);
  digitalWrite(valve2Pin, HIGH);
  digitalWrite(valve3Pin, HIGH);
  delay(1000); // Time valves 2 and 3 are open
  digitalWrite(valve2Pin, LOW);
  digitalWrite(valve3Pin, LOW);
  digitalWrite(valve1Pin, HIGH);
  delay(500); // Time Valve 1 is reopened

  // Print data to serial
  Serial.print("Pressures: N2 = ");
  Serial.print(pressures[0]);
  Serial.print(", O2 = ");
  Serial.print(pressures[1]);
  Serial.print(", CH4 = ");
  Serial.print(pressures[2]);
  Serial.print(", Igniter = ");
  Serial.println(pressures[3]);

  delay(1000); // Wait before the next loop iteration
}