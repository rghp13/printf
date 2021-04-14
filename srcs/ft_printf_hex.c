/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:31:24 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/14 17:44:19 by rponsonn         ###   ########.fr       */
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
}

char	*ft_hexprecision(t_container *var, char *hex)
{
	char	*pref;
	char	*result;
	int		len;

	len = ft_strlen(hex);
	if (!(pref = malloc(sizeof(char) * ((var->fprecision - len) + 1))))
		return (NULL);
	ft_memset(pref, '0', (var->fprecision - len));
	pref[var->fprecision - len] = '\0';
	result = ft_strjoin(pref, hex);
	free(pref);
	return (result);
}