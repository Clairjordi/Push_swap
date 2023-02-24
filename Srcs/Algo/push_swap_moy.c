/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:36:05 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/22 19:40:41 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	push_in_b(t_stacks *stack)
{
	t_dlist	*tmp_a;
	int		nb_n_min;
	int		place;
	int		i;

	tmp_a = stack->a.first;
	nb_n_min = find_n_min(stack, 3);
	place = 0;
	i = stack->a.len;
	while (i-- > 0)
	{
		if (tmp_a->data <= nb_n_min)
		{
			while (tmp_a != stack->a.first)
				what_rotate(stack, 'a', place);
			push_b(stack, 1);
			tmp_a = stack->a.first;
			place = 0;
		}
		else
		{	
			tmp_a = tmp_a->next;
			place++;
		}
	}
}

void	sort_b(t_stacks *stack)
{
	t_dlist	*tmp_b;
	int		place;

	tmp_b = stack->b.first;
	place = 0;
	while (tmp_b)
	{
		if (tmp_b->data == max_int(stack, 'b'))
		{
			while (tmp_b != stack->b.first)
				what_rotate(stack, 'b', place);
			push_a(stack, 1);
			tmp_b = stack->b.first;
			place = 0;
		}
		else
		{
			tmp_b = tmp_b->next;
			place++;
		}
	}
}

void	push_swap_moy(t_stacks *stack)
{
	t_dlist	*tmp_a;

	while (stack->a.len > 3)
		push_in_b(stack);
	if (stack->a.first != NULL)
	{
		tmp_a = stack->a.first;
		while (tmp_a != NULL)
		{
			push_b(stack, 1);
			tmp_a = stack->a.first;
		}
	}
	while (stack->b.len > 0)
		sort_b(stack);
}
