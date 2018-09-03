/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 18:44:38 by syamada           #+#    #+#             */
/*   Updated: 2018/09/02 23:38:38 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static int		s[64] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
};

static uint32_t k[64] = {
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

char			*init_md5(const char *msg, int len)
{
	t_md5		*md5ob;
	int			i;
	unsigned	u;

	md5ob = (t_md5 *)malloc(sizeof(t_md5));
	md5ob->abcd[0] = 0x67452301;
	md5ob->abcd[1] = 0xefcdab89;
	md5ob->abcd[2] = 0x98badcfe;
	md5ob->abcd[3] = 0x10325476;
	md5ob->chunk_n = 1 + (len + 8) / 64;
	md5ob->msg = ft_memalloc(64 * md5ob->chunk_n);
	ft_memcpy(md5ob->msg, msg, len);
	md5ob->msg[len] = (unsigned char)0x80;
	i = len + 1;
	while (i < (64 * md5ob->chunk_n))
		md5ob->msg[i++] = 0;
	// 64 bits representing the length of original message, modulo 2 ^ 64
	u = 8 * len;
	//to fill up last 64 bits.
	i -= 8;
	ft_memcpy(md5ob->msg + i, &u, 4);
	return (md5ob->msg);
}

// to take a part of msg that is given, we need a index to string.
// m { 1, 5 ,3 ,7 }, o { 0, 1, 5 ,0 }
// m[round] p[round]
// g = (m * q + o) % 16

unsigned		*md5_transform(char *str, t_md5 *md5ob)
{
	int			round;
	int			step;
	int			pick_i;
	unsigned	*u;
	unsigned	*md;

	round = 0;
	step = 0;
	//while (md5ob->chunk_n--)
	while (round < 4)
	{
		while (step < 16)
		{
			//need to pick i
			md5ob->f = md5ob->abcd[0] + md5ob->func[step](md5ob->abcd)
					+ k[step + round * 16] + u[pick_i];
			md5ob->abcd[0] = md5ob->abcd[3];
			md5ob->abcd[3] = md5ob->abcd[2];
			md5ob->abcd[2] = md5ob->abcd[1];
			md5ob->abcd[1] = md5ob->abcd[1] + leftrotate(md5ob->f, s[(step + round) * 16]);
			step++;
		}
		round++;
	}
	round = -1;
	while (++round < 4)
		md[round] += md5ob->abcd[round];
	return (md);
}

void	process_md5(int argc, char **argv)
{
	int		op;
	int		i;

	i = 0;
	op = 0;
	if (!(argv = check_mdop(argc, argv, "md5", &op)))
		return ;
	if (!*argv || MATCH(op, FLP))
		return ; // process stdio
	while (i)
	{
	}
	ft_tdstrdel(&argv);
}
