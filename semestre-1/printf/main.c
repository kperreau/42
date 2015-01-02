/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:21:13 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/02 22:32:06 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		main(int argc, char **argv)
{
	t_flags		*flags;

	if (argc > 1)
		ft_parse(char argv[1]);
	return (0);
}
