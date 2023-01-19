#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ft_parcing(ac, av))
		return (0);
	t_pile *pile_a = 0;
	t_pile *pile_b;

	pile_b = 0;
	pile_a = ft_def_pile_a(ac, av);
	// swap_a(pile_a);
	t_pile *ok;

	t_pile *test;
	test = ft_lst_new(0);
	ft_lstadd_front(&pile_a, test);
	ok = pile_a;
	// printf("MAIN ---->%d\n", pile_a->nb);
	while(ok)
	{
		printf("PILE A----->%d\n", ok->nb);
		ok = ok->next;
	}
	
	t_pile *ok2;
	ok2 = pile_b;
	while(ok2)
	{
		printf("PILE B----->%d\n", ok2->nb);
		ok2 = ok2->next;
	}
	t_pile *tmp;
	t_pile *tmp2;

	tmp = pile_a;
	while (tmp)
	{
		tmp2 = tmp -> next;
		free(tmp);
		tmp = tmp2;
	}
	return (0);
}