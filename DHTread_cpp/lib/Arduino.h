#pragma once

// basic types
#define HIGH 0x1
#define LOW  0x0
#define OUTPUT 0x1
#define INPUT  0x0

// core Arduino functions
void setup();
void loop();

void pinMode(int pin, int mode);
void digitalWrite(int pin, int value);
int digitalRead(int pin);
void delay(unsigned long ms);

// timing
unsigned long millis();

// serial mock
class SerialClass {
public:
    void begin(long baud);
    void print(const char* msg);
    void println(const char* msg);
    void print(int value);
    void println(int value);
};

extern SerialClass Serial;