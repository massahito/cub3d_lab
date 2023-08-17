/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:41:26 by kyoda             #+#    #+#             */
/*   Updated: 2023/08/17 13:41:27 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error(char *str, char *str2, char *str3)
{
	ft_putstr_fd("Error\n", 2);
	if (str)
		ft_putstr_fd(str, 2);
	if (str2)
		ft_putstr_fd(str2, 2);
	if (str3)
		ft_putstr_fd(str3, 2);
	ft_putendl_fd("", 2);
	return (1);
}

void	malloc_err(void)
{
	ft_putstr_fd("Error: malloc error\n", 2);
	exit(EXIT_FAILURE);
}

void	read_err(char *meessage, int fd, t_texture_name **texture_name)
{
	if (meessage)
		error(meessage, NULL, NULL);
	if (fd >= 0)
		close(fd);
	if (*texture_name)
		free_azimuths(*texture_name);
	exit(EXIT_FAILURE);
}
