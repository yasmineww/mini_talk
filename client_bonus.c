/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:52:50 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/04/20 20:05:06 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	send_signal(pid_t pid, char **av, int *sig)
{
	int	i;
	int	j;

	i = -1;
	while (av[2][++i])
	{
		j = -1;
		while (++j < 8)
		{
			sig[j] = av[2][i] % 2;
			av[2][i] = av[2][i] / 2;
		}
		while (--j >= 0)
		{
			if (sig[j] == 0)
				protection(kill(pid, SIGUSR2));
			else if (sig[j] == 1)
				protection(kill(pid, SIGUSR1));
			usleep(1000);
		}
	}
	j = -1;
	while (++j < 8)
	{
		protection(kill(pid, SIGUSR2));
		usleep(1000);
	}
}

void	print_design(void)
{
	ft_printf("                                    \n");
	ft_printf("⊱ ───────── {.⋅ ✯ ⋅.} ────────── ⊰\n\n");
	ft_printf(" .--. .-.   .-. .--. .-..-..-----.\n");
	ft_printf(": .--': :   : :: .--': `: :`-. .-'\n");
	ft_printf(": :   : :   : :: `;  : .` :  : :  \n");
	ft_printf(": :__ : :__ : :: :__ : :. :  : :  \n");
	ft_printf("`.__.':___.':_;`.__.':_;:_;  :_;  \n");
	ft_printf("                                    ");
	ft_printf("\n⊱ ───────── {.⋅ ✯ ⋅.} ────────── ⊰\n\n");
}

int	my_atoi(char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		*sig;

	if (ac != 3)
	{
		ft_printf("Invalid number of arguments");
		exit(1);
	}
	pid = my_atoi(av[1]);
	if (pid <= 0)
		exit(1);
	sig = (int *) malloc (sizeof(int) * 8);
	if (!sig)
		return (1);
	print_design();
	signal(SIGUSR1, message);
	send_signal(pid, av, sig);
	free(sig);
	return (0);
}
