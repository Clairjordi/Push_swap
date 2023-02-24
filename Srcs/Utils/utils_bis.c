/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:22:58 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/26 11:57:48 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	what_rotate(t_stacks *stack, char lst, int place)
{
	int	middle;

	if (lst == 'a')
		middle = stack->a.len / 2;
	else if (lst == 'b')
		middle = stack->b.len / 2;
	if (place <= middle)
		rotate(stack, lst, 1);
	else
		reverse_rotate(stack, lst, 1);
}

int	find_n_min(t_stacks *stack, int nb)
{
	t_dlist	*tmp_a;
	int		new_min;
	int		old_min;
	int		n;

	n = stack->a.len / nb;
	old_min = min_int(stack, 'a');
	if (n == 1)
		return (old_min);
	while (--n > 0)
	{
		tmp_a = stack->a.first;
		new_min = max_int(stack, 'a');
		while (tmp_a)
		{
			if (old_min < tmp_a->data && new_min > tmp_a->data)
				new_min = tmp_a->data;
			tmp_a = tmp_a->next;
		}
		old_min = new_min;
	}
	return (new_min);
}

void	last_push_b(t_stacks *stack)
{
	t_dlist	*tmp_b;

	if (stack->b.first != NULL)
	{
		tmp_b = stack->b.first;
		while (tmp_b != NULL)
		{
			push_a(stack, 1);
			tmp_b = stack->b.first;
		}
	}	
}

void	last_push_a(t_stacks *stack)
{
	t_dlist	*tmp_a;

	if (stack->a.first != NULL)
	{
		tmp_a = stack->a.first;
		while (tmp_a != NULL)
		{
			push_b(stack, 1);
			tmp_a = stack->a.first;
		}
	}
}
