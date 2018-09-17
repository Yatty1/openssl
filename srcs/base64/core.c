/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:14:41 by syamada           #+#    #+#             */
/*   Updated: 2018/09/16 19:20:44 by syamada          ###   ########.fr       */
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
	return (0);
}

void				encode3to4(t_base64 *ob)
{
	ob->tokens[0] = ob->bin[0] >> 2;
	ob->tokens[1] = (ob->bin[0] << 4 & 0x3F) | ob->bin[1] >> 4;
	ob->tokens[2] = (ob->bin[1] << 2 & 0x3F) | ob->bin[2] >> 6;
	ob->tokens[3] = ob->bin[2] & 0x3F;
}

void				encode_base64(const char *str, int len)
{
	t_base64	*ob;
	int			i;
	int			n;

	ob = (t_base64 *)malloc(sizeof(t_base64));
	ob->pad = len % 3 == 0 ? 0 : 3 - len % 3;
	ob->bin = ft_memalloc(len + ob->pad);
	ft_memcpy(ob->bin, str, len);
	ft_memset(ob->bin + len, 0, ob->pad);
	while (*ob->bin)
	{
		encode3to4(ob);
		i = 0;
		n = ft_strchr_i((char *)ob->bin, '\0');
		while (n < 3 ? i < 4 - ob->pad : i < 4)
			ft_putchar(g_b64[ob->tokens[i++]]);
		ob->bin += 3;
	}
	while (ob->pad--)
		ft_putchar('=');
	ft_putchar('\n');
}

void				decode4to3(t_base64 *ob)
{
	ob->chunks[0] = (ob->bin[0] << 2 & 0xFC) | (ob->bin[1] >> 4 & 0x3);
	ob->chunks[1] = (ob->bin[1] << 4 & 0xF0) | (ob->bin[2] >> 2 & 0xF);
	ob->chunks[2] = (ob->bin[2] << 6 & 0xC0) | ob->bin[3];
}

void				decode_base64(const char *str, int len)
{
	t_base64	*ob;
	int			i;

	ob = (t_base64 *)malloc(sizeof(t_base64));
	ob->bin = ft_memalloc(len);
	i = -1;
	while (++i < len)
		ob->bin[i] = take_index(str[i]);
	while (*ob->bin)
	{
		decode4to3(ob);
		i = 0;
		while (i < 3)
			ft_putchar(ob->chunks[i++]);
		ob->bin += 4;
	}
	ft_putchar('\n');
}
