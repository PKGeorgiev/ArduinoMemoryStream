#include<ArduinoMemoryStream.h>

ArduinoMemoryStream::ArduinoMemoryStream(uint16_t bufferSize = 128){
  _size = bufferSize;  
  _buffer = (byte*)malloc(_size);
  memset(_buffer, 0, _size);
};

ArduinoMemoryStream::ArduinoMemoryStream(byte* buffer, uint16_t bufferSize, uint16_t contentSize = 0) {
  _size = bufferSize;
  _buffer = buffer;
  _internalBuffer = false;
  
  if (contentSize <= bufferSize) {
    _contentSize = contentSize;
  } else {
    _contentSize = 0;
  };
};

ArduinoMemoryStream::~ArduinoMemoryStream(){
  if (_internalBuffer) {
    delete [] _buffer;  
  };
};

int ArduinoMemoryStream::available(){
  return _contentSize;
};

int ArduinoMemoryStream::read(){
    if (available() == 0) { 
      return -1; 
    } else {
      int p = _buffer[_start];
      _start = (_start + 1) % _size;
      _contentSize--;
      return p;
    };  
};

int ArduinoMemoryStream::peek(){
  if (!_contentSize) {
    // The buffer is empty
    return -1; 
  } else {
    return _buffer[_start];  
  };
};

void ArduinoMemoryStream::flush(){
  // Removing any content
  memset(_buffer, 0, _size);
  _contentSize = 0;
};

size_t ArduinoMemoryStream::write(uint8_t item){
    if (_contentSize < _size)
    {
      _buffer[_end] = item;
      _end = (_end + 1) % _size;      
      return ++_contentSize;
      
    } else {
      // The buffer is full
      return 0;
    }  
};

size_t ArduinoMemoryStream::write(const uint8_t *buffer, size_t size){
  if (size > (_size - _contentSize)) {
    // The buffer is bigger than we can handle
    return -1;
  };
  
  for(size_t k = 0; k < size; k++){
    write(buffer[k]);  
  };
};

