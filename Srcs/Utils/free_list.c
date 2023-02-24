/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 10:59:58 by clorcery          #+#    #+#             */
/*   Updated: 2022/07/22 11:49:38 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

void	free_lst(t_dlist **lst)
{
	t_dlist	*tmp;
	t_dlist	*buf;

	tmp = *lst;
	if (*lst == NULL)
		return ;
	while (tmp != NULL)
	{
		buf = tmp->next;
		free(tmp);
		tmp = buf;
	}
	*lst = NULL;
}

void	free_lsts(t_stacks *stack)
{
	free_lst(&stack->a.first);
	free_lst(&stack->b.first);
}
