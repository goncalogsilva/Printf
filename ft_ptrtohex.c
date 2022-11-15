/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gode-jes <gode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:28:06 by gode-jes          #+#    #+#             */
/*   Updated: 2022/11/15 15:43:47 by gode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrtohex(unsigned long n, int flag)
{
	int		cnt;
	int		r;
	char	c;

	cnt = 0;
	if (!n)
	{
		cnt = write(1, "(nil)", 5);
		return (cnt);
	}
	if (flag == 0)
		cnt = write(1, "0x", 2);
	if ((n / 16) != 0)
		cnt += ft_ptrtohex((n / 16), 1);
	r = n % 16;
	c = r + '0';
	if (r > 9 && r < 16)
		c = r + 87;
	cnt += write(1, &c, 1);
	return (cnt);
}
