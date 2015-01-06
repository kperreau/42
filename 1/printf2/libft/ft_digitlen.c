/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Kevin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 22:22:00 by Kevin             #+#    #+#             */
/*   Updated: 2015/01/04 22:35:13 by Kevin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digitlen(long n)
{
	if (n < 0)
		n = -n;
	return ((n > 9) ? ft_digitlen(n / 10) + 1 : 1);
}