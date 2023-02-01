#include "../push_swap.h"

void	ft_lstadd_front(t_pile **pile_a, t_pile *new)
{
	t_pile	*tmp;

	tmp = *pile_a;
	new->next = tmp;
	*pile_a = new;
}

void	swap(t_pile *pile_a, t_pile *pile_b, char c)
{
	int	tmp;

	if (c == 'a')
	{
		tmp = pile_a->next->nb;
		pile_a->next->nb = pile_a->nb;
		pile_a->nb = tmp;
		write(1, "sa\n", 3);
	}
	if (c == 'b')
	{
		tmp = pile_b->next->nb;
		pile_b->next->nb = pile_b->nb;
		pile_b->nb = tmp;
		write(1, "sb\n", 3);
	}
	if (c == '2')
	{
		swap(pile_a, pile_b, 'a');
		swap(pile_a, pile_b, 'b');
	}
}

void	push_b(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	if (!(*pile_a))
		return ;
	tmp = (*pile_a);
	if (!(*pile_b))
	{
		(*pile_b) = tmp;
		(*pile_a) = (*pile_a)->next;
		(*pile_b)->next = NULL;
	}
	else
	{
		(*pile_a) = (*pile_a)->next;
		tmp->next = (*pile_b);
		(*pile_b) = tmp;
	}
	write(1, "pb\n", 3);
}

void	push_a(t_pile **pile_a, t_pile **pile_b)
{
	t_pile	*tmp;

	if (!(*pile_b))
		return ;
	tmp = (*pile_b);
	if (!(*pile_a))
	{
		(*pile_a) = tmp;
		(*pile_b) = (*pile_b)->next;
		(*pile_a)->next = NULL;
	}
	else
	{
		(*pile_b) = (*pile_b)->next;
		tmp->next = (*pile_a);
		(*pile_a) = tmp;
	}
	write(1, "pa\n", 3);
}

void	rotate_a(t_pile **pile_a)
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
	write(1, "ra\n", 3);
}
