// https://lastminuteengineers.com/esp8266-ntp-server-date-time-tutorial/
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid     = "WIFI NAME";
const char *password = "WIFI PASSWORD";

// Update the timezone by setting this offset in milliseconds (1 * 60 * 60 ) = 3600
// UTC -7 = -25200
// UTC -6 = -21600
// UTC -5 = -18000
// UTC -4 = -14400
// UTC -3 = -10800
// UTC -2 = -7200
// UTC -1 = -3600
// UTC = 0
// UTC +1 = 3600
// UTC +2 = 7200
// UTC +3 = 10800
// UTC +4 = 14400
// UTC +5 = 18000
// UTC +6 = 21600
// UTC +7 = 25200
const long utcOffsetInSeconds = -25200;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup(){
  Serial.begin(115200);
  pinMode(D5, OUTPUT); 
  pinMode(D6, OUTPUT); 
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {

  timeClient.update();

    // Turn off pins on Saturday and Sunday
    if ( timeClient.getDay() == 0 || timeClient.getDay() == 6 ) {
      Serial.println("It is the weekend");
      showTime();
      digitalWrite(D5, LOW);
      digitalWrite(D6, LOW);
    } else {
      // Turn on pins between 8 AM and 5PM
      if ( (timeClient.getHours() >= 8) && (timeClient.getHours() <= 17 ) ) {
        Serial.println("Time to work");
        showTime();
        digitalWrite(D5, HIGH);
        digitalWrite(D6, HIGH);
      } else {
        Serial.println("Time to rest");
        showTime();
        digitalWrite(D5, LOW);
        digitalWrite(D6, LOW);
      }
    }
    // Check every minute
    //TODO: make this more intellegent to not overwhelm NTP servers
    delay(60000);
}

void showTime() {
  Serial.print(daysOfTheWeek[timeClient.getDay()]);
  Serial.print(", ");
  Serial.print(timeClient.getHours());
  Serial.print(":");
  Serial.print(timeClient.getMinutes());
  Serial.print(":");
  Serial.println(timeClient.getSeconds());
}

  
