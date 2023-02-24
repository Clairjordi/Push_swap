/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:31:49 by clorcery          #+#    #+#             */
/*   Updated: 2022/08/03 15:04:46 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stack;	

	if (check_argc(argc, ++argv) == 1)
		ft_error("");
	else
	{
		recup_list(argv, argc, &stack);
		if ((verif_sort(&stack, 'a')) == 1)
		{
			free_lsts(&stack);
			exit (0);
		}
		if (stack.a.len < 6)
			push_swap_min(&stack);
		else if (stack.a.len <= 200)
			push_swap_moy(&stack);
		else
			push_swap_max(&stack);
		free_lsts(&stack);
	}
	return (0);
}
