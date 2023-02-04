/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:42:26 by cabouzir          #+#    #+#             */
/*   Updated: 2023/02/04 04:42:27 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_coups_bas(t_cc *cc)
{
	int	min;

	min = 0;
	min = cc->cc1;
	if (cc->cc2 < min)
		min = cc->cc2;
	if (cc->cc3 < min)
		min = cc->cc3;
	if (cc->cc4 < min)
		min = cc->cc4;
	return (min);
}

void	calcul_prix2(t_cc *cc, t_pile **pile_a, t_pile **pile_b)
{
	cc->cc1 = calcul_coups1(&(*pile_a), &(*pile_b), cc->tmp, cc->tmp2);
	cc->cc2 = calcul_coups2(&(*pile_a), &(*pile_b), cc->tmp, cc->tmp2);
	cc->cc3 = calcul_coups3(&(*pile_a), &(*pile_b), cc->tmp, cc->tmp2);
	cc->cc4 = calcul_coups4(&(*pile_a), &(*pile_b), cc->tmp, cc->tmp2);
	cc->min = ft_coups_bas(&*cc);
	if (cc->min == cc->cc1)
		asign_cc1(&(*pile_a), &(*pile_b), (&cc->tmp), (&cc->tmp2));
	if (cc->min == cc->cc2)
		asign_cc2(&(*pile_a), &(*pile_b), (&cc->tmp), (&cc->tmp2));
	if (cc->min == cc->cc3)
		asign_cc3(&(*pile_a), &(*pile_b), (&cc->tmp), (&cc->tmp2));
	if (cc->min == cc->cc4)
		asign_cc4(&(*pile_a), &(*pile_b), (&cc->tmp), (&cc->tmp2));
}

void	calcul_prix(t_pile **pile_a, t_pile **pile_b)
{
	t_cc	cc;

	cc.tmp2 = (*pile_b);
	while (cc.tmp2)
	{
		cc.tmp = (*pile_a);
		while (cc.tmp)
		{
			if (cc.tmp->nb == cc.tmp2->daron)
			{
				calcul_prix2(&cc, &(*pile_a), &(*pile_b));
				break ;
			}
			cc.tmp = cc.tmp->next;
		}
		cc.tmp2 = cc.tmp2->next;
	}
}

int	minimum_coups(t_pile **pile_b)
{
	int min;
	t_pile *tmp;

	tmp = (*pile_b);
	min = 0;
	min = tmp->total_coups;
	while (tmp)
	{
		if (tmp->total_coups < min)
			min = tmp->total_coups;
		tmp = tmp->next;
	}
	return (min);
}