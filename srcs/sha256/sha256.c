/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 18:45:11 by syamada           #+#    #+#             */
/*   Updated: 2018/09/07 22:23:01 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			sha256_encrypt_stdio(int op)
{
	char		*line;
	char		*str;
	t_sha256	*sha256;

	str = ft_strnew(1);
	while (get_next_line(0, &line) > 0)
	{
		line = ft_strappend(line, '\n');
		str = !*str ? ft_strjoinfree(line, str)
			: ft_strjoinfree(str, line);
	}
	sha256 = init_sha256(str, ft_strlen(str));
	sha256 = transform_sha256(sha256);
	if (MATCH(op, FLP))
	{
		ft_putstr(str);
		output_sha256(sha256);
	}
	else
		output_sha256(sha256);
	ft_putchar('\n');
}

void			printsha256_with_op(t_sha256 *sha256, char *str, int *op)
{
	if (MATCH(*op, FLQ))
		output_sha256(sha256);
	else if (MATCH(*op, FLR) && !MATCH(*op, FLS))
	{
		output_sha256(sha256);
		ft_putstr(" ");
		ft_putstr(str);
	}
	else if (MATCH(*op, FLS))
	{
		MATCH(*op, FLR) ? 0 : ft_printf("SHA256(\"%s\")= ", str);
		output_sha256(sha256);
		MATCH(*op, FLR) ? ft_printf(" \"%s\"", str) : 0;
		*op ^= FLS;
	}
	else
	{
		ft_printf("SHA256(%s)= ", str);
		output_sha256(sha256);
	}
	ft_putchar('\n');
}

int				sha256_encrypt_file(char *filename, int *op)
{
	int			fd;
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*str;
	t_sha256	*sha256;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (open_error("sha256", filename));
	str = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoinfree(str, ft_strdup(buf));
	}
	sha256 = init_sha256(str, ft_strlen(str));
	sha256 = transform_sha256(sha256);
	printsha256_with_op(sha256, filename, op);
	return (1);
}

int				sha256_encrypt_str(char *str, int *op)
{
	t_sha256	*sha256;

	sha256 = init_sha256(str, ft_strlen(str));
	sha256 = transform_sha256(sha256);
	printsha256_with_op(sha256, str, op);
	return (1);
}

void			process_sha256(int argc, char **argv)
{
	int		op;
	int		i;

	i = 0;
	op = 0;
	if (!(argv = check_mdop(argc, argv, "sha256", &op)))
		return ;
	if ((!*argv || MATCH(op, FLP)) &&
			!(!*argv && MATCH(op, FLS) && !MATCH(op, FLP)))
		sha256_encrypt_stdio(op);
	if (!*argv && MATCH(op, FLS))
		noparam_error("sha256", "s");
	if (*argv && MATCH(op, FLS))
		sha256_encrypt_str(argv[i++], &op);
	while (argv[i])
		sha256_encrypt_file(argv[i++], &op);
	if (op != 0)
		ft_tdstrdel(&argv);
}
