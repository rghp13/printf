/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:15:47 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/10 15:10:30 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_struct_init(t_container *var)
{
	var->fleft = 0;
	var->fprecision = 0;
	var->fwidth = 0;
	var->fzero = 0;
	var->type = 0;
	return ;
}

int		ft_str_to_stdout(const char *str)
{
	int	i;

	i = 0;
	while ((str[i]))
	{
		ft_putchar_fd(str[i], STDOUT_FILENO);
		i++;
	}
	return (i);
}
/*
**
*/
int		ft_str_trunc(char *src, t_container *var)
{
	char	*str;

	if (var->fprecision < var->fwidth)
	{
		if (!(str = malloc(sizeof(char) * (var->fwidth + 1))))
			return (-1);
		str[var->fwidth] = '\0';
		ft_memset(str, ' ', var->fwidth);
		if (var->fleft)
			ft_memcpy(str, src, var->fprecision);
		else
			ft_memcpy(str + (var->fwidth - var->fprecision),\
			src, var->fprecision);
		var->retval += ft_str_to_stdout(str);
		free(str);
	}
	else
	{
		src[var->fprecision] = '\0';
		var->retval += ft_str_to_stdout(src);
	}
	return (0);
}
