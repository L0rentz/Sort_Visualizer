/*
** EPITECH PROJECT, 2020
** Visualizer
** File description:
** init
*/

#include "my.h"

void init_all(all_t *s_all)
{
    sfVideoMode mode = {1920, 1080, 32};
    s_all->window = sfRenderWindow_create(mode, "Visualizer", sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(s_all->window, 300);
    sfRenderWindow_setMouseCursorVisible(s_all->window, 0);
    s_all->data_size = sfRenderWindow_getSize(s_all->window).x / 4 + 2;
    s_all->beep = sfMusic_createFromFile("beep.ogg");
    s_all->beep2 = sfMusic_createFromFile("beep.ogg");
    sfMusic_setLoop(s_all->beep, sfTrue);
    sfMusic_setLoop(s_all->beep2, sfTrue);
}

data_t **init_data_array(all_t *s_all)
{
    data_t **tab = malloc(sizeof(data_t *) * (s_all->data_size + 1));

    sfVector2f pos = {0, sfRenderWindow_getSize(s_all->window).y / 2};
    sfVector2f size = {3, 1};
    sfColor rainbow = {255, 0, 0, 255};

    int i = 0;

    for (; i != s_all->data_size; i++) {
        tab[i] = malloc(sizeof(data_t));

        tab[i]->value = i;
        tab[i]->rectangle = sfRectangleShape_create();
        sfRectangleShape_setSize(tab[i]->rectangle, size);
        sfRectangleShape_setPosition(tab[i]->rectangle, pos);
        sfRectangleShape_setFillColor(tab[i]->rectangle, rainbow);
        sfRectangleShape_setOrigin(tab[i]->rectangle, (sfVector2f){size.x, size.y / 2});
        set_data_color(&rainbow);
        tab[i]->pos = pos;
        tab[i]->size = size;
        tab[i]->swap = 0;

        pos.x += 4;
        size.y += 2;
    }
    tab[i] = NULL;

    return (tab);
}