/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:39:01 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/23 15:50:32 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**if precision is longer than num len fill with 0s
**if width is longer than numlen(with precision) fill with blank spaces
**if width is longer than numless without precision with 0
*/

int		ft_print_uint(t_container *var)
{
	t_var	puint;

	puint.ret = 0;
	puint.usval = va_arg(var->ap, unsigned int);
	if ((puint.str = ft_utoa(puint.usval)) == NULL)
		return (-1);
	if (var->fzp && var->fprecision == 0 && puint.usval == 0)
		return (ft_zero_valprec(var, puint.str));
	if (ft_strlen(puint.str) < (size_t)var->fprecision)
	{
		puint.hold = ft_prefprecision(var, puint.str, 0);
		free(puint.str);
		if (puint.hold == NULL)
			return (-1);
		puint.str = puint.hold;
	}
	if ((size_t)var->fwidth > ft_strlen(puint.str))
		puint.ret = ft_printstrwhitespace(var, puint.str, ft_strlen(puint.str));
	else
		var->retval += ft_str_to_stdout(puint.str);
	free(puint.str);
	return (puint.ret);
}

/*
**ignore precision
**width is followed
**0fill is followed if no left adjust
*/

int		ft_print_percent(t_container *var)
{
	char	*str;
	int		ret;

	ret = 0;
	if (!(str = malloc(sizeof(char) * 2)))
		return (-1);
	str[0] = '%';
	str[1] = '\0';
	if ((size_t)var->fwidth > ft_strlen(str))
		ret = ft_printstrwhitespace(var, str, ft_strlen(str));
	else
		var->retval += ft_str_to_stdout(str);
	free(str);
	return (ret);
}
