/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:04:09 by syamada           #+#    #+#             */
/*   Updated: 2018/08/30 14:47:27 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	process_arg(char **argv)
{
	if (ft_strequ(argv[0], "md5"))
		process_md5(argv);
	else if (ft_strequ(argv[0], "sha256"))
		process_sha256(argv);
	else
		error_cmd(argv[0]);
}
