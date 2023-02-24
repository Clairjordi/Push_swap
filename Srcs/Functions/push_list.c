/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:14:39 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/22 19:44:19 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

static void	cut_push_a(t_stacks *stack, t_dlist *old_second_a)
{
	if (stack->a.len == 1)
	{
		stack->a.first = NULL;
		stack->a.last = NULL;
	}
	else
	{
		stack->a.first = old_second_a;
		old_second_a->prev = NULL;
	}
}

static void	cut_push_b(t_stacks *stack, t_dlist *old_second_b)
{
	if (stack->b.len == 1)
	{
		stack->b.first = NULL;
		stack->b.last = NULL;
	}
	else
	{
		stack->b.first = old_second_b;
		old_second_b->prev = NULL;
	}
}

void	push_b(t_stacks *stack, int print)
{
	t_dlist	*old_first_a;
	t_dlist	*old_second_a;
	t_dlist	*old_first_b;
	t_dlist	*tmp;

	if (stack->a.first == NULL )
		return ;
	old_first_a = stack->a.first;
	old_second_a = stack->a.first->next;
	if (stack->b.len > 0)
		old_first_b = stack->b.first;
	ft_dlstadd_front(&stack->b.first, old_first_a);
	if (stack->b.len > 0)
		old_first_b->prev = old_first_a;
	cut_push_a(stack, old_second_a);
	tmp = stack->b.first;
	stack->b.last = ft_dlstlast(tmp);
	stack->a.len--;
	stack->b.len++;
	print_instructions("pb\n", print);
}

void	push_a(t_stacks *stack, int print)
{
	t_dlist	*old_first_b;
	t_dlist	*old_second_b;
	t_dlist	*old_first_a;
	t_dlist	*tmp;

	if (stack->b.first == NULL )
		return ;
	old_first_b = stack->b.first;
	old_second_b = stack->b.first->next;
	if (stack->a.len > 0)
		old_first_a = stack->a.first;
	ft_dlstadd_front(&stack->a.first, old_first_b);
	if (stack->a.len > 0)
		old_first_a->prev = old_first_b;
	cut_push_b(stack, old_second_b);
	tmp = stack->a.first;
	stack->a.last = ft_dlstlast(tmp);
	stack->b.len--;
	stack->a.len++;
	print_instructions("pa\n", print);
}
