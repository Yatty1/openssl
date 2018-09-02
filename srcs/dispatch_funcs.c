/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 11:53:09 by syamada           #+#    #+#             */
/*   Updated: 2018/09/01 17:12:37 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	process_md5(int argc, char **argv)
{
	int		op;
	int		i;

	i = 0;
	op = 0;
	if (!(argv = check_mdop(argc, argv, &op)))
		return ;
	printf("flag: %d\n", op);
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
