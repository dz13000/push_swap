/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:44:06 by cabouzir          #+#    #+#             */
/*   Updated: 2023/02/04 04:50:54 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_de2(t_pile **pile_a, t_pile **pile_b)
{
	swap(&(*pile_a), &(*pile_b), 'a');
	free_pile(&(*pile_a));
	free_pile(&(*pile_b));
	exit(0);
}

void	algo_de3v2(t_pile **pile_a, t_pile **pile_b)
{
	if (((*pile_a)->nb < (*pile_a)->next->nb)
		&& ((*pile_a)->next->nb > (*pile_a)->next->next->nb)
		&& ((*pile_a)->nb > (*pile_a)->next->next->nb))
		reverse_rotate_a(&(*pile_a));
	if (((*pile_a)->nb < (*pile_a)->next->nb)
		&& ((*pile_a)->next->nb > (*pile_a)->next->next->nb)
		&& ((*pile_a)->nb < (*pile_a)->next->next->nb))
	{
		reverse_rotate_a(&(*pile_a));
		swap(&(*pile_a), &(*pile_b), 'a');
	}
}

void	algo_de3(t_pile **pile_a, t_pile **pile_b)
{
	if (((*pile_a)->nb > (*pile_a)->next->nb)
		&& ((*pile_a)->next->nb > (*pile_a)->next->next->nb))
	{
		rotate_a(&(*pile_a));
		swap(&(*pile_a), &(*pile_b), 'a');
	}
	if (((*pile_a)->nb > (*pile_a)->next->nb)
		&& ((*pile_a)->next->nb < (*pile_a)->next->next->nb)
		&& ((*pile_a)->nb > (*pile_a)->next->next->nb))
		rotate_a(&(*pile_a));
	if (((*pile_a)->nb > (*pile_a)->next->nb)
		&& ((*pile_a)->next->nb < (*pile_a)->next->next->nb)
		&& ((*pile_a)->nb < (*pile_a)->next->next->nb))
		swap(&(*pile_a), &(*pile_b), 'a');
	algo_de3v2(&(*pile_a), &(*pile_b));
	free_pile(&(*pile_a));
	free_pile(&(*pile_b));
	exit(0);
}

void	algo_de3_5v2(t_pile **pile_a, t_pile **pile_b)
{
	if (((*pile_a)->nb < (*pile_a)->next->nb)
		&& ((*pile_a)->next->nb > (*pile_a)->next->next->nb)
		&& ((*pile_a)->nb > (*pile_a)->next->next->nb))
		reverse_rotate_a(&(*pile_a));
	if (((*pile_a)->nb < (*pile_a)->next->nb)
		&& ((*pile_a)->next->nb > (*pile_a)->next->next->nb)
		&& ((*pile_a)->nb < (*pile_a)->next->next->nb))
	{
		reverse_rotate_a(&(*pile_a));
		swap(&(*pile_a), &(*pile_b), 'a');
	}
}

void	algo_de3_5(t_pile **pile_a, t_pile **pile_b)
{
	if (((*pile_a)->nb > (*pile_a)->next->nb)
		&& ((*pile_a)->next->nb > (*pile_a)->next->next->nb))
	{
		rotate_a(&(*pile_a));
		swap(&(*pile_a), &(*pile_b), 'a');
	}
	if (((*pile_a)->nb > (*pile_a)->next->nb)
		&& ((*pile_a)->next->nb < (*pile_a)->next->next->nb)
		&& ((*pile_a)->nb > (*pile_a)->next->next->nb))
		rotate_a(&(*pile_a));
	if (((*pile_a)->nb > (*pile_a)->next->nb)
		&& ((*pile_a)->next->nb < (*pile_a)->next->next->nb)
		&& ((*pile_a)->nb < (*pile_a)->next->next->nb))
		swap(&(*pile_a), &(*pile_b), 'a');
	algo_de3_5v2(&(*pile_a), &(*pile_b));
}
