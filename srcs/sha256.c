/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 18:45:11 by syamada           #+#    #+#             */
/*   Updated: 2018/09/04 16:13:15 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			process_sha256(int argc, char **argv)
{
	int		op;
	int		i;

	i = 0;
	op = 0;
	if (!(argv = check_mdop(argc, argv, "sha256", &op)))
		return ;
	if ((!*argv || MATCH(op, FLP)) &&
			!(!*argv && MATCH(op, FLS) && !MATCH(op, FLP)))
		//encrypt_stdio(op);
	if (!*argv && MATCH(op, FLS))
		noparam_error("sha256", "s");
	if (*argv && MATCH(op, FLS))
		//encrypt_str(argv[i++], &op);
	while (argv[i])
		//encrypt_file(argv[i++], &op);
	if (op != 0)
		ft_tdstrdel(&argv);
}
