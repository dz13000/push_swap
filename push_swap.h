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
	int				lis;
	int				*tab;
	int				count;
	int				daron;
	int				up_a;
	int				up_b;
	int				down_a;
	int				down_b;
	int				total_coups;
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
	int				*tab;
}					t_lis;
//lis
void				lis(t_pile **pile_a, t_pile **pile_b);
void				def_lis(t_pile **pile_a);
void				init_lis(t_pile **pile_a);
int					max_lis(t_pile **pile_a);
int					verif_lis(t_pile **pile_a, int i);
void				value_lis(t_pile **pile_a, int lis_max);
void				pre_tri(t_pile **pile_a, t_pile **pile_b);
void				pre_tab(t_pile **pile_a, t_lis *lis, int lis_max);
int					verif_count(t_pile **pile_a);
void				init_count(t_pile **pile_a);

//tri
typedef struct s_coups
{
	int up;
	int down;
}				t_coups;

typedef struct s_cc
{
	int cc1;
	int cc2;
	int cc3;
	int cc4;
}				t_cc;

void				tri(t_pile **pile_a, t_pile **pile_b);
void				ft_daron(t_pile **pile_a, t_pile **pile_b);
void				init_daron(t_pile **pile_b);
int					max_pile(t_pile **pile);
int					min_pile(t_pile **pile);
#endif