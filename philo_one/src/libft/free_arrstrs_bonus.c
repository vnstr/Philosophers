/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 19:15:30 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 19:58:28 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		free_arrstrs(char ***arrstrs)
{
	size_t	i;

	if (arrstrs == NULL || *arrstrs == NULL)
		return (0);
	i = 0;
	while ((*arrstrs)[i] != NULL)
	{
		free((*arrstrs)[i]);
		(*arrstrs)[i] = NULL;
		i++;
	}
	free(*arrstrs);
	*arrstrs = NULL;
	return (0);
}
