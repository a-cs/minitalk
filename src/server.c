/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:36:07 by acarneir          #+#    #+#             */
/*   Updated: 2022/02/19 01:21:45 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	handle_signal(int signal)
{
	static int	character;
	static int	bit;

	if (!bit)
		bit = 128;
	if (signal == SIGUSR1)
		character += bit;
	bit /= 2;
	if (!bit)
	{
		ft_putchar_fd(character, 1);
		character = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("Server pid: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
