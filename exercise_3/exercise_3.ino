const int sensorPin = A0;
const float baselineTemp = 26.0;
int sensorVal;
float voltage;
float temperature;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorVal = analogRead(sensorPin);
  Serial.print("BaseLine:");
  Serial.print(baselineTemp);
  Serial.print(",");
  voltage = (sensorVal/1024.0) * 5.0;
  Serial.print("UpLimit:");
  Serial.print(baselineTemp+6);
  Serial.print(",");
  temperature = (voltage - .5) * 100;
  Serial.print("Temperature:");
  Serial.println(temperature);

  if(temperature < baselineTemp+2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if(temperature >= baselineTemp+6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }

  delay(1000);
}
