/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/08/30 13:19:44 by kperreau          #+#    #+#             */
/*   Updated: 2014/08/31 18:18:19 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	backup_a;

	if (*b != 0)
	{
		backup_a = *a;
		*a /= *b;
		*b = backup_a % *b;
	}
}
