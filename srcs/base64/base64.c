/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 01:00:39 by syamada           #+#    #+#             */
/*   Updated: 2018/09/17 00:34:21 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	base64_stdio(int op)
{
	char	*line;
	char	*str;
	char	*dstr;

	line = NULL;
	str = ft_strnew(1);
	while (get_next_line(0, &line) > 0)
	{
		line = ft_strappend(line, '\n');
		str = !*str ? ft_strjoinfree(line, str)
			: ft_strjoinfree(str, line);
	}
	dstr = MATCH(op, FLD) ? decode_base64(str, ft_strlen(str))
			: encode_base64(str, ft_strlen(str));
	ft_putendl(dstr);
	ft_strdel(&dstr);
	ft_strdel(&str);
}

int		base64_encodefile(char *filename, int *op)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*dstr;

	//if ((fd = open(filename, O_CREATE | O_TRUNC | O_RDWR, S_IRUSR | S_IRWUSR)) < 0)
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (open_error("base64", filename));
	str = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoinfree(str, ft_strdup(buf));
	}
	dstr = encode_base64(str, ft_strlen(str));
	ft_putendl(dstr);
	ft_strdel(&str);
	return (1);
}

void	process_base64(int argc, char **argv)
{
	int		op;
	char	*decstr;

	op = 0;
	if (!(argv = check_base64op(argc, argv, &op)))
		return ;
	if (!*argv)
		base64_stdio(op);
	if (MATCH(op, FLD))
	{
		decstr = decode_base64(argv[0], ft_strlen(argv[0]));
		ft_putendl(decstr);
	}
	if (MATCH(op, FLE))
		base64_encodefile(argv[0], &op);
}
