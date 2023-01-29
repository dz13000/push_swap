#include "push_swap.h"

void	free_pile(t_pile **pile)
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

int	ft_lst_size(t_pile **pile)
{
	t_pile	*size;
	int		i;

	size = (*pile);
	i = 0;
	while (size)
	{
		size = size->next;
		i++;
	}
	return (i);
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
	lis(&pile_a, &pile_b);
	tri(&pile_a, &pile_b);
	// ok = pile_a;
	// while (ok)
	// {
	// 	printf("PILE A----->%d\n", ok->nb);
	// 	printf("LIS----->%d\n", ok->lis);
	// 	printf("Count----->%d\n", ok->count);
	// 	ok = ok->next;
	// }

	t_pile *ok2;
	ok2 = pile_b;
	while (ok2)
	{
		printf("PILE B----->%d\n", ok2->nb);
		printf("Daron----->%d\n", ok2->daron);
		ok2 = ok2->next;
	}

	printf("La taille de la pile A est  : %d\n", ft_lst_size(&pile_a));
	ok = pile_a;
	while (ok)
	{
		printf("PILE A----->%d\n", ok->nb);
		//printf("LIS----->%d\n", ok->lis);
		// printf("Count----->%d\n", ok->count);
		ok = ok->next;
	}

	printf("La taille de la pile A est  : %d\n", ft_lst_size(&pile_a));
	free_pile(&pile_a);
	free_pile(&pile_b);
	return (0);
}