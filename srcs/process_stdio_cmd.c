/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_stdio.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:05:35 by syamada           #+#    #+#             */
/*   Updated: 2018/08/30 14:12:49 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	process_stdio_cmd(void)
{
	char	*line;

	line = NULL;
	ft_putstr("FT_SSL> ");
	while (get_next_line(0, &line) > 0)
	{
		ft_putstr("FT_SSL> ");
	}
	exit(0);
}
