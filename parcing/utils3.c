#include "../push_swap.h"

void	ft_free2(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return ;
}

void	free_pile(t_pile **pile)
{
	t_pile	*tmp;
	t_pile	*tmp2;

	tmp = (*pile);
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}

int	ft_lst_size(t_pile **pile)
{
	t_pile *size;
	int i;

	size = (*pile);
	i = 0;
	while (size)
	{
		size = size->next;
		i++;
	}
	return (i);
}