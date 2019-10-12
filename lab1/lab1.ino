#include <Arduino.h>

#define RGB_COUNT 8
#define DELTA 1;

const byte rgbs[RGB_COUNT] = {2, 3, 4, 5, 6, 7, 8, 9};
int rgbs_values[RGB_COUNT] = {26, 13, 0, -13, 26, 13, 0, -13};

void setup()
{
    Serial.begin(115200);
    Serial.println("Started!");

    for (int i = 0; i < RGB_COUNT; i++) 
        pinMode(rgbs[i], OUTPUT);
//
//    analogWrite(22, 255);
//    analogWrite(2, 255);
//    analogWrite(3, 255);
//    for (int i = 0; i < 256; i++)
//    {
//      analogWrite(2,255-i);
//      delay(10);
//    }
//    analogWrite(3, 0);
//    analogWrite(4, 50);
//    analogWrite(5, 100);
//    analogWrite(6, 230);
//    analogWrite(7, 240);
//    analogWrite(8, 250);
//    analogWrite(9, 254);
//    delay(10000);
}

void loop() 
{
    for (int i = 0; i < RGB_COUNT; i++)
    {
        int possible_value = rgbs_values[i] + DELTA;
        rgbs_values[i] = possible_value > 52 ? 0 : possible_value;
    }
    set_rgbs_values();
    delay(30);
//      for (int i = 255; i >= 0; i--)
//      {
//          analogWrite(2, i);
//          delay(10);
//      }
}

void set_rgbs_values() {
    for (int i = 0; i < RGB_COUNT; i++)
        analogWrite(rgbs[i], 255 - get_true_rgb_value(rgbs_values[i]));
}

byte get_true_rgb_value(int rgb_value)
{
    return rgb_value <= 26 ? rgb_value : 52 - rgb_value;
}
