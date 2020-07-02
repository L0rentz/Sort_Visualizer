/*
** EPITECH PROJECT, 2020
** Visualizer
** File description:
** bubble_sort
*/

#include "my.h"

void bubble_sort(all_t *s_all)
{
    for (int i = 0, j = 0, k = s_all->data_size; i < s_all->data_size - 1; i++, k--) {
        sfRenderWindow_clear(s_all->window, sfBlack);

        for (int i = s_all->data_size - 1; i != 0; i--) {
            sfRectangleShape_setPosition(s_all->data_tab[i]->rectangle, s_all->data_tab[i]->pos);
            sfRenderWindow_drawRectangleShape(s_all->window, s_all->data_tab[i]->rectangle, NULL);
        }

        for (j = 0; j < s_all->data_size - i - 1; j++) {
            if (s_all->data_tab[j]->value > s_all->data_tab[j + 1]->value) {
                sfVector2f pos = s_all->data_tab[j]->pos;
                s_all->data_tab[j]->pos = s_all->data_tab[j + 1]->pos;
                s_all->data_tab[j + 1]->pos = pos;
                int value = s_all->data_tab[j]->value;
                s_all->data_tab[j]->value = s_all->data_tab[j + 1]->value;
                s_all->data_tab[j + 1]->value = value;
            }
        }

        sfMusic_setPitch(s_all->beep, (float)k / 100);
        sfMusic_setPitch(s_all->beep2, (float)k / 300);

        usleep(15000);
        sfRenderWindow_display(s_all->window);
    }
}

void cocktail_shaker(all_t *s_all)
{
    for (int i = 0, j = 0, k = s_all->data_size; i < s_all->data_size / 4.5; i++, k--) {
        sfRenderWindow_clear(s_all->window, sfBlack);

        for (int i = s_all->data_size - 1; i != 0; i--) {
            sfRectangleShape_setPosition(s_all->data_tab[i]->rectangle, s_all->data_tab[i]->pos);
            sfRenderWindow_drawRectangleShape(s_all->window, s_all->data_tab[i]->rectangle, NULL);
        }

        for (j = 0; j < s_all->data_size - i - 1; j++) {
            if (s_all->data_tab[j]->value > s_all->data_tab[j + 1]->value) {
                sfVector2f pos = s_all->data_tab[j]->pos;
                s_all->data_tab[j]->pos = s_all->data_tab[j + 1]->pos;
                s_all->data_tab[j + 1]->pos = pos;
                int value = s_all->data_tab[j]->value;
                s_all->data_tab[j]->value = s_all->data_tab[j + 1]->value;
                s_all->data_tab[j + 1]->value = value;
            }
        }

        for (j = s_all->data_size - i - 2; j > 0; j--) {
            if (s_all->data_tab[j]->value > s_all->data_tab[j + 1]->value) {
                sfVector2f pos = s_all->data_tab[j]->pos;
                s_all->data_tab[j]->pos = s_all->data_tab[j + 1]->pos;
                s_all->data_tab[j + 1]->pos = pos;
                int value = s_all->data_tab[j]->value;
                s_all->data_tab[j]->value = s_all->data_tab[j + 1]->value;
                s_all->data_tab[j + 1]->value = value;
            }
        }

        sfMusic_setPitch(s_all->beep, (float)k / 100);
        sfMusic_setPitch(s_all->beep2, (float)i / 300);

        usleep(50000);
        sfRenderWindow_display(s_all->window);
    }
}