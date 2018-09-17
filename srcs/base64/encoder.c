/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 21:51:17 by syamada           #+#    #+#             */
/*   Updated: 2018/09/16 23:52:06 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static const char	g_b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void				encode3to4(t_base64 *ob, int o)
{
	ob->tokens[0] = ob->bin[o + 0] >> 2;
	ob->tokens[1] = (ob->bin[o + 0] << 4 & 0x3F)
					| ob->bin[o + 1] >> 4;
	ob->tokens[2] = (ob->bin[o + 1] << 2 & 0x3F)
					| ob->bin[o + 2] >> 6;
	ob->tokens[3] = ob->bin[o + 2] & 0x3F;
}

char				*encode_base64(const char *str, int len)
{
	t_base64	*ob;
	char		*dstr;
	int			i;

	ob = (t_base64 *)malloc(sizeof(t_base64));
	ob->pad = len % 3 == 0 ? 0 : 3 - len % 3;
	ob->bin = ft_memalloc(len + ob->pad);
	ft_memcpy(ob->bin, str, len);
	ft_memset(ob->bin + len, 0, ob->pad);
	dstr = ft_strnew(1);
	ob->offset = 0;
	while (ob->offset < len + ob->pad)
	{
		encode3to4(ob, ob->offset);
		i = 0;
		while ((len - ob->offset) < 3 ? i < 4 - ob->pad : i < 4)
			dstr = ft_strappend(dstr, g_b64[ob->tokens[i++]]);
		ob->offset += 3;
	}
	while (ob->pad--)
		dstr = ft_strappend(dstr, '=');
	free_base64(&ob, len);
	return (dstr);
}
