/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:52:43 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/04/20 19:02:24 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	protection(int return_type)
{
	if (return_type == -1)
		exit(1);
}

void	print_design(pid_t pid)
{
	ft_printf("                                    \n");
	ft_printf("⊱ ─────────── {.⋅ ✯ ⋅.} ──────────── ⊰\n\n");
	ft_printf(" .--.  .--. .---. .-..-. .--. .---. \n");
	ft_printf(": .--': .--': .; :: :: :: .--': .; :\n");
	ft_printf("`. `. : `;  :   .': :: :: `;  :   .'\n");
	ft_printf(" _`, :: :__ : :.`.: `' ;: :__ : :.`.\n");
	ft_printf("`.__.'`.__.':_;:_; `.,' `.__.':_;:_;\n");
	ft_printf("                                    ");
	ft_printf("\n\t     PID : %d\n", pid);
	ft_printf("⊱ ─────────── {.⋅ ✯ ⋅.} ──────────── ⊰\n\n");
}

void	signal_handler(int sig, siginfo_t *my_struct, void *a)
{
	static int		i = 7;
	static int		c;
	static pid_t	pid;

	(void)a;
	if (my_struct->si_pid != pid)
	{
		pid = my_struct->si_pid;
		i = 7;
		c = 0;
	}
	if (sig == SIGUSR1)
		c += 1 << i;
	else if (sig == SIGUSR2)
		c += 0 << i;
	i--;
	if (i == -1)
	{
		if (c == '\0')
			protection(kill(pid, SIGUSR2));
		write(1, &c, 1);
		i = 7;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	my_struct;
	pid_t				pid;

	pid = getpid();
	print_design(pid);
	my_struct.sa_sigaction = signal_handler;
	my_struct.sa_flags = SA_SIGINFO; ///////
	while (1)
	{
		protection(sigaction(SIGUSR1, &my_struct, NULL));
		protection(sigaction(SIGUSR2, &my_struct, NULL));
		pause();
	}
}
