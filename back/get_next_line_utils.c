/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 12:20:21 by sephilip          #+#    #+#             */
/*   Updated: 2023/10/20 16:55:30 by sephilip         ###   ########.fr       */

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
//		printf("DST[%zu] = %c\n\n", i, dst[i]);
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
	if (big[0] != '\0')
	{
//		printf("liberdade para o: %s\n", big);
		free(big);
	}
//	printf("len: %d RET: %s\n", (i + j + 1), str);
	return (str);
}

char	*ft_bufan(int fd, char *save, char *tmp, int	a) //the \n not yet found
{
	char	*big;
	int	i;

	if (save)//ha save mas \n nao esta la
		big = inccpy(save, tmp);
	else
		big = inccpy("", tmp);
	while (a == BUFFER_SIZE && ft_verline(big) == -1)
	{
		a = read(fd, tmp, BUFFER_SIZE);
		tmp[a] = 0;
//			printf("a: %d tmp: %s\n", a, tmp);
		big = inccpy(big, tmp);
		if (a < BUFFER_SIZE)
		break ;
	} // eof or found the \n
	i = 0;
	while (i < BUFFER_SIZE)
	{
		tmp[i] = 0;
		i++;
	}
	return (big);
}

char	*ft_save(char	*save, int	a)
{

//a = numero a partir do qual queremos cortar
	char	*ret;
	int	i;

	if (save[0] == 0)
	{
		free(save);
		save = "";
		return(NULL);
	}
	i = 0;
	while (save[i])
		i++;
	if (i <= a) // nao ha save que sobre depois do corte
	{
		free(save);
		save = "";
		return (NULL);	
	}
	ret = (char *)malloc((i - a + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, &(save[a]), (i + 1));
	free(save);
	return (ret);
}
