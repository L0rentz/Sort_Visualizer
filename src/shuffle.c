/*
** EPITECH PROJECT, 2020
** Visualizer
** File description:
** selection_sort
*/

#include "my.h"

void shuffle(all_t *s_all)
{
    for (int i = 0; s_all->data_tab[i] != NULL; i++)
        s_all->data_tab[i]->swap = 0;

    for (int i = 0, j = 0; i < s_all->data_size; i++) {
        j = rand() % (s_all->data_size);

        while (s_all->data_tab[j]->swap != 0)
            j = rand() % (s_all->data_size);
        s_all->data_tab[j]->swap = 1;

        sfMusic_setPitch(s_all->beep, (float)j / 100);
        sfMusic_setPitch(s_all->beep2, (float)j / 300);

        sfVector2f pos = s_all->data_tab[j]->pos;
        s_all->data_tab[j]->pos = s_all->data_tab[i]->pos;
        s_all->data_tab[i]->pos = pos;
        int value = s_all->data_tab[j]->value;
        s_all->data_tab[j]->value = s_all->data_tab[i]->value;
        s_all->data_tab[i]->value = value;

        sfRectangleShape_setPosition(s_all->data_tab[i]->rectangle, s_all->data_tab[j]->pos);
        sfRectangleShape_setPosition(s_all->data_tab[j]->rectangle, s_all->data_tab[i]->pos);

        sfRenderWindow_clear(s_all->window, sfBlack);
        for (int i = s_all->data_size - 1; i != 0; i--) {
            sfRectangleShape_setPosition(s_all->data_tab[i]->rectangle, s_all->data_tab[i]->pos);
            sfRenderWindow_drawRectangleShape(s_all->window, s_all->data_tab[i]->rectangle, NULL);
        }

        usleep(100);
        sfRenderWindow_display(s_all->window);
    }
}