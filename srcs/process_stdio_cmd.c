/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_stdio.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:05:35 by syamada           #+#    #+#             */
/*   Updated: 2018/09/08 21:49:12 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		ft_tdstrlen(char **tdstr)
{
	int		i;

	i = 0;
	while (tdstr[i])
		i++;
	return (i);
}

void	process_stdio_cmd(void)
{
	char	*line;
	char	**input;

	line = NULL;
	ft_putstr("FT_SSL> ");
	while (get_next_line(0, &line) > 0)
	{
		if (line && *line)
		{
			input = ft_strsplit(line, ' ');
			dispatcher(ft_tdstrlen(input), input);
			ft_tdstrdel(&input);
		}
		ft_strdel(&line);
		ft_putstr("FT_SSL> ");
	}
	exit(0);
}
