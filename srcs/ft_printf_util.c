/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:15:47 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/17 14:11:03 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_struct_init(t_container *var)
{
	var->fleft = 0;
	var->fprecision = -1;
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

int		ft_str_trunc(char *src, t_container *var)
{
	if (var->fprecision < var->fwidth)
	{
		ft_printstrwhitespace(var, src, var->fprecision);
	}
	else
	{
		src[var->fprecision] = '\0';
		var->retval += ft_str_to_stdout(src);
	}
	return (0);
}

/*
**len has to be strlen or precision
**takes str of width size, fills with space then copies src depending on align
**not useful if you need to 0 fill||ADDED IF STATEMENT TO PAD 0s IF RIGHT AND 0
*/

int		ft_printstrwhitespace(t_container *var, char *src, int len)
{
	char	*ptr;

	if (!(ptr = malloc(sizeof(char) * (var->fwidth + 1))))
		return (-1);
	ptr[var->fwidth] = '\0';
	if (var->fleft == 0 && var->fzero == 1)
		ft_memset(ptr, '0', var->fwidth);
	else
		ft_memset(ptr, ' ', var->fwidth);
	if (var->fleft)
		ft_memcpy(ptr, src, len);
	else
		ft_memcpy(ptr + (var->fwidth - len), src, len);
	var->retval += ft_str_to_stdout(ptr);
	free(ptr);
	return (0);
}
