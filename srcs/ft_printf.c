/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 02:32:40 by romain            #+#    #+#             */
/*   Updated: 2021/04/22 22:36:41 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** - = left justify
** 0 = left pad with 0s instead of spaces where padding is requested
**num= for digits it sets minimum amt of space.
** . = precision, on floats it shows how far to go, on ints it shows the
**minimum amount of digits to write, for strings this is the maximum space
**you can take(will truncate)
** .*= precision is the previous argument.
**main function initializes, second starts outputting chars, if
** 0 precision + 0 value on the value == no output
** 0 precision on string is no output no matter the value
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
			i += processed;
			if (var->type)
			{
				if (ft_print_arg(var) == -1)
				{
					var->retval = -1;
					return ;
				}
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
	int ret;

	if (var->type == 'c')
		ret = ft_print_char(var);
	else if (var->type == 's')
		ret = ft_print_str(var);
	else if (var->type == 'p')
		ret = ft_print_address(var);
	else if (var->type == 'd' || var->type == 'i')
		ret = ft_print_int(var);
	else if (var->type == 'u')
		ret = ft_print_uint(var);
	else if (var->type == 'x' || var->type == 'X')
		ret = ft_print_hex(var);
	else if (var->type == '%')
		ret = ft_print_percent(var);
	else
		return (-1);
	return (ret);
}

int		ft_print_nonformat(t_container *var, int i)
{
	write(1, var->format + i, 1);
	var->retval++;
	return (0);
}

int		ft_printf(const char *format, ...)
{
	t_container var;

	var.format = format;
	var.retval = 0;
	ft_struct_init(&var);
	va_start(var.ap, format);
	ft_read(&var);
	va_end(var.ap);
	return (var.retval);
}
