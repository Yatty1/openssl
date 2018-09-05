/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:25:45 by syamada           #+#    #+#             */
/*   Updated: 2018/09/04 20:49:16 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	sha256sig0(uint32_t hash[8])
{
	return ((ROTR(hash[0], 2, 32)) ^ (ROTR(hash[0], 13, 32)) ^ (ROTR(hash[0], 22, 32)));
}

uint32_t	sha256sig1(uint32_t hash[8])
{
	return ((ROTR(hash[4], 6, 32)) ^ (ROTR(hash[4], 11, 32)) ^ (ROTR(hash[4], 25, 32)));
}

uint32_t	sha256sig2(uint32_t hash[8])
{
	return ((ROTR(hash[4], 7, 32)) ^ (ROTR(hash[4], 18, 32)) ^ (hash[4] >> 3));
}

uint32_t	sha256sig3(uint32_t hash[8])
{
	return ((ROTR(hash[4], 17, 32)) ^ (ROTR(hash[4], 19, 32)) ^ (hash[4] >> 10));
}
