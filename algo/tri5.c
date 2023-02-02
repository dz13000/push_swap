#include "../push_swap.h"

void	utils_coups2(t_cp *c2, t_pile *pos_a, t_pile *pos_b)
{
	while (c2->tmp)
	{
		c2->i++;
		if (c2->tmp == pos_a)
			break ;
		c2->tmp = c2->tmp->next;
	}
	c2->i--;
	while (c2->tmp2)
	{
		c2->j++;
		if (c2->tmp2 == pos_b)
			break ;
		c2->tmp2 = c2->tmp2->next;
	}
	c2->j--;
}

int	calcul_coups2(t_pile **pile_a, t_pile **pile_b, t_pile *pos_a,
		t_pile *pos_b)
{
	t_cp c2;

	asign_cp(&c2, &(*pile_a), &(*pile_b));
	utils_coups2(&c2, &(*pos_a), &(*pos_b));
	if (c2.i == 0 && c2.j == 0)
		return (0);
	if (c2.i == 0)
		return (ft_lst_size(&(*pile_a)) - c2.j);
	if (c2.j == 0)
		return (ft_lst_size(&(*pile_a)) - c2.i);
	c2.temp = ft_lst_size(&(*pile_a)) - c2.i;
	c2.i = c2.temp;
	c2.temp = ft_lst_size(&(*pile_b)) - c2.j;
	c2.j = c2.temp;
	if (c2.j >= c2.i)
	{
		c2.r = c2.j - c2.i;
		return (c2.r + c2.i);
	}
	else
	{
		c2.r = c2.i - c2.j;
		return (c2.r + c2.j);
	}
}