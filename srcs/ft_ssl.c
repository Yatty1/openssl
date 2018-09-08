/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:46:55 by syamada           #+#    #+#             */
/*   Updated: 2018/09/07 22:43:03 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_cmd	g_cmd_table[CMD_NUM] = {
	{"md5", &process_md5},
	{"sha256", &process_sha256},
};

void	dispatcher(int argc, char **argv)
{
	int		i;

	i = 0;
	while (i < CMD_NUM)
	{
		if (ft_strequ(argv[0], g_cmd_table[i].name))
		{
			g_cmd_table[i].hash(--argc, ++argv);
			return ;
		}
		i++;
	}
	error_cmd(argv[0]);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		process_stdio_cmd();
	dispatcher(--argc, ++argv);
	return (0);
}
