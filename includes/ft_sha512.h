/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 23:24:33 by syamada           #+#    #+#             */
/*   Updated: 2018/09/08 00:29:49 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA512_H
# define FT_SHA512_H
# include "ft_ssl.h"

# define CSIG0(x) \
	(ROTR(x, 2, 32) ^ ROTR(x, 13, 32) ^ ROTR(x, 22, 32))
# define CSIG1(x) \
	(ROTR(x, 6, 32) ^ ROTR(x, 11, 32) ^ ROTR(x, 25, 32))
# define SSIG0(x) \
	(ROTR(x, 7, 32) ^ ROTR(x, 18, 32) ^ (x >> 3))
# define SSIG1(x) \
	(ROTR(x, 17, 32) ^ ROTR(x, 19, 32) ^ (x >> 10))

# define ENCODE64(msg, offset, t) \
	(msg[offset + t * 8 + 0] << 56 \
		| msg[offset + t * 8 + 1] << 48 \
		| msg[offset + t * 8 + 2] << 40 \
		| msg[offset + t * 8 + 3] << 32 \
		| msg[offset + t * 8 + 4] << 24 \
		| msg[offset + t * 8 + 5] << 16 \
		| msg[offset + t * 8 + 6] << 8 \
		| msg[offset + t * 8 + 7])

typedef uint64_t	(t_sha512func)(uint64_t hash[8]);
typedef uint64_t	(t_sha512csigf)(uint64_t hash);
typedef uint64_t	(t_sha512ssigf)(uint64_t hash);

typedef struct	s_sha512
{
	uint64_t		hash[8];
	uint64_t		h[8];
	t_sha512func	*ch;
	t_sha512func	*ma;
	t_sha512csigf	*csigf[2];
	t_sha512ssigf	*ssigf[2];
	uint64_t		t1;
	uint64_t		t2;
	uint64_t		w[80];
	t_encode512		e;
	unsigned char	*msg;
	int				chunk_n;
}				t_sha512;

uint64_t	sha512ch(uint64_t hash[8]);
uint64_t	sha512ma(uint64_t hash[8]);
uint64_t	sha512csig0(uint64_t hash);
uint64_t	sha512csig1(uint64_t hash);
uint64_t	sha512ssig0(uint64_t hash);
uint64_t	sha512ssig1(uint64_t hash);

t_sha512	*init_sha512(const char *str, int len);
t_sha512	*transform_sha512(t_sha512 *ob);
void		output_sha512(t_sha512 *ob);

#endif
