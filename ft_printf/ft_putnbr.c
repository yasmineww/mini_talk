/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:13:08 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/04/17 12:47:31 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

void	ft_putnbr(int n, int *size)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", size);
	}
	else if (n < 0)
	{
		n = n * -1;
		ft_putchar('-', size);
		ft_putnbr(n, size);
	}
	else if (n > 9)
	{
		ft_putnbr((n / 10), size);
		ft_putnbr((n % 10), size);
	}
	else
	{
		ft_putchar((n + '0'), size);
	}
}
