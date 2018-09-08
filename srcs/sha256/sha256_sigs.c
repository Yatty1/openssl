/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:25:45 by syamada           #+#    #+#             */
/*   Updated: 2018/09/07 21:54:10 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t       sha256sig0(uint32_t hash)
{
       return ((ROTR(hash, 2, 32)) ^ (ROTR(hash, 13, 32)) ^ (ROTR(hash, 22, 32)));
}

uint32_t       sha256sig1(uint32_t hash)
{
       return ((ROTR(hash, 6, 32)) ^ (ROTR(hash, 11, 32)) ^ (ROTR(hash, 25, 32)));
}

uint32_t       sha256sig2(uint32_t hash)
{
       return ((ROTR(hash, 7, 32)) ^ (ROTR(hash, 18, 32)) ^ (hash >> 3));
}

uint32_t       sha256sig3(uint32_t hash)
{
       return ((ROTR(hash, 17, 32)) ^ (ROTR(hash, 19, 32)) ^ (hash >> 10));
}
