/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gode-jes <gode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:10:20 by gode-jes          #+#    #+#             */
/*   Updated: 2022/11/15 15:38:37 by gode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		ft_putnbr(int nb);
int		ft_putnbr_u(long nb);
int		ft_dectohexlower(unsigned long n);
int		ft_dectohexupper(unsigned long n);
int		ft_ptrtohex(unsigned long n, int flag);

#endif