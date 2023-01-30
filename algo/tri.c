#include "../push_swap.h"

int	calcul_coups1(t_pile **pile_a, t_pile **pile_b, t_pile *pos_a, t_pile *pos_b)
{
	t_pile *tmp;
	t_pile *tmp2;
	int i;
	int j;
	int r;

	tmp = (*pile_a);
	tmp2 = (*pile_b);
	i = 0;
	j = 0;
	r = 0;
	while(tmp)
	{
		i++;
		if (tmp == pos_a)
			break;
		tmp = tmp->next;
	}
	i--;
	while(tmp2)
	{
		j++;
		if (tmp2 == pos_b)
			break;
		tmp2 = tmp2->next;
	}
	j--;
	if (i == 0)
		return (j);
	if (j >= i)
	{
		r = j - i;
		return(r + i);
	}
	else
	{
		r = i - j;
		return(r + j);
	}
}

int	calcul_coups2(t_pile **pile_a, t_pile **pile_b, t_pile *pos_a, t_pile *pos_b)
{
	t_pile *tmp;
	t_pile *tmp2;
	int i;
	int j;
	int r;
	int temp;

	tmp = (*pile_a);
	tmp2 = (*pile_b);
	i = 0;
	j = 0;
	r = 0;
	temp = 0;
	while(tmp)
	{
		i++;
		if (tmp == pos_a)
			break;
		tmp = tmp->next;
	}
	i--;
	while(tmp2)
	{
		j++;
		if (tmp2 == pos_b)
			break;
		tmp2 = tmp2->next;
	}
	j--;
	temp = ft_lst_size(&(*pile_a)) - i;
	i = temp;
	temp = ft_lst_size(&(*pile_b)) - j;
	j = temp;
	if (i == 0)
		return(j);
	if (j >= i)
	{
		r = j - i;
		return(r + i);
	}
	else
	{
		r = i - j;
		return(r + j);
	}
}

void	asign_cc1(t_pile **pile_a, t_pile **pile_b, t_pile **pos_a, t_pile **pos_b)
{
	t_pile *tmp;
	t_pile *tmp2;
	int i;
	int j;
	int	tt;

	tmp = (*pile_a);
	tmp2 = (*pile_b);
	i = 0;
	j = 0;
	tt = 0;
	while(tmp)
	{
		i++;
		if (tmp == (*pos_a))
			break;
		tmp = tmp->next;
	}
	i--;
	(*pos_b)->up_a = i;
	(*pos_b)->down_a = 0;
	while (tmp2)
	{
		j++;
		if (tmp2 == (*pos_b))
			break;
		tmp2 = tmp2->next;
	}
	j--;
	(*pos_b)->up_b = j;
	(*pos_b)->down_b = 0;
	if (j >= i)
	{
		tt = j - i;
		(*pos_b)->total_coups = tt + i;
	}
	else
	{
		tt = i - j;
		(*pos_b)->total_coups = tt + j;
	}
}

void	calcul_prix(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	t_cc	cc;

	cc.cc1 = 0;
	tmp2 = (*pile_b);
    while(tmp2)
    {
		tmp = (*pile_a);
		while(tmp)
		{
			if (tmp->nb == tmp2->daron)
			{
				cc.cc1 = calcul_coups1(&(*pile_a), &(*pile_b), tmp, tmp2);
				cc.cc2 = calcul_coups2(&(*pile_a), &(*pile_b), tmp, tmp2);
				//if (cc.cc1 <= cc.cc2)
					asign_cc1(&(*pile_a), &(*pile_b), (&tmp), (&tmp2));
				break;
			}
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
    }
}

void	tri(t_pile **pile_a, t_pile **pile_b)
{
	init_daron(&(*pile_b));
	ft_daron(&(*pile_a), &(*pile_b));
	calcul_prix(&(*pile_a), &(*pile_b));
}