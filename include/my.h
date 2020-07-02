/*
** EPITECH PROJECT, 2020
** Visualizer
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "time.h"

typedef struct data
{
    int swap;
    int value;
    sfRectangleShape *rectangle;
    sfVector2f pos;
    sfVector2f size;
} data_t;

typedef struct all
{
    sfRenderWindow *window;
    sfEvent event;
    data_t **data_tab;
    int data_size;
    sfMusic *beep;
    sfMusic *beep2;
} all_t;

void set_data_color(sfColor *rainbow);
void init_all(all_t *s_all);
data_t **init_data_array(all_t *s_all);
void shuffle(all_t *s_all);
void bubble_sort(all_t *s_all);
void selection_sort(all_t *s_all);
void double_selection_sort(all_t *s_all);
void cocktail_shaker(all_t *s_all);
void insertion_sort(all_t *s_all);
void shell_sort(all_t *s_all);

#endif /* !MY_H_ */