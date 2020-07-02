/*
** EPITECH PROJECT, 2020
** Visualizer
** File description:
** main
*/

#include "my.h"

void display(all_t *s_all)
{
    for (int i = s_all->data_size - 1; i != 0; i--) {
        sfRectangleShape_setPosition(s_all->data_tab[i]->rectangle, s_all->data_tab[i]->pos);
        sfRenderWindow_drawRectangleShape(s_all->window, s_all->data_tab[i]->rectangle, NULL);
    }
    sfRenderWindow_display(s_all->window);
}

void event_control(all_t *s_all)
{
    if (s_all->event.type == sfEvtClosed)
        sfRenderWindow_close(s_all->window);
}

void render_loop(all_t *s_all)
{
    while (sfRenderWindow_isOpen(s_all->window)) {

        while (sfRenderWindow_pollEvent(s_all->window, &s_all->event))
            event_control(s_all);

        //display(s_all);
    }
}

//void display_text(all_t *s_all)
//{

//}

void end_animation(all_t *s_all)
{
    sfMusic_stop(s_all->beep);
    sfMusic_stop(s_all->beep2);
}

void between_animation(all_t *s_all)
{
    sfMusic_stop(s_all->beep);
    sfMusic_stop(s_all->beep2);
    sleep(1);
    sfMusic_play(s_all->beep);
    sfMusic_play(s_all->beep2);
}

void animation(all_t *s_all)
{
    shuffle(s_all);
    between_animation(s_all);
    bubble_sort(s_all);
    between_animation(s_all);
    shuffle(s_all);
    between_animation(s_all);
    selection_sort(s_all);
    between_animation(s_all);
    shuffle(s_all);
    between_animation(s_all);
    double_selection_sort(s_all);
    between_animation(s_all);
    shuffle(s_all);
    between_animation(s_all);
    cocktail_shaker(s_all);
    between_animation(s_all);
    shuffle(s_all);
    between_animation(s_all);
    insertion_sort(s_all);
    between_animation(s_all);
    shuffle(s_all);
    between_animation(s_all);
    shell_sort(s_all);
    between_animation(s_all);
    shuffle(s_all);
    end_animation(s_all);
}

int main(void)
{
    all_t s_all;

    init_all(&s_all);
    if (!s_all.window)
        return (84);

    srand(time(NULL));
    sfMusic_play(s_all.beep);
    sfMusic_play(s_all.beep2);

    s_all.data_tab = init_data_array(&s_all);
    
    animation(&s_all);

    render_loop(&s_all);

    sfMusic_destroy(s_all.beep);
    sfMusic_destroy(s_all.beep2);

    return (0);
}