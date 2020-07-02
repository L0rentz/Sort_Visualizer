/*
** EPITECH PROJECT, 2020
** Visualizer
** File description:
** insertion_sort
*/

#include "my.h"

void insertion_sort(all_t *s_all)
{
    int key_pos;
    int key_value;
    int j;

    for (int i = 1; i < s_all->data_size; i++) {
        key_value = s_all->data_tab[i]->value;
        key_pos = s_all->data_tab[i]->pos.x;
        j = i - 1;

        while (j >= 0 && s_all->data_tab[j]->value > key_value) {
            s_all->data_tab[j + 1]->value = s_all->data_tab[j]->value;
            s_all->data_tab[j + 1]->pos.x = s_all->data_tab[j]->pos.x;
            j = j - 1;
        }
        s_all->data_tab[j + 1]->value = key_value;
        s_all->data_tab[j + 1]->pos.x = key_pos;

        sfRenderWindow_clear(s_all->window, sfBlack);

        for (int i = s_all->data_size - 1; i != 0; i--) {
            sfRectangleShape_setPosition(s_all->data_tab[i]->rectangle, s_all->data_tab[i]->pos);
            sfRenderWindow_drawRectangleShape(s_all->window, s_all->data_tab[i]->rectangle, NULL);
        }

        sfMusic_setPitch(s_all->beep, (float)i / 100);
        sfMusic_setPitch(s_all->beep2, (float)i / 300);

        usleep(10000);
        sfRenderWindow_display(s_all->window);

    }
}

void shell_sort(all_t *s_all)
{
    int pitch1 = 1;
    int pitch2 = 2;
    for (int gap = s_all->data_size / 2; gap > 0; gap /= 2, pitch1 -= 150, pitch2 -= 350) {

        for (int i = gap; i < s_all->data_size; i += 1, pitch1 += 1, pitch2 += 2) {
            int value = s_all->data_tab[i]->value;
            int pos = s_all->data_tab[i]->pos.x;

            int j;
            for (j = i; j >= gap && s_all->data_tab[j - gap]->value > value; j -= gap) {
                s_all->data_tab[j]->value = s_all->data_tab[j - gap]->value;
                s_all->data_tab[j]->pos.x = s_all->data_tab[j - gap]->pos.x;

                sfRenderWindow_clear(s_all->window, sfBlack);

                for (int i = s_all->data_size - 1; i != 0; i--) {
                    sfRectangleShape_setPosition(s_all->data_tab[i]->rectangle, s_all->data_tab[i]->pos);
                    sfRenderWindow_drawRectangleShape(s_all->window, s_all->data_tab[i]->rectangle, NULL);
                }
            }
            s_all->data_tab[j]->value = value;
            s_all->data_tab[j]->pos.x = pos;

            sfMusic_setPitch(s_all->beep, (float)pitch1 / 500);
            sfMusic_setPitch(s_all->beep2, (float)pitch2 / 300);

            sfRectangleShape_setPosition(s_all->data_tab[j]->rectangle, s_all->data_tab[j]->pos);
            sfRenderWindow_drawRectangleShape(s_all->window, s_all->data_tab[j]->rectangle, NULL);

            sfRenderWindow_display(s_all->window);
        }

        sfRenderWindow_clear(s_all->window, sfBlack);

        for (int i = s_all->data_size - 1; i != 0; i--) {
            sfRectangleShape_setPosition(s_all->data_tab[i]->rectangle, s_all->data_tab[i]->pos);
            sfRenderWindow_drawRectangleShape(s_all->window, s_all->data_tab[i]->rectangle, NULL);
        }

        sfRenderWindow_display(s_all->window);
    }
}