#include "push_swap.h"

void	free_pile_a(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = (*pile);
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

int	main(int ac, char **av)
{
	if (ft_parcing(ac, av))
		return (0);
	t_pile *pile_a = 0;
	t_pile *pile_b;

	pile_b = 0;
	pile_a = ft_def_pile_a(ac, av);

	t_pile *ok;
	ok = pile_a;
	while (ok)
	{
		printf("PILE A----->%d\n", ok->nb);
		ok = ok->next;
	}

	t_pile *ok2;
	ok2 = pile_b;
	while (ok2)
	{
		printf("PILE B----->%d\n", ok2->nb);
		ok2 = ok2->next;
	}

	t_pile *size;
	int i;

	size = pile_a;
	i = 0;
	while (size)
	{
		size = size->next;
		i++;
	}

	printf("La taille de la pile A est  : %d\n", i);
	free_pile_a(&pile_a);
	return (0);
}