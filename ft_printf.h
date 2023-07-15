/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcopoglu <bcopoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:05:45 by bcopoglu          #+#    #+#             */
/*   Updated: 2023/07/14 16:05:45 by bcopoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char x);
int	ft_format(va_list *args, char w);
int	ft_int(int d);
int	ft_unsigned(unsigned int ud);
int	ft_string(char *str);
int	ft_hex(unsigned int d, char c);
int	ft_point(unsigned long w, int i);
int	ft_check(char str);
#endif
