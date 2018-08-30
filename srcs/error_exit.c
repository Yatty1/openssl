/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:32:16 by syamada           #+#    #+#             */
/*   Updated: 2018/08/30 14:43:27 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	error_cmd(char *str)
{
	ft_putstrerr("./ft_ssl: Error: ");
	ft_putstrerr(str);
	ft_putstrerr("is an invalid command\n");
	ft_putstrerr("Standard commands: \n\n");
	ft_putstrerr("Message Digest commands:\n");
	err_mdcmd();
	ft_putstrerr("Cipher commands:\n\n");
	exit(1);
}

void	err_mdcmd(void)
{
	ft_putstrerr("md5\n");
	ft_putstrerr("sha256\n");
}
