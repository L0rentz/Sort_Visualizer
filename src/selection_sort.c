/*
** EPITECH PROJECT, 2020
** Visualizer
** File description:
** selection_sort
*/

#include "my.h"

void selection_sort(all_t *s_all)
{
    int lowest = 0;
    int save = 0;
    int pitch = 300;
    for (int i = 0, j = 0, k = 0; i != s_all->data_size - 1; i++, k++) {
        lowest = __INT_MAX__;

        sfRenderWindow_clear(s_all->window, sfBlack);

        for (int i = s_all->data_size - 1; i != 0; i--) {
            sfRectangleShape_setPosition(s_all->data_tab[i]->rectangle, s_all->data_tab[i]->pos);
            sfRenderWindow_drawRectangleShape(s_all->window, s_all->data_tab[i]->rectangle, NULL);
        }

        for (j = i; j != s_all->data_size; j++) {
            if (s_all->data_tab[j]->value <= lowest) {
                lowest = s_all->data_tab[j]->value;
                save = j;
            }
        }

        sfVector2f pos = s_all->data_tab[save]->pos;
        s_all->data_tab[save]->pos = s_all->data_tab[i]->pos;
        s_all->data_tab[i]->pos = pos;
        int value = s_all->data_tab[save]->value;
        s_all->data_tab[save]->value = s_all->data_tab[i]->value;
        s_all->data_tab[i]->value = value;

        sfMusic_setPitch(s_all->beep, (float)i / 100);
        if (k == 100) {
            k = 0;
            pitch += 50;
        }
        sfMusic_setPitch(s_all->beep2, (float)i / pitch);

        usleep(25000);
        sfRenderWindow_display(s_all->window);
    }
}

void double_selection_sort(all_t *s_all)
{
    int lowest = 0;
    int biggest = 0;
    int save = 0;
    for (int i = 0, j = 0, k = 0, l = s_all->data_size - 1; i != s_all->data_size / 2 + 1; i++, k++, l--) {
        lowest = __INT_MAX__;
        biggest = __INT_MAX__ * -1;

        sfRenderWindow_clear(s_all->window, sfBlack);

        for (int i = s_all->data_size - 1; i != 0; i--) {
            sfRectangleShape_setPosition(s_all->data_tab[i]->rectangle, s_all->data_tab[i]->pos);
            sfRenderWindow_drawRectangleShape(s_all->window, s_all->data_tab[i]->rectangle, NULL);
        }

        for (j = i; j != s_all->data_size; j++) {
            if (s_all->data_tab[j]->value <= lowest) {
                lowest = s_all->data_tab[j]->value;
                save = j;
            }
        }

        sfVector2f pos = s_all->data_tab[save]->pos;
        s_all->data_tab[save]->pos = s_all->data_tab[i]->pos;
        s_all->data_tab[i]->pos = pos;
        int value = s_all->data_tab[save]->value;
        s_all->data_tab[save]->value = s_all->data_tab[i]->value;
        s_all->data_tab[i]->value = value;

        for (j = l; j != -1; j--) {
            if (s_all->data_tab[j]->value >= biggest) {
                biggest = s_all->data_tab[j]->value;
                save = j;
            }
        }

        pos = s_all->data_tab[save]->pos;
        s_all->data_tab[save]->pos = s_all->data_tab[l]->pos;
        s_all->data_tab[l]->pos = pos;
        value = s_all->data_tab[save]->value;
        s_all->data_tab[save]->value = s_all->data_tab[l]->value;
        s_all->data_tab[l]->value = value;

        sfMusic_setPitch(s_all->beep, (float)i / 200);
        sfMusic_setPitch(s_all->beep2, (float)l / 200);

        usleep(25000);
        sfRenderWindow_display(s_all->window);
    }
}