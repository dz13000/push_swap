/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabouzir <cabouzir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 04:44:09 by cabouzir          #+#    #+#             */
/*   Updated: 2023/02/05 05:47:55 by cabouzir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

//Parcing
typedef struct s_tab
{
	int				*tab;
}					t_tab;

int					verif_arg(char **str);
int					verif_arg2(char **str);
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
void				swap(t_pile **pile_a, t_pile **pile_b, char c);
void				push_b(t_pile **pile_a, t_pile **pile_b);
void				push_a(t_pile **pile_a, t_pile **pile_b);
void				rotate_a(t_pile **pile_a);
void				rotate_b(t_pile **pile_b);
void				rotate_1(t_pile **pile_b);
void				rotate_2(t_pile **pile_b);
void				reverse_rotate_1(t_pile **pile_a);
void				reverse_rotate_2(t_pile **pile_a);
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
	int				up;
	int				down;
}					t_coups;

typedef struct s_cc
{
	int				cc1;
	int				cc2;
	int				cc3;
	int				cc4;
	int				min;
	t_pile			*tmp;
	t_pile			*tmp2;
}					t_cc;

typedef struct s_cp
{
	t_pile			*tmp;
	t_pile			*tmp2;
	int				i;
	int				j;
	int				r;
	int				temp;
	int				tt;
}					t_cp;

void				tri(t_pile **pile_a, t_pile **pile_b);
void				ft_daron(t_pile **pile_a, t_pile **pile_b);
void				init_daron(t_pile **pile_b);
int					max_pile(t_pile **pile);
int					min_pile(t_pile **pile);
void				asign_cp(t_cp *c, t_pile **pile_a, t_pile **pile_b);
void				utils_coups1(t_cp *c1, t_pile *pos_a, t_pile *pos_b);
void				utils_coups2(t_cp *c2, t_pile *pos_a, t_pile *pos_b);
void				utils_cc1(t_cp *cc1, t_pile **pos_a, t_pile **pos_b);
int					calcul_coups1(t_pile **pile_a, t_pile **pile_b,
						t_pile *pos_a, t_pile *pos_b);
int					calcul_coups2(t_pile **pile_a, t_pile **pile_b,
						t_pile *pos_a, t_pile *pos_b);
int					calcul_coups3(t_pile **pile_a, t_pile **pile_b,
						t_pile *pos_a, t_pile *pos_b);
int					calcul_coups4(t_pile **pile_a, t_pile **pile_b,
						t_pile *pos_a, t_pile *pos_b);
void				asign_cc1(t_pile **pile_a, t_pile **pile_b, t_pile **pos_a,
						t_pile **pos_b);
void				asign_cc2(t_pile **pile_a, t_pile **pile_b, t_pile **pos_a,
						t_pile **pos_b);
void				asign_cc3(t_pile **pile_a, t_pile **pile_b, t_pile **pos_a,
						t_pile **pos_b);
void				asign_cc4(t_pile **pile_a, t_pile **pile_b, t_pile **pos_a,
						t_pile **pos_b);
void				up2(t_pile **pile_a, t_pile **pile_b, t_pile *pos_b);
void				down2(t_pile **pile_a, t_pile **pile_b, t_pile *pos_b);
void				up_pa(t_pile **pile_a, t_pile *pos_b);
void				up_pb(t_pile **pile_a, t_pile *pos_b);
int					ft_coups_bas(t_cc *cc);
void				calcul_prix(t_pile **pile_a, t_pile **pile_b);
void				calcul_prix2(t_cc *cc, t_pile **pile_a, t_pile **pile_b);
void				insertion(t_pile **pile_a, t_pile **pile_b, t_pile *pos_b);
int					minimum_coups(t_pile **pile_b);

// Algo de 2,3 et 5

void				algo_de2(t_pile **pile_a, t_pile **pile_b);
void				algo_de3v2(t_pile **pile_a, t_pile **pile_b);
void				algo_de3(t_pile **pile_a, t_pile **pile_b);
void				algo_de3_5v2(t_pile **pile_a, t_pile **pile_b);
void				algo_de3_5(t_pile **pile_a, t_pile **pile_b);
void				algo_de5(t_pile **pile_a, t_pile **pile_b);
void				ft_replace(t_pile **pile_a);

#endif