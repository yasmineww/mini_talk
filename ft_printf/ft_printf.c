/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymakhlou <ymakhlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:12:10 by ymakhlou          #+#    #+#             */
/*   Updated: 2024/04/17 12:47:23 by ymakhlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mini_talk.h"

static void	ft_helper(const char *format, int *size, va_list ap)
{
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(ap, int), size);
	else if (*format == 'c')
		ft_putchar(va_arg(ap, int), size);
	else if (*format == 's')
		ft_putstr(va_arg(ap, char *), size);
	else
		ft_putchar(*format, size);
}

int	ft_printf(const char *format, ...)
{
	int		size;
	va_list	ap;

	va_start(ap, format);
	size = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break ;
			ft_helper(format, &size, ap);
		}
		else
		{
			write(1, format, 1);
			size++;
		}
		format++;
	}
	va_end(ap);
	return (size);
}
