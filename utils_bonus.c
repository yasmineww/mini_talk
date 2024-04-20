/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:39:35 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/04/20 20:05:16 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	message(int pid)
{
	ft_printf("Message sent successfully\n", pid);
}

void	protection(int return_type)
{
	if (return_type == -1)
		exit(1);
}
