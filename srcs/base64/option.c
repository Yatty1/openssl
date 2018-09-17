/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:51:28 by syamada           #+#    #+#             */
/*   Updated: 2018/09/16 18:42:09 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int	is_base_option(char c)
{
	if (c == 'd' || c == 'e' || c == 'i' || c == 'o')
		return (1);
	return (0);
}

char		**check_base64op(int argc, char **argv, int *op)
{
	int		i;

	i = 0;
	if (!*argv || argv[i][0] != '-' || ft_strequ(argv[i], "-"))
		return (argv);
	if (!validate_option(argv, "base64", &is_base_option,
								&illegal_op_base64))
		return (NULL);
	while (argv[i] && argv[i][0] == '-' && !ft_strequ(argv[i], "-"))
	{
		*op |= ft_strchr(argv[i], 'd') ? FLD : 0;
		*op |= ft_strchr(argv[i], 'e') ? FLE : 0;
		*op |= ft_strchr(argv[i], 'i') ? FLI : 0;
		*op |= ft_strchr(argv[i], 'o') ? FLO : 0;
		i++;
	}
	argv += i;
	return (argv);
}
