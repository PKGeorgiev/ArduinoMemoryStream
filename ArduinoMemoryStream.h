#ifndef ArduinoMemoryStream_h
#define ArduinoMemoryStream_h
#include<Arduino.h>
#include<Stream.h>

///////////////////////////////////
// ArduinoMemoryStream
///////////////////////////////////

class ArduinoMemoryStream : public Stream {
  public:
    ArduinoMemoryStream(int bufferSize);
    ArduinoMemoryStream(byte* buffer, int bufferSize, int contentSize);
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
    unsigned int _size;
    volatile int _contentSize = 0;
    volatile int _start = 0;
    volatile int _end = 0;
};

#endif