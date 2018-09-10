/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base64.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 19:48:29 by syamada           #+#    #+#             */
/*   Updated: 2018/09/09 19:54:22 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BASE64_H
# define FT_BASE64_H

# define FLD 0x01
# define FLE 0x02
# define FLI 0x04
# define FLO 0x08

char	**check_base64op(int argc, char **argv, int *op);

#endif
