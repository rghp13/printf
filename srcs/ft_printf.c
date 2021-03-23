/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 02:32:40 by romain            #+#    #+#             */
/*   Updated: 2021/03/23 16:50:51 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** c = Char
** s = String
** p = Memory address
** d = Signed int
** i = Signed int
** u = Unsigned int
** x = Hexadecimal, so take the int and convert to hex
** X = Hexadecimal
** % = for when you want the % symbol to display
** - = left justify
** 0 = left pad with 0s instead of spaces where padding is requested
** .*= precision is the previous argument.
*/

void	ft_read(t_container container)
{
	
}

int		ft_printf(const char *format, ...)
{
	t_container container;

	container.format = format;
	va_start(container.ap, container.format);
	ft_read(container);
	
	return (container.retval);
}
