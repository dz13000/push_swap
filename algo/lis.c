#include "../push_swap.h"

// void	def_lis(t_pile **pile_a)
// {
// 	t_pile	*tmp;
// 	t_pile	*tmp2;

// 	tmp = (*pile_a);
// 	tmp2 = tmp->next;
// 	while (tmp2)
// 	{
// 		tmp = (*pile_a);
// 		while (tmp != tmp2)
// 		{
// 			if (tmp2->nb > tmp->nb && tmp2->lis == tmp->lis)
// 				tmp2->lis++;
// 			tmp = tmp->next;
// 		}
// 		tmp2 = tmp2->next;
// 	}
// }

// void	init_lis(t_pile **pile_a)
// {
// 	t_pile	*tmp;

// 	tmp = (*pile_a);
// 	while (tmp)
// 	{
// 		tmp->lis = 1;
// 		tmp = tmp->next;
// 	}
// }

// int	max_lis(t_pile **pile_a)
// {
// 	int		max;
// 	t_pile	*tmp;

// 	max = 0;
// 	tmp = (*pile_a);
// 	while (tmp)
// 	{
// 		if (tmp->lis > max)
// 			max = tmp->lis;
// 		tmp = tmp->next;
// 	}
// 	return (max);
// }

// int	verif_lis(t_pile **pile_a, int i)
// {
// 	t_pile	*tmp;

// 	tmp = (*pile_a);
// 	tmp = tmp->next;
// 	while (tmp)
// 	{
// 		if (tmp->lis == i)
// 			return (1);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

// void	value_lis(t_pile **pile_a, int lis_max)
// {
// 	int		i;
// 	t_pile	*tmp;
// 	t_pile	*tmp2;

// 	i = lis_max;
// 	tmp = (*pile_a);
// 	while (i > 0)
// 	{
// 		tmp = (*pile_a);
// 		while (tmp)
// 		{
// 			if (i == tmp->lis && verif_lis(&tmp, i) == 0)
// 			{
// 				tmp->count = tmp->lis;
// 				tmp2 = tmp;
// 				while (tmp2)
// 				{
// 					tmp2->lis = 0;
// 					tmp2 = tmp2->next;
// 				}
// 			}
// 			tmp = tmp->next;
// 		}
// 		i--;
// 	}
// }

void	pre_tab(t_pile **pile_a, t_lis *lis, int lis_max)
{
	int		i;
	int		j;
	t_pile	*tmp;

	j = 1;
	i = 0;
	while (i < lis_max)
	{
		tmp = (*pile_a);
		while (tmp)
		{
			if (tmp->count == j)
				lis->tab[i] = tmp->nb;
			tmp = tmp->next;
		}
		j++;
		i++;
	}
}

int	verif_count(t_pile **pile_a)
{
	t_pile	*tmp;

	tmp = (*pile_a);
	while (tmp)
	{
		if (tmp->count == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	init_count(t_pile **pile_a)
{
	t_pile	*tmp;

	tmp = (*pile_a);
	while (tmp)
	{
		tmp->count = 0;
		tmp = tmp->next;
	}
}

void	pre_tri(t_pile **pile_a, t_pile **pile_b)
{
	t_pile *tmp;

	tmp = (*pile_a);
	while (tmp)
	{
		if (tmp->count == 0)
		{
			push_b(&(*pile_a), &(*pile_b));
			tmp = (*pile_a);
		}
		if (tmp->count != 0)
		{
			rotate_a(&(*pile_a));
			tmp = (*pile_a);
		}
		if (verif_count(&*pile_a) == 0)
			break ;
	}
}

void	lis(t_pile **pile_a, t_pile **pile_b)
{
	t_lis	lis;
	int		lis_max;
	int		j;

	j = 0;
	lis_max = 0;
	init_lis(&(*pile_a));
	init_count(&(*pile_a));
	def_lis(&(*pile_a));
	lis_max = max_lis(&(*pile_a));
	value_lis(*(&pile_a), lis_max);
	lis.tab = malloc(sizeof(int) * lis_max);
	pre_tab(&(*pile_a), &lis, lis_max);
	while (j < lis_max)
	{
		printf("Le lis.tabLEAU %d\n", lis.tab[j++]);
	}
	pre_tri(&(*pile_a), &(*pile_b));
	free(lis.tab);
}

// tmp2 = (*pile_a);
// while (tmp2->count != 1)
// {
//     rotate_a(&(*pile_a));
//     tmp2 = (*pile_a);
// }