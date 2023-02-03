#include "push_swap.h"

int	ft_min(t_pile **pile_a)
{
	int		min;
	t_pile	*tmp2;

	tmp2 = (*pile_a);
	min = tmp2->nb;
	while (tmp2)
	{
		if (tmp2->nb < min)
			min = tmp2->nb;
		tmp2 = tmp2->next;
	}
	return (min);
}

void	up_a(t_pile **pile_a, int min)
{
	t_pile	*tmp2;

	tmp2 = ((*pile_a));
	while (tmp2->nb != min)
	{
		rotate_a(&(*pile_a));
		nombre++;
		tmp2 = ((*pile_a));
	}
}

void	down_a(t_pile **pile_a, int min)
{
	t_pile	*tmp2;

	tmp2 = ((*pile_a));
	while (tmp2->nb != min)
	{
		reverse_rotate_a(&(*pile_a));
		nombre++;
		tmp2 = ((*pile_a));
	}
}

void	ft_replace(t_pile **pile_a)
{
	int		min;
	t_pile	*tmp2;
	int		cc;
	int		moy;

	min = ft_min(&(*pile_a));
	tmp2 = ((*pile_a));
	cc = ft_lst_size(&tmp2);
	cc = cc / 2;
	moy = 0;
	while (tmp2)
	{
		if (min == tmp2->nb)
			break ;
		moy++;
		tmp2 = tmp2->next;
	}
	tmp2 = ((*pile_a));
	if (moy <= cc)
		up_a(&(*pile_a), min);
	else
		down_a(&(*pile_a), min);
}

int	main(int ac, char **av)
{
	t_pile *pile_a;
	t_pile *pile_b;

	if (ft_parcing(ac, av))
		return (0);
	pile_b = 0;
	pile_a = 0;
	pile_a = ft_def_pile_a(ac, av);

	lis(&pile_a, &pile_b);
	tri(&pile_a, &pile_b);
	ft_replace(&pile_a);

	// t_pile *ok;
	// printf("La taille de la pile A est  : %d\n", ft_lst_size(&pile_a));
	// ok = pile_a;
	// while (ok)
	// {
	// 	printf("PILE A----->%d\n", ok->nb);
	// 	//printf("LIS----->%d\n", ok->lis);
	// 	// printf("Count----->%d\n", ok->count);
	// 	ok = ok->next;
	// }

	// ok = pile_b;
	// while (ok)
	// {
	// 	printf("PILE B----->%d\n", ok->nb);
	// 	printf("PILE B-----> DARON *****%d*****\n", ok->daron);
	// 	//printf("LIS----->%d\n", ok->lis);
	// 	// printf("Count----->%d\n", ok->count);
	// 	ok = ok->next;
	// }

	printf("La taille de la pile A est  : %d\n", ft_lst_size(&pile_a));
	printf("Le nombre de coups est de : %d\n", nombre);
	free_pile(&pile_a);
	free_pile(&pile_b);
	return (0);
}