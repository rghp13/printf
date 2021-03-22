/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:35:06 by rponsonn          #+#    #+#             */
/*   Updated: 2021/01/24 16:49:16 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*ptr;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	if (!(ptr = malloc(sizeof(char) * len + 1)))
		return (NULL);
	ptr[len] = '\0';
	while (i < len)
	{
		ptr[i] = (*f)(i, s[i]);
		i++;
	}
	return (ptr);
}
