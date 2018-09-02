/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 21:05:10 by syamada           #+#    #+#             */
/*   Updated: 2018/09/01 17:08:56 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

int		illegal_op_md(char *cmd, char *option)
{
	ft_putstrerr(cmd);
	ft_putstrerr(": illegal option -- ");
	ft_putstrerr(option);
	ft_putstrerr("\n");
	ft_putstrerr("usage: ");
	ft_putstrerr(cmd);
	ft_putstrerr(" [-pqr] [-s string] [files ...]\n");
	return (0);
}
