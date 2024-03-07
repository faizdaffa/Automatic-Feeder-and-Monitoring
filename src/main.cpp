#include <Arduino.h>
#include <ultrasonic.h>
#include <pH_sensor.h>
#include <motor.h>
#include <thermocouple.h>
#include <tds_sensor copy.h>

#include <Wifi.h>
#include <HTTPClient.h>

String URL = "http://192.168.18.70/automatic_feeder_project/tes1.php";

const char* ssid = "BaseEngineering"; 
const char* password = "123456780"; 

// int ph = 11;
// int tds = 22;
// int temperature = 33;
// int pellets = 44;

void connectWiFi() {
  WiFi.mode(WIFI_OFF);
  delay(1000);
  //This line hides the viewing of ESP as wifi hotspot
  WiFi.mode(WIFI_STA);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
    
  Serial.print("connected to : "); Serial.println(ssid);
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
}

void setup()
{
  Serial.begin(9600);
  connectWiFi();
  ph_innit();
  tds_innit();
  ultrasonic_innit();
  // motor_innit();
  Serial.println("START");
}

void loop()
{
  if(WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }

  ph_value(read_ph_analog_avg(ph_pin, 1000));
  tds_value(read_tds_analog_avg(tds_pin, 1000));
  read_thermocouple();
  read_distance();
  // clockwise();

  String postData = "ph=" + String(ph) + "&tds=" + String(tds) + "&temperature=" + String(temperature) + "&pellets=" + String(pellets);
  
  HTTPClient http;
  http.begin(URL);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  int httpCode = http.POST(postData);
  String payload = http.getString();

  Serial.print("URL : "); Serial.println(URL); 
  Serial.print("Data: "); Serial.println(postData);
  Serial.print("httpCode: "); Serial.println(httpCode);
  Serial.print("payload : "); Serial.println(payload);
  Serial.println("--------------------------------------------------");

  Serial.println("pH: " + String(ph) + " || TDS: " + String(tds) + " || T: " + String(temperature) + " || Pelet: " + String(pellets));
  // Serial.println(distance);
  // delay(500);
}