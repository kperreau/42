/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talmazov <talmazov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/03 08:53:59 by kperreau          #+#    #+#             */
/*   Updated: 2014/09/07 19:56:45 by talmazov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_valide(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
			return (0);
		i++;
	}
	if (i != 9)
		return (0);
	return (1);
}
