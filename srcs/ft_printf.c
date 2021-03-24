/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 02:32:40 by romain            #+#    #+#             */
/*   Updated: 2021/03/24 18:03:53 by rponsonn         ###   ########.fr       */
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
**main function initializes, second starts outputting chars, if
*/

void	ft_read(t_container var)
{
	int i;
	int processed;

	i = -1;
	while (var.format[++i])
	{
		processed = 0;
		if (var.format[i] == '%' && var.format[i + 1] != '\0')
		{
			processed = ft_flag_check(var, i);
			if (processed)
			{
				ft_print_arg(var);
				i += processed;
			}
			else
				ft_print_char(var, i);
		}
		else
			ft_print_char(var, i);
	}
}

int		ft_printf(const char *format, ...)
{
	t_container var;

	var.format = format;
	ft_struct_init(var);
	va_start(var.ap, var.format);
	ft_read(var);
	return (var.retval);
}
