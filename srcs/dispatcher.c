/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:27:54 by syamada           #+#    #+#             */
/*   Updated: 2018/08/30 21:22:28 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	process_md5(int argc, char **argv)
{
	int		mdop;
	int		i;

	i = 0;
	mdop = 0;
	argv = check_mdop(argc, argv, &mdop);
	printf("flag: %d\n", mdop);
	while (argv[i])
		printf("argv: %s\n", argv[i++]);
	ft_tdstrdel(&argv);
}

void	process_sha256(int argc, char **argv)
{
}

void	process_sha3(int argc, char **argv)
{
}
