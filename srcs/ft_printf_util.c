/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:15:47 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/02 16:37:52 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_struct_init(t_container *var)
{
	var->fleft = 0;
	var->fprecision = 0;
	var->fwidth = 0;
	var->fzero = 0;
	var->type = 0;
	return ;
}

int		ft_flag_check(t_container *var, int i)
{
	int diff;

	diff = i;
	ft_struct_init(var);
	i += ft_parse_flag(var, i);
	i += ft_parse_precision(var, i);
	ft_is_valid_type(var->format[i], VALTYPE);
	return (i - diff);
}

int		ft_parse_precision(t_container *var, int i)
{
	
}

int		ft_parse_flag(t_container *var, int i)//look for '-' '0' a num or * then '.'
{
	char	hold;
	int		diff;

	diff = i;
	hold = var->format[i];
	if (hold == '-')
		var->fleft = 1;
	else if (hold == '0')
		var->fzero = 1;
	else if (hold == '*')
		var->fwidth = va_arg(var->ap, int);
	else if (hold > '0' && hold <= '9')
	{
		var->fwidth = ft_atoi(var->format[i]);
		while (ft_isalnum(var->format[i]))
			i++;
	}
	else
		return (i - diff);
	i++;
}
