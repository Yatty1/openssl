/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 21:05:10 by syamada           #+#    #+#             */
/*   Updated: 2018/09/17 21:35:30 by syamada          ###   ########.fr       */
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

int		open_error(char *cmd, char *filename)
{
	ft_putstrerr(cmd);
	ft_putstrerr(": ");
	ft_putstrerr(filename);
	ft_putstrerr(": ");
	ft_putstrerr(strerror(errno));
	ft_putstrerr("\n");
	return (0);
}

int		noparam_error(char *cmd, char *option)
{
	ft_putstrerr(cmd);
	ft_putstrerr(": option ");
	ft_putstrerr(option);
	ft_putstrerr(" requires parameter\n");
	ft_putstrerr("usage: ");
	ft_putstrerr(cmd);
	ft_putstrerr(" [-pqr] [-s string] [files ...]\n");
	return (0);
}
