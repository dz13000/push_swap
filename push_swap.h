#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//Parcing
typedef struct s_tab
{
	int				*tab;
}					t_tab;

int					verif_arg(char **str);
int					ft_isdigit(char c);
int					check_space(char **str);
void				ft_putstr_fd(char *s, int fd);
void				ft_putchar_fd(char c, int fd);
int					ft_parcing(int av, char **ac);
int					verif_int(char **av, int ac, t_tab *tab);
long int			ft_atoi_long(char *str);
int					check_doubles(t_tab *tab, int ac);
int					verif_tri(t_tab *tab, int ac);
int					verif_2args(char **av, t_tab *tab2);
char				**ft_split(char const *s, char c);
int					verif_int2(char **av);
int					count_tab2(char **tab);
int					count_tab(char **tab, t_tab *tab2);
int					check_doubles2(int *tab, int ac);
int					verif_tri2(int *tab, int ac);
void				ft_free2(char **tab);

//Init Pile a

typedef struct s_pile
{
	int				nb;
	struct s_pile	*next;
}					t_pile;

t_pile				*ft_def_pile_a(int ac, char **av);
void				free_pile(t_pile **pile);
void				ft_lstadd_front(t_pile **pile_a, t_pile *new);
t_pile				*ft_lst_new(int nb);
int					ft_atoi(char *str);
int					*def_tab(char **av, int *size);
int					*def_tab2(char **av, int *size);
void				ft_lstadd_back(t_pile *lst, t_pile *new);
int					ft_lst_size(t_pile **pile);

// Moves
void				swap(t_pile *pile_a, t_pile *pile_b, char c);
void				push_b(t_pile **pile_a, t_pile **pile_b);
void				push_a(t_pile **pile_a, t_pile **pile_b);
void				rotate_a(t_pile **pile_a);
void				rotate_b(t_pile **pile_b);
void				rr(t_pile **pile_a, t_pile **pile_b);
void				reverse_rotate_a(t_pile **pile_a);
void				reverse_rotate_b(t_pile **pile_b);
void				rrr(t_pile **pile_a, t_pile **pile_b);

// Algo

typedef struct s_lis
{
	int				size;
	int				*tab;
}					t_lis;

void				lis(t_pile **pile_a, t_pile **pile_b);

#endif