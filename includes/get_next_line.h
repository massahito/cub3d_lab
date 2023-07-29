/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu2204 <ubuntu2204@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 03:00:10 by kyoda             #+#    #+#             */
/*   Updated: 2023/07/29 18:33:56 by ubuntu2204       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define MAX 1000
# define MAX_FD 256

char	*get_next_line(int fd);
char	*ft_gnl_strjoin(char const *s1, char const *s2);
char	*ft_gnl_strchr(const char *s, int c);
size_t	ft_gnl_strlen(const char *str);
char	*ft_gnl_free(char *free_ptr);

#endif
