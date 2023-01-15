#include "../push_swap.h"

int	count_tab2(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	check_doubles2(int *tab, int ac)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	//printf("%d\n", ac - 1);
	while (i < ac)
	{
		tmp = tab[i];
		printf(">%d\n", tab[i]);
		j = i + 1;
		while (j < ac)
		{
			if (tab[j] == tmp)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	verif_tri2(int *tab, int ac)
{
	int i;

	i = 0;
	while (i < ac - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	verif_int2(char **av)
{
	int			i;
	int			count;
	int			*tab;
	long int	nb;

	count = count_tab2(av);
	tab = malloc(sizeof(int) * count);
	if (!tab)
		return (1);
	i = 0;
	nb = 0;
	while (av[i])
	{
		nb = ft_atoi_long(av[i]);
		tab[i] = nb;
		if (nb > 2147483647 || nb < -2147483648)
			return (1);
		nb = 0;
		i++;
	}
	if(check_doubles2(tab, count) || verif_tri2(tab, count))
		return(free(tab), 1);
	//free(tab);
	return (free(tab), 0);
}

int	verif_2args(char **av)
{
	char	**tab;

	// int		i;
	// i = 0;
	tab = ft_split(av[1], ' ');
	if (!tab)
		return (1);
	if (count_tab(tab))
		return (ft_free2(tab), 1);
	if (verif_arg(av))
		return (ft_free2(tab), 1);
	if (verif_int2(tab))
		return (ft_free2(tab), 1);
	return (0);
}