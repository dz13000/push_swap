/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:42:30 by cabouzir          #+#    #+#             */
/*   Updated: 2023/02/04 05:58:16 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	up2(t_pile **pile_a, t_pile **pile_b, t_pile *pos_b)
{
	while (pos_b->up_a > 0 && pos_b->up_b > 0)
	{
		rr(&(*pile_a), &(*pile_b));
		pos_b->up_a--;
		pos_b->up_b--;
	}
}

void	down2(t_pile **pile_a, t_pile **pile_b, t_pile *pos_b)
{
	while (pos_b->down_a > 0 && pos_b->down_b > 0)
	{
		rrr(&(*pile_a), &(*pile_b));
		pos_b->down_a--;
		pos_b->down_b--;
	}
}

void	up_pa(t_pile **pile_a, t_pile *pos_b)
{
	while (pos_b->up_a > 0)
	{
		rotate_a(&(*pile_a));
		pos_b->up_a--;
	}
}

void	up_pb(t_pile **pile_b, t_pile *pos_b)
{
	while (pos_b->up_b > 0)
	{
		rotate_b(&(*pile_b));
		pos_b->up_b--;
	}
}

void	insertion(t_pile **pile_a, t_pile **pile_b, t_pile *pos_b)
{
	up2(&(*pile_a), &(*pile_b), &(*pos_b));
	down2(&(*pile_a), &(*pile_b), &(*pos_b));
	up_pa(&(*pile_a), &(*pos_b));
	up_pb(&(*pile_b), &(*pos_b));
	while (pos_b->up_b > 0)
	{
		rotate_b(&(*pile_b));
		pos_b->up_b--;
	}
	while (pos_b->down_a > 0)
	{
		reverse_rotate_a(&(*pile_a));
		pos_b->down_a--;
	}
	while (pos_b->down_b > 0)
	{
		reverse_rotate_b(&(*pile_b));
		pos_b->down_b--;
	}
	push_a(&(*pile_a), &(*pile_b));
}
