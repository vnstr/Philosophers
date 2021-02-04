/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrstrs_addback.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:07:12 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 19:58:29 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_arrstrs_addback(char ***begin_arr, char *s)
{
	char	**res;
	size_t	len;

	if (begin_arr == NULL || s == NULL)
		return (NULL);
	len = ft_arrstrs_len(*begin_arr) + 1;
	if ((res = (char**)malloc(sizeof(char*) * (len + 1))) == NULL)
	{
		free_arrstrs(begin_arr);
		return (NULL);
	}
	res[len--] = NULL;
	res[len] = s;
	while (len-- != 0)
	{
		res[len] = (*begin_arr)[len];
	}
	free(*begin_arr);
	*begin_arr = res;
	return (s);
}
