/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:43:22 by cabouzir          #+#    #+#             */
/*   Updated: 2023/02/04 04:43:23 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_1(t_pile **pile_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (!(*pile_b))
		return ;
	if (ft_lst_size(&(*pile_b)) == 1)
		return ;
	tmp = (*pile_b);
	tmp2 = (*pile_b);
	(*pile_b) = (*pile_b)->next;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = tmp2;
	tmp2->next = NULL;
}

void	rotate_2(t_pile **pile_a)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (!(*pile_a))
		return ;
	if (ft_lst_size(&(*pile_a)) == 1)
		return ;
	tmp = (*pile_a);
	tmp2 = (*pile_a);
	(*pile_a) = (*pile_a)->next;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = tmp2;
	tmp2->next = NULL;
}

void	reverse_rotate_1(t_pile **pile_a)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	t_pile	*tmp3;

	tmp = (*pile_a);
	tmp2 = (*pile_a);
	tmp3 = (*pile_a);
	if (!(*pile_a))
		return ;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp2 = tmp->next;
	tmp2->next = tmp3;
	tmp3 = tmp2;
	tmp->next = NULL;
	(*pile_a) = tmp3;
}

void	reverse_rotate_2(t_pile **pile_b)
{
	t_pile *tmp;
	t_pile *tmp2;
	t_pile *tmp3;

	tmp = (*pile_b);
	tmp2 = (*pile_b);
	tmp3 = (*pile_b);
	if (!(*pile_b))
		return ;
	while (tmp->next->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp2 = tmp->next;
	tmp2->next = tmp3;
	tmp3 = tmp2;
	tmp->next = NULL;
	(*pile_b) = tmp3;
}