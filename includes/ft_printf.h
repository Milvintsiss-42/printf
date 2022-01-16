/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 03:25:32 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/16 18:22:15 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>

# define STR_NULL "(null)"
# ifdef __linux__
#  define PTR_NULL "(nil)"
# else
#  define PTR_NULL "(0x0)"
# endif

# define FLAG_ALTER		0x01
# define FLAG_SPACE		0x02
# define FLAG_PLUS		0x04
# define FLAG_PADR		0x08
# define FLAG_ZERO		0x16

typedef struct s_str
{
	char	*str;
	size_t	len;
}	t_str;

int		ft_printf(const char *format, ...);

int		ft_parse(t_list **print, const char *format, va_list ap);

int		ft_buildstr(char **ret, t_list *lst, int len);

int		free_all(t_list *lst);

int		ft_addstr(t_list **lst, const char *str, size_t len);
int		ft_clearlst(t_list *lst);
int		ft_freestr(t_str *s_str);

#endif