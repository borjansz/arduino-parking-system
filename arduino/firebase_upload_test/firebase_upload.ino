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

int count = 0;
unsigned long sendDataPrevMillis = 0;


const int trigPin1 = 7;
const int echoPin1 = 6;
const int trigPin2 = 3;
const int echoPin2 = 4;

long duration1;
int distance1;
long duration2;
int distance2;

FirebaseData fbdo;

FirebaseData stream;

String path = "/test/stream";


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

void loop()
{

  if (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)
  {
    sendDataPrevMillis = millis();
    count++;

    Serial.print("Set string... ");

    if (Firebase.pushString(fbdo, path + "/string", "Hello World! " + String(count)))
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
    Serial.println();

    // clear internal memory used
    fbdo.clear();
  }

  if (!Firebase.readStream(stream))
  {
    Serial.println("Can't read stream, "+ stream.errorReason());
  }

  if (stream.streamTimeout())
  {
    Serial.println("Stream timed out, resuming...");
  }

  if (stream.streamAvailable())
  {
    count++;
    if (stream.dataType() == "null")
      count = 0;

    Serial.println("Stream data received... ");
    Serial.println("stream path: " + stream.streamPath());
    Serial.println("event path: " + stream.dataPath());
    Serial.println("data type: " + stream.dataType());
    Serial.println("event type: " + stream.eventType());
    Serial.print("value: ");
    if (stream.dataType() == "int")
      Serial.println(stream.intData());
    if (stream.dataType() == "int64")
      Serial.println(stream.int64Data());
    if (stream.dataType() == "uint64")
      Serial.println(stream.uint64Data());
    else if (stream.dataType() == "double")
      Serial.println(stream.doubleData());
    else if (stream.dataType() == "float")
      Serial.println(stream.floatData());
    else if (stream.dataType() == "boolean")
      Serial.println(stream.boolData() == 1 ? "true" : "false");
    else if (stream.dataType() == "string")
      Serial.println(stream.stringData());
    else if (stream.dataType() == "json")
      Serial.println(stream.jsonData());
    else if (stream.dataType() == "array")
      Serial.println(stream.arrayData());
    Serial.println();

    // clear internal memory used
    stream.clear();
  }
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
