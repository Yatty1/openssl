/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:49:46 by syamada           #+#    #+#             */
/*   Updated: 2018/09/08 19:37:18 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"
# include "ft_md5.h"
# include "ft_sha256.h"
# include "ft_sha512.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# define MATCH(value, op) ((value & op) == op)
# define FLP 0x01
# define FLQ 0x02
# define FLR 0x04
# define FLS 0x08

# define CMD_NUM 4

# define ROTR(x, n, w) ((x >> n) | (x << (w - n)))
# define ROTL(x, n, w) ((x << n) | (x >> (w - n)))

typedef void		(t_hash_func)(int, char **);

typedef struct		s_cmd
{
	char		*name;
	t_hash_func	*hash;
}					t_cmd;

typedef union		u_encode32
{
	uint32_t		in;
	unsigned char	b[4];
}					t_encode32;

typedef union		u_encode64
{
	uint64_t		in;
	unsigned char	b[8];
}					t_encode64;

void				process_stdio_cmd(void);
void				dispatcher(int argc, char **argv);
int					ft_tdstrlen(char **tdstr);
char				**check_mdop(int argc, char **argv, char *cmd, int *mdop);
int					validate_option(char **argv, char *cmd,
						int (*validator)(char), int (*msg)(char *, char *));
/*
** command funcs
*/

void				process_md5(int argc, char **argv);
void				process_sha256(int argc, char **argv);
void				process_sha224(int argc, char **argv);
void				process_sha512(int argc, char **argv);
void				process_sha3(int argc, char **argv);

/*
** error messages
*/

int					open_error(char *cmd, char *filename);
int					noparam_error(char *cmd, char *option);
void				error_cmd(char *str);
void				err_mdcmd(void);
void				err_stdcmd(void);
void				err_ciphercmd(void);
int					illegal_op_md(char *cmd, char *option);

#endif
