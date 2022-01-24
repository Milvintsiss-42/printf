/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:25:33 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/17 19:20:08 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_addstr(
				t_list **lst,
				const char *str,
				size_t len,
				void (*lstadd)(t_list **, t_list *)
				)
{
	t_str	*s_str;
	t_list	*new;

	s_str = malloc(sizeof(t_str));
	if (!s_str)
		return (0);
	s_str->str = malloc(sizeof(char) * len);
	if (!s_str->str)
		return (ft_free(s_str));
	s_str->str = ft_memcpy(s_str->str, str, len);
	s_str->len = len;
	new = ft_lstnew(s_str);
	if (!new)
		return (ft_freestr(s_str));
	(*lstadd)(lst, new);
	return (1);
}

int	ft_addstr_b(t_list **lst, const char *str, size_t len)
{
	return (ft_addstr(lst, str, len, &ft_lstadd_back));
}

int	ft_addstr_n(t_list **lst, const char *str, size_t len)
{
	return (ft_addstr(lst, str, len, &ft_lstadd_next));
}

int	ft_freestr(t_str *s_str)
{
	free(s_str->str);
	free(s_str);
	return (0);
}

int	ft_clearlst(t_list *lst)
{
	t_list	*to_free;

	while (lst)
	{
		to_free = lst;
		lst = lst->next;
		ft_freestr(to_free->content);
		free(to_free);
	}
	return (-1);
}
