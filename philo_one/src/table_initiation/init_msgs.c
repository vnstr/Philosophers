/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 17:53:01 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/07 17:53:02 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "table_initiation.h"

void		del_msgs(t_msgs **msgs)
{
	if ((*msgs)->eating != NULL)
		free((*msgs)->eating);
	if ((*msgs)->sleeping != NULL)
		free((*msgs)->sleeping);
	if ((*msgs)->thinking != NULL)
		free((*msgs)->thinking);
	if ((*msgs)->dying != NULL)
		free((*msgs)->dying);
	if ((*msgs)->taking_fork != NULL)
		free((*msgs)->taking_fork);
	free(*msgs);
	*msgs = NULL;
}

static int	init_text(t_msgs *msgs)
{
	if ((msgs->taking_fork = ft_strdup(TAKING_FORKS)) == NULL)
		return (1);
	if ((msgs->eating = ft_strdup(EATING)) == NULL)
		return (1);
	if ((msgs->sleeping = ft_strdup(SLEEPING)) == NULL)
		return (1);
	if ((msgs->thinking = ft_strdup(THINKING)) == NULL)
		return (1);
	if ((msgs->dying = ft_strdup(DIE)) == NULL)
		return (1);
	return (0);
}

t_msgs		*init_msgs(void)
{
	t_msgs	*msgs;

	msgs = (t_msgs*)malloc(sizeof(t_msgs));
	if (msgs == NULL)
		return (NULL);
	msgs->eating = NULL;
	msgs->sleeping = NULL;
	msgs->thinking = NULL;
	msgs->dying = NULL;
	if (init_text(msgs) != 0)
	{
		del_msgs(&msgs);
		return (NULL);
	}
	return (msgs);
}
