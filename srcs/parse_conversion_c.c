/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:53:15 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/24 17:56:51 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parsechar(t_mod mod, t_list **print, char c)
{
	if (c != '%' && !ft_checkflag(mod.flags, FLAG_PADR))
		if (!ft_addpad(print, mod.width - 1))
			return (-1);
	if (!ft_addstr_b(print, &c, 1))
		return (-1);
	if (c != '%' && ft_checkflag(mod.flags, FLAG_PADR))
		if (!ft_addpad(print, mod.width - 1))
			return (-1);
	if (c == '%')
		return (1);
	return (ft_max(mod.width, 1));
}
