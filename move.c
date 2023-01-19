#include "push_swap.h"

void    ft_lstadd_front(t_pile **pile_a, t_pile *new)
{
    t_pile *tmp;

    tmp = *pile_a;
    new->next = tmp;
    *pile_a = new;
}

// void    swap_a(t_pile *pile_a)
// {
//     t_pile *tmp;
//     t_pile *tmp2;

//     if(!pile_a || pile_a->next == NULL)
//         return;
//     tmp = pile_a;
//     tmp2 = pile_a;

//     tmp2 = pile_a->next;
//     tmp->next = pile_a->next->next;
//     ft_lstadd_front(&pile_a, tmp2);
//     // tmp2->next = tmp;
//     // pile_a = tmp2;
//     printf("Test ---->%d\n", tmp2->nb);
//     printf("Test 2 ---->%d\n", pile_a->nb);
//     pile_a = tmp;

// }