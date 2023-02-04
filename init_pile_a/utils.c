/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:43:06 by cabouzir          #+#    #+#             */
/*   Updated: 2023/02/04 06:29:42 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

int	*def_tab(char **av, int *size)
{
	char	**tab;
	int		*tab2;
	int		j;
	int		i;

	i = 0;
	tab = ft_split(av[1], ' ');
	while (tab[i])
		i++;
	tab2 = malloc(sizeof(int) * i);
	if (!tab2)
		exit(1);
	i = 0;
	j = 0;
	while (tab[i])
	{
		tab2[j] = ft_atoi(tab[i]);
		j++;
		i++;
	}
	ft_free2(tab);
	*size = i;
	return (tab2);
}

int	*def_tab2(char **av, int *size)
{
	int	*tab2;
	int	j;
	int	i;

	i = 1;
	while (av[i])
		i++;
	tab2 = malloc(sizeof(int) * i);
	if (!tab2)
		exit(1);
	i = 1;
	j = 0;
	while (av[i])
	{
		tab2[j] = ft_atoi(av[i]);
		j++;
		i++;
	}
	*size = i;
	return (tab2);
}

t_pile	*ft_lst_new(int nb)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		exit(1);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_pile *lst, t_pile *new)
{
	t_pile	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	tmp->next->next = NULL;
}
