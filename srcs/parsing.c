/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:52:15 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/05 22:45:29 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(t_list **print, const char *format, va_list ap)
{
	char	*start;
	int		len;

	*print = ft_lstnew(NULL);
	if (!*print)
		return (-1);
	(*print)->content = malloc(sizeof(char));
	if (!(*print)->content)
		return (-1);
	*(char *)(*print)->content = 0;
	while (*format)
	{
		start = format;
		while (*format && *format != '%')
			format++;
		if (*format)
		{
			if (!ft_addstr(print, format, format - start - 1))
				return (ft_clearlst(*print));
			len += format - start - 1;
			// ft_add();
		}
	}
	return (len);
}
