/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 04:23:33 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/05 20:09:01 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf2(const char *format, va_list ap);
static int	ft_vasprintf(char **ret, const char *format, va_list ap);

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_printf2(format, ap);
	va_end(ap);
	return (len);
}

static int	ft_printf2(const char *format, va_list ap)
{
	char	*str;
	int		len;

	len = ft_vasprintf(&str, format, ap);
	ft_putstr(str);
	return (len);
}

static int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	t_list	*print;
	int		len;

	(void)ap;
	len = ft_parse(&print, format, ap);
	if (!ft_buildstr(ret, print, len))
		return (-1);
	return (len);
}
