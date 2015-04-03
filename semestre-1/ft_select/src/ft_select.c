/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 18:13:04 by kperreau          #+#    #+#             */
/*   Updated: 2015/03/30 20:39:32 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		ft_reset_term(t_termios *term)
{
	char	*res;

	if (tcgetattr(0, term) == -1)
		return (-1);
	term->c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, term) == -1)
		return (-1);
	if ((res = tgetstr("cl", NULL)) == NULL)
		return (-1);
	tputs(res, 0, ft_my_outc);
	if ((res = tgetstr("ve", NULL)) == NULL)
		return (-1);
	tputs(res, 0, ft_my_outc);
	return (0);
}

static int		ft_init_term(t_termios *term, t_infos *infos)
{
	char	*res;

	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (ioctl(STDIN_FILENO,TIOCGWINSZ, (char*)&infos->size) < 0)
		ft_putstr_fd("Erreur TIOCGEWINSZ\n", 2);
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (-1);
	if ((res = tgetstr("cl", NULL)) == NULL)
		return (-1);
	tputs(res, 0, ft_my_outc);
	if ((res = tgetstr("vi", NULL)) == NULL)
		return (-1);
	tputs(res, 0, ft_my_outc);
	return (0);
}

void			ft_select(int argc, char **argv, t_infos *infos)
{
	int		key;

	if (ft_init_term(&infos->term, infos) != -1)
	{
		signal(SIGWINCH, ft_resize);
		infos->args = ft_args(argc, argv);
		ft_display(infos);
		while (1)
		{
			read(0, &key, sizeof(int));
			// printf("w: %d, h: %d\n", infos->size.ws_col, infos->size.ws_row);
			if (key == K_EXIT)
				break ;
			// printf("key: %d\n", key);
			key = 0;
		}
		ft_reset_term(&infos->term);
	}
}
