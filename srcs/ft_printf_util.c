/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:15:47 by rponsonn          #+#    #+#             */
/*   Updated: 2021/03/27 14:14:23 by rponsonn         ###   ########.fr       */
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
	ft_struct_init(var);
	i += ft_parse_flag(var, i);
	i += ft_parse_precision(var, i);
	if (ft_is_valid_type(var->format[i], VALTYPE))
	{
		;
	}
}
