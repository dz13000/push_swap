/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:42:45 by cabouzir          #+#    #+#             */
/*   Updated: 2023/02/04 04:42:46 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	utils_cc2(t_cp *cc2, t_pile **pos_a, t_pile **pos_b, t_pile **pile_a)
{
	while (cc2->tmp)
	{
		cc2->i++;
		if (cc2->tmp == (*pos_a))
			break ;
		cc2->tmp = cc2->tmp->next;
	}
	cc2->i--;
	while (cc2->tmp2)
	{
		cc2->j++;
		if (cc2->tmp2 == (*pos_b))
			break ;
		cc2->tmp2 = cc2->tmp2->next;
	}
	cc2->j--;
	if (cc2->i != 0)
	{
		cc2->temp = ft_lst_size(&(*pile_a)) - cc2->i;
		cc2->i = cc2->temp;
	}
}

void	asign_cc2(t_pile **pile_a, t_pile **pile_b, t_pile **pos_a,
		t_pile **pos_b)
{
	t_cp cc2;

	asign_cp(&cc2, &(*pile_a), &(*pile_b));
	utils_cc2(&cc2, &(*pos_a), &(*pos_b), &(*pile_a));
	if (cc2.j != 0)
	{
		cc2.temp = ft_lst_size(&(*pile_b)) - cc2.j;
		cc2.j = cc2.temp;
	}
	(*pos_b)->up_b = 0;
	(*pos_b)->up_a = 0;
	(*pos_b)->down_a = cc2.i;
	(*pos_b)->down_b = cc2.j;
	if (cc2.j >= cc2.i)
	{
		cc2.tt = cc2.j - cc2.i;
		(*pos_b)->total_coups = cc2.tt + cc2.i;
	}
	else
	{
		cc2.tt = cc2.i - cc2.j;
		(*pos_b)->total_coups = cc2.tt + cc2.j;
	}
}