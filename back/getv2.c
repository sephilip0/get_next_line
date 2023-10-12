/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:41:57 by sephilip          #+#    #+#             */
/*   Updated: 2023/10/12 12:35:54 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <stdlib.h>

int	buf = 10;

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

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*inccpy(char *big, char *glued)
{
	char	*str;
	int	i;
	int	j;

//	printf("incbig: %s\n incglue: %s\n", big, glued);
	i = 0;
	j = 0;
	while (big[i])
		i++;
	while (glued[j])
		j++;
//	printf("i + j = %d\n", i + j);
	str = (char *)malloc((i + j + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (big[i])
	{
		str[i] = big[i];
//		printf("str[%d] = (%c)\n", i, str[i]);
		i++;
	}
	while (glued[j])
	{
		str[i + j] = glued[j];
//		printf("str[%d] = (%c)\n", i+j, str[i + j]);
		j++;
	}
	str[i + j] = 0;
//	printf("big: %d glued: %d\n", ft_strlen(big), ft_strlen(glued));
//	printf("i + j = %d\n", (i + j));
//	printf("STRING MALUCA: %s\n", str);
	return (str);
}

char	*ft_smallbuf(int fd, char *save, char *tmp) //the \n not yet found
{
	char	*big;
	int	a;

	if (save)
		big = inccpy(save, tmp);
	else
		big = inccpy(tmp, ""); //meter tudo para o big, para que nao haja probl
	while (ft_verline(tmp) == -1)
	{
		a = read(fd, tmp, buf);
		big = inccpy(big, tmp);
		if (a < buf)
		{
			break ;
		}
	} // eof or found the \n
	return (big); }
		
char	*ft_bigbuf(char *save, char *tmp) //the \n is in here
{
	char	*str;

//	if (a < buf) //eof == A \n esta na save
		
	if (save)
		str = inccpy(save, tmp);
//	printf("SAI DO BIGBUF com %s\n", str);
	return (str);

}// maybe change name to inc and cat?
/*
char	*ft_clean(char *str, int u)
{
	int	i;

	i = 0;
	while (i < u)
	{
		str[i] = 0;

}*/


char	*get_next_line(int fd)
{
	static char	*save = "";
	char	tmp[buf];
	char	*str;
	int	a;
	int	i;


	i = 0;
	while (i < buf)
	{
		tmp[i] = 0;
		i++;
	}
//	printf("TMP SUS: %s\n", tmp);
//	printf("teste: %d\n", ft_verline(save) == -1);
	if (ft_verline(save) == -1) //not in save
	{
		a = read(fd, tmp, buf);
		if (a != buf || ft_verline(tmp) != -1) // in tmp
		{
//			printf("ENTROU BIG: %s + %s com a: %d!\n", save, tmp, a);
			save = ft_bigbuf(save, tmp);
		}
		else					// not in tmp || could a < buf
		{
//			printf("ENTROU SMALL: %s + %s !\n", save, tmp);
			save = ft_smallbuf(fd, save, tmp);
		}
	}
	i = 0;
	while ((save[i] != '\n') && (save[i] != '\0')) // here \n always found
	{
//		printf("FOI: save[%d] = %c\n", i, save[i]);
//		printf("ENCONTROU: %d\n", save[i + 1] == '\n');
		i++;
	}
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
//	printf("SAVE: %s\n", save);
//	printf("SAVE[i]: %c\n", save[3]);
	ft_strlcpy(str, save, i + 2);
//	printf("vai sair: %s com strlen %d\n", str, ft_strlen(str));
	//str[i + 1] = '\n';
	save += (i + 1);
//	printf("str: %s\n", str);
//	printf("save: %s\n", save);
	return (str);
}

int	main()
{
	int	fd;

	fd = open("2text.txt", O_RDONLY);
	printf("->%s", get_next_line(fd));
	printf("->%s", get_next_line(fd));
	printf("->%s", get_next_line(fd));
	printf("->%s", get_next_line(fd));
	close(fd);
	return (0);
}
