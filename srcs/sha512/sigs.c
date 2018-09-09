/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_sigs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 23:20:42 by syamada           #+#    #+#             */
/*   Updated: 2018/09/08 13:46:29 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint64_t	sha512csig0(uint64_t hash)
{
	return (ROTR(hash, 28, 64) ^ ROTR(hash, 34, 64) ^ ROTR(hash, 39, 64));
}

uint64_t	sha512csig1(uint64_t hash)
{
	return (ROTR(hash, 14, 64) ^ ROTR(hash, 18, 64) ^ ROTR(hash, 41, 64));
}

uint64_t	sha512ssig0(uint64_t hash)
{
	return (ROTR(hash, 1, 64) ^ ROTR(hash, 8, 64) ^ (hash >> 7));
}

uint64_t	sha512ssig1(uint64_t hash)
{
	return (ROTR(hash, 19, 64) ^ ROTR(hash, 61, 64) ^ (hash >> 6));
}
