/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:08:08 by gdrive            #+#    #+#             */
/*   Updated: 2020/12/17 19:58:31 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_nblen(char *s)
{
	size_t	s_len;

	s_len = 0;
	while (*s >= 48 && *s++ <= 57)
		s_len++;
	return (s_len);
}

int		ft_atoi_longcmp(char *str, int sign)
{
	size_t	str_len;

	str_len = ft_atoi_nblen(str);
	if (str_len < 19)
		return (0);
	if (sign < 0)
	{
		if (ft_memcmp(str, "9223372036854775808", 20) > 0)
			return (-1);
		return (0);
	}
	if (ft_memcmp(str, "9223372036854775807", 20) > 0)
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int		sign;
	int		res;
	int		long_cmp;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = 1;
	if (*str == '-' && *(str + 1) != '+')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	if ((*str < 48 || *str > 57))
		return (0);
	long_cmp = ft_atoi_longcmp((char*)str, sign);
	if (long_cmp > 0)
		return (-1);
	if (long_cmp < 0)
		return (0);
	res = *str - 48;
	while (*str >= 48 && *str <= 57)
	{
		if (*(++str) >= 48 && *(str) <= 57)
			res = res * 10 + (*str - 48);
	}
	return (res * sign);
}
