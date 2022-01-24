/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 03:25:32 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/24 18:19:33 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>

# define INV_FMT "(invalid format)"

# define STR_NULL "(null)"
# ifdef __linux__
#  define PTR_NULL "(nil)"
# else
#  define PTR_NULL "(0x0)"
# endif

# define FLAG_ALTER		1
# define FLAG_SPACE		2
# define FLAG_PLUS		4
# define FLAG_PADR		8
# define FLAG_ZERO		16
# define FLAG_PREC		32

typedef struct s_str
{
	char	*str;
	size_t	len;
}	t_str;

typedef struct s_mod
{
	int				flags;
	unsigned int	width;
	unsigned int	prec;
}	t_mod;

int				ft_printf(const char *format, ...);

int				ft_parse(t_list **print, const char *format, va_list ap);

int				ft_buildstr(char **ret, t_list *lst, int len);

int				free_all(t_list *lst);

int				ft_addstr_b(t_list **lst, const char *str, size_t len);
int				ft_addstr_n(t_list **lst, const char *str, size_t len);
int				ft_clearlst(t_list *lst);
int				ft_freestr(t_str *s_str);

int				ft_isconversion(char c);
int				ft_ishexconversion(char c);
int				ft_isnumericconversion(char c);

int				ft_getflags(const char **fmt);
unsigned int	ft_getwidth(const char **fmt);
unsigned int	ft_getprecision(const char **fmt, int *flags);
t_mod			ft_handle_args_exceptions(t_mod mod);

int				ft_invalidconversion(t_list **print);

int				ft_parsechar(t_mod mod, t_list **print, char c);
int				ft_parsestring(t_mod mod, t_list **print, char *s);
int				ft_parseptr(t_mod mod, t_list **print, void *ptr);
int				ft_parseint(t_mod mod, t_list **print, int n);
int				ft_parseunsign(t_mod mod, t_list **print, unsigned int n,
					const char *base);

int				ft_addpad(t_list **print, int nb);
int				ft_addstr_and_padding(t_mod mod, t_list **print, char *str,
					int len);
char			*ft_prec(char *str, t_mod mod);
int				ft_preczero_nzero(t_mod mod, t_list **print);

#endif