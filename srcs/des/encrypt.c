/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 22:00:52 by syamada           #+#    #+#             */
/*   Updated: 2018/09/20 23:33:19 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static const int	pc_1[] = {
	57, 49, 41, 33, 25, 17, 9,
	1, 58, 50, 42, 34, 26, 18,
	10, 2, 59, 51, 43, 35, 27,
	19, 11, 3, 60, 52, 44, 36,
	63, 55, 47, 39, 31, 23, 15,
	7, 62, 54, 46, 38, 30, 22,
	14, 6, 61, 53, 45, 37, 29,
	21, 13, 5, 28, 20, 12, 4,
};

static const int	key_shift[] = {
	1, 1, 2, 2, 2, 2, 2, 2,
	1, 2, 2, 2, 2, 2, 2, 1,
};

static const int	pc_2[] = {
	14, 17, 11, 24, 1, 5,
	3, 28, 15, 6, 21, 10,
	23, 19, 12, 4, 26, 8,
	16, 7, 287, 20, 13, 2,
	41, 52, 31, 37, 47, 55,
	30, 40, 51, 45, 33, 48,
	44, 49, 39, 56, 34, 53,
	46, 42, 50, 36, 29, 32,
};

static const int	ip[] = {
	58, 50, 42, 34, 26, 18, 10, 2,
	60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,
	64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17, 9, 1,
	59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,
	63, 55, 47, 39, 31, 23, 15, 7,
};

static const int	e_bit[] = {
	32, 1, 2, 3, 4, 5,
	4, 5, 6, 7, 8, 9,
	8, 9, 10, 11, 12, 13,
	12, 13, 14, 15, 16, 17,
	16, 17, 18, 19, 20, 21,
	20, 21, 22, 23, 24, 25,
	24, 25, 26, 27, 28, 29,
	28, 29, 30, 31, 32, 1,
};

/*
** How des works
** M = plain text -> it's divided into two parts
** IP = plain text after ip is applied
** K = key -> it's used 56 bits of them, and every 8th bit will be eliminated
** Step 1:
** -> by using pc_1 number, you could get 56-bit permutation key.
** -> take 1 bit from the position of the number that points to
** -> divide into 2 parts. left and right (28 bits each)
** -> by using key_shift, you shift 16 times and Ln and Rn is formed
** from the previous pair Ln-1 and Rn-1 respectively.(left rotate)
** -> you do above until L16 and R16
** -> concatenate Ln and Rn (56 bits in total)
** -> by using pc_2, take 1 bit from the position of LnRn that pc2 tells you
** and keep doing it 48 times on each keys
** -> finally you'll have subkeys that you are going to use
** to apply to data block on next step
** Step 2:
** -> use ip to make M IP
** -> divide IP into L and R (32 bits each)
** -> process operation 16 rounds on both blocks using subkeys that are created
** -> Ln = Rn-1; Rn = Ln-1 + f(Rn-1,Kn)
** -> How f() works:
** 	      -> make Rn-1 from 32 bits to 48 bits by using e_bit
**        -> Kn + e(Rn-1) where + is xor
**        -> eight groups of six bits
** -> now you have eight groups of 6 bits, and you are going to take 6 bits and turn it into 4 bits
**
*/
