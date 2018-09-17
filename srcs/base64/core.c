/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:14:41 by syamada           #+#    #+#             */
/*   Updated: 2018/09/16 17:31:26 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static const char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void	encode3to4(t_base64 *ob)
{
	ob->tokens[0] = ob->bin[0] >> 2;
	ob->tokens[1] = (ob->bin[0] << 4 & 0x3F) | ob->bin[1] >> 4;
	ob->tokens[2] = (ob->bin[1] << 2 & 0x3F) | ob->bin[2] >> 6;
	ob->tokens[3] = ob->bin[2] & 0x3F;
}

void	conversion(const char *str, int len)
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
			ft_putchar(b64[ob->tokens[i++]]);
		ob->bin += 3;
	}
	while (ob->pad--)
		ft_putchar('=');
	ft_putchar('\n');
}
