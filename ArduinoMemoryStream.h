#ifndef ArduinoMemoryStream_h
#define ArduinoMemoryStream_h
#include<Arduino.h>
#include<Stream.h>

///////////////////////////////////
// ArduinoMemoryStream
///////////////////////////////////

class ArduinoMemoryStream : public Stream {
  public:
    ArduinoMemoryStream(uint16_t bufferSize);
    ArduinoMemoryStream(byte* buffer, uint16_t bufferSize, uint16_t contentSize);
    ~ArduinoMemoryStream();
    int available();
    int read();
    int peek();
    void flush();
    size_t write(uint8_t item);
    size_t write(const uint8_t *buffer, size_t size);
  protected:
    byte* _buffer;
    bool _internalBuffer = true;
    uint16_t _size;
    volatile uint16_t _contentSize = 0;
    volatile uint16_t _start = 0;
    volatile uint16_t _end = 0;
};

#endif