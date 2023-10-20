/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:41:57 by sephilip          #+#    #+#             */
/*   Updated: 2023/10/16 16:10:42 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <stdlib.h>


int	ft_verline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	while (src[len])
		len++;	
	if (!size)
		return (len);
	while (src[i] && (i < size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (len);
}

char	*inccpy(char *big, char *glued)
{
	char	*str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (big[i])
		i++;
	while (glued[j])
		j++;
	str = (char *)malloc((i + j + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, big, i + 1);
	ft_strlcpy(&(str[i]), glued, i + j + 1);
	return (str);
}

char	*ft_smallbuf(int fd, char *save, char *tmp) //the \n not yet found
{
	char	*big;
	int	a;
	int	i;

	if (save)
		big = inccpy(save, tmp);
	else
		big = inccpy(tmp, ""); //meter tudo para o big, para que nao haja probl
	while (ft_verline(tmp) == -1)
	{
		a = read(fd, tmp, buf);
		big = inccpy(big, tmp);
		if (a < buf)
			break ;
	} // eof or found the \n
	// instead of having it in gnl
	i = 0;
	while (i < buf)
	{
		tmp[i] = 0;
		i++;
	}
	return (big);
}
		
char	*ft_bigbuf(char *save, char *tmp) //the \n is in here
{
	char	*str;
	int	i;

	if (save)
		str = inccpy(save, tmp);
	i = 0;
	while (i < buf)
	{
		tmp[i] = 0;
		i++;
	}
	return (str);
}*/


char	*get_next_line(int fd)
{
	static char	*save = "";
	char	tmp[BUFFER_SIZE + 1];
	char	*str;
	int	a;
	int	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_verline(save) == -1) //not in save
	{
		a = read(fd, tmp, BUFFER_SIZE);
//		printf("BUFFER: %d\n", BUFFER_SIZE);
		tmp[BUFFER_SIZE] = 0;
//		printf("tmp[%d] = %c\n", BUFFER_SIZE, tmp[BUFFER_SIZE]);
//		printf("tmp: %s\n", tmp);
		if (a != BUFFER_SIZE || ft_verline(tmp) != -1) // in tmp
			save = ft_bigbuf(save, tmp);
		else					// not in tmp || could a < buf
			save = ft_smallbuf(fd, save, tmp);
	}
	i = 0;
	while ((save[i] != '\n') && (save[i] != '\0')) // here \n always found
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, save, i + 2);
	save += (i + 1);
/*	if (ft_verline(save) == -1)
		free(save);
	else
		save += (i + 1);*/
//	printf("save: %s\n", save);
	return (str);
}
/*
int	main()
{
	int	fd;

	fd = open("3text.txt", O_RDONLY);
	printf("->%s", get_next_line(fd));
	printf("->%s", get_next_line(fd));
	printf("->%s", get_next_line(fd));
	printf("->%s", get_next_line(fd));
	printf("->%s", get_next_line(fd));
	printf("->%s", get_next_line(fd));
	printf("->%s", get_next_line(fd));
	close(fd);
	return (0);
}*/
