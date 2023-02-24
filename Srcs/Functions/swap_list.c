/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:41:39 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/22 19:46:10 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

static t_dlist	*swap_lst(t_dlist *tmp, t_stacks *stack)
{
	t_dlist	*old_second;
	t_dlist	*old_first;

	old_first = tmp;
	old_second = tmp->next;
	old_first->next = old_second->next;
	old_first->prev = old_second;
	old_second->next = old_first;
	old_second->prev = NULL;
	if (stack->a.len > 2 || stack->b.len > 2)
		tmp->next->prev = tmp;
	return (old_second);
}

void	swap(t_stacks *stack, char lst, int print)
{
	t_dlist	*new_first;
	t_dlist	*tmp;

	if (lst == 'a' && stack->a.first != NULL && stack->a.len > 1)
		tmp = stack->a.first;
	else if (lst == 'b' && stack->b.first != NULL && stack->b.len > 1)
		tmp = stack->b.first;
	else
		return ;
	new_first = swap_lst(tmp, stack);
	if (lst == 'a')
	{
		stack->a.first = new_first;
		print_instructions("sa\n", print);
	}
	else if (lst == 'b')
	{
		stack->b.first = new_first;
		print_instructions("sb\n", print);
	}
}

void	swap_ab(t_stacks *stack)
{
	swap(stack, 'a', 0);
	swap(stack, 'b', 0);
	ft_printf("ss\n");
}
