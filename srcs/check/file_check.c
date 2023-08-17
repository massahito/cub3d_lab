/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoda <kyoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:41:13 by kyoda             #+#    #+#             */
/*   Updated: 2023/08/17 13:41:14 by kyoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_file(char *str)
{
	int	fd;

	if (!str || strlen(str) < 4)
	{
		error("Invalid file name: ", str, NULL);
		return (true);
	}
	else if (strncmp(&(str[strlen(str) - 4]), ".cub", 4))
	{
		error("Invalid file name: ", str, NULL);
		return (true);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		error("File open error: ", str, NULL);
		return (true);
	}
	return (false);
}
