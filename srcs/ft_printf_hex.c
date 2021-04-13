/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:31:24 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/13 16:58:51 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
**unsure if this file will be necessary much longer
*/

char				*ft_convert_address(unsigned long int address)
{
	char *hex;
	char *ptr;

	hex = ft_itoa_hex(address);
	ptr = ft_strjoin("0x", hex);
	free(hex);
}
