/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 19:48:29 by syamada           #+#    #+#             */
/*   Updated: 2018/09/17 22:03:20 by syamada          ###   ########.fr       */
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
	int				offset;
}				t_base64;

char	*encode_base64(const char *str, int len);
char	*decode_base64(const char *str, int len);
void	encode3to4(t_base64 *ob, int o);
void	decode4to3(t_base64 *ob, int o);
void	free_base64(t_base64 **ob, int len);
char	**check_base64op(int argc, char **argv, int *op);

void	base64_stdio(char *filename, int op);
int		base64_file(char *dstfile, char *filename, int op);
int		base64_write(char *filename, char *content, int op);

void	o_error(void);
int		illegal_op_base64(char *cmd, char *option);
void	usage_base64(void);

#endif
