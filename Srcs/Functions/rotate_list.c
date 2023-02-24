/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:51:59 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/22 11:48:21 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	rotate(t_stacks *stack, char lst, int print)
{
	t_dlist	*old_first;
	t_dlist	*old_second;

	if (lst == 'a' && stack->a.first != NULL && stack->a.len > 1)
	{
		old_second = stack->a.first->next;
		old_first = stack->a.first;
		ft_dlstadd_back(&stack->a.first, old_first);
		stack->a.last = old_first;
		stack->a.first = old_second;
		old_second->prev = NULL;
		print_instructions("ra\n", print);
	}
	else if (lst == 'b' && stack->b.first != NULL && stack->b.len > 1)
	{
		old_second = stack->b.first->next;
		old_first = stack->b.first;
		ft_dlstadd_back(&stack->b.first, old_first);
		stack->b.last = old_first;
		stack->b.first = old_second;
		old_second->prev = NULL;
		print_instructions("rb\n", print);
	}
	else
		return ;
}

void	rotate_ab(t_stacks *stack)
{
	rotate(stack, 'a', 0);
	rotate(stack, 'b', 0);
	ft_printf("rr\n");
}
