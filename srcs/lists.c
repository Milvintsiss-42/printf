/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:25:33 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/06 20:31:10 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_addstr(t_list **lst, const char *str, size_t len)
{
	t_str	*s_str;
	t_list	*new;

	printf("len: %d\n", len);
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
	ft_lstadd_back(lst, new);
	printf("end\n");
	return (1);
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
