/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:28:59 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/19 14:00:18 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "includes/ft_printf.h"

int	main(void)
{
	unsigned num;

	num = 0xfff;
	ft_printf("_%*x_\n", -5, num);
	ft_printf("_%*x_\n", 5, num);
	printf("_%*x_\n", -5, num);
	printf("_%*x_\n", 5, num);
	return (0);
}

/*
**if val is 0 and prec is 0 pdiuxX
**(p still puts 0x prefix)
**(don't need to do anything for c and s because 0 is null terminator)
**NEW BUG == * BEING A NEGATIVE NUMBER IN PRECISION OR WIDTH
**Negative precision is ignored. negative width is turned into positive
*/
