/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 13:47:15 by syamada           #+#    #+#             */
/*   Updated: 2018/09/02 23:38:41 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

unsigned md5f(unsigned abcd[4])
{
	return ((abcd[1] & abcd[2]) | (~abcd[1] & abcd[3]));
}

unsigned md5g(unsigned abcd[4])
{
	return ((abcd[3] & abcd[1]) | (~abcd[3] & abcd[2]));
}

unsigned md5h(unsigned abcd[4])
{
	return abcd[1] ^ abcd[2] ^ abcd[3];
}

unsigned md5i(unsigned abcd[4])
{
	return abcd[2] ^ (abcd[1] |~ abcd[3]);
}

unsigned leftrotate(unsigned a, int n)
{
	return (a << n | a >> (32 - n));
}
