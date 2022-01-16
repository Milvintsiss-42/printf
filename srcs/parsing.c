/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:52:15 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/16 18:59:28 by ple-stra         ###   ########.fr       */
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
	char	*str;
	int		len;

	if (s == NULL)
		str = STR_NULL;
	else
		str = s;
	len = ft_strlen(str);
	if (!ft_addstr(print, str, len))
		return (-1);
	*total_len += len;
	return (1);
}

static int	ft_parseptr(int *total_len, t_list **print, void *ptr)
{
	char	*str;

	if (ptr == NULL)
	{
		if (!ft_addstr(print, PTR_NULL, ft_strlen(PTR_NULL)))
			return (-1);
		*total_len += ft_strlen(PTR_NULL);
		return (1);
	}
	else
	{
		str = ft_itoa_base_ul((unsigned long)ptr, HEX_BASE);
		if (!str)
			return (-1);
		if (!ft_addstr(print, "0x", 2)
			|| !ft_addstr(print, str, ft_strlen(str)))
		{
			free(str);
			return (-1);
		}
		*total_len += 2 + ft_strlen(str);
		free(str);
		return (1);
	}
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

static int	ft_parseunsignedbase(
				int *total_len,
				t_list **print,
				unsigned int n,
				const char *base
				)
{
	char	*s;
	int		len;
	int		r;

	s = ft_itoa_base_u(n, base);
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
	if (*start == 'p')
		return (ft_parseptr(total_len, print, va_arg(ap, void *)));
	if (*start == 'd' || *start == 'i')
		return (ft_parseint(total_len, print, va_arg(ap, int)));
	if (*start == 'u')
		return (ft_parseunsignedbase(total_len, print, va_arg(ap, unsigned int),
				DEC_BASE));
	if (*start == 'x')
		return (ft_parseunsignedbase(total_len, print, va_arg(ap, unsigned int),
				HEX_BASE));
	if (*start == 'X')
		return (ft_parseunsignedbase(total_len, print, va_arg(ap, unsigned int),
				HEX_BASE_CAPS));
	return (-1);
}

// static int ft_parseflags(int *total_len, t_list **print, const char **start)
// {
//
// }
