/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:50:27 by gdrive            #+#    #+#             */
/*   Updated: 2020/10/30 14:50:29 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  Man strchr.
*/

char	*ft_strchr(const char *s, int c)
{
	unsigned char *cs;

	cs = (unsigned char*)s;
	while (*cs != '\0')
	{
		if (*cs == (unsigned char)c)
			return ((char*)cs);
		cs++;
	}
	if (c == 0)
		return ((char*)cs);
	return (NULL);
}
