/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 23:24:33 by syamada           #+#    #+#             */
/*   Updated: 2018/09/08 20:00:45 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA512_H
# define FT_SHA512_H

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

uint64_t		sha512ch(uint64_t hash[8]);
uint64_t		sha512ma(uint64_t hash[8]);
uint64_t		sha512csig0(uint64_t hash);
uint64_t		sha512csig1(uint64_t hash);
uint64_t		sha512ssig0(uint64_t hash);
uint64_t		sha512ssig1(uint64_t hash);

uint64_t		encode64(t_sha512 *ob, int offset, int t);
void			decode128(t_sha512 *ob, unsigned __int128 u, int i);

t_sha512		*init_sha512(const char *str, int len);
t_sha512		*transform_sha512(t_sha512 *ob);
void			output_sha512(t_sha512 *ob);

#endif
