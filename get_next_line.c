/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:41:57 by sephilip          #+#    #+#             */
/*   Updated: 2023/10/10 21:37:17 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <stdlib.h>


char	*ft_resize(char *ptr, size_t size)
{
	char	*ret;
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (ptr[len])
		len++;
	if (size > len)
		return (ptr);	
	ret = (char *)malloc((size + 1) * sizeof(char));
	while (ptr[i])
	{
		ret[i] = ptr[i];
		i++;
	}
	while (ret[i])
	{
		ret[i] = 0;
		i++;
	}
	return (ret);
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

int	ft_untilfind(int fd, char *tmp, unsigned int buf)
{
	int	counter;
	int	ar;
// e vamos meter o tmp onde?
	counter = 1;
	ar =  read(fd, tmp, buf);
	while (ar >= buf) //check for eof
	{
		if (ft_verline(tmp) != -1) //finally found the \n
			return (counter);
		ar = read(fd, tmp, buf);
		counter++;
	}
	return(counter);
}


char	*get_next_line(int fd)
{
	char	*str;
	char	*tmp;
	int	cpos;
	int	i;
	unsigned int	buf = 10;
	static unsigned int	pos = 0;
// se no buffer encontrarmos o \n entao corta ai
// caso contrario, teremos que ler outra vez?

	tmp = (char *)malloc(buf * sizeof(char));
	cpos = read(fd, tmp, buf);
	i = ft_verline(tmp)
	while (i == -1)
	{
		read(fd, tmp, buf)
		if (ft_verline(tmp) = 
		


	}
/*	while (cpos < buf) //eof
	{
		i = ft_verline(&tmp[pos]);
		if (i == -1)
			cpos = read(fd, tmp, buf);
			//change value of tmp!!! check if tmp is empty
		else
			break ;
	}
	if (i != -1)
	{
		str = (char *)malloc((i + 2) * sizeof(char));
		while (pos > i)
		{
			str[pos] = tmp[pos];
			pos++;
		}
		str[cpos] = '\n';
		str[cpos + 1] = 0;
	}*/
	return (str);
}

int	main()
{
	int	fd;
	char	*abc;

	fd = open("test.txt", O_RDONLY);
	abc = get_next_line(fd);
//	printf("%s\n", abc);
	close(fd);
	return (0);
}
