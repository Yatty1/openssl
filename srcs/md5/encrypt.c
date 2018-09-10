/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_encrypt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:13:57 by syamada           #+#    #+#             */
/*   Updated: 2018/09/09 18:03:47 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int		g_s[64] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

static uint32_t	g_k[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391,
};

static short	g_m[5] = {
	1, 5, 3, 7,
};

static short	g_o[5] = {
	0, 1, 5, 0,
};

t_md5			*init_md5(const char *msg, int len)
{
	t_md5		*md5ob;
	int			i;
	long long	u;

	md5ob = (t_md5 *)malloc(sizeof(t_md5));
	md5ob->md[0] = 0x67452301;
	md5ob->md[1] = 0xefcdab89;
	md5ob->md[2] = 0x98badcfe;
	md5ob->md[3] = 0x10325476;
	md5ob->func[0] = &md5f;
	md5ob->func[1] = &md5g;
	md5ob->func[2] = &md5h;
	md5ob->func[3] = &md5i;
	md5ob->chunk_n = 1 + (len + 8) / 64;
	md5ob->msg = ft_memalloc(64 * md5ob->chunk_n);
	ft_memcpy(md5ob->msg, msg, len);
	md5ob->msg[len] = (unsigned char)0x80;
	i = len + 1;
	while (i < (64 * md5ob->chunk_n) - 8)
		md5ob->msg[i++] = 0;
	u = 8 * len;
	ft_memcpy(md5ob->msg + i, &u, 8);
	return (md5ob);
}

static t_md5	*transform(t_md5 *md5ob, int round, int step)
{
	int		pick_i;

	pick_i = (g_m[round] * step + g_o[round]) % 16;
	md5ob->f = md5ob->abcd[0] + md5ob->func[round](md5ob->abcd)
			+ g_k[round * 16 + step] + md5ob->mm.in[pick_i];
	md5ob->abcd[0] = md5ob->abcd[3];
	md5ob->abcd[3] = md5ob->abcd[2];
	md5ob->abcd[2] = md5ob->abcd[1];
	md5ob->abcd[1] = md5ob->abcd[1]
		+ leftrotate(md5ob->f, g_s[round * 16 + step]);
	return (md5ob);
}

t_md5			*transform_md5(t_md5 *md5ob)
{
	int			round;
	int			step;
	int			offset;

	offset = 0;
	while (md5ob->chunk_n--)
	{
		round = -1;
		ft_memcpy(md5ob->mm.c, md5ob->msg + offset, 64);
		while (++round < 4)
			md5ob->abcd[round] = md5ob->md[round];
		round = -1;
		while (++round < 4)
		{
			step = -1;
			while (++step < 16)
				md5ob = transform(md5ob, round, step);
		}
		round = -1;
		while (++round < 4)
			md5ob->md[round] += md5ob->abcd[round];
		offset += 64;
	}
	return (md5ob);
}

void			output_md5(t_md5 *md5ob)
{
	int			i;
	int			j;
	t_encode32	m;

	i = 0;
	while (i < 4)
	{
		m.in = md5ob->md[i];
		j = 0;
		while (j < 4)
			ft_printf("%02x", m.b[j++]);
		i++;
	}
	free(md5ob->msg);
	free(md5ob);
}
