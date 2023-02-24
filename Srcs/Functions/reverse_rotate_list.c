/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:04:23 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/22 19:45:12 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

static void	reverse_rotate_a(t_stacks *stack, int print)
{	
	t_dlist	*old_first;
	t_dlist	*old_last;

	old_first = stack->a.first;
	old_last = stack->a.last;
	old_last->prev->next = NULL;
	stack->a.last = old_last->prev;
	ft_dlstadd_front(&stack->a.first, old_last);
	old_first->prev = old_last;
	stack->a.first = old_last;
	print_instructions("rra\n", print);
}

static void	reverse_rotate_b(t_stacks *stack, int print)
{	
	t_dlist	*old_first;
	t_dlist	*old_last;

	old_first = stack->b.first;
	old_last = stack->b.last;
	old_last->prev->next = NULL;
	stack->b.last = old_last->prev;
	ft_dlstadd_front(&stack->b.first, old_last);
	old_first->prev = old_last;
	stack->b.first = old_last;
	print_instructions("rrb\n", print);
}

void	reverse_rotate(t_stacks *stack, char lst, int print)
{
	if (lst == 'a' && stack->a.first != NULL && stack->a.len > 1)
		reverse_rotate_a(stack, print);
	else if (lst == 'b' && stack->b.first != NULL && stack->b.len > 1)
		reverse_rotate_b(stack, print);
	else
		return ;
}

void	reverse_rotate_ab(t_stacks *stack)
{
	reverse_rotate(stack, 'a', 0);
	reverse_rotate(stack, 'b', 0);
	ft_printf("rrr\n");
}
