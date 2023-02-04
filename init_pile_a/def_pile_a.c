/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def_pile_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:42:57 by cabouzir          #+#    #+#             */
/*   Updated: 2023/02/04 12:10:34 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	def2(char **av, t_pile **res)
{
	int		*tab;
	int		size;
	int		j;
	t_pile	*new;

	size = 0;
	tab = def_tab2(av, &size);
	j = 0;
	(*res) = ft_lst_new(tab[j]);
	j++;
	while (j < size - 1)
	{
		new = ft_lst_new(tab[j]);
		if (!new)
		{
			free_pile(&(*res));
			exit(1);
		}
		ft_lstadd_back(*res, new);
		j++;
	}
	free(tab);
}

void	def(char **av, t_pile **res)
{
	int		size;
	int		*tab;
	int		j;
	t_pile	*new;

	size = 0;
	tab = def_tab(av, &size);
	j = 0;
	(*res) = ft_lst_new(tab[j]);
	j++;
	while (j < size)
	{
		new = ft_lst_new(tab[j]);
		if (!new)
		{
			free_pile(&(*res));
			exit(1);
		}
		ft_lstadd_back(*res, new);
		j++;
	}
	free(tab);
}

t_pile	*ft_def_pile_a(int ac, char **av)
{
	t_pile	*res;

	res = NULL;
	if (ac == 2)
		def(av, &res);
	else
		def2(av, &res);
	return (res);
}
