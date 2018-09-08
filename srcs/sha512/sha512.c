/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 23:12:37 by syamada           #+#    #+#             */
/*   Updated: 2018/09/07 23:53:08 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			sha512_encrypt_stdio(int op)
{
	char		*line;
	char		*str;
	t_sha512	*sha512;

	str = ft_strnew(1);
	while (get_next_line(0, &line) > 0)
	{
		line = ft_strappend(line, '\n');
		str = !*str ? ft_strjoinfree(line, str)
			: ft_strjoinfree(str, line);
	}
	sha512 = init_sha512(str, ft_strlen(str));
	sha512 = transform_sha512(sha512);
	if (MATCH(op, FLP))
	{
		ft_putstr(str);
		output_sha512(sha512);
	}
	else
		output_sha512(sha512);
	ft_putchar('\n');
}

void			printsha512_with_op(t_sha512 *sha512, char *str, int *op)
{
	if (MATCH(*op, FLQ))
		output_sha512(sha512);
	else if (MATCH(*op, FLR) && !MATCH(*op, FLS))
	{
		output_sha512(sha512);
		ft_putstr(" ");
		ft_putstr(str);
	}
	else if (MATCH(*op, FLS))
	{
		MATCH(*op, FLR) ? 0 : ft_printf("SHA512(\"%s\")= ", str);
		output_sha512(sha512);
		MATCH(*op, FLR) ? ft_printf(" \"%s\"", str) : 0;
		*op ^= FLS;
	}
	else
	{
		ft_printf("SHA512(%s)= ", str);
		output_sha512(sha512);
	}
	ft_putchar('\n');
}

int				sha512_encrypt_file(char *filename, int *op)
{
	int			fd;
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*str;
	t_sha512	*sha512;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (open_error("sha512", filename));
	str = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoinfree(str, ft_strdup(buf));
	}
	sha512 = init_sha512(str, ft_strlen(str));
	sha512 = transform_sha512(sha512);
	printsha512_with_op(sha512, filename, op);
	return (1);
}

int				sha512_encrypt_str(char *str, int *op)
{
	t_sha512	*sha512;

	sha512 = init_sha512(str, ft_strlen(str));
	sha512 = transform_sha512(sha512);
	printsha512_with_op(sha512, str, op);
	return (1);
}

void			process_sha512(int argc, char **argv)
{
	int		op;
	int		i;

	i = 0;
	op = 0;
	if (!(argv = check_mdop(argc, argv, "sha512", &op)))
		return ;
	if ((!*argv || MATCH(op, FLP)) &&
			!(!*argv && MATCH(op, FLS) && !MATCH(op, FLP)))
		sha512_encrypt_stdio(op);
	if (!*argv && MATCH(op, FLS))
		noparam_error("sha512", "s");
	if (*argv && MATCH(op, FLS))
		sha512_encrypt_str(argv[i++], &op);
	while (argv[i])
		sha512_encrypt_file(argv[i++], &op);
	if (op != 0)
		ft_tdstrdel(&argv);
}
