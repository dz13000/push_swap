#include "../push_swap.h"

t_pile	*ft_def_pile_a(int ac, char **av)
{
	t_pile *res = NULL;
	if (ac == 2)
	{
		int size = 0;
		int *tab = def_tab(av, &size);
		int j;
		j = 0;
		res = ft_lst_new(tab[j]);
		j++;
		while (j < size)
		{
			t_pile *new;
			new = ft_lst_new(tab[j]);
			ft_lstadd_back(res, new);
			j++;
		}
		free(tab);
	}
	else
	{
		int *tab;
		int size;

		size = 0;
		tab = def_tab2(av, &size);
		int j;
		j = 0;
		res = ft_lst_new(tab[j]);
		j++;
		while (j < size - 1)
		{
			t_pile *new;
			new = ft_lst_new(tab[j]);
			ft_lstadd_back(res, new);
			j++;
		}
		free(tab);
	}
	t_pile *tmp;
	tmp = res;
	while (tmp)
	{
		printf("La liste : %d\n", tmp->nb);
		tmp = tmp->next;
	}
	return (res);
}