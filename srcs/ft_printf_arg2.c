/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:39:01 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/16 18:08:10 by rponsonn         ###   ########.fr       */
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
	unsigned	num;
	char		*str;
	char		*hold;

	num = va_arg(var->ap, unsigned int);
	str = ft_utoa(num);
	if (ft_strlen(str) < (size_t)var->fprecision)
	{
		hold = ft_prefprecision(var, str);
		free(str);
		str = hold;
	}
	if ((size_t)var->fwidth > ft_strlen(str))
		ft_printstrwhitespace(var, str, ft_strlen(str));
	else
		var->retval += ft_str_to_stdout(str);
	free(str);
	return (0);
}

/*
**ignore precision
**width is followed
**0fill is followed if no left adjust
*/

int		ft_print_percent(t_container *var)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * 2)))
		return (-1);
	str[0] = '%';
	str[1] = '\0';
	if ((size_t)var->fwidth > ft_strlen(str))
		ft_printstrwhitespace(var, str, ft_strlen(str));
	else
		var->retval += ft_str_to_stdout(str);
	free(str);
	return (0);
}
