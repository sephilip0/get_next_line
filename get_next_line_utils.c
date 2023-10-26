/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:20:21 by sephilip          #+#    #+#             */
/*   Updated: 2023/10/26 17:03:37 by sephilip         ###   ########.fr       */

#include "get_next_line.h"

int	ft_verline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
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

char	*ft_inccpy(char *big, char *glued, int size)
{
	char	*str;
	int	i;

	i = 0;
	if (!big)
		big = "";
	while (big[i])
		i++;
	if (size == 0) //join everything
	{
		while (glued[size])
			size++;
	}
	str = (char *)malloc((i + size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, big, i + 1);
	ft_strlcpy(&(str[i]), glued, size + 1);
	if (*big) //same as big[0] != '\0'
		free(big);
	return (str);
}

char	*ft_cleanbuf(char *buf, int size)
{
	int	i;


	i = size;
	ft_strlcpy(buf, &buf[size], BUFFER_SIZE);
	if (!buf)
		return NULL;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			break;
		}
		buf[i] = 0;
		i++;
	}
	return (buf);
}
/*
int	ft_readline(char **str, char buf[1][BUFFER_SIZE + 1], int fd)
{
	int	a;
	int	size;
	
	while (ft_verline(*str) == -1)
	{
		a = read(fd, *buf, BUFFER_SIZE);
		if (a == 0)
		{
			*buf[0] = 0;
			break ;
		}
		else if (a < 0)
		{
			*buf[0] = 0;
			free(*str);
			return (0);
		}
		*buf[a] = 0;
		size = ft_verline(*buf) + 1;
		*str = ft_inccpy(*str, *buf, size);
		return (size);
	}
	return (-1); 
}*/


char	*ft_readline(char	buf[1][BUFFER_SIZE + 1], char *str, int fd)
{
	int	a;
	int	size;

        if (**buf)
        {   
                size = ft_verline(*buf) + 1;
                str = ft_inccpy(str, *buf, size);
        }
        while (ft_verline(str) == -1) 
        {
                a = read(fd, *buf, BUFFER_SIZE);
                *buf[a] = 0;
                if (a == 0)
                        break;
                if (a < 0)
                        return (NULL);
                size = ft_verline(*buf) + 1;
                str = ft_inccpy(str, *buf, size); //if 0, join everything
        }
        if (**buf)
                ft_strlcpy(*buf, buf[size], BUFFER_SIZE);
        return (str);
}


char	*ft_clear(char	buf[1][BUFFER_SIZE + 1], char *str, int	a)
{
	if (a <= 0)
		*buf[0] = 0;
	if (a < 0)
		free(str);
	return (NULL);
}
