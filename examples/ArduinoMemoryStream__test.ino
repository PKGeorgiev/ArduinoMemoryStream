#include ArduinoMemoryStream.h

void setup() {
   put your setup code here, to run once

  Serial.begin(9600);
  while(!Serial);
  Serial.println(OK);

   Declare a memory stream with 3 bytes in size
  ArduinoMemoryStream stm = new ArduinoMemoryStream(3);

   Write some bytes
  stm-write(1);
  stm-write(2);
  stm-write(3);

   These writes will fail since the buffer is full
   write() will return 0
  stm-write(4);
  stm-write(5);

  while(stm-available()) {
    Serial.println(stm-read());
  };
};

void loop() {
   put your main code here, to run repeatedly

}
