/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:31:24 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/19 17:41:11 by rponsonn         ###   ########.fr       */
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
		pref[0] = '-';
	result = ft_strjoin(pref, str);
	free(pref);
	return (result);
}
