/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 18:44:38 by syamada           #+#    #+#             */
/*   Updated: 2018/09/03 16:21:36 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	process_md5(int argc, char **argv)
{
	int		op;
	int		i;
	t_md5	*md5;

	i = 0;
	op = 0;
	if (!(argv = check_mdop(argc, argv, "md5", &op)))
		return ;
	md5 = init_md5(argv[0], ft_strlen(argv[0]));
	md5 = transform_md5(md5);
	output_md5(md5);
	/*
	if (!*argv || MATCH(op, FLP))
		return ; // process stdio
	while (i)
	{
	}
	*/
	ft_tdstrdel(&argv);
}
