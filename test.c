/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ple-stra <ple-stra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 04:00:43 by ple-stra          #+#    #+#             */
/*   Updated: 2022/01/05 18:50:18 by ple-stra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(int argc, char const **argv)
{
	char	*null_ptr;

	//printf("Null ptr: %s", NULL);
	printf(argv[1]);
	ft_printf(argv[1]);
	return (0);
}
