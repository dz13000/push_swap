#include "../push_swap.h"

int	verif_arg(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != ' ' && str[i][j] != '-'
				&& ft_isdigit(str[i][j]) == 0)
				return (1);
			else if (str[i][j] == '-' && !(str[i][j + 1] >= '0' && str[i][j
						+ 1] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	verif_int(char **av, int ac, t_tab *tab)
{
	int			i;
	long int	nb;

	tab->tab = malloc(sizeof(int) * ac);
	i = 0;
	nb = 0;
	while (av[i])
	{
		nb = ft_atoi_long(av[i]);
		tab->tab[i] = nb;
		if (nb > 2147483647 || nb < -2147483648)
			return (1);
		nb = 0;
		i++;
	}
	return (0);
}

int	check_doubles(t_tab *tab, int ac)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	tmp = 0;
	printf("%d", ac);
	ac -= 1;
	while (ac > 0)
	{
		tmp = tab->tab[i];
		printf("%d\n", tab->tab[i]);
		j = i + 1;
		while (tab->tab[j])
		{
			if (tab->tab[j] == tmp)
				return (1);
			j++;
		}
		i++;
		ac--;
	}
	return (0);
}

int	ft_parcing(int ac, char **av)
{
	t_tab		tab;

	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (verif_arg(av))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (verif_int(av, ac, &tab))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (check_doubles(&tab, ac))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	//free(tab.tab);
	return (0);
}
