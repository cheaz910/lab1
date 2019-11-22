#include <Arduino.h>

#define RGB_COUNT 8
#define DELTA 1
#define MAX_RGB_VALUE 52
#define MIDDLE_RGB_VALUE 26
#define UPDATE_DELAY_MS 30

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
        updateLedIntensity(i);
    set_rgbs_values();
    delay(UPDATE_DELAY_MS);
}

void updateLedIntensity(int i) {
    int possible_value = rgbs_values[i] + DELTA;
    rgbs_values[i] = possible_value > MAX_RGB_VALUE ? 0 : possible_value;
    rgbs_values[i] = get_middle_rgb_value(rgbs_values[i]);
}

void set_rgbs_values() {
    for (int i = 0; i < RGB_COUNT; i++)
        analogWrite(rgbs[i], 255 - rgbs_values[i]);
}

byte get_middle_rgb_value(int rgb_value)
{
    return rgb_value <= MIDDLE_RGB_VALUE ? rgb_value : MAX_RGB_VALUE - rgb_value;
}
