/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:26:16 by rponsonn          #+#    #+#             */
/*   Updated: 2021/01/31 14:23:50 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*ptr;

	size = ft_strlen(s1);
	if (!(ptr = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ptr = ft_memcpy(ptr, s1, size + 1);
	return (ptr);
}
