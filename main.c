/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:28:59 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/17 16:05:20 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "includes/ft_printf.h"

int	main(void)
{
	int retval;

	retval = 5;
	retval = ft_printf("%d\n", retval);
	//ft_printf("Return value is %d\n", retval);
	retval = printf("%.0c\n", 0);
	printf("Return value is %d\n", retval);
	return (0);
}
