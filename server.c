/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:52:43 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/04/18 16:31:06 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	print_design(pid_t pid)
{
	// ft_printf("");
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

void	signal_handler_1()
{
	ft_printf("Received : 1\n");
}

void	signal_handler_0()
{
	ft_printf("Received : 0\n");
}

int main (void)
{
	pid_t pid = getpid();
	print_design(pid);
	signal(SIGUSR1, signal_handler_1);
	signal(SIGUSR2, signal_handler_0);
    while (1)
	{
	}
}
