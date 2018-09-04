/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:29:13 by syamada           #+#    #+#             */
/*   Updated: 2018/09/03 16:37:49 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int			validate_option(char **argv, char *cmd, int (*validator)(char),
							int (*msg)(char *, char *))
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (argv[i] && argv[i][0] == '-')
	{
		j = 1;
		len = ft_strchr(argv[i], 's') ?
			ft_strchr_i(argv[i], 's') : ft_strlen(argv[i]);
		while (j < len)
		{
			if (!validator(argv[i][j]))
				return (msg(cmd, ft_strdup(argv[i] + j)));
			j++;
		}
		i++;
	}
	return (1);
}
