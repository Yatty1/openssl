/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:49:46 by syamada           #+#    #+#             */
/*   Updated: 2018/08/30 14:47:25 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define MATCH(value, cmd) ((value & cmd) == cmd)
# define MD5	0x01
# define SHA256	0x02
# define SHA3	0x03

typedef enum	e_md5f
{
	NO = 0x00,
	P = 0x01,
	Q = 0x02,
	R = 0x04,
	S = 0x08,
}				t_md5f;

void			process_stdio_cmd(void);
void			process_arg(char **argv);

/*
** command funcs
*/

void			process_md5(char **argv);
void			process_sha256(char **argv);
void			process_sha3(char **argv);

/*
** error messages
*/

void			error_cmd(char *str);
void			err_mdcmd(void);
void			err_stdcmd(void);
void			err_ciphercmd(void);

#endif
