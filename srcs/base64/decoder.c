/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:14:41 by syamada           #+#    #+#             */
/*   Updated: 2018/09/16 23:58:03 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static const char	g_b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static int			take_index(char c)
{
	int i;

	i = 0;
	while (i < 64)
	{
		if (c == g_b64[i])
			return (i);
		i++;
	}
	return (i);
}

static int			count_appear(const char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void				free_base64(t_base64 **ob, int len)
{
	t_base64	*tmp;

	tmp = *ob;
	ft_strdel((char **)&tmp->bin);
	free(tmp);
	tmp = NULL;
}

void				decode4to3(t_base64 *ob, int o)
{
	ob->chunks[0] = (ob->bin[o + 0] << 2 & 0xFC)
					| (ob->bin[o + 1] >> 4 & 0x3);
	ob->chunks[1] = (ob->bin[o + 1] << 4 & 0xF0)
					| (ob->bin[o + 2] >> 2 & 0xF);
	ob->chunks[2] = (ob->bin[o + 2] << 6 & 0xC0) | ob->bin[o + 3];
}

char				*decode_base64(const char *str, int len)
{
	t_base64	*ob;
	char		*dstr;
	int			i;

	ob = (t_base64 *)malloc(sizeof(t_base64));
	ob->bin = ft_memalloc(len);
	ob->pad = count_appear(str, '=');
	dstr = ft_strnew(1);
	i = -1;
	while (++i < len)
		ob->bin[i] = take_index(str[i]);
	ob->offset = 0;
	while (ob->offset < len)
	{
		decode4to3(ob, ob->offset);
		i = 0;
		while ((len - ob->offset) <= 4 ? i < 3 - ob->pad : i < 3)
			dstr = ft_strappend(dstr, ob->chunks[i++]);
		ob->offset += 4;
	}
	free_base64(&ob, len);
	return (dstr);
}
