/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:28:59 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/19 17:34:19 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "includes/ft_printf.h"

int	main(void)
{
/*	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
*/
	ft_printf("%.*d\n", 4, -12);
	printf("%.*d\n", 4, -12);
	return (0);
}

/*
**if val is 0 and prec is 0 pdiuxX
**(p still puts 0x prefix)
**(don't need to do anything for c and s because 0 is null terminator)
**NEW BUG == * BEING A NEGATIVE NUMBER IN PRECISION OR WIDTH
**Negative precision is ignored. negative width is turned into positive
**NEW BUG == if negative 2 digit gets 3 width you have to output -012 instead of -12
**NEW BUG == find out why %0*d prints 0-12
*/
