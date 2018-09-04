/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:25:45 by syamada           #+#    #+#             */
/*   Updated: 2018/09/04 16:43:23 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	sha256ch(uint32_t hash[8])
{
	return ((hash[4] & hash[5]) ^ (~hash[4] & hash[6]));
}

uint32_t	sha256ma(uint32_t hash[8])
{
	return ((hash[0] & hash[1]) ^ (hash[0] & hash[2]) ^ (hash[1] & hash[2]));
}

uint32_t	sha256sig0(uint32_t hash[8])
{
	return ((hash[0] >> 2) ^ (hash[0] >> 13) ^ (hash[0] >> 22));
}

uint32_t	sha256sig1(uint32_t hash[8])
{
	return ((hash[4] >> 6) ^ (hash[4] >> 11) ^ (hash[4] >> 25));
}
