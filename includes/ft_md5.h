/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 16:06:58 by syamada           #+#    #+#             */
/*   Updated: 2018/09/03 18:12:17 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H
# define FT_MD5_H

typedef uint32_t	(t_md5func)(uint32_t abcd[4]);

typedef union		u_md5m
{
	uint32_t		in[16];
	char			c[64];
}					t_md5m;

typedef union		u_encode
{
	uint32_t		in;
	unsigned  char	b[4];
}					t_encode;

typedef struct		s_md5
{
	uint32_t	abcd[4];
	t_md5func	*func[4];
	uint32_t	md[4];
	char		*msg;
	int			chunk_n;
	uint32_t	f;
	t_md5m		mm;
}					t_md5;

uint32_t			md5f(uint32_t abcd[4]);
uint32_t			md5g(uint32_t abcd[4]);
uint32_t			md5h(uint32_t abcd[4]);
uint32_t			md5i(uint32_t abcd[4]);
uint32_t			leftrotate(uint32_t a, int n);

t_md5				*init_md5(const char *msg, int len);
t_md5				*transform_md5(t_md5 *md5ob);
void				output_md5(t_md5 *mdob);
void				printmd5_with_op(t_md5 *md5, char *str, int *op);

#endif
