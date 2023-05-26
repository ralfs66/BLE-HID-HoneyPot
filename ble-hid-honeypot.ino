/**
 * This example turns the ESP32 into a Bluetooth LE Keyboard - Honeypot that runs RickRoll HID attacks on the system.
  ralfs.batarags    26.05.2023
 */

#include <BleKeyboard.h>
BleKeyboard BleKeyboard("HoneyBoard", "trustmebro", 100);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Meduspods aktīvs!");
  BleKeyboard.begin();
  BleKeyboard.setDelay(50);
}

void loop() {
  if(BleKeyboard.isConnected()) {
  // put your main code here, to run repeatedly:
  Serial.println("Ready, now waiting 15000ms !");
  delay(15000);
  BleKeyboard.press(KEY_LEFT_GUI); //left winkey
  BleKeyboard.press('r');
  BleKeyboard.releaseAll();
  delay(100);  
    BleKeyboard.print("chrome https:");
    delay(100);
    BleKeyboard.print("//www.youtube.com/");
    delay(100);  
    BleKeyboard.print("watch?v=");
    delay(100);
    BleKeyboard.println("dQw4w9WgXcQ");
    delay(100);
    Serial.println("RickRoll unleashed!");
  //BleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
  delay(5000);
  //BleKeyboard.end();
  ESP.restart();
  }
}