/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 01:00:39 by syamada           #+#    #+#             */
/*   Updated: 2018/09/16 19:04:47 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	process_base64(int argc, char **argv)
{
	int		op;

	op = 0;
	if (!(argv = check_base64op(argc, argv, &op)))
		return ;
	if (MATCH(op, FLE) || op == 0)
		encode_base64(argv[0], ft_strlen(argv[0]));
	if (MATCH(op, FLD))
		decode_base64(argv[0], ft_strlen(argv[0]));
}
