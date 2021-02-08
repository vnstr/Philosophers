/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:43:42 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/06 18:43:43 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "utils.h"
#include "table_initiation.h"
#include "saying.h"

void	print_preview(uint64_t time, int id)
{
	ft_putnbr_fd(time, STDOUT);
	write(1, " ", 1);
	ft_putnbr_fd(id, STDOUT);
}

void	say_msg(char *msg)
{
	write(1, msg, ft_strlen(msg));
}
