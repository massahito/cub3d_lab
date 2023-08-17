/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:42:25 by kyoda             #+#    #+#             */
/*   Updated: 2023/08/17 13:42:25 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_rgb(int *num, char *str)
{
	char	**arr;
	int		i;
	int		n[3];

	i = 0;
	arr = ft_split(str, ',');
	if (!arr)
		malloc_err();
	while (arr[i])
	{
		n[i] = ft_atoi(arr[i]);
		i++;
	}
	ft_double_ptr_free(arr);
	*num = change_rgb(n);
}
