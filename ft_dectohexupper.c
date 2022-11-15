/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohexupper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gode-jes <gode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:46:08 by gode-jes          #+#    #+#             */
/*   Updated: 2022/11/15 13:11:11 by gode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_dectohexupper(int j)
{
	char	n;

	n = j + '0';
	if (j > 9 && j < 16)
		n = j + 55;
	return (write(1, &n, 1));
}

static long int	multiplicador_dectohexupper(long i, long nb)
{
	i = 16;
	while (nb / i != 0)
	{
		i = i * 16;
	}
	i = i / 16;
	return (i);
}

int	ft_dectohexupper(unsigned long n)
{
	long int		i;
	int				j;
	int				cnt;
	unsigned long	num;

	num = n;
	i = 16;
	cnt = 0;
	i = multiplicador_dectohexupper(i, num);
	while (i >= 1)
	{
		j = num / i;
		cnt += print_dectohexupper(j);
		num = num - (j * i);
		i = i / 16;
	}
	return (cnt);
}
