/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:41:57 by sephilip          #+#    #+#             */
/*   Updated: 2023/10/19 15:13:54 by sephilip         ###   ########.fr       */
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

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*save = "";
	int	a;
	char	tmp[BUFFER_SIZE + 1];
	char	*str;
	int	i;

	if (BUFFER_SIZE <= 0 || fd < 0 || (read(fd, tmp, 0) < 0))
		return (NULL);
	if (ft_verline(save) == -1) //not in save
	{
		a = read(fd, tmp, BUFFER_SIZE);
		tmp[a] = 0;
	//	printf("LIDO: %s\n\n", tmp);
		save = ft_bufan(fd, save, tmp, a);
	}
	i = 0;
	while ((save[i] != '\n') && (save[i] != '\0')) // here \n always found
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, save, i + 2);
//	printf("SAVE ANTES: %s com len: %d\n\n", save, ft_strlen(save));
	str = ft_save(str, (0));
	save = ft_save(save, (i + 1));
//	printf("SAVE DEPOIS: %p\n\n", save);
//	printf("str: %s\n", str);
	return (str);
}
// CORNER CASES
/*
int	main()
{
	int	fd;
	char	*ptr;

	fd = open("empty.txt", O_RDONLY);
	ptr = get_next_line(fd);
	printf("--->%s", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("--->%s", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("--->%s", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("--->%s", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("--->%s", ptr);
	free(ptr);
	close(fd);
	return (0);
}*/
