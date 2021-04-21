/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:09:10 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/21 17:26:34 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_print(char a)
{
	write(1, &a, 1);
	return (1);
}

int	ft_pad_print(int len)
{
	char	*ptr;

	if (len > 0)
	{
		ptr = malloc(sizeof(char) * len);
		if (!ptr)
			return (-1);
		ptr[len] = '\0';
		ft_memset(ptr, ' ', len);
		write(STDOUT_FILENO, ptr, len);
		free(ptr);
		return (len);
	}
	return (0);
}
