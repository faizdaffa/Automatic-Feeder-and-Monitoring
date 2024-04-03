#include <Wifi.h>
#include <HTTPClient.h>

String URL = "https://fishfeeder.baseengineering-indonesia.com/api.php";

const char *ssid = "BaseEngineering";
const char *password = "123456780";

void connectWiFi()
{
    WiFi.mode(WIFI_OFF);
    delay(1000);
    // This line hides the viewing of ESP as wifi hotspot
    WiFi.mode(WIFI_STA);

    WiFi.begin(ssid, password);
    Serial.println("Connecting to WiFi");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.print("connected to : "); Serial.println(ssid);
    Serial.print("IP address: ");    Serial.println(WiFi.localIP());
}

void sendData(float ph, float tds, float temperature, float pellets)
{
    if (WiFi.status() != WL_CONNECTED)
    {
        connectWiFi();
    }

    String postData = "ph=" + String(ph) + "&tds=" + String(tds) + "&temperature=" + String(temperature) + "&pellets=" + String(pellets);
  
    HTTPClient http;
    http.begin(URL);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    int httpCode = http.POST(postData);
    String payload = http.getString();

    Serial.print("URL : ");     Serial.println(URL); 
    Serial.print("Data: ");     Serial.println(postData);
    Serial.print("httpCode: "); Serial.println(httpCode);
    Serial.print("payload : "); Serial.println(payload);
    Serial.println("--------------------------------------------------");
}