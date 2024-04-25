/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:52:43 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/04/25 12:13:49 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

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

void	define_size(unsigned char c, int *size)
{
	if (c >= 0 && c <= 127)
		*size = 1;
	else if (c >= 192 && c <= 223)
		*size = 2;
	else if (c >= 224 && c <= 239)
		*size = 3;
	else if (c >= 240 && c <= 244)
		*size = 4;
}

void	print_char(pid_t *pid, unsigned char *c, int *size, int *buf_index)
{
	static char	buffer[4];

	buffer[(*buf_index)++] = *c;
	if (*buf_index == *size)
	{
		write(1, buffer, *size);
		*buf_index = 0;
	}
	if (*c == '\0')
		protection(kill(*pid, SIGUSR1));
}

void	signal_handler(int sig, siginfo_t *my_struct, void *a)
{
	static int				i = 7;
	static unsigned char	c;
	static pid_t			pid;
	static int				buf_index;
	static int				size;

	(void)a;
	if (my_struct->si_pid != pid)
	{
		pid = my_struct->si_pid;
		i = 7;
		c = 0;
		buf_index = 0;
	}
	if (sig == SIGUSR1)
		c += 1 << i;
	i--;
	define_size(c, &size);
	if (i == -1)
	{
		print_char(&pid, &c, &size, &buf_index);
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
	my_struct.sa_flags = SA_SIGINFO;
	protection(sigaction(SIGUSR1, &my_struct, NULL));
	protection(sigaction(SIGUSR2, &my_struct, NULL));
	while (1)
		pause();
}
