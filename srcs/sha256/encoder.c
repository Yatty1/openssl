/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 19:22:27 by syamada           #+#    #+#             */
/*   Updated: 2018/09/08 19:40:11 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	encode32(t_sha256 *ob, int offset, int t)
{
	return (ob->msg[offset + t * 4 + 0] << 24
			| ob->msg[offset + t * 4 + 1] << 16
			| ob->msg[offset + t * 4 + 2] << 8
			| ob->msg[offset + t * 4 + 3] << 0);
}
