/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 04:58:33 by ple-stra          #+#    #+#             */
/*   Updated: 2021/11/27 23:46:21 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_dup;
	char	*s_iter;

	s_dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s_dup)
		return (NULL);
	s_iter = s_dup;
	while (*s)
	{
		*(s_iter++) = *(s++);
	}
	*s_iter = 0;
	return (s_dup);
}	

// int	main(void)
// {
// 	char 	*str;
// 	char	*tmp = "Hello je suis une string";

// 	str = ft_strdup(tmp);
// 	printf("%s\n", str);
// 	printf("%s\n", tmp);
// }
