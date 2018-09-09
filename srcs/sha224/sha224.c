/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 22:43:59 by syamada           #+#    #+#             */
/*   Updated: 2018/09/08 21:45:36 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			sha224_encrypt_stdio(int op)
{
	char		*line;
	char		*str;
	t_sha256	*sha224;

	str = ft_strnew(1);
	while (get_next_line(0, &line) > 0)
	{
		line = ft_strappend(line, '\n');
		str = !*str ? ft_strjoinfree(line, str)
			: ft_strjoinfree(str, line);
	}
	sha224 = init_sha224(str, ft_strlen(str));
	sha224 = transform_sha224(sha224);
	if (MATCH(op, FLP))
	{
		ft_putstr(str);
		output_sha224(sha224);
	}
	else
		output_sha224(sha224);
	ft_putchar('\n');
	ft_strdel(&str);
}

void			printsha224_with_op(t_sha256 *sha224, char *str, int *op)
{
	if (MATCH(*op, FLQ))
		output_sha224(sha224);
	else if (MATCH(*op, FLR) && !MATCH(*op, FLS))
	{
		output_sha224(sha224);
		ft_putstr(" *");
		ft_putstr(str);
	}
	else if (MATCH(*op, FLS))
	{
		MATCH(*op, FLR) ? 0 : ft_printf("SHA224(\"%s\")= ", str);
		output_sha224(sha224);
		MATCH(*op, FLR) ? ft_printf(" \"%s\"", str) : 0;
		*op ^= FLS;
	}
	else
	{
		ft_printf("SHA224(%s)= ", str);
		output_sha224(sha224);
	}
	ft_putchar('\n');
}

int				sha224_encrypt_file(char *filename, int *op)
{
	int			fd;
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*str;
	t_sha256	*sha224;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (open_error("sha224", filename));
	str = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoinfree(str, ft_strdup(buf));
	}
	sha224 = init_sha224(str, ft_strlen(str));
	sha224 = transform_sha224(sha224);
	printsha224_with_op(sha224, filename, op);
	ft_strdel(&str);
	return (1);
}

int				sha224_encrypt_str(char *str, int *op)
{
	t_sha256	*sha224;

	sha224 = init_sha224(str, ft_strlen(str));
	sha224 = transform_sha224(sha224);
	printsha224_with_op(sha224, str, op);
	return (1);
}

void			process_sha224(int argc, char **argv)
{
	int		op;
	int		i;

	i = 0;
	op = 0;
	if (!(argv = check_mdop(argc, argv, "sha224", &op)))
		return ;
	if ((!*argv || MATCH(op, FLP)) &&
			!(!*argv && MATCH(op, FLS) && !MATCH(op, FLP)))
		sha224_encrypt_stdio(op);
	if (!*argv && MATCH(op, FLS))
		noparam_error("sha224", "s");
	if (*argv && MATCH(op, FLS))
		sha224_encrypt_str(argv[i++], &op);
	while (argv[i])
		sha224_encrypt_file(argv[i++], &op);
	if (op != 0)
		ft_tdstrdel(&argv);
}
