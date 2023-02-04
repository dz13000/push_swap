/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:43:39 by cabouzir          #+#    #+#             */
/*   Updated: 2023/02/04 11:53:18 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if ((j != 0 && str[i][j] == '-') || (str[i][j] == ' '))
				return (1);
			if (str[i][j] != ' ' && str[i][j] != '-'
				&& ft_isdigit(str[i][j]) == 0)
				return (1);
			else if (str[i][j] == '-' && !(str[i][j + 1] >= '0' && str[i][j
						+ 1] <= '9'))
				return (1);
			j++;
		}
		if (j == 0)
			exit(49);
		i++;
	}
	return (0);
}

int	verif_int(char **av, int ac, t_tab *tab)
{
	int			i;
	long int	nb;

	tab->tab = malloc(sizeof(int) * ac);
	if (!tab->tab)
		return (1);
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
	while (i < ac)
	{
		tmp = tab->tab[i];
		j = i + 1;
		while (j < ac)
		{
			if (tab->tab[j] == tmp)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	verif_tri(t_tab *tab, int ac)
{
	int	i;

	i = 1;
	if (ac == 2)
		return (0);
	while (i < ac - 1)
	{
		if (tab->tab[i] > tab->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_parcing(int ac, char **av)
{
	t_tab	tab;

	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (verif_arg(av))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (verif_int(av, ac, &tab))
		return (ft_putstr_fd("Error\n", 2), free(tab.tab), 1);
	if (check_doubles(&tab, ac))
		return (ft_putstr_fd("Error\n", 2), free(tab.tab), 1);
	if (verif_tri(&tab, ac) == 1)
	{
		free(tab.tab);
		exit(0);
	}
	if (ac == 2)
	{
		if (verif_2args(av, &tab))
			return (ft_putstr_fd("Error\n", 2), free(tab.tab), 1);
	}
	return (free(tab.tab), 0);
}
