#include <Arduino.h>

#define RGB_COUNT 8
#define DELTA 10;

const byte rgbs[RGB_COUNT] = {22, 23, 24, 25, 26, 27, 28, 29};
int rgbs_values[RGB_COUNT] = {255, 127, 0, 382, 255, 127, 0, 382};

void setup()
{
    Serial.begin(115200);
    Serial.println("Started!");

    for (int i = 0; i < RGB_COUNT; i++) 
        pinMode(rgbs[i], OUTPUT);
}

void loop() 
{
    for (int i = 0; i < RGB_COUNT; i++)
    {
        int possible_value = rgbs_values[i] + DELTA;
        rgbs_values[i] = possible_value > 500 ? 0 : possible_value;
    }
    set_rgbs_values();
    delay(30);
}

void set_rgbs_values() {
    for (int i = 0; i < RGB_COUNT; i++)
        analogWrite(rgbs[i], get_true_rgb_value(rgbs_values[i]));
}

byte get_true_rgb_value(int rgb_value)
{
    return rgb_value < 256 ? rgb_value : 510 - rgb_value;
}
