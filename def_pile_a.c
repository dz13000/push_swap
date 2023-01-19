#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

int	*def_tab(char **av, int *size)
{
	char	**tab;
	int		*tab2;
	int		j;
	int		i;

	i = 0;
	tab = ft_split(av[1], ' ');
	while (tab[i])
		i++;
	tab2 = malloc(sizeof(int) * i);
	if (!tab2)
		exit(1);
	i = 0;
	j = 0;
	while (tab[i])
	{
		tab2[j] = ft_atoi(tab[i]);
		j++;
		i++;
	}
    ft_free2(tab);
    *size = i;
	return (tab2);
}

t_pile *ft_lst_new(int nb)
{
    t_pile *new;
	new = malloc(sizeof(t_pile));
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_pile *lst, t_pile *new)
{
	t_pile *tmp;

	tmp = lst;
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	tmp->next->next = NULL;
}

t_pile	*ft_def_pile_a(int ac, char **av)
{
    t_pile  *res;
	if (ac == 2)
	{
        int size = 0;
		int *tab = def_tab(av, & size);
		int j;
        j = 0;
		res = ft_lst_new(tab[j]);
		// printf("La liste : %d\n", res->nb);
		j++;
		while (j < size)
		{
			t_pile *new;
			new = ft_lst_new(tab[j]);
			ft_lstadd_back(res, new);
			// free(new);
			j++;
		}
		// free(new);
        free(tab);
	}
	t_pile *tmp;
	tmp = res;
	while(tmp)
	{
		printf("La liste : %d\n", tmp->nb);
		tmp = tmp->next;
	}
	return (res);
}