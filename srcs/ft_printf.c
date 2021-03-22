/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 02:32:40 by romain            #+#    #+#             */
/*   Updated: 2021/03/16 18:44:13 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//You'll probably need a Struct that holds all the vars you'll be using
//Expect to treat cspdiuxX%
/*
** c = Char
** s = String
** p = Memory address
** d = Signed int
** i = Signed int
** u = Unsigned int
** x = Hexadecimal, so take the int and convert to hex
** X = Hexadecimal
** % = for when you want the % symbol to display
** - = left justify
** 0 = left pad with 0s instead of spaces where padding is requested
** .*= precision is the previous argument.
*/
int ft_printf(const char *format, ...)
{
	t_container container;

}