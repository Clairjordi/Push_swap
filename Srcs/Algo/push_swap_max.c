/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:44:52 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/26 12:07:03 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	push_in_b_max(t_stacks *stack)
{
	t_dlist	*tmp_a;
	int		nb_n_min;
	int		place;
	int		i;

	tmp_a = stack->a.first;
	nb_n_min = find_n_min(stack, 7);
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

void	push_in_b_max_bis(t_stacks *stack)
{
	t_dlist	*tmp_a;
	int		nb_n_min;
	int		place;
	int		i;

	tmp_a = stack->a.first;
	nb_n_min = find_n_min(stack, stack->a.len / 6 * 11 / 36);
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

void	sort_b_max(t_stacks *stack)
{
	t_dlist	*tmp_b;
	int		place;

	tmp_b = stack->b.first;
	place = 0;
	while (stack->a.len < (2 * stack->b.len))
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

void	push_swap_max(t_stacks *stack)
{
	while (stack->a.len > 7)
		push_in_b_max(stack);
	last_push_a(stack);
	sort_b_max(stack);
	last_push_b(stack);
	while (verif_sort(stack, 'a') == 0)
		push_in_b_max_bis(stack);
	while (stack->b.len > 0)
		sort_b(stack);
}
