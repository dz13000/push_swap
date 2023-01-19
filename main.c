#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ft_parcing(ac, av))
		return (0);
	t_pile *pile_a = 0;
	pile_a = ft_def_pile_a(ac, av);
	
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