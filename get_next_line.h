/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:22:09 by sephilip          #+#    #+#             */
/*   Updated: 2023/10/17 12:21:56 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

int	ft_verline(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*inccpy(char *big, char *glued);
char	*ft_bufan(int fd, char *save, char *tmp, int a);
char	*ft_save(char *save, int a);

#endif /*GET_NEXT_LINE_H */
