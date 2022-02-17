/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschwitz <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:19:27 by bschwitz          #+#    #+#             */
/*   Updated: 2022/02/17 16:02:16 by bschwitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	send_bin(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (--bit > -1)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep (10);
	}
	return (0);
}

static int	ftp_server(pid_t pid_num, char *str)
{
	int	i;

	i = 0;
	while (str[i] >= ' ' && str[i] <= '~')
	{
		if (send_bin(pid_num, str[i]))
			return (1);
		++i;
	}
	i = 0;
	while (i < 7)
	{
		kill(pid_num, SIGUSR1);
		i++;
		usleep(10);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid_num;

	if (argc != 3)
	{
		write(STDOUT_FILENO, "Entrez un PID et une string.\n", 30);
		return (1);
	}
	else
	{
		pid_num = ft_atoi(argv[1]);
		if (pid_num == 0)
			return (1);
		if (pid_num)
			ftp_server(pid_num, argv[2]);
	}
	return (0);
}
