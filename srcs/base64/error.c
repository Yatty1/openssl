/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 21:34:29 by syamada           #+#    #+#             */
/*   Updated: 2018/09/17 22:05:06 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	usage_base64(void)
{
	ft_putstrerr("usage: base64");
	ft_putstrerr(" [-i inputfile] [-o inpufile]\n");
	ft_putstrerr("-d, --decode	decode inputs\n\
-e, --encode	encode inputs\n\
-i, --input	input files\n\
-o, --output	output files\n");
}

int		illegal_op_base64(char *cmd, char *option)
{
	ft_putstrerr(cmd);
	ft_putstrerr(": illegal option -- ");
	ft_putstrerr(option);
	ft_putstrerr("\n");
	usage_base64();
	return (0);
}

void	o_error(void)
{
	ft_putstrerr("base64: ");
	ft_putstrerr("option requires an argument -- o\n");
	usage_base64();
}
