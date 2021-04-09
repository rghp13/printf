/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:27:17 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/09 22:53:23 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_container *var)
{
	char	hold;
	char	*ptr;
	int		i;

	hold = va_arg(var->ap, char);
	i = 0;
	if (!(ptr = malloc(sizeof(char) * var->fwidth + 1)))
		return (-1);
	ptr[var->fwidth + 1] = '\0';
	while (var->fwidth > i)
		ptr[i++] = ' ';
	if (var->fleft)
		ptr[var->fwidth] = hold;
	else
		ptr[0] = hold;
	var->retval += ft_str_to_stdout(ptr);
	free(ptr);
	return (0);
}
/*
**TRUNCATE IF PRECISION IS SMALLER THAN STRING
**OTHERWISE IF WIDTH IS SMALLER THAN STRING YOU CAN GO OVER
*/

int	ft_print_str(t_container *var)
{
	char	*hold;
	char	*ptr;
	int		len;

	hold = va_arg(var->ap, char*);
	len = ft_strlen(hold);
	if (var->fprecision > 0 && var->fprecision < len)//this means there is truncation
		ft_str_trunc(hold, var);
	else//no trunc
	{
		if (var->fwidth > len)
		{
			if (!(ptr = malloc(sizeof(char) * var->fwidth + 1)))
		}
	}
}
