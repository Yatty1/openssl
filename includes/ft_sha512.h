/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 23:24:33 by syamada           #+#    #+#             */
/*   Updated: 2018/09/08 16:56:22 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA512_H
# define FT_SHA512_H
# include "ft_ssl.h"

# define ENCODE64(msg, offset, t)		\
	(msg[offset + t * 8 + 0] << 56		\
		| msg[offset + t * 8 + 1] << 48	\
		| msg[offset + t * 8 + 2] << 40	\
		| msg[offset + t * 8 + 3] << 32	\
		| msg[offset + t * 8 + 4] << 24	\
		| msg[offset + t * 8 + 5] << 16	\
		| msg[offset + t * 8 + 6] << 8	\
		| msg[offset + t * 8 + 7])

# define B_END(msg, i, u)	\
	msg[i] = u >> 120;		\
	msg[i + 1] = u >> 112;	\
	msg[i + 2] = u >> 104;	\
	msg[i + 3] = u >> 96;	\
	msg[i + 4] = u >> 88;	\
	msg[i + 5] = u >> 80;	\
	msg[i + 6] = u >> 72;	\
	msg[i + 7] = u >> 64;	\
	msg[i + 8] = u >> 56;	\
	msg[i + 9] = u >> 48;	\
	msg[i + 10] = u >> 40;	\
	msg[i + 11] = u >> 32;	\
	msg[i + 12] = u >> 24;	\
	msg[i + 13] = u >> 16;	\
	msg[i + 14] = u >> 8;	\
	msg[i + 15] = u;


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
