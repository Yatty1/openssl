/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 13:49:46 by syamada           #+#    #+#             */
/*   Updated: 2018/09/02 23:38:40 by syamada          ###   ########.fr       */
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

# define MATCH(value, op) ((value & op) == op)
# define FLP 0x01
# define FLQ 0x02
# define FLR 0x04
# define FLS 0x08

# define CMD_NUM 2

typedef void		(t_hash_func)(int, char **);
typedef uint32_t	(t_md5func)(uint32_t abcd[4]);

typedef struct		s_cmd
{
	char		*name;
	t_hash_func	*hash;
}					t_cmd;

typedef struct		s_md5
{
	uint32_t	abcd[4];
	t_md5func	*func[4];
	char		*msg;
	int			chunk_n;
	unsigned	f;
	unsigned	u;
	int			round;
	int			step;
}					t_md5;

void				process_stdio_cmd(void);
void				dispatcher(int argc, char **argv);
char				**check_mdop(int argc, char **argv, char *cmd, int *mdop);
void				ft_tdstrdel(char ***tdstr);
int					validate_option(char **argv, char *cmd,
						int (*validator)(char), int (*msg)(char *, char *));

/*
** md5
*/

unsigned md5f(unsigned abcd[4]);
unsigned md5g(unsigned abcd[4]);
unsigned md5h(unsigned abcd[4]);
unsigned md5i(unsigned abcd[4]);
unsigned leftrotate(unsigned a, int n);

/*
** command funcs
*/

void				process_md5(int argc, char **argv);
void				process_sha256(int argc, char **argv);
void				process_sha3(int argc, char **argv);

/*
** error messages
*/

void				error_cmd(char *str);
void				err_mdcmd(void);
void				err_stdcmd(void);
void				err_ciphercmd(void);
int					illegal_op_md(char *cmd, char *option);

#endif
