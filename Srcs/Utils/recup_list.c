/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:00:41 by clorcery          #+#    #+#             */
/*   Updated: 2022/08/04 15:27:16 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	init_lst(t_stacks *stack)
{
	stack->a.first = NULL;
	stack->a.last = NULL;
	stack->a.len = 0;
	stack->b.first = NULL;
	stack->b.last = NULL;
	stack->b.len = 0;
}

void	free_str(char **tab, char *str)
{
	free (str);
	ft_free_tab_char(tab);
}

void	recup_list(char **av, int argc, t_stacks *stack)
{
	char	**tab;
	char	*str;
	int		j;

	j = 1;
	if (argc == 2)
	{
		tab = ft_split(av[0], ' ');
		create_list(tab, stack);
		ft_free_tab_char(tab);
	}
	else
	{
		while (av[j])
		{
			if (j == 1)
				str = ft_strjoin_space(av[0], av[j], j);
			else
				str = ft_strjoin_space(str, av[j], j);
			j++;
		}
		tab = ft_split(str, ' ');
		create_list(tab, stack);
		free_str(tab, str);
	}
}

void	create_list(char **av, t_stacks *stack)
{
	t_dlist	*new_elem;
	int		i;

	i = 1;
	init_lst(stack);
	stack->a.first = ft_dlstnew(ft_atoi(av[0]));
	stack->a.len++;
	while (av[i] != NULL)
	{
		new_elem = ft_dlstnew(ft_atoi(av[i]));
		ft_dlstadd_back(&stack->a.first, new_elem);
		i++;
		stack->a.len++;
	}
	stack->a.last = new_elem;
	stack->b.first = NULL;
}
