/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:42:09 by cabouzir          #+#    #+#             */
/*   Updated: 2023/02/04 04:42:10 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	t_pile	*tmp;

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
	t_lis lis;
	int lis_max;

	lis_max = 0;
	init_lis(&(*pile_a));
	init_count(&(*pile_a));
	def_lis(&(*pile_a));
	lis_max = max_lis(&(*pile_a));
	value_lis(*(&pile_a), lis_max);
	lis.tab = malloc(sizeof(int) * lis_max);
	if (!lis.tab)
	{
		free_pile(&(*pile_a));
		free_pile(&(*pile_b));
		return ;
	}
	pre_tab(&(*pile_a), &lis, lis_max);
	pre_tri(&(*pile_a), &(*pile_b));
	free(lis.tab);
}