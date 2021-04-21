/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:31:24 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/21 12:57:51 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**unsure if this file will be necessary much longer
*/

char	*ft_convert_address(unsigned long int address)
{
	char *hex;
	char *ptr;

	hex = ft_itoa_hex(address);
	ptr = ft_strjoin("0x", hex);
	free(hex);
	return (ptr);
}

char	*ft_prefprecision(t_container *var, char *str, int num)
{
	char	*pref;
	char	*result;
	int		len;
	int		neg;

	neg = 0;
	if (num < 0)
		neg = 1;
	len = ft_strlen(str);
	if (!(pref = malloc(sizeof(char) * ((var->fprecision + neg - len) + 1))))
		return (NULL);
	ft_memset(pref, '0', (var->fprecision + neg - len));
	pref[var->fprecision + neg - len] = '\0';
	if (neg)
	{
		pref[0] = '-';
		var->negflag = TRUE;
	}
	result = ft_strjoin(pref, str);
	free(pref);
	return (result);
}

/*
**so in this version you know that a - is needed you just don't know where
*/

int		ft_printnegint(t_container *var, char *src, int len)
{
	char	*ptr;

	if (!(ptr = malloc(sizeof(char) * (var->fwidth + 1))))
		return (-1);
	ptr[var->fwidth] = '\0';
	if (var->fleft == 0 && var->fzero == 1
			&& var->fzp == 0 && (ft_memset(ptr, '0', var->fwidth)))
	{
		ptr[0] = '-';
		var->negflag = TRUE;
	}
	else
		ft_memset(ptr, ' ', var->fwidth);
	if (var->fleft && (ptr[0] = '-'))
		ft_memcpy(ptr + 1, src, len);
	else
	{
		ft_memcpy(ptr + (var->fwidth - len), src, len);
		if (var->negflag == FALSE)
			ptr[(var->fwidth - len) - 1] = '-';
	}
	var->retval += ft_str_to_stdout(ptr);
	free(ptr);
	return (0);
}

void	ft_join_print_int(t_container *var, char *str, int num)
{
	if (num < 0 && var->negflag == FALSE)
		var->retval += ft_str_to_stdout("-");
	var->retval += ft_str_to_stdout(str);
	return ;
}

int	ft_zero_valprec(t_container *var, char *str)
{
	char	*ptr;

	free(str);
	if (!(ptr = malloc(sizeof(char) * (var->fwidth + 1))))
		return (-1);
	ptr[var->fwidth] = '\0';
	ptr = ft_memset(ptr, ' ', var->fwidth);
	var->retval += ft_str_to_stdout(ptr);
	free(ptr);
	return (0);
}
