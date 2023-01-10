#include "push_swap.h"

int verif_arg(char **str)
{
    int i = 1;
    int j;

    while (str[i])
    {
        j = 0;
        while(str[i][j])
        {
            if (str[i][j] != ' ' && str[i][j] != '-' && ft_isdigit(str[i][j]) == 0)
                return(1);
            else if (str[i][j] == '-' && !(str[i][j + 1] >= '0' && str[i][j + 1] <= '9'))
                return(1);
            j++;
        }
        i++;
    }
    return(0);
}

int ft_isdigit(char c)
{
    if(c >= '0' && c <= '9')
        return(1);
    return (0);
}
