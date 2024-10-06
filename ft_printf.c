/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:49:12 by jalcausa          #+#    #+#             */
/*   Updated: 2024/10/06 20:06:18 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		printed;

	i = 0;
	printed = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			++i;
			printed += ft_filter_format(s[i], &args);
		}
		else if (s[i])
			printed += ft_putchar(s[i]);
		++i;
	}
	va_end(args);
	return (printed);
}