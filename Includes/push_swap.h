/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:42:39 by clorcery          #+#    #+#             */
/*   Updated: 2022/08/04 15:22:36 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../Libft/all_h.h"

typedef struct s_lst_info
{
	int		len;
	t_dlist	*first;
	t_dlist	*last;
}	t_lst;

typedef struct s_stacks
{
	t_lst	a;
	t_lst	b;

}	t_stacks;

//CHECK_ARGC
int			check_argc(int ac, char **av);
int			check_digit(char *av);
int			check_max_min(long long av);
int			check_double(char **av);
int			check_argv(char *av, int ac);
int			check_argv_bis(char **tmp);
char		*ft_strjoin_space(char *s1, char *s2, int k);
long long	ft_atoll_p(const char *nptr);

//RECUP_LIST
void		recup_list(char **av, int argc, t_stacks *stack);
void		create_list(char **av, t_stacks *stack);

//FUNCTIONS
void		swap(t_stacks *stack, char lst, int print);
void		swap_ab(t_stacks *stack);
void		rotate(t_stacks *stack, char lst, int print);
void		rotate_ab(t_stacks *stack);
void		reverse_rotate(t_stacks *stack, char lst, int print);
void		reverse_rotate_ab(t_stacks *stack);
void		push_a(t_stacks *stack, int print);
void		push_b(t_stacks *stack, int print);

//ALGO
void		push_swap_min(t_stacks *stack);
void		push_swap_moy(t_stacks *stack);
void		push_swap_max(t_stacks *stack);
void		sort_b(t_stacks *stack);

//UTILS
void		print_instructions(char *s, int p);
int			min_int(t_stacks *stack, char lst);
int			max_int(t_stacks *stack, char lst);
int			verif_sort(t_stacks *stack, char lst);
void		last_push_a(t_stacks *stack);
void		last_push_b(t_stacks *stack);

//UTILS_BIS
void		what_rotate(t_stacks *stack, char lst, int place);
int			find_n_min(t_stacks *stack, int nb);

//FREE
void		free_lsts(t_stacks *stack);
void		free_lst(t_dlist **lst);

#endif
