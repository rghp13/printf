/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:27:17 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/22 16:40:57 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_container *var)
{
	char	hold;

	hold = va_arg(var->ap, int);
	if (var->fleft)
	{
		var->retval += ft_char_print(hold);
		var->retval += ft_pad_print(var->fwidth - 1);
	}
	else
	{
		var->retval += ft_pad_print(var->fwidth - 1);
		var->retval += ft_char_print(hold);
	}
	return (0);
}

/*
**TRUNCATE IF PRECISION IS SMALLER THAN STRING
**OTHERWISE IF WIDTH IS SMALLER THAN STRING YOU CAN GO OVER
*/

int	ft_print_str(t_container *var)
{
	char	*hold;
	int		len;

	hold = va_arg(var->ap, char*);
	if (hold == NULL)
		hold = ft_strdup("(null)");
	else
		hold = ft_strdup(hold);
	if (hold == NULL)
		return (-1);
	len = ft_strlen(hold);
	if (var->fzp && var->fprecision < len)
		ft_str_trunc(hold, var);
	else
	{
		if (var->fwidth > len)
		{
			if (ft_printstrwhitespace(var, hold, len) == -1)
				return (-1);
		}
		else
			var->retval += ft_str_to_stdout(hold);
	}
	free(hold);
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
	if (var->fprecision == 0 && var->fzp && address == 0)
		ptr[2] = '\0';
	if ((size_t)var->fwidth > ft_strlen(ptr))
		ft_printstrwhitespace(var, ptr, ft_strlen(ptr));
	else
		var->retval += ft_str_to_stdout(ptr);
	free(ptr);
	return (0);
}

/*
**0fill ignored if left adjusted. 0 prepend if precision is bigger than num len
**still add blank space if width is bigger. ignore 0 fill if there is any prec
** RETOOL INT TO DEAL WITH -1 PRECISION THATS NOW A POSSIBILITY
**RETOOL ITOA FOR NEG NUMBERS THAT NEED TO BE 0 FILLED FIRST
*/

int	ft_print_int(t_container *var)
{
	int		num;
	char	*str;
	char	*hold;
	int		ret;

	num = va_arg(var->ap, int);
	str = ft_abs_itoa(num);
	if (var->fzp && var->fprecision == 0 && num == 0)
		return (ft_zero_valprec(var, str));
	if (ft_strlen(str) < (size_t)var->fprecision)
	{
		hold = ft_prefprecision(var, str, num);
		free(str);
		str = hold;
	}
	if ((size_t)var->fwidth > ft_strlen(str) && (var->negflag || num >= 0))
		ret = ft_printstrwhitespace(var, str, strlen(str));
	else if ((size_t)var->fwidth > ft_strlen(str))
		ret = ft_printnegint(var, str, strlen(str));
	else
		ret = ft_join_print_int(var, str, num);
	free(str);
	return (ret);
}

/*
**0flag ignored, extra precision prefixes string with 0's but
**blank space still needed if the width is bigger than precision
*/

int	ft_print_hex(t_container *var)
{
	unsigned	hexval;
	char		*hex;
	char		*hold;

	hexval = va_arg(var->ap, unsigned int);
	hex = ft_itoa_hex(hexval);
	if (var->fzp && var->fprecision == 0 && hexval == 0)
		return (ft_zero_valprec(var, hex));
	if (var->type == 'X')
		hex = ft_strupcase(hex);
	if (ft_strlen(hex) < (size_t)var->fprecision)
	{
		hold = ft_prefprecision(var, hex, 0);
		free(hex);
		hex = hold;
	}
	if ((size_t)var->fwidth > ft_strlen(hex))
		ft_printstrwhitespace(var, hex, strlen(hex));
	else
		var->retval += ft_str_to_stdout(hex);
	free(hex);
	return (0);
}
