#include "../push_swap.h"

int		nombre = 0;

void	asign_cp(t_cp *c, t_pile **pile_a, t_pile **pile_b)
{
	c->tmp = (*pile_a);
	c->tmp2 = (*pile_b);
	c->i = 0;
	c->j = 0;
	c->r = 0;
	c->temp = 0;
	c->tt = 0;
}

void	asign_cc1(t_pile **pile_a, t_pile **pile_b, t_pile **pos_a,
		t_pile **pos_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	int		i;
	int		j;
	int		tt;

	tmp = (*pile_a);
	tmp2 = (*pile_b);
	i = 0;
	j = 0;
	tt = 0;
	while (tmp)
	{
		i++;
		if (tmp == (*pos_a))
			break ;
		tmp = tmp->next;
	}
	i--;
	(*pos_b)->up_a = i;
	(*pos_b)->down_a = 0;
	while (tmp2)
	{
		j++;
		if (tmp2 == (*pos_b))
			break ;
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

void	asign_cc2(t_pile **pile_a, t_pile **pile_b, t_pile **pos_a,
		t_pile **pos_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	int		i;
	int		j;
	int		tt;
	int		temp;

	tmp = (*pile_a);
	tmp2 = (*pile_b);
	i = 0;
	j = 0;
	tt = 0;
	temp = 0;
	while (tmp)
	{
		i++;
		if (tmp == (*pos_a))
			break ;
		tmp = tmp->next;
	}
	i--;
	while (tmp2)
	{
		j++;
		if (tmp2 == (*pos_b))
			break ;
		tmp2 = tmp2->next;
	}
	j--;
	if (i != 0)
	{
		temp = ft_lst_size(&(*pile_a)) - i;
		i = temp;
	}
	if (j != 0)
	{
		temp = ft_lst_size(&(*pile_b)) - j;
		j = temp;
	}
	(*pos_b)->up_b = 0;
	(*pos_b)->up_a = 0;
	(*pos_b)->down_a = i;
	(*pos_b)->down_b = j;
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

void	asign_cc3(t_pile **pile_a, t_pile **pile_b, t_pile **pos_a,
		t_pile **pos_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	int		i;
	int		j;

	tmp = (*pile_a);
	tmp2 = (*pile_b);
	i = 0;
	j = 0;
	while (tmp)
	{
		i++;
		if (tmp == (*pos_a))
			break ;
		tmp = tmp->next;
	}
	i--;
	while (tmp2)
	{
		j++;
		if (tmp2 == (*pos_b))
			break ;
		tmp2 = tmp2->next;
	}
	j--;
	(*pos_b)->up_a = i;
	(*pos_b)->up_b = 0;
	(*pos_b)->down_a = 0;
	if (j == 0)
	{
		(*pos_b)->down_b = j;
		(*pos_b)->total_coups = i + j;
		return ;
	}
	(*pos_b)->down_b = (ft_lst_size(&(*pile_b))) - j;
	(*pos_b)->total_coups = i + (ft_lst_size(&(*pile_b)) - j);
}

void	asign_cc4(t_pile **pile_a, t_pile **pile_b, t_pile **pos_a,
		t_pile **pos_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	int		i;
	int		j;

	tmp = (*pile_a);
	tmp2 = (*pile_b);
	i = 0;
	j = 0;
	while (tmp)
	{
		i++;
		if (tmp == (*pos_a))
			break ;
		tmp = tmp->next;
	}
	i--;
	while (tmp2)
	{
		j++;
		if (tmp2 == (*pos_b))
			break ;
		tmp2 = tmp2->next;
	}
	j--;
	(*pos_b)->up_a = 0;
	(*pos_b)->down_b = 0;
	(*pos_b)->up_b = j;
	if (i == 0)
	{
		(*pos_b)->down_a = 0;
		(*pos_b)->total_coups = i + j;
		return ;
	}
	(*pos_b)->down_a = (ft_lst_size(&(*pile_a))) - i;
	(*pos_b)->total_coups = j + (ft_lst_size(&(*pile_a)) - i);
}

void	tri(t_pile **pile_a, t_pile **pile_b)
{
	t_pile *tmp;
	t_pile *tmp2;
	int min;

	tmp = (*pile_b);
	min = 0;
	while (tmp)
	{
		init_daron(&(*pile_b));
		ft_daron(&(*pile_a), &(*pile_b));
		calcul_prix(&(*pile_a), &(*pile_b));
		min = minimum_coups(&(*pile_b));
		tmp2 = (*pile_b);
		while (tmp2)
		{
			if (tmp2->total_coups == min)
			{
				insertion(&(*pile_a), &(*pile_b), tmp2);
				break ;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		tmp = (*pile_b);
	}
}