/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:31:55 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/19 19:10:51 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	print_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

static void	send_signal(char *str, int pid)
{
	int	bit_shift;

	while (*str)
	{
		bit_shift = 0;
		while (bit_shift < 8)
		{
			if (*str & (128 >> bit_shift))
			{
				if (kill(pid, SIGUSR1) == -1)
					print_error("Error: unable to send a signal.\n");
			}
			else
			{
				if ((kill(pid, SIGUSR2) == -1))
					print_error("Error: unable to send a signal.\n");
			}
			usleep(10000);
			bit_shift++;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		print_error("How to use: ./client SERVER_PID MESSAGE\n");
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		print_error("Error: SERVER_PID has to be positive integer.\n");
	send_signal(argv[2], pid);
	return (0);
}
