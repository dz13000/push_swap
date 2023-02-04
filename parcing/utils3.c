/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:43:51 by cabouzir          #+#    #+#             */
/*   Updated: 2023/02/04 06:59:22 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free2(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return ;
}

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

void	algo_de5(t_pile **pile_a, t_pile **pile_b)
{
	ft_replace(&(*pile_a));
	push_b(&(*pile_a), &(*pile_b));
	ft_replace(&(*pile_a));
	push_b(&(*pile_a), &(*pile_b));
	algo_de3_5(&(*pile_a), &(*pile_b));
	push_a(&(*pile_a), &(*pile_b));
	push_a(&(*pile_a), &(*pile_b));
	free_pile(&(*pile_a));
	free_pile(&(*pile_b));
	exit(0);
}
