#include "push_swap.h"

int main(int ac, char **av)
{
    (void)ac;
    if (ac < 2)
        printf("Error");
    if (verif_arg(av))
        printf("Error");
    else
    printf("ok");
    int i = 0;
    while(av[i])
        i++;
    printf("%d", i);
}