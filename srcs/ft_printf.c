/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 02:32:40 by romain            #+#    #+#             */
/*   Updated: 2021/04/12 15:07:34 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** - = left justify
** 0 = left pad with 0s instead of spaces where padding is requested
**num= for digits it sets minimum amt of space.
** . = precision, on floats it shows how far to go, on ints it shows the minimum amount of digits to write, for strings this is the maximum space you can take(will truncate)
** .*= precision is the previous argument.
**main function initializes, second starts outputting chars, if
*/

void	ft_read(t_container *var)
{
	int i;
	int processed;

	i = -1;
	while (var->format[++i])
	{
		processed = 0;
		if (var->format[i] == '%' && var->format[i + 1] != '\0')
		{
			processed = ft_flag_check(var, ++i);
			if (processed && var->type)
			{
				if (ft_print_arg(var) < 0)
					ft_putstr_fd("Error, entered ft_print_arg with no type", 1);
				i += processed;
			}
			else
				ft_print_nonformat(var, i);
		}
		else
			ft_print_nonformat(var, i);
	}
}

int		ft_print_arg(t_container *var)
{
	if (var->type == 'c')
		ft_print_char(var);
	else if (var->type == 's')
		ft_print_str(var);
	else if (var->type == 'p')
		ft_print_address(var);
	else if (var->type == 'd' || var->type == 'i')
		ft_print_int(var);
	else if (var->type == 'u')
		ft_print_uint(var);
	else if (var->type == 'x' || var->type == 'X')
		ft_print_hex(var);
	else if (var->type == '%')
		ft_print_percent(var);
	else
		return (-1);
	return (0);
}

int		ft_print_nonformat(t_container *var, int i)
{
	write(1, var->format + i, 1);
	var->retval++;
}

int		ft_printf(const char *format, ...)
{
	t_container var;

	var.format = format;
	var.retval = 0;
	ft_struct_init(&var);
	va_start(var.ap, var.format);
	ft_read(&var);
	return (var.retval);
}
