/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:13:03 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/04/17 12:47:34 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

void	ft_putstr(char *s, int *size)
{
	if (s == NULL)
	{
		*size += 6;
		write(1, "(null)", 6);
		return ;
	}
	while (*s)
	{
		ft_putchar(*s, size);
		s++;
	}
}
