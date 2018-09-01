/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:31:10 by syamada           #+#    #+#             */
/*   Updated: 2018/09/01 16:43:21 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	error_cmd(char *str)
{
	ft_putstrerr("./ft_ssl: Error: ");
	ft_putstrerr(str);
	ft_putstrerr(" is an invalid command\n\n");
	ft_putstrerr("Standard commands: \n\n");
	ft_putstrerr("Message Digest commands:\n");
	err_mdcmd();
	ft_putstrerr("Cipher commands:\n\n");
}

void	err_mdcmd(void)
{
	ft_putstrerr("md5\n");
	ft_putstrerr("sha256\n");
	ft_putstrerr("\n");
}
