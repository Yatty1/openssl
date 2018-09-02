/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:29:57 by syamada           #+#    #+#             */
/*   Updated: 2018/09/01 17:12:46 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
** check all cases
** if s appears, check if there are any characters after s.
** if there are any, take position of s and take characters after s,
** and put it into begining of new 2d argv array.
** if there are no such characters or no s, just create new 2d array.
*/

static int	is_md_option(char c)
{
	if (c == 'p' || c == 'q' || c == 'r' || c == 's')
		return (1);
	return (0);
}

static char	**convert_argv(int argc, char **argv, char **new, int i)
{
	while (i < argc)
		new[i++] = ft_strdup(*argv++);
	new[i] = 0;
	return (new);
}

static char	**create_argv(int argc, char **argv, int *op)
{
	char	**new;
	int		i;
	int		len;

	i = 0;
	new = (char **)malloc(sizeof(char *) * (argc + 1));
	while (argv[i] && argv[i][0] == '-')
	{
		if ((len = ft_strchr_i(argv[i], 's')) > 0 && argv[i][len + 1] != '\0')
		{
			new[0] = ft_strdup(argv[i] + len + 1);
			break ;
		}
		i++;
		if (len)
		{
			len = 0;
			break ;
		}
	}
	argv += (MATCH(*op, FLS) && len) ? i + 1 : i;
	i = !len ? 0 : 1;
	return (convert_argv(argc, argv, new, i));
}

int			validate_option(char **argv, int (*validator)(char),
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
				return (msg("md5", ft_strdup(argv[i] + j)));
			j++;
		}
		i++;
	}
	return (1);
}

char		**check_mdop(int argc, char **argv, int *op)
{
	int		i;
	int		len;

	i = 0;
	if (!*argv)
		return (argv);
	if (!validate_option(argv, &is_md_option, &illegal_op_md))
		return (NULL);
	while (argv[i] && argv[i][0] == '-')
	{
		if ((len = ft_strchr_i(argv[i], 's')) > 0)
			*op |= FLS;
		len = len ? len : ft_strlen(argv[i]);
		*op |= ft_strnstr(argv[i], "p", len) ? FLP : 0;
		*op |= ft_strnstr(argv[i], "q", len) ? FLQ : 0;
		*op |= ft_strnstr(argv[i], "r", len) ? FLR : 0;
		if (MATCH(*op, FLS))
			break ;
		i++;
	}
	if (MATCH(*op, FLS))
		argc -= (argv[i][len + 1] != '\0') ? i : i + 1;
	else
		argc -= i;
	return (create_argv(argc, argv, op));
}
