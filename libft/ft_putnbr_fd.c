/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:42:32 by kyoda             #+#    #+#             */
/*   Updated: 2022/11/27 11:41:34 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put(long n, int len, int fd)
{
	char	ans;

	if (n >= 10)
	{
		ft_put(n / 10, len, fd);
		ft_put(n % 10, len, fd);
	}
	else
	{
		ans = n + '0';
		ft_putchar_fd(ans, fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr == 0)
	{
		c = '0';
		ft_putchar_fd(c, fd);
		return ;
	}
	else if (nbr < 0)
	{
		c = '-';
		ft_putchar_fd(c, fd);
		nbr *= -1;
	}
	ft_put(nbr, 0, fd);
}
