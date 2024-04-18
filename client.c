/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:52:50 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/04/18 18:34:00 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	print_design()
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

int main (int ac, char **av)
{
    pid_t   pid;
    int     i;
    int     j;
    int    *sig;

    if (ac != 3)
    {
        ft_printf("Invalid number of arguments");
        exit(1);
    }
    i = -1;
    sig = (int *) malloc (sizeof(int) * 8);
    if (!sig)
        return (1);
    pid = my_atoi(av[1]);
    print_design();
    while (av[2][++i])
    { 
        j = 0;
        while (j < 8)
        {
            sig[j] = av[2][i] % 2;
            av[2][i] = av[2][i] / 2;
            j++;
        }
        while (--j >= 0)
        {
            if (sig[j] == 0)
                kill(pid, SIGUSR2);
            else if (sig[j] == 1)
                kill(pid, SIGUSR1);
            usleep(500);
        }
    }
    free(sig);
    return (0);
}
