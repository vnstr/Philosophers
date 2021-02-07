/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 15:09:42 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/07 15:09:44 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

#include "utils.h"

void	ft_mssleep(uint64_t mstime)
{
	uint64_t		start_mstime;

	start_mstime = get_mstime();
	while (get_mstime() - start_mstime < mstime)
	{
		usleep(5);
	}
}
