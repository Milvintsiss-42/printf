/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:55:29 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/16 18:18:15 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_buildstr(char **ret, t_list *lst, int len)
{
	char	*str;
	t_str	s_str;

	*ret = malloc(sizeof(char) * (len + 1));
	if (!*ret)
		return (0);
	str = *ret;
	while (lst)
	{
		s_str = *(t_str *)(lst->content);
		ft_memcpy(str, s_str.str, s_str.len);
		str += s_str.len;
		lst = lst->next;
	}
	*str = 0;
	return (1);
}
