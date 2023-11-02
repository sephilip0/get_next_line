/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:20:21 by sephilip          #+#    #+#             */
/*   Updated: 2023/10/24 22:04:55 by sephilip         ###   ########.fr       */

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

//	printf("DST: %s STR: %s\n", dst, src);
	len = 0;
	i = 0;
	while (src[len])
		len++;	
	if (!size)
		return (len);
	while (src[i] && (i < size - 1))
	{
//		printf("DST[%zu] = %c\n\n", i, dst[i]);
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
//	printf("big: %s\nglued: %s\nsize: %d\n", big, glued, size);
	if (!big)
	{
//		printf("BRO\n");
		big = "";
	}
	while (big[i])
		i++;
	if (size == 0) //join everything
	{
		while (glued[size])
			size++;
	}
//	printf("malozinho: %d\n", size + i + 1);
	str = (char *)malloc((i + size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, big, i + 1);
//	printf("string1: %s\n", str);
	ft_strlcpy(&(str[i]), glued, size + 1);
//	printf("string2: %s\n", str);
	if (*big) //same as big[0] != '\0'
	{
//		printf("liberdade para o: %s\n", big);
		free(big);
	}
//	printf("len: %d RET: %s\n", (i + j + 1), str);
	return (str);
}
/*
char	*ft_save(char	*str)
{
// recorte do str, o resto no buf

//a = numero a partir do qual queremos cortar
	char	*ret;
	int	i;

	if (*str == '\0')
	{
		free(str);
		return(NULL);
	}
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
//	printf("i: %d a: %d\n", i, a);
	ret = (char *)malloc((i + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, str, (i + 1));
	//quanto cortamos do buffer?
	//ft_strlcpy(*buf, buf[a], BUFFER_SIZE);
//	printf("abandonar navio: %s\n", save);
//	printf("capitao com %s!\n", ret);
	free(str);
	return (ret);
}*/
