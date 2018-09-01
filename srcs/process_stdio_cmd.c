/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_stdio.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:05:35 by syamada           #+#    #+#             */
/*   Updated: 2018/09/01 13:26:03 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	process_stdio_cmd(void)
{
	char	*line;

	line = NULL;
	ft_putstr_fd("FT_SSL> ", 1);
	while (get_next_line(0, &line) > 0)
	{
		//parse with strsplit
		//pass to the same function as I do to normal thing
		ft_putendl(line);
		ft_strdel(&line);
		ft_putstr_fd("FT_SSL> ", 1);
	}
	exit(0);
}
