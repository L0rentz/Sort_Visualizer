/*
** EPITECH PROJECT, 2020
** Visualizer
** File description:
** color
*/

#include "my.h"

void set_data_color(sfColor *rainbow)
{
    static int color = 0;

    if (color == 0)
        rainbow->g += 2;
    if (color == 1)
        rainbow->r -= 2;
    if (color == 2) {
        rainbow->b += 2;
        rainbow->g -= 2;
    }
    if (color == 3) {
        rainbow->r += 1;
        rainbow->b -= 1;
    }
    if (color == 4) {
        rainbow->r += 2;
        rainbow->b += 1;
    }
    if (color == 5) {
        rainbow->b -= 3;
        rainbow->r += 1;
    }

    if (rainbow->g >= 210 && color == 0)
        color = 1;
    if (rainbow->r <= 10 && color == 1)
        color = 2;
    if (rainbow->b >= 200 && color == 2)
        color = 3;
    if (rainbow->r >= 75 && color == 3)
        color = 4;
    if (rainbow->b >= 164 && color == 4)
        color = 5;
    if (rainbow->r >= 180 && color == 5)
        color = 6;
}