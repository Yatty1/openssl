/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_encrypt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 23:31:25 by syamada           #+#    #+#             */
/*   Updated: 2018/09/08 15:12:01 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static const uint64_t	g_k[80] = {
	0x428a2f98d728ae22, 0x7137449123ef65cd,
	0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
	0x3956c25bf348b538, 0x59f111f1b605d019,
	0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
	0xd807aa98a3030242, 0x12835b0145706fbe,
	0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
	0x72be5d74f27b896f, 0x80deb1fe3b1696b1,
	0x9bdc06a725c71235, 0xc19bf174cf692694,
	0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
	0x2de92c6f592b0275, 0x4a7484aa6ea6e483,
	0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
	0x983e5152ee66dfab, 0xa831c66d2db43210,
	0xb00327c898fb213f, 0xbf597fc7beef0ee4,
	0xc6e00bf33da88fc2, 0xd5a79147930aa725,
	0x06ca6351e003826f, 0x142929670a0e6e70,
	0x27b70a8546d22ffc, 0x2e1b21385c26c926,
	0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
	0x650a73548baf63de, 0x766a0abb3c77b2a8,
	0x81c2c92e47edaee6, 0x92722c851482353b,
	0xa2bfe8a14cf10364, 0xa81a664bbc423001,
	0xc24b8b70d0f89791, 0xc76c51a30654be30,
	0xd192e819d6ef5218, 0xd69906245565a910,
	0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53,
	0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
	0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
	0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
	0x748f82ee5defb2fc, 0x78a5636f43172f60,
	0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9,
	0xbef9a3f7b2c67915, 0xc67178f2e372532b,
	0xca273eceea26619c, 0xd186b8c721c0c207,
	0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
	0x06f067aa72176fba, 0x0a637dc5a2c898a6,
	0x113f9804bef90dae, 0x1b710b35131c471b,
	0x28db77f523047d84, 0x32caab7b40c72493,
	0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
	0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
	0x5fcb6fab3ad6faec, 0x6c44198c4a475817,
};

static void				init_properties(t_sha512 *ob)
{
	ob->hash[0] = 0x6a09e667f3bcc908;
	ob->hash[1] = 0xbb67ae8584caa73b;
	ob->hash[2] = 0x3c6ef372fe94f82b;
	ob->hash[3] = 0xa54ff53a5f1d36f1;
	ob->hash[4] = 0x510e527fade682d1;
	ob->hash[5] = 0x9b05688c2b3e6c1f;
	ob->hash[6] = 0x1f83d9abfb41bd6b;
	ob->hash[7] = 0x5be0cd19137e2179;
	ob->ch = &sha512ch;
	ob->ma = &sha512ma;
	ob->csigf[0] = &sha512csig0;
	ob->csigf[1] = &sha512csig1;
	ob->ssigf[0] = &sha512ssig0;
	ob->ssigf[1] = &sha512ssig1;
}

t_sha512				*init_sha512(const char *str, int len)
{
	t_sha512			*ob;
	int					i;
	unsigned __int128	u;

	ob = (t_sha512 *)malloc(sizeof(t_sha512));
	init_properties(ob);
	ob->chunk_n = 1 + (len + 16) / 128;
	ob->msg = ft_memalloc(128 * ob->chunk_n);
	ft_memcpy(ob->msg, str, len);
	ob->msg[len] = (unsigned char)0x80;
	i = len + 1;
	while (i < (128 * ob->chunk_n) - 16)
		ob->msg[i++] = 0;
	u = len * 8;
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
	return (ob);
}

static void				transform(t_sha512 *ob)
{
	int		t;

	t = 0;
	while (t < 80)
	{
		ob->t1 = ob->h[7] + ob->csigf[1](ob->h[4])
			+ ob->ch(ob->h) + g_k[t] + ob->w[t];
		ob->t2 = ob->csigf[0](ob->h[0]) + ob->ma(ob->h);
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

t_sha512				*transform_sha512(t_sha512 *ob)
{
	int			t;
	int			offset;

	offset = 0;
	while (ob->chunk_n--)
	{
		t = -1;
		while (++t < 16)
		{
			ob->w[t] = ob->msg[offset + t * 8 + 0] << 24
				| ob->msg[offset + t * 8 + 1] << 16
				| ob->msg[offset + t * 8 + 2] << 8
				| ob->msg[offset + t * 8 + 3];
			ob->w[t] = ob->w[t] << 32
				| ob->msg[offset + t * 8 + 4] << 24
				| ob->msg[offset + t * 8 + 5] << 16
				| ob->msg[offset + t * 8 + 6] << 8
				| ob->msg[offset + t * 8 + 7];
		}
		t = 15;
		while (++t < 80)
			ob->w[t] = ob->ssigf[1](ob->w[t - 2]) + ob->w[t - 7]
				+ ob->ssigf[0](ob->w[t - 15]) + ob->w[t - 16];
		t = -1;
		while (++t < 8)
			ob->h[t] = ob->hash[t];
		transform(ob);
		t = -1;
		while (++t < 8)
			ob->hash[t] += ob->h[t];
		offset += 128;
	}
	return (ob);
}

void					output_sha512(t_sha512 *ob)
{
	int			i;
	int			j;
	t_encode64	m;

	i = 0;
	while (i < 8)
	{
		m.in = ob->hash[i];
		j = 8;
		while (j--)
			ft_printf("%02x", m.b[j]);
		i++;
	}
	free(ob->msg);
	free(ob);
}
