/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_encrypt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:13:35 by syamada           #+#    #+#             */
/*   Updated: 2018/09/07 22:03:37 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static const uint32_t	g_sk[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static void				init_properties(t_sha256 *ob)
{
	ob->hash[0] = 0x6a09e667;
    ob->hash[1] = 0xbb67ae85;
    ob->hash[2] = 0x3c6ef372;
    ob->hash[3] = 0xa54ff53a;
    ob->hash[4] = 0x510e527f;
    ob->hash[5] = 0x9b05688c;
    ob->hash[6] = 0x1f83d9ab;
    ob->hash[7] = 0x5be0cd19;
	ob->ch = &sha256ch;
	ob->ma = &sha256ma;
	ob->sigf[0] = &sha256sig0;
	ob->sigf[1] = &sha256sig1;
	ob->sigf[2] = &sha256sig2;
	ob->sigf[3] = &sha256sig3;
}

/* How to do padding
** count chunks based on length
** add 1 to the end
** fill up 0 k bits based on this formula l + 1 + k = 448
** (where l == length of str)
** length * 8 == length in bits
** add original length to last 64 bits of msg
*/

t_sha256				*init_sha256(const char *str, int len)
{
	t_sha256	*ob;
	int			i;
	long long	u;

	ob = (t_sha256 *)malloc(sizeof(t_sha256));
	init_properties(ob);
	ob->chunk_n = 1 + (len + 8) / 64;
	ob->msg = ft_memalloc(64 * ob->chunk_n);
	ft_memcpy(ob->msg, str, len);
	ob->msg[len] = (unsigned char)0x80;
	i = len + 1;
	while (i < (64 * ob->chunk_n) - 8)
		ob->msg[i++] = 0;
	u = len * 8;
	ob->msg[i] = u >> 56;
	ob->msg[i + 1] = u >> 48;
	ob->msg[i + 2] = u >> 40;
	ob->msg[i + 3] = u >> 32;
	ob->msg[i + 4] = u >> 24;
	ob->msg[i + 5] = u >> 16;
	ob->msg[i + 6] = u >> 8;
	ob->msg[i + 7] = u;
	return (ob);
}

/*
**How to transform
** a message schedule of sixty four 32-bit words
** eight working variables of 32 bits each
** a hash value of eight 32 bits words
** 1. prepare the message schedule W
** 2. initialize the eight working variables with const hash nums
** 3. 64 steps with sig 0 and sig 1
** 4. compute i th intermediate hash value
*/

void					transform(t_sha256 *ob)
{
	int		t;

	t = 0;
	while (t < 64)
	{
		ob->t1 = ob->h[7] + ob->sigf[1](ob->h[4]) + ob->ch(ob->h) + g_sk[t] + ob->w[t];
		ob->t2 = ob->sigf[0](ob->h[0]) + ob->ma(ob->h);
		ob->h[7] = ob->h[6];
		ob->h[6] = ob->h[5];
		ob->h[5] = ob->h[4];
		ob->h[4] = ob->h[3] + ob->t1;
		ob->h[3] = ob->h[2];
		ob->h[2] = ob->h[1];
		ob->h[1] = ob->h[0];
		ob->h[0] = ob->t1 + ob->t2;
		t++;
	}
}

t_sha256				*transform_sha256(t_sha256 *ob)
{
	int			t;
	int			offset;

	offset = 0;
	while (ob->chunk_n--)
	{
		t = -1;
		while (++t < 16)
			ob->w[t] = ENCODE32(ob->msg, offset, t);
		t = 15;
		while (++t < 64)
			ob->w[t] = ob->sigf[3](ob->w[t - 2]) + ob->w[t - 7]
				+ ob->sigf[2](ob->w[t - 15]) + ob->w[t - 16];
		t = -1;
		while (++t < 8)
			ob->h[t] = ob->hash[t];
		transform(ob);
		t = -1;
		while (++t < 8)
			ob->hash[t] += ob->h[t];
		offset += 64;
	}
	return (ob);
}

void					output_sha256(t_sha256 *ob)
{
	int			i;
	int			j;
	t_encode32	m;

	i = 0;
	while (i < 8)
	{
		m.in = ob->hash[i];
		j = 4;
		while (j--)
			ft_printf("%02x", m.b[j]);
		i++;
	}
	free(ob->msg);
	free(ob);
}
