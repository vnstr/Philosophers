/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstrs_len_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:02:21 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 19:58:30 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_arrstrs_len(char **arr)
{
	size_t	len;

	if (arr == NULL)
		return (0);
	len = 0;
	while (arr[len] != NULL)
		len++;
	return (len);
}
