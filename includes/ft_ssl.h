/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:49:46 by syamada           #+#    #+#             */
/*   Updated: 2018/08/30 19:38:23 by syamada          ###   ########.fr       */
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
#include <stdio.h>

# define MATCH(value, cmd) ((value & cmd) == cmd)
# define MD5	0x01
# define SHA256	0x02
# define SHA3	0x03

# define FLP 0x01
# define FLQ 0x02
# define FLR 0x04
# define FLS 0x08

void			process_stdio_cmd(void);
void			process_arg(int argc, char **argv);
char			**check_mdop(int argc, char **argv, int *mdop);
void			ft_tdstrdel(char ***tdstr);

/*
** command funcs
*/

void			process_md5(int argc, char **argv);
void			process_sha256(int argc, char **argv);
void			process_sha3(int argc, char **argv);

/*
** error messages
*/

void			error_cmd(char *str);
void			err_mdcmd(void);
void			err_stdcmd(void);
void			err_ciphercmd(void);

#endif
