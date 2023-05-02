//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "qPQLHY1LKaPQ0fNW4lnHfD7WJQLnZrhk";//Enter your Auth token
char ssid[] = "Nagella'sWifi";//Enter your WIFI name
char pass[] = "28112002";//Enter your WIFI password

DHT dht(D3, DHT11); //(sensor pin,sensor type)
BlynkTimer timer;
bool pirbutton = 0;

// Define component pins
#define Buzzer D0
#define MQ2 A0
#define trig D4
#define echo D5
#define PIR D2
const int ledpin = 13;
const int ldrpin = 5;

//Get buttons values
BLYNK_WRITE(V0) {
  pirbutton = param.asInt();
}

void setup() {
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(ledpin,OUTPUT);
  pinMode(ldrpin,INPUT);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  dht.begin();

//Call the functions
  timer.setInterval(100L, gassensor);
  timer.setInterval(100L, DHT11sensor);
  timer.setInterval(100L, pirsensor);
  timer.setInterval(100L, ultrasonic);
  timer.setInterval(100L, ldr);
}

//Get the MQ2 sensor values
void gassensor() {
  int value = analogRead(MQ2);
  Serial.println(value);
  value = map(value, 0, 1024, 0, 100);
  if (value <= 55) {
    digitalWrite(Buzzer, LOW);
  } else if (value > 55) {
    digitalWrite(Buzzer, HIGH);
  }
  Blynk.virtualWrite(V1, value);
}

//Get the DHT11 sensor values
void DHT11sensor() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V2, t);
  Blynk.virtualWrite(V3, h);
}

//Get the PIR sensor values
void pirsensor() {
  bool value = digitalRead(PIR);
  if (pirbutton == 1) {
    if (value == 0) {
      digitalWrite(Buzzer, LOW);
      Serial.println("No Detection");
    } else if (value == 1) {
      digitalWrite(Buzzer, HIGH);
    }
  }
}

//Get the ultrasonic sensor values
void ultrasonic() {
  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long t = pulseIn(echo, HIGH);
  long cm = t / 29 / 2;
  Blynk.virtualWrite(V4, cm);
}

//Get ldr values
void ldr(){
  int ldrstatus = digitalRead(ldrpin);
  if(ldrstatus == 1){
    digitalWrite(ledpin,HIGH);
    Serial.print("Its DARK, turn on the LED :");
    Serial.println(ldrstatus);
  }else{
    digitalWrite(ledpin,LOW);
    Serial.print("Its BRIGHT, turn off the LED :");
    Serial.println(ldrstatus);
  }
}
void loop() {
  Blynk.run();//Run the Blynk library
  timer.run();//Run the Blynk timer
}
