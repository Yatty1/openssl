/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 01:00:39 by syamada           #+#    #+#             */
/*   Updated: 2018/09/09 19:55:59 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	process_base64(int argc, char **argv)
{
	int		op;

	op = 0;
	if (!(argv = check_base64op(argc, argv, &op)))
		return ;
	int i = 0;
	ft_putnbr(op);
	ft_putchar('\n');
	while (argv[i])
		ft_putendl(argv[i++]);
}
