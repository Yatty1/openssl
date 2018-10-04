/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_des.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 22:40:39 by syamada           #+#    #+#             */
/*   Updated: 2018/09/22 14:54:55 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DES_H
# define FT_DES_H

# define DESFLA 0x01
# define DESFLD 0x02
# define DESFLE 0x04
# define DESFLI 0x08
# define DESFLK 0x10
# define DESFLO 0x20
# define DESFLP 0x40
# define DESFLS 0x80
# define DESFLV 0x100

typedef struct	s_des
{
	char		*key;
	uint64_t	o_key;
	char		p_key[7];
	char		*salt;
	char		*iv;
	char		*passwd;
	char		*msg;
}				t_des;

void		process_des(int argc, char **argv);

#endif
