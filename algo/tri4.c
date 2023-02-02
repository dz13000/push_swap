#include "../push_swap.h"

int	calcul_coups3(t_pile **pile_a, t_pile **pile_b, t_pile *pos_a,
		t_pile *pos_b)
{
	t_cp c3;

	asign_cp(&c3, &(*pile_a), &(*pile_b));
	while (c3.tmp)
	{
		c3.i++;
		if (c3.tmp == pos_a)
			break ;
		c3.tmp = c3.tmp->next;
	}
	c3.i--;
	while (c3.tmp2)
	{
		c3.j++;
		if (c3.tmp2 == pos_b)
			break ;
		c3.tmp2 = c3.tmp2->next;
	}
	c3.j--;
	if (c3.j == 0)
		return (c3.i);
	c3.r = (ft_lst_size(&(*pile_b))) - c3.j;
	return (c3.r + c3.i);
}

int	calcul_coups4(t_pile **pile_a, t_pile **pile_b, t_pile *pos_a,
		t_pile *pos_b)
{
	t_cp c4;

	asign_cp(&c4, &(*pile_a), &(*pile_b));
	while (c4.tmp)
	{
		c4.i++;
		if (c4.tmp == pos_a)
			break ;
		c4.tmp = c4.tmp->next;
	}
	c4.i--;
	while (c4.tmp2)
	{
		c4.j++;
		if (c4.tmp2 == pos_b)
			break ;
		c4.tmp2 = c4.tmp2->next;
	}
	c4.j--;
	if (c4.i == 0)
		return (c4.j);
	c4.r = (ft_lst_size(&(*pile_a))) - c4.i;
	return (c4.r + c4.j);
}

void	utils_coups1(t_cp *c1, t_pile *pos_a, t_pile *pos_b)
{
	while (c1->tmp)
	{
		c1->i++;
		if (c1->tmp == pos_a)
			break ;
		c1->tmp = c1->tmp->next;
	}
	c1->i--;
	while (c1->tmp2)
	{
		c1->j++;
		if (c1->tmp2 == pos_b)
			break ;
		c1->tmp2 = c1->tmp2->next;
	}
	c1->j--;
}

int	calcul_coups1(t_pile **pile_a, t_pile **pile_b, t_pile *pos_a,
		t_pile *pos_b)
{
	t_cp	c1;

	asign_cp(&c1, &(*pile_a), &(*pile_b));
	utils_coups1(&c1, &(*pos_a), &(*pos_b));
	if (c1.i == 0)
		return (c1.j);
	if (c1.j >= c1.i)
	{
		c1.r = c1.j - c1.i;
		return (c1.r + c1.i);
	}
	else
	{
		c1.r = c1.i - c1.j;
		return (c1.r + c1.j);
	}
}