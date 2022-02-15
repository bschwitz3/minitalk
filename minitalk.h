/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwitz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:38:55 by bschwitz          #+#    #+#             */
/*   Updated: 2022/02/15 17:22:09 by bschwitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stddef.h>

void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putnbr_fd(int c, int fd);

#endif
