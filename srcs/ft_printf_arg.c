/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:27:17 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/23 16:46:40 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_container *var)
{
	char	hold;
	int		ret;

	hold = va_arg(var->ap, int);
	if (var->fleft)
	{
		var->retval += ft_char_print(hold);
		ret = ft_pad_print(var->fwidth - 1);
		if (ret == -1)
			return (-1);
		var->retval += ret;
	}
	else
	{
		ret = ft_pad_print(var->fwidth - 1);
		if (ret == -1)
			return (-1);
		var->retval += ret;
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
		if (ft_str_setup_space(var, hold, len) == -1)
		{
			free(hold);
			return (-1);
		}
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
	t_var	padd;

	padd.uval = va_arg(var->ap, unsigned long int);
	if ((padd.str = ft_itoa_hex(padd.uval)) == NULL)
		return (-1);
	padd.hold = ft_strjoin("0x", padd.str);
	free(padd.str);
	if (padd.hold == NULL)
		return (-1);
	if (var->fprecision == 0 && var->fzp && padd.uval == 0)
		padd.hold[2] = '\0';
	if ((size_t)var->fwidth > ft_strlen(padd.hold))
	{
		if ((ft_printstrwhitespace(var, padd.hold, ft_strlen(padd.hold))) == -1)
		{
			free(padd.hold);
			return (-1);
		}
	}
	else
		var->retval += ft_str_to_stdout(padd.hold);
	free(padd.hold);
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
	t_var	pint;

	pint.val = va_arg(var->ap, int);
	pint.str = ft_abs_itoa(pint.val);
	if (pint.str == NULL)
		return (-1);
	if (var->fzp && var->fprecision == 0 && pint.val == 0)
		return (ft_zero_valprec(var, pint.str));
	if (ft_strlen(pint.str) < (size_t)var->fprecision)
	{
		pint.hold = ft_prefprecision(var, pint.str, pint.val);
		free(pint.str);
		if (pint.hold == NULL)
			return (-1);
		pint.str = pint.hold;
	}
	if ((size_t)var->fwidth > ft_strlen(pint.str)
		&& (var->negflag || pint.val >= 0))
		pint.ret = ft_printstrwhitespace(var, pint.str, strlen(pint.str));
	else if ((size_t)var->fwidth > ft_strlen(pint.str))
		pint.ret = ft_printnegint(var, pint.str, strlen(pint.str));
	else
		pint.ret = ft_join_print_int(var, pint.str, pint.val);
	free(pint.str);
	return (pint.ret);
}

/*
**0flag ignored, extra precision prefixes string with 0's but
**blank space still needed if the width is bigger than precision
*/

int	ft_print_hex(t_container *var)
{
	t_var		phex;

	phex.ret = 0;
	phex.usval = va_arg(var->ap, unsigned int);
	phex.str = ft_itoa_hex(phex.usval);
	if (phex.str == NULL)
		return (-1);
	if (var->fzp && var->fprecision == 0 && phex.usval == 0)
		return (ft_zero_valprec(var, phex.str));
	if (var->type == 'X')
		phex.str = ft_strupcase(phex.str);
	if (ft_strlen(phex.str) < (size_t)var->fprecision)
	{
		phex.hold = ft_prefprecision(var, phex.str, 0);
		free(phex.str);
		if (phex.hold == NULL)
			return (-1);
		phex.str = phex.hold;
	}
	if ((size_t)var->fwidth > ft_strlen(phex.str))
		phex.ret = ft_printstrwhitespace(var, phex.str, strlen(phex.str));
	else
		var->retval += ft_str_to_stdout(phex.str);
	free(phex.str);
	return (phex.ret);
}
