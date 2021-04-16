/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 12:28:59 by rponsonn          #+#    #+#             */
/*   Updated: 2021/04/16 18:07:30 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "includes/ft_printf.h"

int	main(void)
{
	printf("|%-020%|\n");
	ft_printf("|%-020%|\n");
	return (0);
}
