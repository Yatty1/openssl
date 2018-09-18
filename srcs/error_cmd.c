/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:31:10 by syamada           #+#    #+#             */
/*   Updated: 2018/09/17 21:35:42 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	error_cmd(char *str, t_cmd *cmd)
{
	ft_putstrerr("./ft_ssl: Error: ");
	ft_putstrerr(str);
	ft_putstrerr(" is an invalid command\n\n");
	ft_putstrerr("Standard commands: \n\n");
	ft_putstrerr("Message Digest commands:\n");
	err_mdcmd(cmd);
	ft_putstrerr("Cipher commands:\n\n");
}

void	err_mdcmd(t_cmd *cmd)
{
	int		i;

	i = 0;
	while (i < CMD_NUM)
	{
		ft_putstrerr(cmd[i++].name);
		ft_putstrerr("\n");
	}
	ft_putstrerr("\n");
}
