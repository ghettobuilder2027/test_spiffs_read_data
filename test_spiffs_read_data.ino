// Display all the files stored on spiffs
#include "SPIFFS.h"
 
void setup() {
 
  Serial.begin(115200);
 
  if (!SPIFFS.begin(true)) {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
 
  File root = SPIFFS.open("/");
 
  File file = root.openNextFile();
 
  while(file){
 
      Serial.print("FILE: ");
      Serial.println(file.name());
      Serial.println("File Content:");
      while(file.available()){
        Serial.write(file.read());
      }
      Serial.println("");
      file.close();
 
      file = root.openNextFile();
  }
}
 
void loop() {}
