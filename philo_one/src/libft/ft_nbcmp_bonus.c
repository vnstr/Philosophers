/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbcmp_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 17:53:06 by gdrive            #+#    #+#             */
/*   Updated: 2020/11/28 17:53:07 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbcmp(const char *nb1, const char *nb2)
{
	size_t	nb1_len;
	size_t	nb2_len;

	if (nb1 == NULL && nb2 != NULL)
		return (-1);
	if (nb1 != NULL && nb2 == NULL)
		return (1);
	if (nb1 == NULL && nb2 == NULL)
		return (0);
	nb1_len = ft_strlen(nb1);
	nb2_len = ft_strlen(nb2);
	if (nb1_len < nb2_len)
		return (-1);
	if (nb1_len > nb2_len)
		return (1);
	while (*nb1 != '\0' && *nb2 != '\0')
	{
		if (*nb1 != *nb2)
			return (*nb1 - *nb2);
		nb1++;
		nb2++;
	}
	return (*nb1 - *nb2);
}
