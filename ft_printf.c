/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gode-jes <gode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:08:23 by gode-jes          #+#    #+#             */
/*   Updated: 2022/11/15 15:43:24 by gode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	check_char(char c, va_list args)
{
	int	cnt;

	cnt = 0;
	if (c == 'c')
		cnt = ft_putchar(va_arg(args, int));
	else if (c == 's')
		cnt = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		cnt += ft_ptrtohex(va_arg(args, unsigned long), 0);
	else if (c == 'd')
		cnt = ft_putnbr(va_arg(args, int));
	else if (c == 'i')
		cnt = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		cnt = ft_putnbr_u(va_arg(args, unsigned int));
	else if (c == 'x')
		cnt = ft_dectohexlower(va_arg(args, unsigned int));
	else if (c == 'X')
		cnt = ft_dectohexupper(va_arg(args, unsigned int));
	else if (c == '%')
		cnt = ft_putchar('%');
	return (cnt);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		cnt;

	va_start(args, s);
	cnt = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			cnt += check_char(*(s + 1), args);
			s++;
		}
		else
			cnt += write(1, s, 1);
		s++;
	}
	va_end(args);
	return (cnt);
}

/*int	main(void)
{
	int	i;
	int	a;


	a = printf("%p %p\n", (void *)16, (void *)16);
	i = ft_printf("%p %p\n", (void *)16, (void *)16);
	printf("%d\n", a);
	printf("%d\n", i);
	return (0);
}*/
