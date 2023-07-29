/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:22:39 by keys              #+#    #+#             */
/*   Updated: 2022/11/27 12:31:19 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_ans(int n, char *str)
{
	int	tmp;
	int	n_len;
	int	i;

	i = 0;
	tmp = n;
	n_len = 1;
	while (n / 10 > 0)
	{
		n_len *= 10;
		n /= 10;
	}
	while (n_len > 0)
	{
		str[i++] = tmp / n_len + 48;
		tmp -= tmp - (tmp % n_len);
		n_len /= 10;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	char	str[12];

	if (n == -2147483648)
	{
		str[0] = '-';
		itoa_ans(2147483647, &str[1]);
		str[10] = '8';
		return (ft_strdup(str));
	}
	if (n < 0)
	{
		str[0] = '-';
		itoa_ans(n * -1, &str[1]);
		return (ft_strdup(str));
	}
	itoa_ans(n, str);
	return (ft_strdup(str));
}

// static char	*ft_remalloc(char *str, int c)
// {
// 	char	*tmp;
// 	size_t	len;

// 	len = ft_strlen(str);
// 	tmp = (char *)malloc(sizeof(char) * (len + 2));
// 	if (!tmp)
// 		return (NULL);
// 	*tmp = (char)c;
// 	ft_strlcat(tmp + 1, str, len + 1);
// 	free(str);
// 	return (tmp);
// }

// static char	*ft_get_num(char *str, long n)
// {
// 	int	c;

// 	while (n)
// 	{
// 		c = (n % 10) + 48;
// 		n = n / 10;
// 		str = ft_remalloc(str, c);
// 		if (!str)
// 			return (NULL);
// 	}
// 	return (str);
// }

// char	*ft_itoa(int n)
// {
// 	char	*str;
// 	long	number;
// 	int		flag;

// 	flag = 0;
// 	number = (long)n;
// 	if (number == 0)
// 		return (ft_strdup("0"));
// 	if (number < 0)
// 	{
// 		flag = 1;
// 		number = number * -1L;
// 	}
// 	str = ft_strdup("");
// 	if (!str)
// 		return (NULL);
// 	str = ft_get_num(str, number);
// 	if (!str)
// 		return (NULL);
// 	if (flag == 1)
// 		str = ft_remalloc(str, '-');
// 	return (str);
// }
