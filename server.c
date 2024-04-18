/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:52:43 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/04/18 19:12:08 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"
#include <stdio.h>

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

void	signal_handler(int sig)
{
	static int		i = 7;
	static char		c = 0;

	if (sig == SIGUSR1)
		c += 1 << i;
	else if (sig == SIGUSR2)
		c += 0 << i;
	i--;
	if (i == -1)
	{
		write(1, &c, 1);
		i = 7;
		c = 0;
	}
}

int main (void)
{
	pid_t pid = getpid();
	print_design(pid);
    while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
	}
}
