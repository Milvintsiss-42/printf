/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 03:05:47 by ple-stra          #+#    #+#             */
/*   Updated: 2021/11/28 01:45:24 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c == -1)
		return (-1);
	if (c < -1)
		return ((unsigned char)c);
	return (c + (c >= 'A' && c <= 'Z') * 32);
}

// int	main(void)
// {
// 	printf("%d", ft_tolower(-100));
// }
