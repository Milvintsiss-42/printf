/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 04:00:43 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/11 01:55:10 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(int argc, char const **argv)
{
	int		len1;
	int		len2;
	char	*null_ptr;
	char	c;

	c = '$';
	null_ptr = NULL;
	printf("Null ptr: %p\n", null_ptr);
	
	ft_putstr("printf: ");
	len1 = printf(argv[1], c, argv[2], 123, 123, -1);
	ft_putstr("ft_printf: ");
	len2 = ft_printf(argv[1], c, argv[2], 123, 123, -1);
	
	printf("len printf: %d\n", len1);
	printf("len ft_printf: %d\n", len2);
	return (0);
}
