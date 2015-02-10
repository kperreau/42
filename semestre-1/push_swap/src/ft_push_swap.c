/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 22:18:32 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/10 22:18:35 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_toint(char **tab, int *a, int n)
{
	long	temp;
	int		count;
	int		*begin;

	begin = a;
	count = 0;
	while (n--)
	{
		if (ft_strlen(*tab) > 11)
			return (-1);
		temp = ft_atoi(*tab++);
		if ((temp > 2147483647 || temp < -2147483647) ||
			(count && ft_isdouble(begin, count, temp)))
			return (-1);
		*a++ = (int)temp;
		++count;
	}
	return (0);
}

static int	ft_convert(char **tab, int *a, int n)
{
	if (!ft_isnumbers(tab, n) || ft_toint(tab, a, n) == -1)
		return (-1);
	return (0);
}

void		ft_push_swap(char **tab, int n)
{
	int		*a;
	int		*b;
	int		debug;

	debug = 0;
	if (!ft_strcmp(*tab, "-v"))
	{
		debug = 1;
		++tab;
		--n;
	}
	if (debug && n < 3)
	{
		write(2, "Error\n", 6);
		return ;
	}
	if ((a = (int*)malloc(sizeof(int) * n)) == NULL)
		return ;
	if ((b = (int*)malloc(sizeof(int) * n)) == NULL)
		return ;
	if (ft_convert(tab, a, n) != -1)
		ft_calc(a, b, n, debug);
	else
		write(2, "Error\n", 6);
}
