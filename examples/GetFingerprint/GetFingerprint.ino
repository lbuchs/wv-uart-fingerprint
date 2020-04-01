/*
 * Example usage of the Arduino Library for Waveshare UART fingerprint sensor
 */
 
#include <WvFingerprint.h>

int RST_PIN = 32;
int WAKE_PIN = 33;

// create instance
WvFingerprint myfp(Serial1, RST_PIN, WAKE_PIN);

void setup() {

    // print out serialNo
    int serialNo = myfp.getSerialNumber();
    Serial.print("Fingerprint Serial No: ");
    Serial.println(serialNo); 
}


void loop() {
  
    int userId = myfp.checkForFingerprint();

    // userId = 0: no finger on device
    // userId = 0xFFFF: finger on device but no match  
    if (userId == 0xFFFF) {
        Serial.println("Finger found but unknown!");

    } else if (userId > 0) {
        Serial.print("user match. userId: ");
        Serial.println(userId);
        
    }
}

