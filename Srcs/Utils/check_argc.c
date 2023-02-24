/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorcery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:39:07 by clorcery          #+#    #+#             */
/*   Updated: 2022/08/04 15:28:39 by clorcery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/push_swap.h"

char	*ft_strjoin_space(char *s1, char *s2, int k)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i++] = ' ';
	j = 0;
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	if (k > 1)
		free(s1);
	return (dest);
}

long long	ft_atoll_p(const char *nptr)
{
	long long	i;
	long int	reponse;
	int			nb;

	i = 0;
	reponse = 0;
	nb = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			nb *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		reponse = reponse * 10;
		reponse = reponse + nptr[i] - '0';
		if (reponse * nb > 2147483647 || reponse * nb < -2147483648)
			return (2147483666);
		i++;
	}
	return (reponse * nb);
}

static int	check_argc_multi(int ac, char **av)
{	
	int		j;
	char	*str;

	j = 1;
	while (av[j])
	{
		if (j == 1)
		{
			str = ft_strjoin_space(av[0], av[j], j);
		}
		else
			str = ft_strjoin_space(str, av[j], j);
		j++;
	}
	if (check_argv(str, ac) == 1)
		return (1);
	return (0);
}

static int	check_space(char **av)
{
	int	i;
	int	j;

	j = 0;
	while (av[j] != NULL)
	{
		i = 0;
		if (av[j][i] == '\0')
			return (1);
		while (av[j][i] == ' ')
		{
			if (av[j][i + 1] == '\0')
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	check_argc(int ac, char **av)
{
	if (ac < 2)
		exit(0);
	if (av[0][0] == '\0')
		return (1);
	else if (ac == 2)
	{
		if (check_argv(av[0], ac) == 1)
			return (1);
	}
	else
	{
		if (check_space(av) == 1)
			return (1);
		if (check_argc_multi(ac, av) == 1)
			return (1);
	}
	return (0);
}
