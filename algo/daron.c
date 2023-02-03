#include "../push_swap.h"

void	init_daron(t_pile **pile_b)
{
	t_pile	*tmp;

	tmp = (*pile_b);
	while (tmp)
	{
		tmp->daron = tmp->nb;
		tmp = tmp->next;
	}
}

int	max_pile(t_pile **pile)
{
	t_pile	*tmp;
	int		max;

	tmp = (*pile);
	max = 0;
	while (tmp)
	{
		if (tmp->nb > max)
			max = tmp->nb;
		tmp = tmp->next;
	}
	return (max);
}

int	min_pile(t_pile **pile)
{
	t_pile	*tmp;
	int		min;

	tmp = (*pile);
	min = tmp->nb;
	while (tmp)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_daron(t_pile **pile_a, t_pile **pile_b)
{
	t_pile *tmp;
	t_pile *tmp2;

	tmp2 = (*pile_b);
	while (tmp2)
	{
		tmp = (*pile_a);
		while (tmp)
		{
			if ((tmp2->daron == tmp2->nb) && (tmp->nb > tmp2->nb))
				tmp2->daron = tmp->nb;
			if (tmp->nb > tmp2->nb && tmp->nb < tmp2->daron)
				tmp2->daron = tmp->nb;
			if (tmp2->nb > max_pile(&(*pile_a)))
				tmp2->daron = min_pile(&(*pile_a));
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
}