/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcausa <jalcausa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 19:50:08 by jalcausa          #+#    #+#             */
/*   Updated: 2024/10/17 11:08:44 by jalcausa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(unsigned long int n);
int	ft_count_digits(int n);
int	ft_putnbr(int n);
int	ft_count_digits_unsigned(unsigned int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_puthex(unsigned long int n, char c);

#endif