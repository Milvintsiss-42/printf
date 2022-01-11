/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:52:15 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/11 01:59:34 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse2(
				int *total_len,
				t_list **print,
				const char *start,
				va_list ap
				);

int	ft_parse(t_list **print, const char *format, va_list ap)
{
	const char	*start;
	int			total_len;
	int			len_read;

	(void)ap;
	total_len = 0;
	while (*format)
	{
		start = format;
		while (*format && *format != '%')
			format++;
		if (!ft_addstr(print, start, format - start))
			return (-1);
		total_len += format - start;
		if (*format == '%')
		{
			len_read = ft_parse2(&total_len, print, ++format, ap);
			if (len_read == -1)
				return (-1);
			format += len_read;
		}
	}
	return (total_len);
}

static int	ft_parsechar(int *total_len, t_list **print, char c)
{
	if (!ft_addstr(print, &c, 1))
		return (-1);
	*total_len += 1;
	return (1);
}

static int	ft_parsestring(int *total_len, t_list **print, char *s)
{
	int	len;

	len = ft_strlen_c(s, '%');
	if (!ft_addstr(print, s, len))
		return (-1);
	*total_len += len;
	return (1);
}

static int	ft_parseint(int *total_len, t_list **print, int n)
{
	char	*s;
	int		len;
	int		r;

	s = ft_itoa(n);
	if (!s)
		return (-1);
	len = ft_strlen(s);
	r = ft_addstr(print, s, len);
	free(s);
	if (!r)
		return (-1);
	*total_len += len;
	return (1);
}

static int	ft_parseunsigned(int *total_len, t_list **print, unsigned int n)
{
	char	*s;
	int		len;
	int		r;

	s = ft_itoa_u(n);
	if (!s)
		return (-1);
	len = ft_strlen(s);
	r = ft_addstr(print, s, len);
	free(s);
	if (!r)
		return (-1);
	*total_len += len;
	return (1);
}

static int	ft_parse2(
				int *total_len,
				t_list **print,
				const char *start,
				va_list ap
				)
{
	if (*start == '%')
		return (ft_parsechar(total_len, print, '%'));
	if (*start == 'c')
		return (ft_parsechar(total_len, print, (char)va_arg(ap, int)));
	if (*start == 's')
		return (ft_parsestring(total_len, print, va_arg(ap, char *)));
	if (*start == 'd' || *start == 'i')
		return (ft_parseint(total_len, print, va_arg(ap, int)));
	if (*start == 'u')
		return (ft_parseunsigned(total_len, print, va_arg(ap, unsigned int)));
}
