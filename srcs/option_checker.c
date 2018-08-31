/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:29:57 by syamada           #+#    #+#             */
/*   Updated: 2018/08/30 21:25:50 by syamada          ###   ########.fr       */
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

static int	is_valid_option(char c)
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

static char	**create_argv(int argc, char **argv, int *mdop)
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
	argv += (MATCH(*mdop, FLS) && len) ? i + 1 : i;
	i = !len ? 0 : 1;
	return (convert_argv(argc, argv, new, i));
}

/*
** IDEA:
** make this function below resuable by passing 
** function as parameter.
** one for validation the other for printing error msg
*/

void		check_valid_option(char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[i] && argv[i][0] == '-')
	{
		j = 1;
		while (argv[i][j])
		{
			if (!is_valid_option(argv[i][j]))
				illegal_op_md("md5", ft_strdup(argv[i] + j));
			j++;
		}
		i++;
	}
}

char		**check_mdop(int argc, char **argv, int *mdop)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!*argv)
		return (argv);
	check_valid_option(argv);
	while (argv[i] && argv[i][0] == '-')
	{
		if ((len = ft_strchr_i(argv[i], 's')) > 0)
			*mdop |= FLS;
		len = len ? len : ft_strlen(argv[i]);
		*mdop |= ft_strnstr(argv[i], "p", len) ? FLP : 0;
		*mdop |= ft_strnstr(argv[i], "q", len) ? FLQ : 0;
		*mdop |= ft_strnstr(argv[i], "r", len) ? FLR : 0;
		if (MATCH(*mdop, FLS))
			break ;
		i++;
	}
	if (MATCH(*mdop, FLS))
		argc -= (argv[i][len + 1] != '\0') ? i : i + 1;
	else
		argc -= i;
	return (create_argv(argc, argv, mdop));
}
