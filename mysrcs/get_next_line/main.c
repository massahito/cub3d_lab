/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keys <keys@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:40:59 by ken               #+#    #+#             */
/*   Updated: 2022/11/27 23:31:33 by keys             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	*buf;
	int		fd;

	fd = open("text.txt", O_RDONLY);
	while (1)
	{
		buf = get_next_line(fd);
		printf("%s", buf);
		if (!buf)
			break ;
		free(buf);
	}
	close(fd);
	return (0);
}
