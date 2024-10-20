/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:49:12 by jalcausa          #+#    #+#             */
/*   Updated: 2024/10/20 16:16:55 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_filter_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(*args, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), c));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

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
			printed += ft_filter_format(s[++i], &args);
		else if (s[i])
			printed += ft_putchar(s[i]);
		++i;
	}
	va_end(args);
	return (printed);
}

/*
int   main()
{
	void *a;

	a = (void *)42;

    ft_printf("Muestra un caracter = %c\n \
	Muestra un string = %s\n \
	Muestra un porcentaje = %%\n \
	Muestra número decimal = %d\n \
	Muestra un entero de base 10 = %i\n \
	Muestra un número decimal sin signo = %u\n \
	Muestra un número hexadecimal en minuscula = %x\n \
	Muestra un número hexadecimal en mayúscula = %X\n \
	Muestra un puntero *void imprimido en hezadecimal = %p\n",
	'c', "Hola",  -16, 9, -45, 42, 42, a); \
    
    printf("Muestra un caracter = %c\n \
	Muestra un string = %s\n \
	Muestra un porcentaje = %%\n \
	Muestra número decimal = %d\n \
	Muestra un entero de base 10 = %i\n \
	Muestra un número decimal sin signo = %u\n \
	Muestra un número hexadecimal en minuscula = %x\n \
	Muestra un número hexadecimal en mayúscula = %X\n \
	Muestra un puntero *void imprimido en hezadecimal = %p\n", \
	'c', "Hola",  -16, 9, -45, 42, 42, a); \
} 

*/