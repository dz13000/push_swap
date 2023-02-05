/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:43:48 by cabouzir          #+#    #+#             */
/*   Updated: 2023/02/04 06:39:28 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (i < ac)
	{
		tmp = tab[i];
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
	int	i;

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
	if (check_doubles2(tab, count) || verif_tri2(tab, count))
		return (free(tab), 1);
	return (free(tab), 0);
}

int	verif_2args(char **av, t_tab *tab2)
{
	char	**tab;

	tab = ft_split(av[1], ' ');
	if (!tab)
		return (1);
	if (count_tab(tab, &*tab2))
		return (ft_free2(tab), 1);
	if (verif_arg2(av))
		return (ft_free2(tab), 1);
	if (verif_int2(tab))
		return (ft_free2(tab), 1);
	return (ft_free2(tab), 0);
}
