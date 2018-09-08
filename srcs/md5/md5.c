/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 18:44:38 by syamada           #+#    #+#             */
/*   Updated: 2018/09/07 22:12:12 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			md5_encrypt_stdio(int op)
{
	char	*line;
	char	*str;
	t_md5	*md5;

	str = ft_strnew(1);
	while (get_next_line(0, &line) > 0)
	{
		line = ft_strappend(line, '\n');
		str = !*str ? ft_strjoinfree(line, str)
			: ft_strjoinfree(str, line);
	}
	md5 = init_md5(str, ft_strlen(str));
	md5 = transform_md5(md5);
	if (MATCH(op, FLP))
	{
		ft_putstr(str);
		output_md5(md5);
	}
	else
		output_md5(md5);
	ft_putchar('\n');
}

void			printmd5_with_op(t_md5 *md5, char *str, int *op)
{
	if (MATCH(*op, FLQ))
		output_md5(md5);
	else if (MATCH(*op, FLR) && !MATCH(*op, FLS))
	{
		output_md5(md5);
		ft_putstr(" ");
		ft_putstr(str);
	}
	else if (MATCH(*op, FLS))
	{
		MATCH(*op, FLR) ? 0 : ft_printf("MD5(\"%s\")= ", str);
		output_md5(md5);
		MATCH(*op, FLR) ? ft_printf(" \"%s\"", str) : 0;
		*op ^= FLS;
	}
	else
	{
		ft_printf("MD5(%s)= ", str);
		output_md5(md5);
	}
	ft_putchar('\n');
}

int				md5_encrypt_file(char *filename, int *op)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	t_md5	*md5;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (open_error("md5", filename));
	str = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoinfree(str, ft_strdup(buf));
	}
	md5 = init_md5(str, ft_strlen(str));
	md5 = transform_md5(md5);
	printmd5_with_op(md5, filename, op);
	return (1);
}

int				md5_encrypt_str(char *str, int *op)
{
	t_md5	*md5;

	md5 = init_md5(str, ft_strlen(str));
	md5 = transform_md5(md5);
	printmd5_with_op(md5, str, op);
	return (1);
}

void			process_md5(int argc, char **argv)
{
	int		op;
	int		i;

	i = 0;
	op = 0;
	if (!(argv = check_mdop(argc, argv, "md5", &op)))
		return ;
	if ((!*argv || MATCH(op, FLP)) &&
			!(!*argv && MATCH(op, FLS) && !MATCH(op, FLP)))
		md5_encrypt_stdio(op);
	if (!*argv && MATCH(op, FLS))
		noparam_error("md5", "s");
	if (*argv && MATCH(op, FLS))
		md5_encrypt_str(argv[i++], &op);
	while (argv[i])
		md5_encrypt_file(argv[i++], &op);
	if (op != 0)
		ft_tdstrdel(&argv);
}
