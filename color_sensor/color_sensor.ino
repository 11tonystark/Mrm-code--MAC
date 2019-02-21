
#define S0 5
#define S1 6
#define S2 9
#define S3 10
#define sensorOut 3
int frequency = 0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
  // Setting red filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  if(frequency>255)
  frequency=255;
  frequency = map(frequency, 17,70,255,0);
  Serial.print(frequency);//printing RED color frequency
  
  Serial.print("  ");
  delay(300);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("G= ");//printing name
  if(frequency>255)
  frequency=255;
  Serial.print(frequency);//printing RED color frequency
  Serial.print("  ");
  delay(300);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequency = pulseIn(sensorOut, LOW);
  // Printing the value on the serial monitor
  Serial.print("B= ");//printing name
  if(frequency>255)
  frequency=255;
  Serial.print(frequency);//printing RED color frequency
  Serial.println("  ");
  delay(300);
}
