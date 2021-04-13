/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:27:17 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/13 17:35:05 by rponsonn         ###   ########.fr       */
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
	if (var->fprecision > 0 && var->fprecision < len)
		ft_str_trunc(hold, var);
	else
	{
		if (var->fwidth > len)
		{
			ft_printstrwhitespace(var, hold, len);
		}
		else
			var->retval += ft_str_to_stdout(hold);
	}
	return (0);
}

/*
**left adjust works, 0 fill does not.
**there is no precision.
*/

int	ft_print_address(t_container *var)
{
	unsigned long int	address;
	char				*hex;
	char				*ptr;

	address = va_arg(var->ap, unsigned long int);
	hex = ft_itoa_hex(address);
	ptr = ft_strjoin("0x", hex);
	free(hex);
	if (var->fwidth > ft_strlen(ptr))
		ft_printstrwhitespace(var, ptr, ft_strlen(ptr));
	else
		var->retval += ft_str_to_stdout(ptr);
	free(ptr);
	return (0);
}

/*
**
*/

int ft_print_int(t_container *var)
{
	
}