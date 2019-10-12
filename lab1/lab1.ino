#include <Arduino.h>

#define RGB_COUNT 4
const byte rgbs[RGB_COUNT][3] = {{22, 23, 24}, 
                                 {25, 26, 27}, 
                                 {28, 29, 30}, 
                                 {31, 32, 33}};

void setup()
{
    Serial.begin(115200);
    Serial.println("Started!");

    for (int i = 0; i < RGB_COUNT; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            pinMode(rgbs[i][j], OUTPUT);
        }
    }
}

void loop() 
{
    int opposite_rgb = RGB_COUNT / 2;
    for (int i = 0; i < opposite_rgb; i++)
    {
        gradual_turn(i, i + opposite_rgb, true);
        gradual_turn(i, i + opposite_rgb, false);
    }
}

void gradual_turn(int rgb_number1, int rgb_number2, boolean turn_on) {
    for (int i = 255; i >= 0; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            if (turn_on)
            {
                analogWrite(rgbs[rgb_number1][j], i);
                analogWrite(rgbs[rgb_number2][j], i);
            }
            else
            {
                analogWrite(rgbs[rgb_number1][j], 255 - i);
                analogWrite(rgbs[rgb_number2][j], 255 - i);
            }
            delay(10);
        }
    }
}
