/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 19:48:29 by syamada           #+#    #+#             */
/*   Updated: 2018/09/16 18:39:53 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE64_H
# define FT_BASE64_H

# define FLD 0x01
# define FLE 0x02
# define FLI 0x04
# define FLO 0x08

typedef struct	s_base64
{
	unsigned char	*bin;
	unsigned char	tokens[4];
	unsigned char	chunks[3];
	int				pad;
}				t_base64;

void	encode_base64(const char *str, int len);
void	decode_base64(const char *str, int len);
void	encode3to4(t_base64 *ob);
void	decode4to3(t_base64 *ob);
char	**check_base64op(int argc, char **argv, int *op);

#endif
