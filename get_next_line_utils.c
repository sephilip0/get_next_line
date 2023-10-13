/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:20:21 by sephilip          #+#    #+#             */
/*   Updated: 2023/10/13 12:35:03 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		a = read(fd, tmp, BUFFER_SIZE);
		big = inccpy(big, tmp);
		if (a < BUFFER_SIZE)
			break ;
	} // eof or found the \n
	// instead of having it in gnl
	i = 0;
	while (i < BUFFER_SIZE)
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
	while (i < BUFFER_SIZE)
	{
		tmp[i] = 0;
		i++;
	}
	return (str);
}
