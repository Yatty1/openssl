/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 01:00:39 by syamada           #+#    #+#             */
/*   Updated: 2018/09/17 22:16:37 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	base64_stdio(char *filename, int op)
{
	char	*line;
	char	*str;
	char	*dstr;

	line = NULL;
	if (filename == 0 && MATCH(op, FLO))
		return ;
	str = ft_strnew(1);
	while (get_next_line(0, &line) > 0)
	{
		line = ft_strappend(line, '\n');
		str = !*str ? ft_strjoinfree(line, str)
			: ft_strjoinfree(str, line);
	}
	dstr = MATCH(op, FLD) ? decode_base64(str, ft_strlen(str))
			: encode_base64(str, ft_strlen(str));
	MATCH(op, FLO) ? base64_write(filename, dstr, op) : ft_putendl(dstr);
	ft_strdel(&dstr);
	ft_strdel(&str);
}

int		base64_write(char *filename, char *content, int op)
{
	int		fd;

	if ((fd = open(filename, O_CREAT | O_TRUNC | O_RDWR,
					S_IRUSR | S_IWUSR)) < 0)
		return (open_error("base64", filename));
	write(fd, content, ft_strlen(content));
	return (1);
}

int		base64_file(char *dstfile, char *filename, int op)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*dstr;

	if (dstfile == 0 && MATCH(op, FLO))
		return (0);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (open_error("base64", filename));
	str = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoinfree(str, ft_strdup(buf));
	}
	dstr = MATCH(op, FLD) ? decode_base64(str, ft_strlen(str))
			: encode_base64(str, ft_strlen(str));
	MATCH(op, FLO) ? base64_write(dstfile, dstr, op) : ft_putendl(dstr);
	ft_strdel(&dstr);
	ft_strdel(&str);
	return (1);
}

void	process_base64(int argc, char **argv)
{
	int		op;

	op = 0;
	if (!(argv = check_base64op(argc, argv, &op)))
		return ;
	if (!*argv && !MATCH(op, FLO))
		base64_stdio(0, op);
	if (!*argv && MATCH(op, FLO))
		return (o_error());
	if (MATCH(op, FLO))
		*(argv + 1) ? base64_file(argv[0], argv[1], op) :
			base64_stdio(argv[0], op);
	else
		base64_file(0, argv[MATCH(op, FLI) && argc > 2 ? 1 : 0], op);
}
