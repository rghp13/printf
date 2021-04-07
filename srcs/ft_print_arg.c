/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 17:27:17 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/07 20:50:05 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_container *var)
{
	char hold;
	char *ptr;
	int i;

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
	ft_str_to_stdout(ptr);
	free(ptr);
	return (0);
}

int	ft_str_to_stdout(const char *str)
{
	int i;

	i = 0;
	while((str[i]))
	{
		ft_putchar_fd(str[i], STDOUT_FILENO);
		i++;
	}
	return (i);
}