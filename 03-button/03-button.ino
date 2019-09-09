#define PIN_LED 32
#define PIN_BUTTON 34
#define DEBOUNCE_DELAY 300

bool currentLEDState = false;

void setup(){

  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);

  Serial.begin(115200);
  Serial.println("Setup complete");
}


void loop(){

  int reading = digitalRead(PIN_BUTTON);

  if(reading == HIGH){
    
    currentLEDState = !currentLEDState;

    Serial.print("Changing LED state to: ");
    Serial.println(currentLEDState);
    
    digitalWrite(PIN_LED, currentLEDState);
  }
  
}
