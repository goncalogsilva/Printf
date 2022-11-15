/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gode-jes <gode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:44:48 by gode-jes          #+#    #+#             */
/*   Updated: 2022/11/15 13:13:48 by gode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_u(int j)
{
	char	n;

	n = j + '0';
	return (write(1, &n, 1));
}

static long int	multiplicador_u(long int i, long nb)
{
	i = 10;
	while (nb / i != 0)
	{
		i = i * 10;
	}
	i = i / 10;
	return (i);
}

int	ft_putnbr_u(long nb)
{
	long int	i;
	int			j;
	int			cnt;
	long int	num;

	num = nb;
	cnt = 0;
	i = 10;
	i = multiplicador_u(i, num);
	while (i >= 1)
	{
		j = num / i;
		cnt += print_u(j);
		num = num - (j * i);
		i = i / 10;
	}
	return (cnt);
}
