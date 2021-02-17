/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:46:08 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/17 17:46:10 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

#include "utils.h"

void	ft_usleep(uint64_t utime)
{
	uint64_t		start_utime;

	start_utime = get_utime();
	while (get_utime() - start_utime < utime)
	{
		usleep(5);
	}
}
