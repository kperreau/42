/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:40:01 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/10 19:51:43 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "stdio.h"

void		ft_push_swap(char **tab, int n);
int			ft_isnumbers(char **tab, int n);
int			ft_isdouble(int *a, int size, int value);
void		ft_calc(int *a, int *b, int n, int debug);
void		ft_rotate(int *pile, int n, int display);
void		ft_push_b(int *a, int *b, int pb);
void		ft_push_a(int *a, int *b, int pa);

#endif
