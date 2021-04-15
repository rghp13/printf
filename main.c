/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:28:59 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/15 18:32:34 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "printf.h"

int	main(void)
{
	unsigned int i;

	i = 1234;
	ft_printf("%5d\n", i);
	return (0);
}
