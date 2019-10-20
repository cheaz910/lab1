#include <Arduino.h>

#define RGB_COUNT 8
#define DELTA 1;
#define MAX_RGB_VALUE 52;
#define MAX_RGB_TRUE_VALUE 26;

const byte rgbs[RGB_COUNT] = {2, 3, 4, 5, 6, 7, 8, 9};
int rgbs_values[RGB_COUNT] = {26, 13, 0, -13, 26, 13, 0, -13};

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
        rgbs_values[i] = possible_value > MAX_RGB_VALUE ? 0 : possible_value;
    }
    set_rgbs_values();
    delay(30);
}

void set_rgbs_values() {
    for (int i = 0; i < RGB_COUNT; i++)
        analogWrite(rgbs[i], 255 - get_true_rgb_value(rgbs_values[i]));
}

byte get_true_rgb_value(int rgb_value)
{
    return rgb_value <= MAX_RGB_TRUE_VALUE ? rgb_value : MAX_RGB_VALUE - rgb_value;
}
