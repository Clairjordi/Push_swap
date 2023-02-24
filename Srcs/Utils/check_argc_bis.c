/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:25:24 by clorcery          #+#    #+#             */
/*   Updated: 2022/08/04 15:09:23 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

int	check_digit(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '-')
	{
		if (av[i + 1] == '\0')
			return (1);
		i++;
	}
	while (av[i])
	{
		if (av[i] == ' ')
			i++;
		else if (ft_isdigit(av[i]) == 0)
			return (1);
		else
			i++;
	}
	return (0);
}

int	check_max_min(long long av)
{
	if (av >= -2147483648 && av <= 2147483647)
		return (0);
	return (1);
}

int	check_double(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (i != j && ft_atoll_p(av[i]) == ft_atoll_p(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_argv_bis(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != NULL)
	{
		if (check_digit(tmp[i]) == 1)
		{
			ft_free_tab_char(tmp);
			return (1);
		}
		if (check_max_min(ft_atoll_p(tmp[i])) == 1)
		{
			ft_free_tab_char(tmp);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_argv(char *av, int ac)
{
	char	**tmp;

	tmp = ft_split(av, ' ');
	if (ac > 2)
		free(av);
	if (!tmp[0])
	{
		ft_free_tab_char(tmp);
		return (1);
	}
	if (check_argv_bis(tmp) == 1)
		return (1);
	if (check_double(tmp) == 1)
	{
		ft_free_tab_char(tmp);
		return (1);
	}
	ft_free_tab_char(tmp);
	return (0);
}
