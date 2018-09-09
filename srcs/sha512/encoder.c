/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 16:37:15 by syamada           #+#    #+#             */
/*   Updated: 2018/09/08 20:11:27 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint64_t	encode64(t_sha512 *ob, int offset, int t)
{
	ob->w[t] = ob->msg[offset + t * 8 + 0] << 24
				| ob->msg[offset + t * 8 + 1] << 16
				| ob->msg[offset + t * 8 + 2] << 8
				| ob->msg[offset + t * 8 + 3];
	return (ob->w[t] << 32
				| ob->msg[offset + t * 8 + 4] << 24
				| ob->msg[offset + t * 8 + 5] << 16
				| ob->msg[offset + t * 8 + 6] << 8
				| ob->msg[offset + t * 8 + 7]);
}

void		decode128(t_sha512 *ob, unsigned __int128 u, int i)
{
	ob->msg[i] = u >> 120;
	ob->msg[i + 1] = u >> 112;
	ob->msg[i + 2] = u >> 104;
	ob->msg[i + 3] = u >> 96;
	ob->msg[i + 4] = u >> 88;
	ob->msg[i + 5] = u >> 80;
	ob->msg[i + 6] = u >> 72;
	ob->msg[i + 7] = u >> 64;
	ob->msg[i + 8] = u >> 56;
	ob->msg[i + 9] = u >> 48;
	ob->msg[i + 10] = u >> 40;
	ob->msg[i + 11] = u >> 32;
	ob->msg[i + 12] = u >> 24;
	ob->msg[i + 13] = u >> 16;
	ob->msg[i + 14] = u >> 8;
	ob->msg[i + 15] = u;
}
