/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:28:59 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/23 17:03:16 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "includes/ft_printf.h"

int	main(void)
{
	int a;
	int b;

	a = 0x7fffffff;
	b = 42;
	printf("%d\n", ft_printf("%*.4d\n", a, b));
	return (0);
}
