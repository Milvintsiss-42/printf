/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:59:21 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/24 18:19:19 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_invalidconversion(t_list **print)
{
	if (!ft_addstr_b(print, INV_FMT, ft_strlen(INV_FMT)))
		return (-1);
	return (ft_strlen(INV_FMT));
}
