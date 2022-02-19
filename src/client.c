/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:31:55 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/19 01:25:32 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>

static void	send_signal(char *str, int pid)
{
	int	bit_shift;

	while (*str)
	{
		bit_shift = 0;
		while (bit_shift < 8)
		{
			if (*str & (128 >> bit_shift))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit_shift++;
			usleep(10000);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		ft_putstr_fd("How to use: ./client SERVER_PID MESSAGE\n", 1);
	pid = ft_atoi(argv[1]);
	send_signal(argv[2], pid);
	return (0);
}
