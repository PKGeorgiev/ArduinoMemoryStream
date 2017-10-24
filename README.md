# ArduinoMemoryStream
A memory backed Stream descendant. Implements a Ring buffer. In case the buffer is full the write() function will return 0 and no content will be added/overwrited.

You can specify buffer's size in the Contructor. If not specified the default buffer size is 128 bytes. The memory will be allocated dynamically.

There is a second constructor that allows you to specify external buffer.

# Example

```c
#include<ArduinoMemoryStream.h>

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  while(!Serial);
  Serial.println("OK");

  // Declare a memory stream with 3 bytes in size
  ArduinoMemoryStream *stm = new ArduinoMemoryStream(3);

  // Write some bytes
  stm->write(1);
  stm->write(2);
  stm->write(3);

  // These writes will fail since the buffer is full
  // i.e. write() will return 0 and no bytes will be written to the buffer
  stm->write(4);
  stm->write(5);

  while(stm->available()) {
    Serial.println(stm->read());
  };
};

void loop() {
  // put your main code here, to run repeatedly:

}

```
