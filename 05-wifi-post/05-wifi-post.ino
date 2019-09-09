#include <WiFi.h>
#include <HTTPClient.h>

#define PIN_LED 32
#define PIN_BUTTON 34
#define DEBOUNCE_DELAY 300

#define WIFI_SSID "XXX"
#define WIFI_PASS "XXX"

#define HOST "http://X.X.X.X:80/"

unsigned long lastDebounceTime = 0;

int numberToSend = 1234;

void setup(){

  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);

  Serial.begin(115200);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASS);


  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(5000);
  }

  Serial.println("");
  Serial.print("WiFi connected. IP address is: ");
  Serial.print(WiFi.localIP());
  Serial.print(", with Mac Address: ");
  Serial.println(WiFi.macAddress());

  // Blink LED to indicate connected
  digitalWrite(PIN_LED, HIGH);
  delay(100);
  digitalWrite(PIN_LED, LOW);
  
  Serial.println("Setup complete");
}


void loop(){

  int reading = digitalRead(PIN_BUTTON);
  unsigned long currentTime = millis();

  if((reading == HIGH) 
    && ((currentTime - lastDebounceTime) > DEBOUNCE_DELAY)){
    // Process the button press if we have exceed the debounce time
    
    lastDebounceTime = currentTime;

    String macAddr = WiFi.macAddress();
    String textToSend = "ESP32 " + macAddr + " value " + String(numberToSend);
    numberToSend++;

    Serial.print("Button pressed, sending: ");
    Serial.println(textToSend);
    postRequest(textToSend);
  }
  
}

void postRequest(String message){

   HTTPClient http;
 
   http.begin(HOST);
   http.addHeader("Content-Type", "text/plain");
 
   int httpCode = http.POST(message);
   String payload = http.getString();
 
   Serial.println(httpCode);
   Serial.println(payload);
 
   http.end();
}
