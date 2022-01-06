/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 03:25:32 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/05 22:44:21 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>

# define P_NULL "(null)"

typedef struct s_str
{
	char	*str;
	size_t	len;
}	t_str;

int		ft_printf(const char *format, ...);

int		ft_parse(t_list **print, const char *format, va_list ap);

int		ft_buildstr(char **ret, t_list *lst, int len);

int		ft_addstr(t_list **lst, char *str, size_t len);
int		ft_clearlst(t_list *lst);
int		ft_freestr(t_str *s_str);

#endif