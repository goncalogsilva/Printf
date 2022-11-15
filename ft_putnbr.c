/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gode-jes <gode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:25:24 by gode-jes          #+#    #+#             */
/*   Updated: 2022/11/15 11:34:00 by gode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print(int j)
{
	char	n;

	n = j + '0';
	return (write(1, &n, 1));
}

static long int	multiplicador(long int i, int nb)
{
	i = 10;
	while (nb / i != 0)
	{
		i = i * 10;
	}
	i = i / 10;
	return (i);
}

int	ft_putnbr(int nb)
{
	long int	i;
	int			j;
	int			cnt;
	long int	num;

	num = nb;
	cnt = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		cnt++;
	}
	i = 10;
	i = multiplicador(i, num);
	while (i >= 1)
	{
		j = num / i;
		cnt += print(j);
		num = num - (j * i);
		i = i / 10;
	}
	return (cnt);
}
