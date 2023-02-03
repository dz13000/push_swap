#include "../push_swap.h"

int		nombre = 0;

void	utils_cc3(t_cp *cc3, t_pile **pos_a, t_pile **pos_b)
{
	while (cc3->tmp)
	{
		cc3->i++;
		if (cc3->tmp == (*pos_a))
			break ;
		cc3->tmp = cc3->tmp->next;
	}
	cc3->i--;
	while (cc3->tmp2)
	{
		cc3->j++;
		if (cc3->tmp2 == (*pos_b))
			break ;
		cc3->tmp2 = cc3->tmp2->next;
	}
	cc3->j--;
}
void	asign_cc3(t_pile **pile_a, t_pile **pile_b, t_pile **pos_a,
		t_pile **pos_b)
{
	t_cp cc3;

	asign_cp(&cc3, &(*pile_a), &(*pile_b));
	utils_cc3(&cc3, &(*pos_a), &(*pos_b));
	(*pos_b)->up_a = cc3.i;
	(*pos_b)->up_b = 0;
	(*pos_b)->down_a = 0;
	if (cc3.j == 0)
	{
		(*pos_b)->down_b = cc3.j;
		(*pos_b)->total_coups = cc3.i + cc3.j;
		return ;
	}
	(*pos_b)->down_b = (ft_lst_size(&(*pile_b))) - cc3.j;
	(*pos_b)->total_coups = cc3.i + (ft_lst_size(&(*pile_b)) - cc3.j);
}

void	utils_cc4(t_cp *cc4, t_pile **pos_a, t_pile **pos_b)
{
	while (cc4->tmp)
	{
		cc4->i++;
		if (cc4->tmp == (*pos_a))
			break ;
		cc4->tmp = cc4->tmp->next;
	}
	cc4->i--;
	while (cc4->tmp2)
	{
		cc4->j++;
		if (cc4->tmp2 == (*pos_b))
			break ;
		cc4->tmp2 = cc4->tmp2->next;
	}
	cc4->j--;
}

void	asign_cc4(t_pile **pile_a, t_pile **pile_b, t_pile **pos_a,
		t_pile **pos_b)
{
	t_cp cc4;

	asign_cp(&cc4, &(*pile_a), &(*pile_b));
	utils_cc4(&cc4, &(*pos_a), &(*pos_b));
	(*pos_b)->up_a = 0;
	(*pos_b)->down_b = 0;
	(*pos_b)->up_b = cc4.j;
	if (cc4.i == 0)
	{
		(*pos_b)->down_a = 0;
		(*pos_b)->total_coups = cc4.i + cc4.j;
		return ;
	}
	(*pos_b)->down_a = (ft_lst_size(&(*pile_a))) - cc4.i;
	(*pos_b)->total_coups = cc4.j + (ft_lst_size(&(*pile_a)) - cc4.i);
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
	// init_daron(&(*pile_b));
	// 	ft_daron(&(*pile_a), &(*pile_b));
}