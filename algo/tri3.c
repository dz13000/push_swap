#include "../push_swap.h"

void	up2(t_pile **pile_a, t_pile **pile_b, t_pile *pos_b)
{
	while (pos_b->up_a > 0 && pos_b->up_b > 0)
	{
		rr(&(*pile_a), &(*pile_b));
		pos_b->up_a--;
		pos_b->up_b--;
		nombre++;
	}
}

void	down2(t_pile **pile_a, t_pile **pile_b, t_pile *pos_b)
{
	while (pos_b->down_a > 0 && pos_b->down_b > 0)
	{
		rrr(&(*pile_a), &(*pile_b));
		pos_b->down_a--;
		pos_b->down_b--;
		nombre++;
	}
}

void	up_pa(t_pile **pile_a, t_pile *pos_b)
{
	while (pos_b->up_a > 0)
	{
		rotate_a(&(*pile_a));
		pos_b->up_a--;
		nombre++;
	}
}

void	up_pb(t_pile **pile_b, t_pile *pos_b)
{
	while (pos_b->up_b > 0)
	{
		rotate_b(&(*pile_b));
		pos_b->up_b--;
		nombre++;
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
		nombre++;
	}
	while (pos_b->down_a > 0)
	{
		reverse_rotate_a(&(*pile_a));
		pos_b->down_a--;
		nombre++;
	}
	while (pos_b->down_b > 0)
	{
		reverse_rotate_b(&(*pile_b));
		pos_b->down_b--;
		nombre++;
	}
	push_a(&(*pile_a), &(*pile_b));
	nombre++;
}