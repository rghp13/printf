/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 02:34:37 by romain            #+#    #+#             */
/*   Updated: 2021/04/23 16:23:50 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# define VALTYPE "cspdiuxX%"
# define TRUE 1
# define FALSE 0

typedef	struct		s_container
{
	va_list			ap;
	const char		*format;
	int				retval;
	int				fzero;
	int				fleft;
	int				fwidth;
	int				fprecision;
	int				fzp;
	int				negflag;
	char			type;
}					t_container;

typedef	struct		s_var
{
	int				len;
	int				ret;
	int				val;
	char			*hold;
	char			*str;
	unsigned		usval;
	unsigned long	uval;
}					t_var;

int					ft_printf(const char *format, ...);
int					ft_read(t_container *var);
int					ft_flag_check(t_container *var, int i);
int					ft_print_arg(t_container *var);
void				ft_struct_init(t_container *var);
int					ft_flag_check(t_container *var, int i);
int					ft_parse_type(t_container *var, int i, char *type);
int					ft_parse_precision(t_container *var, int i);
int					ft_parse_flag(t_container *var, int i);
int					ft_print_char(t_container *var);
int					ft_print_str(t_container *var);
int					ft_print_address(t_container *var);
int					ft_print_int(t_container *var);
int					ft_print_uint(t_container *var);
int					ft_print_hex(t_container *var);
int					ft_print_percent(t_container *var);
int					ft_print_nonformat(t_container *var, int i);
int					ft_str_to_stdout(const char *str);
int					ft_str_trunc(char *str, t_container *var);
int					ft_printstrwhitespace(t_container *var, char *src, int len);
char				*ft_prefprecision(t_container *var, char *str, int num);
void				ft_parse_sanitize(t_container *var);
char				*ft_abs_itoa(int num);
int					ft_printnegint(t_container *var, char *src, int len);
int					ft_join_print_int(t_container *var, char *str, int num);
int					ft_zero_valprec(t_container *var, char *str);
int					ft_char_print(char a);
int					ft_pad_print(int len);
int					ft_str_setup_space(t_container *var, char *hold, int len);

#endif
