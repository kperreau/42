/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 16:44:31 by kperreau          #+#    #+#             */
/*   Updated: 2015/02/12 18:26:08 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_init_tofind(char **tofind)
{
	tofind[0] = CMD_1;
	tofind[1] = CMD_2;
	tofind[2] = CMD_3;
	tofind[3] = CMD_4;
	tofind[4] = CMD_5;
	tofind[5] = '\0';
}

static void		ft_init_f(t_pfunc f)
{
	f[0] = ft_cmd_bin;
	f[1] = ft_cmd_exit;
	f[2] = ft_cmd_env;
	f[3] = ft_cmd_setenv;
	f[4] = ft_cmd_unsetenv;
	f[5] = ft_cmd_cd;
}

static int		ft_find_func(char *cmd)
{
	int		i;
	char	*tofind[NBRCMD];

	ft_init_tofind(tofind);
	i = 0;
	while (tofind[i])
	{
		if (!ft_strcmp(tofind[i++], cmd))
			return (i);
	}
	return (0);
}

int				ft_parse_stdin(char *line, t_list **lenv)
{
	char	**cmd;
	char	**cmds;
	int		i;
	t_pfunc	f;

	ft_init_f(f);
	cmds = ft_strsplit(line, ';');
	i = 0;
	while (cmds[i])
	{
		cmd = ft_splitword(cmds[i]);
		if (!cmd || !*cmd)
			return (0);
		(f[ft_find_func(*cmd)])(cmd, lenv);
		++i;
		ft_freetab(cmd);
	}
	ft_freetab(cmds);
	return (0);
}

int				ft_shell(t_list **lenv)
{
	char	*line;
	int		ret;

	while (1)
	{
		write(1, "$> ", 3);
		while ((ret = get_next_line(0, &line)) == -1)
			;
		if (!ret)
		{
			write(1, "logout\n", 7);
			return (0);
		}
		ft_parse_stdin(line, lenv);
		free(line);
	}
	return (0);
}
