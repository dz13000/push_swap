#include "../push_swap.h"

void	rotate_b(t_pile **pile_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	if (!(*pile_b))
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
	write(1, "rb\n", 3);
}

void	rr(t_pile **pile_a, t_pile **pile_b)
{
	rotate_a(&(*pile_a));
	rotate_b(&(*pile_b));
}

void	reverse_rotate_a(t_pile **pile_a)
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
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_pile **pile_b)
{
	t_pile	*tmp;
	t_pile	*tmp2;
	t_pile	*tmp3;

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
	write(1, "rrb\n", 4);
}

void	rrr(t_pile **pile_a, t_pile **pile_b)
{
	reverse_rotate_a(&(*pile_a));
	reverse_rotate_b(&(*pile_b));
}