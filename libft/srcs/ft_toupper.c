/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 03:11:09 by ple-stra          #+#    #+#             */
/*   Updated: 2021/11/28 01:46:57 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c == -1)
		return (-1);
	if (c < -1)
		return ((unsigned char)c);
	return (c - (c >= 'a' && c <= 'z') * 32);
}
