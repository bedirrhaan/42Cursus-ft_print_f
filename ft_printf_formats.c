/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:10:45 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/07/14 16:10:45 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int(int d)
{
	int	len;

	len = 0;
	if (d == 0)
		return (write(1, "0", 1));
	if (d == -2147483648)
		return (write(1, "-2147483648", 11));
	if (d < 0)
	{
		len += write(1, "-", 1);
		d *= -1;
	}
	if (d >= 10)
		len += ft_int(d / 10);
	write(1, &"0123456789"[d % 10], 1);
	return (len + 1);
}

int	ft_unsigned(unsigned int ud)
{
	int	len;

	len = 0;
	if (ud >= 10)
		len += ft_unsigned(ud / 10);
	write(1, &"0123456789"[ud % 10], 1);
	return (len + 1);
}

int	ft_string(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
		write(1, &str[i], 1);
	return (i);
}

int	ft_hex(unsigned int d, char c)
{
	int	len;

	len = 0;
	if (d >= 16)
		len += ft_hex(d / 16, c);
	if (c == 'X')
		write(1, &"0123456789ABCDEF"[d % 16], 1);
	if (c == 'x')
		write(1, &"0123456789abcdef"[d % 16], 1);
	return (len + 1);
}

int	ft_point(unsigned long w, int i)
{
	int	len;

	len = 0;
	if (i == 1)
	{
		len += write(1, "0x", 2);
		i = 0;
	}
	if (w >= 16)
		len += ft_point(w / 16, i);
	write(1, &"0123456789abcdef"[w % 16], 1);
	return (len + 1);
}
