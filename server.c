/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwitz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:24:28 by bschwitz          #+#    #+#             */
/*   Updated: 2022/02/16 17:23:55 by bschwitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_server_on = 1;

static void	print_pid(void)
{
	pid_t	pid_num;

	pid_num = getpid();
	if (pid_num == 0)
		return ;
	write(STDOUT_FILENO, "PID : ", 7);
	ft_putnbr_fd(pid_num, 1);
	write(STDOUT_FILENO, "\n", 2);
}

static void	reception(int sig)
{
	static size_t	i;
	static int		bit;
	static char		buf[1000000];

	if (--bit == -1)
	{
		bit = 6;
		++i;
	}
	buf[i] &= ~(1 << 7);
	if (sig == SIGUSR1)
		buf[i] |= (1 << bit);
	else if (sig == SIGUSR2)
		buf[i] &= ~(1 << bit);
	if (i == 999999 || buf[i] == 127)
	{
		buf[i] = 0;
		write(STDOUT_FILENO, buf, i + 1);
		ft_memset(buf, '\0', 999999);
		i = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	argv = NULL;
	if (argc != 1)
	{
		write (STDERR_FILENO, "Executez uniquement ./server.\n", 31);
		return (1);
	}
	else
	{
		print_pid();
		signal(SIGUSR1, reception);
		signal(SIGUSR2, reception);
		while (g_server_on)
		{
		}
	}
	return (0);
}
