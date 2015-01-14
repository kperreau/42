/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 21:10:58 by kperreau          #+#    #+#             */
/*   Updated: 2015/01/14 22:20:44 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# define FT_PARSE "hljz-+ #.*"
# define FT_TYPES "sSpdDioOuUxXcC"
# define FT_MODIF "hljz"
# define FT_FLAGS "-+ #"
# define FT_HEX "abcdef"

typedef struct	s_options
{
	int	flags;
	int	len;
	int	precise;
	int	modif;
	int	type;
	int	zero;
}				t_options;

typedef struct	s_vars
{
	va_list		ap;
	int			(*f[14])(t_options *, va_list *, int *);
	int			ret;
}				t_vars;

/*
**Fonctions Main
*/
int				ft_printf(const char *format, ...);
void			ft_parse(char *str, int len, t_vars *vars);
int				ft_dectohex(char *hex, unsigned long n, int up);
unsigned long	ft_dectooctal(char *oct, unsigned long n);
void			ft_putnbrul(unsigned long n);
void			ft_putspace(t_options *opt, int len, long long n);
void			ft_putzero(t_options *opt, int len);
void			ft_putsigned(int flags, long long n);
int				ft_nbrlen2(unsigned long n);
int				ft_zero(char *s1);
int				ft_searchpoint(char *str, int len);
int				ft_utfclen(int c);
int				ft_to_utf8(int c, int bytes, unsigned char *mask);
int				ft_utflen(wchar_t *s);

/*
**Fonctions Parse Types
*/
int				ft_sub(char *str);
int				ft_len(char *str, int len, va_list *ap);
int				ft_precise(char *str, int len, va_list *ap);
int				ft_modif(char *str, int len);
int				ft_flag(char *s1, char *s2, int len);

/*
**Fonctions Types
*/
int				ft_s(t_options *opt, va_list *ap, int *ret);
int				ft_s2(t_options *opt, va_list *ap, int *ret);
int				ft_d(t_options *opt, va_list *ap, int *ret);
int				ft_d2(t_options *opt, va_list *ap, int *ret);
int				ft_c(t_options *opt, va_list *ap, int *ret);
int				ft_c2(t_options *opt, va_list *ap, int *ret);
int				ft_p(t_options *opt, va_list *ap, int *ret);
int				ft_x(t_options *opt, va_list *ap, int *ret);
int				ft_x2(t_options *opt, va_list *ap, int *ret);
int				ft_o(t_options *opt, va_list *ap, int *ret);
int				ft_o2(t_options *opt, va_list *ap, int *ret);
int				ft_u(t_options *opt, va_list *ap, int *ret);
int				ft_u2(t_options *opt, va_list *ap, int *ret);

#endif
