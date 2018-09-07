/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 19:41:53 by syamada           #+#    #+#             */
/*   Updated: 2018/09/06 21:28:30 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H

# define ROTR(x, n, w) ((x >> n) | (x << (w - n)))
# define ROTL(x, n, w) ((x << n) | (x >> (w - n)))
# define CSIG0(x) ()
# define CSIG1(x) ()
# define SSIG0(x) ()
# define SSIG1(x) ()

typedef uint32_t	(t_sha256func)(uint32_t hash[8]);
typedef uint32_t	(t_sha256sig)(uint32_t hash);

typedef union	u_encode512
{
	uint32_t		m[16];
	unsigned char	c[64];
}				t_encode512;

typedef struct	s_sha256
{
	uint32_t		hash[8];
	uint32_t		h[8];
	t_sha256func	*ch;
	t_sha256func	*ma;
	t_sha256sig		*sigf[4];
	uint32_t		t1;
	uint32_t		t2;
	uint32_t		w[64];
	t_encode512		e;
	unsigned char	*msg;
	int				chunk_n;
}				t_sha256;

uint32_t	sha256ch(uint32_t hash[8]);
uint32_t	sha256ma(uint32_t hash[8]);
uint32_t	sha256sig0(uint32_t hash);
uint32_t	sha256sig1(uint32_t hash);
uint32_t	sha256sig2(uint32_t hash);
uint32_t	sha256sig3(uint32_t hash);

t_sha256	*init_sha256(const char *str, int len);
t_sha256	*transform_sha256(t_sha256 *ob);
void		output_sha256(t_sha256 *ob);

#endif
