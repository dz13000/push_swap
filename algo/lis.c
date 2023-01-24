#include "../push_swap.h"

void    def_lis(t_pile **pile_a)
{
    t_pile *tmp;
    t_pile *tmp2;

    tmp = (*pile_a);
    tmp2 = tmp->next;
    while (tmp2)
    {
        tmp = (*pile_a);
        while (tmp != tmp2)
        {
            if (tmp2->nb > tmp->nb && tmp2->lis == tmp->lis)
                tmp2->lis++;
            tmp = tmp->next;
        }
        tmp2 = tmp2->next;
    }
}

void    init_lis(t_pile **pile_a)
{
    t_pile *tmp;

    tmp = (*pile_a);
    while (tmp)
    {
        tmp->lis = 1;
        tmp = tmp->next;
    }
}

int     max_lis(t_pile **pile_a)
{
    int max;
    t_pile *tmp;

    max = 0;
    tmp = (*pile_a);
    while (tmp)
    {
        if (tmp->lis > max)
            max = tmp->lis;
        tmp = tmp->next;
    }
    return(max);
    
}

int     verif_lis(t_pile **pile_a, int i)
{
    t_pile *tmp;

    tmp = (*pile_a);
    tmp = tmp->next;
    while (tmp)
    {
        if(tmp->lis == i)
            return(1);
        tmp = tmp->next;
    }
    return(0);
}

void    value_lis(t_pile **pile_a, int lis_max)
{
    int i = 1;
    t_pile *tmp;

    tmp = (*pile_a);
    while (i <= lis_max)
    {
        tmp = (*pile_a);
        while(tmp)
        {
            if (i == tmp->lis && verif_lis(&tmp, i) == 1)
                tmp->lis = 0;
            tmp = tmp->next;
        }
        i++;
    }
}
void	lis(t_pile **pile_a, t_pile **pile_b)
{
    t_pile *tmp;
    int lis_max;
    int *tab;
    int i;
    int j;

    i = 0;
    j = 0;
    tmp = (*pile_a);
    lis_max = 0;
    init_lis(&(*pile_a));
    def_lis(&(*pile_a));
    lis_max = max_lis(&(*pile_a));
    value_lis(*(&pile_a), lis_max);
    tab = malloc(sizeof(int) * lis_max);
    while (tmp)
    {
        if (tmp->lis != 0)
        {
            tab[i] = tmp->nb;
            i++;
        }
        tmp = tmp->next;
    }
    while (j < lis_max)
    {
        printf("Le TABLEAU %d\n", tab[j++]);
    }
    (void)(*pile_b);
}