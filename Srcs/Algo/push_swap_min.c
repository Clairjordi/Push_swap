/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:36:37 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/22 19:43:14 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

static void	sort_3(t_stacks *stack)
{
	int	data_max;
	int	data_min;
	int	first_d;
	int	last_d;

	data_min = min_int(stack, 'a');
	data_max = max_int(stack, 'a');
	first_d = stack->a.first->data;
	last_d = stack->a.last->data;
	if (verif_sort(stack, 'a') == 1)
		return ;
	if (data_max == last_d
		|| (data_max == first_d && data_min == last_d)
		|| (data_min == first_d))
		swap(stack, 'a', 1);
	else if (data_min == last_d)
		reverse_rotate(stack, 'a', 1);
	else if (data_max == first_d)
		rotate(stack, 'a', 1);
	if (verif_sort(stack, 'a') == 0)
		sort_3(stack);
}

static void	sort_4(t_stacks *stack)
{
	t_dlist	*tmp_a;
	int		place;

	tmp_a = stack->a.first;
	place = 0;
	while (tmp_a)
	{
		if (tmp_a->data == min_int(stack, 'a'))
		{
			while (tmp_a != stack->a.first)
				what_rotate(stack, 'a', place);
			push_b(stack, 1);
			break ;
		}
		else
		{
			tmp_a = tmp_a->next;
			place++;
		}
	}
	sort_3(stack);
	push_a(stack, 1);
}

static void	sort_5(t_stacks *stack)
{
	t_dlist	*tmp_a;
	int		place;

	tmp_a = stack->a.first;
	place = 0;
	while (tmp_a)
	{
		if (tmp_a->data == min_int(stack, 'a'))
		{
			while (tmp_a != stack->a.first)
				what_rotate(stack, 'a', place);
			push_b(stack, 1);
			break ;
		}
		else
		{
			tmp_a = tmp_a->next;
			place++;
		}
	}
	sort_4(stack);
	push_a(stack, 1);
}

void	push_swap_min(t_stacks *stack)
{
	if (stack->a.len == 2)
		swap(stack, 'a', 1);
	else if (stack->a.len == 3)
		sort_3(stack);
	else if (stack->a.len == 4)
		sort_4(stack);
	else if (stack->a.len == 5)
		sort_5(stack);
}
