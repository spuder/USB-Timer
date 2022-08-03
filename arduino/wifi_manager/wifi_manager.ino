//https://github.com/tzapu/WiFiManager
#include <Arduino.h>
#include <LittleFS.h>
#include <FS.h>

String readFile(fs::FS &fs, const char * path){
  Serial.printf("Reading file: %s\r\n", path);
  File file = fs.open(path, "r");
  if(!file || file.isDirectory()){
    Serial.println("- empty file or failed to open file");
    return String();
  }
  Serial.println("- read from file:");
  String fileContent;
  while(file.available()){
    fileContent+=String((char)file.read());
  }
  file.close();
  Serial.println(fileContent);
  return fileContent;
}
void writeFile(fs::FS &fs, const char * path, const char * message){
  Serial.printf("Writing file: %s\r\n", path);
  File file = fs.open(path, "w");
  if(!file){
    Serial.println("- failed to open file for writing");
    return;
  }
  if(file.print(message)){
    Serial.println("- file written");
  } else {
    Serial.println("- write failed");
  }
  file.close();
}

int data = 4; 
char timezone[40] = "-7";
char on_time[40] = "08:00";
char off_time[40] = "17:00";

#include <WiFiManager.h>
#define RESET_PIN D4
int timeout = 120; // seconds to run for

void setup() {
    if (!LittleFS.begin()) { //to start littlefs
        Serial.println("LittleFS mount failed");
        return;
    }
    data = readFile(LittleFS, "/data.txt").toInt();
    WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP  
    // put your setup code here, to run once:
    pinMode(RESET_PIN, INPUT_PULLUP);

    WiFiManagerParameter custom_timezone("timezone", "timezone", timezone, 40);
    WiFiManagerParameter custom_on_time("on_time", "on_time", on_time, 40);
    WiFiManagerParameter custom_off_time("off_time", "off_time", off_time, 40);

    WiFiManager wm;

    wm.addParameter(&custom_timezone);
    wm.addParameter(&custom_on_time);
    wm.addParameter(&custom_off_time);

    //wm.resetSettings();
    bool res;
    res = wm.autoConnect("USB-Timer");
    if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    }
    //read updated parameters
    strcpy(timezone, custom_timezone.getValue());
    strcpy(on_time, custom_on_time.getValue());
    strcpy(off_time, custom_off_time.getValue());
    Serial.println("The values in the file are: ");
    Serial.println("\tmqtt_server : " + String(timezone));
    Serial.println("\tmqtt_port : " + String(on_time));
    Serial.println("\tapi_token : " + String(off_time));

}

void loop() {
    if ( digitalRead(RESET_PIN) == LOW) {
        WiFiManager wm;    
        //wm.resetSettings();
        wm.setConfigPortalTimeout(timeout);
        if (!wm.startConfigPortal("USB-Timer")) {
            Serial.println("failed to connect and hit timeout");
            delay(3000);
            ESP.restart();
            delay(5000);
        }
        Serial.println("connected...yeey :)");
    }
}
