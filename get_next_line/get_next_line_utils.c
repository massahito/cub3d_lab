/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu2204 <ubuntu2204@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 02:50:36 by kyoda             #+#    #+#             */
/*   Updated: 2023/07/29 18:33:56 by ubuntu2204       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*p;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = 0;
	len = ft_gnl_strlen(s1) + ft_gnl_strlen(s2);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = '\0';
	return (p);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	char	ch;

	if (!s)
		return (NULL);
	ch = (char)c;
	while (1)
	{
		if (*s == ch)
			return ((char *)s);
		if (*s == '\0')
			break ;
		s++;
	}
	return (NULL);
}

size_t	ft_gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_gnl_free(char *free_ptr)
{
	if (free_ptr)
	{
		free(free_ptr);
		free_ptr = NULL;
	}
	return (NULL);
}
