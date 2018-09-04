/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 13:47:15 by syamada           #+#    #+#             */
/*   Updated: 2018/09/03 16:37:08 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	md5f(uint32_t abcd[4])
{
	return ((abcd[1] & abcd[2]) | (~abcd[1] & abcd[3]));
}

uint32_t	md5g(uint32_t abcd[4])
{
	return ((abcd[3] & abcd[1]) | (~abcd[3] & abcd[2]));
}

uint32_t	md5h(uint32_t abcd[4])
{
	return abcd[1] ^ abcd[2] ^ abcd[3];
}

uint32_t	md5i(uint32_t abcd[4])
{
	return abcd[2] ^ (abcd[1] |~ abcd[3]);
}

uint32_t	leftrotate(uint32_t a, int n)
{
	return ((a << n) | (a >> (32 - n)));
}
