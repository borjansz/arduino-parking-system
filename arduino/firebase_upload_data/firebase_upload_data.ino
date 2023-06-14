#include <Config.h>
#include <Firebase.h>
#include <Firebase_Arduino_WiFi101.h>
#include <Firebase_TCP_Client.h>
#include <WCS.h>

#include <WiFi101.h>
#include <WiFiUdp.h>

// Set up your Firebase credentials
#define FIREBASE_HOST "YOUR RTDB HOST"
#define FIREBASE_AUTH "YOUR DATABASE SECRET"
#define WIFI_SSID "YOUR SSID" 
#define WIFI_PASSWORD "SSID PASSWORD"


const int trigPin1 = 7;
const int echoPin1 = 6;
const int trigPin2 = 3;
const int echoPin2 = 4;
long duration1;
int distance1;
int space1Status;
long duration2;
int distance2;
int space2Status;
FirebaseData fbdo;
FirebaseData stream;
String path = "/parking/stream";


void setup() { 
    pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
    pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
    Serial.begin(115200);
    
    // Connect to Wi-Fi
    Serial.println("Connecting to Wi-Fi");
    int status = WL_IDLE_STATUS;
    while (status != WL_CONNECTED)
    {
      Serial.println(".");
      status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
      delay(10000);
    }
    // Succesful connection
    Serial.println("Connected to Wi-Fi");
    Serial.println("----------------------------------------");
    printData();
    Serial.println("----------------------------------------");
    Serial.println(WiFi.localIP());
    Serial.println();
    //Provide the autntication data
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH, WIFI_SSID, WIFI_PASSWORD);
    Firebase.reconnectWiFi(true);
    if (!Firebase.beginStream(stream, path))
    {
      Serial.println("Can't connect stream, " + stream.errorReason());
      Serial.println();
    }
    else{
      Serial.println("Connected firebase");
    }

} 


void loop() { 
  // Measure distance for the first sensor
  distance1 = getDistance(trigPin1, echoPin1);
  Serial.print("Distance 1: ");
  Serial.print(distance1);
  Serial.println(" cm");

  // Measure distance for the second sensor
  distance2 = getDistance(trigPin2, echoPin2);
  Serial.print("Distance 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  space1Status = checkSpace(distance1);
  space2Status = checkSpace(distance2);

  delay(1000);
  Serial.print("Firebase Upload: ");

  // Upload data for first sensor
  if (Firebase.setInt(fbdo, path + "/space1", space1Status))
  {
    Serial.println("ok");
    Serial.println("path: " + fbdo.dataPath());
    Serial.println("type: " + fbdo.dataType());
    Serial.print("value: ");
    if (fbdo.dataType() == "int")
      Serial.println(fbdo.intData());
    if (fbdo.dataType() == "int64")
      Serial.println(fbdo.int64Data());
    if (fbdo.dataType() == "uint64")
      Serial.println(fbdo.uint64Data());
    else if (fbdo.dataType() == "double")
      Serial.println(fbdo.doubleData());
    else if (fbdo.dataType() == "float")
      Serial.println(fbdo.floatData());
    else if (fbdo.dataType() == "boolean")
      Serial.println(fbdo.boolData() == 1 ? "true" : "false");
    else if (fbdo.dataType() == "string")
      Serial.println(fbdo.stringData());
    else if (fbdo.dataType() == "json")
      Serial.println(fbdo.jsonData());
    else if (fbdo.dataType() == "array")
      Serial.println(fbdo.arrayData());
  }
  else
  {
    Serial.println("error, "+ fbdo.errorReason());
  }

    // Upload data for second sensor
  if (Firebase.setInt(fbdo, path + "/space2", space2Status))
  {
    Serial.println("ok");
    Serial.println("path: " + fbdo.dataPath());
    Serial.println("type: " + fbdo.dataType());
    Serial.print("value: ");
    if (fbdo.dataType() == "int")
      Serial.println(fbdo.intData());
    if (fbdo.dataType() == "int64")
      Serial.println(fbdo.int64Data());
    if (fbdo.dataType() == "uint64")
      Serial.println(fbdo.uint64Data());
    else if (fbdo.dataType() == "double")
      Serial.println(fbdo.doubleData());
    else if (fbdo.dataType() == "float")
      Serial.println(fbdo.floatData());
    else if (fbdo.dataType() == "boolean")
      Serial.println(fbdo.boolData() == 1 ? "true" : "false");
    else if (fbdo.dataType() == "string")
      Serial.println(fbdo.stringData());
    else if (fbdo.dataType() == "json")
      Serial.println(fbdo.jsonData());
    else if (fbdo.dataType() == "array")
      Serial.println(fbdo.arrayData());
  }
  else
  {
    Serial.println("error, "+ fbdo.errorReason());
  }

  // clear internal memory used
  fbdo.clear();

}


int getDistance(int trigPin, int echoPin) {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);

  // Calculating the distance based on the speed of sound (approximated at 343 meters per second)
  int distance = duration * 0.0343 / 2;

  return distance;
}


int checkSpace(int distance)
{
  if(distance < 20)
    return 0;
  else
    return 1;
}


void printData() {
  Serial.println("Board Information:");
  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  Serial.println();
  Serial.println("Network Information:");
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.println(rssi);

}
