/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:14:34 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/22 15:09:07 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_check(t_container *var, int i)
{
	int diff;

	diff = i;
	ft_struct_init(var);
	i += ft_parse_flag(var, i);
	i += ft_parse_precision(var, i);
	i += ft_parse_type(var, i, VALTYPE);
	ft_parse_sanitize(var);
	return (i - diff);
}

int		ft_parse_type(t_container *var, int i, char *type)
{
	int		diff;

	diff = i;
	while (ft_strchr(type, var->format[i]) == 0 && var->format[i] != '\0')
		i++;
	if (var->format[i])
		var->type = var->format[i];
	else if (var->format[i] == '\0')
		i--;
	return (i - diff);
}

int		ft_parse_precision(t_container *var, int i)
{
	char	hold;
	int		diff;

	diff = i;
	hold = var->format[i];
	if (hold == '.')
	{
		i++;
		var->fzp = TRUE;
		if (var->format[i] == '*')
			var->fprecision = va_arg(var->ap, int);
		else if (var->format[i] >= '0' && var->format[i] <= '9')
		{
			var->fprecision = ft_atoi(var->format + i);
			while (ft_isdigit(var->format[i]))
				i++;
			i--;
		}
		else
			return (i - diff);
		i++;
	}
	return (i - diff);
}

int		ft_parse_flag(t_container *var, int i)
{
	int		diff;

	diff = i;
	while (TRUE)
	{
		if (var->format[i] == ' ')
			var->retval += ft_str_to_stdout(" ");
		else if (var->format[i] == '-')
			var->fleft = 1;
		else if (var->format[i] == '0')
			var->fzero = 1;
		else if (var->format[i] == '*')
			var->fwidth = va_arg(var->ap, int);
		else if (var->format[i] > '0' && var->format[i] <= '9')
		{
			var->fwidth = ft_atoi(var->format + i);
			while (ft_isdigit(var->format[i]))
				i++;
			i--;
		}
		else
			break ;
		i++;
	}
	return (i - diff);
}

void	ft_parse_sanitize(t_container *var)
{
	if (var->fwidth < 0)
	{
		var->fwidth = -var->fwidth;
		var->fleft = TRUE;
	}
	if (var->fprecision < 0)
	{
		var->fprecision = 0;
		var->fzp = FALSE;
	}
}
