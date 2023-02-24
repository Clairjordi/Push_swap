/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:11:30 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/22 11:49:19 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	print_instructions(char *s, int p)
{
	if (p == 1)
		ft_printf("%s", s);
}

int	verif_sort(t_stacks *stack, char lst)
{
	t_dlist	*tmp;

	if (lst == 'a')
		tmp = stack->a.first;
	else if (lst == 'b')
		tmp = stack->b.first;
	while (tmp->next != NULL && tmp->data < tmp->next->data)
		tmp = tmp->next;
	if (tmp->next == NULL)
		return (1);
	return (0);
}

int	min_int(t_stacks *stack, char lst)
{
	int		m_int;
	int		tmp_data;
	t_dlist	*tmp;

	if (lst == 'a')
	{
		m_int = stack->a.first->data;
		tmp_data = stack->a.first->data;
		tmp = stack->a.first;
	}
	else if (lst == 'b')
	{
		m_int = stack->b.first->data;
		tmp_data = stack->b.first->data;
		tmp = stack->b.first;
	}
	while (tmp != NULL)
	{
		tmp_data = tmp->data;
		if (tmp_data < m_int)
			m_int = tmp_data;
		tmp = tmp->next;
	}
	return (m_int);
}

int	max_int(t_stacks *stack, char lst)
{
	int		m_int;
	int		tmp_data;
	t_dlist	*tmp;

	if (lst == 'a')
	{
		m_int = stack->a.first->data;
		tmp_data = stack->a.first->data;
		tmp = stack->a.first;
	}
	else if (lst == 'b')
	{
		m_int = stack->b.first->data;
		tmp_data = stack->b.first->data;
		tmp = stack->b.first;
	}
	while (tmp != NULL)
	{
		tmp_data = tmp->data;
		if (tmp_data > m_int)
			m_int = tmp_data;
		tmp = tmp->next;
	}
	return (m_int);
}
