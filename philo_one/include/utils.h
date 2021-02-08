/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrive <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 13:42:05 by gdrive            #+#    #+#             */
/*   Updated: 2021/02/05 13:42:07 by gdrive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>
# include <stdlib.h>

size_t		ft_strlen(const char *s);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_atoi(const char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(uint64_t n, int fd);
char		*ft_strdup(const char *s1);

uint64_t	get_mstime(void);
uint64_t	get_sim_mstime(uint64_t start_sim_time);

void		ft_mssleep(uint64_t mstime);

#endif
