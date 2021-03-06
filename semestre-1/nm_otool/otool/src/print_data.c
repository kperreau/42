/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/22 17:06:57 by kperreau          #+#    #+#             */
/*   Updated: 2015/09/22 17:06:58 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "otool.h"

static void			print_head_data_64(struct section_64 *section, char *name,
		int print)
{
	if (print == 0)
		ft_printf("%s:\n", name);
	ft_printf("(%s,%s) section\n", section->segname, section->sectname);
	if (section->size != 0)
		ft_printf("%.16llx\t", section->addr);
}

static void			print_head_data(struct section *section, char *name,
		int print)
{
	if (print == 0)
		ft_printf("%s:\n", name);
	ft_printf("(%s,%s) section\n", section->segname, section->sectname);
	if (section->size != 0)
		ft_printf("%.8x\t", section->addr);
}

void				print_hex_data_64(char *ptr, struct section_64 *section,
		char *name, int print)
{
	int						k;
	char					c;
	struct mach_header		*h;

	h = (struct mach_header*)ptr;
	k = 0;
	print_head_data_64(section, name, print);
	while (k < (int)section->size)
	{
		c = *(ptr + (int)(section->offset) + k++);
		ft_printf("%.2hhx", c);
		if (k % 16 == 0 && k != (int)section->size)
			ft_printf(" \n%.16llx\t", section->addr + k);
		else
			ft_putchar(' ');
	}
	if (section->size != 0)
		ft_putchar('\n');
}

void				print_hex_data(char *ptr, struct section *section,
			char *name, int print)
{
	int		k;
	char	c;

	ft_printf("IN 32\n");
	k = 0;
	print_head_data(section, name, print);
	while (k < (int)section->size)
	{
		c = *(ptr + (int)(section->offset) + k++);
		ft_printf("%.2hhx", c);
		if (k % 16 == 0 && k != (int)section->size)
			ft_printf(" \n%.8x\t", section->addr + k);
		else
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
