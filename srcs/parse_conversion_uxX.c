/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion_uxX.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:48:01 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/24 17:53:57 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_alter(char *str, t_mod mod, unsigned int n, const char *base)
{
	char	*tmp;

	if (!ft_checkflag(mod.flags, FLAG_ALTER) || n == 0 || base[10] == 0)
		return (str);
	tmp = str;
	if (base[10] == 'a')
		str = ft_strjoin("0x", tmp);
	else
		str = ft_strjoin("0X", tmp);
	free(tmp);
	return (str);
}

static int	ft_parseunsign2(t_mod mod, t_list **print, unsigned int n,
	const char *base)
{
	char	*str;
	int		len;

	str = ft_itoa_base_u(n, base);
	if (!str)
		return (-1);
	str = ft_prec(str, mod);
	if (!str)
		return (-1);
	str = ft_alter(str, mod, n, base);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	return (ft_addstr_and_padding(mod, print, str, len));
}

int	ft_parseunsign(t_mod mod, t_list **print, unsigned int n, const char *base)
{
	if (n == 0 && ft_checkflag(mod.flags, FLAG_PREC) && mod.prec == 0)
		return (ft_preczero_nzero(mod, print));
	return (ft_parseunsign2(mod, print, n, base));
}
