#include "../push_swap.h"

void	ft_free2(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return ;
}