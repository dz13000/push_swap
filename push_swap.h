#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//Parcing

typedef struct s_tab
{
	int		*tab;
}			t_tab;

int			verif_arg(char **str);
int			ft_isdigit(char c);
int			check_space(char **str);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_parcing(int av, char **ac);
int			verif_int(char **av, int ac, t_tab *tab);
long int	ft_atoi_long(char *str);
int			check_doubles(t_tab *tab, int ac);

#endif