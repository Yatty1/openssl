/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 19:41:53 by syamada           #+#    #+#             */
/*   Updated: 2018/09/08 00:11:31 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H
# include "ft_ssl.h"

# define CSIG0(x) \
	(ROTR(x, 2, 32) ^ ROTR(x, 13, 32) ^ ROTR(x, 22, 32))
# define CSIG1(x) \
	(ROTR(x, 6, 32) ^ ROTR(x, 11, 32) ^ ROTR(x, 25, 32))
# define SSIG0(x) \
	(ROTR(x, 7, 32) ^ ROTR(x, 18, 32) ^ (x >> 3))
# define SSIG1(x) \
	(ROTR(x, 17, 32) ^ ROTR(x, 19, 32) ^ (x >> 10))

# define ENCODE32(msg, offset, t) \
	(msg[offset + t * 4 + 0] << 24 \
		| msg[offset + t * 4 + 1] << 16 \
		| msg[offset + t * 4 + 2] << 8 \
		| msg[offset + t * 4 + 3] << 0)

typedef uint32_t	(t_sha256func)(uint32_t hash[8]);
typedef uint32_t	(t_sha256sigf)(uint32_t hash);

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
	t_sha256sigf	*sigf[4];
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

t_sha256	*init_sha224(const char *str, int len);
t_sha256	*transform_sha224(t_sha256 *ob);
void		output_sha224(t_sha256 *ob);


#endif
