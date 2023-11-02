/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephilip@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:03:47 by sephilip          #+#    #+#             */
/*   Updated: 2023/11/02 16:04:19 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 16
# endif

char	*get_next_line(int fd);

int		ft_verline(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_inccpy(char *big, char *glued, int size);
char	*ft_clear(char buf[MAX_FD][BUFFER_SIZE + 1], char *str, int fd, int a);

#endif /*GET_NEXT_LINE_BONUS_H */
