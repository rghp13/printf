/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 02:34:37 by romain            #+#    #+#             */
/*   Updated: 2021/03/24 18:03:51 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct		s_container
{
	va_list			ap;
	const char		*format;
	int				retval;
}					t_container;

int		ft_printf(const char *format, ...);
void	ft_read(t_container var);
int		ft_flag_check(t_container var, int i);
void	ft_print_arg(t_container var);

#endif
