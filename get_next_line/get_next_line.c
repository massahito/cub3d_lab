/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marai <marai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 03:03:37 by kyoda             #+#    #+#             */
/*   Updated: 2023/08/17 13:54:55 by marai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free_join(const char *s1, const char *s2, long flag)
{
	char	*re;

	if (flag > 0)
		re = ft_gnl_strjoin(s1 + flag, s2);
	else
		re = ft_gnl_strjoin(s1, s2);
	ft_gnl_free((char *)s1);
	return (re);
}

static char	*ft_read_fd(int fd, char *memory, char *line)
{
	ssize_t	count;

	if (memory == NULL)
	{
		memory = malloc(1);
		if (memory == NULL)
			return (NULL);
		*memory = '\0';
	}
	while (1)
	{
		count = read(fd, line, BUFFER_SIZE);
		if (count == 0)
			break ;
		else if (count < 0)
			return (ft_gnl_free(line));
		*(line + count) = '\0';
		memory = ft_free_join(memory, line, 0);
		if (!memory || ft_gnl_strchr(memory, '\n') != NULL)
			break ;
	}
	ft_gnl_free(line);
	return (memory);
}

static char	*ft_get_reline(char *memory)
{
	char	*line;
	int		i;

	i = 0;
	if (!memory[i])
		return (NULL);
	while (memory[i] != '\n' && memory[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (memory[i] != '\n' && memory[i])
	{
		line[i] = memory[i];
		i++;
	}
	if (memory[i] && memory[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_new_next_memory(char *memory)
{
	long	i;
	char	*tmp;

	if (!memory[0])
		return (ft_gnl_free(memory));
	tmp = ft_gnl_strchr(memory, '\n');
	if (tmp == NULL)
		return (ft_gnl_free(memory));
	i = tmp - memory;
	memory = ft_free_join(memory, "", i + 1);
	return (memory);
}

char	*get_next_line(int fd)
{
	static char	*memory[MAX_FD];
	char		*re;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!ft_gnl_strchr(memory[fd], '\n'))
	{
		line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!line)
			return (NULL);
		memory[fd] = ft_read_fd(fd, memory[fd], line);
	}
	if (!memory[fd])
		return (NULL);
	re = ft_get_reline(memory[fd]);
	memory[fd] = ft_new_next_memory(memory[fd]);
	return (re);
}
