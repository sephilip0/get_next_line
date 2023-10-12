/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:43:20 by sephilip          #+#    #+#             */
/*   Updated: 2023/10/12 12:13:54 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*
int	main(void)
{
	static char	*str;
	static int	a = 0;
	int			size;
	int			i;
	int	b = 0;

	a++;
	i = 0;
	size = 10;
	str = (char *)malloc(size * sizeof(char *));
	while (i < size)
	{
		str[i] = 'a';
		i++;
	}
	printf("%s\n", str);
	printf("%d\n", a);
	return (0);
}*/

int	main()
{
	char	tmp[10];
	int	buf = 10;
	int	fd;
	int	a;
	int	i;

	i = 0;
	fd = open("1text.txt", O_RDONLY);
	a = read(fd, tmp, buf);
	printf("->%s %d\n", tmp, a);
	while (tmp[i])
	{
		tmp[i] = 0;
		i++;
	}
	a = read(fd, tmp, buf);
	printf("->%s %d\n", tmp, a);
	a = read(fd, tmp, buf);
	printf("->%s %d\n", tmp, a);
	return (0);
}
