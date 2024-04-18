/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:53:12 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/04/17 18:09:46 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *size);
void	ft_putnbr(int n, int *size);
void	ft_putstr(char *s, int *size);
int     my_atoi(char *str);

#endif