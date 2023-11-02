/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:41:57 by sephilip          #+#    #+#             */
/*   Updated: 2023/11/02 16:04:39 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[MAX_FD][BUFFER_SIZE + 1];
	char		*str;
	int			a;
	int			size;

	str = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || (read(fd, buf[fd], 0) < 0))
		return (ft_clear(buf, str, fd, -1));
	if (*buf[fd])
	{
		size = ft_verline(buf[fd]) + 1;
		str = ft_inccpy(str, buf[fd], size);
	}
	while (ft_verline(str) == -1)
	{
		a = read(fd, buf[fd], BUFFER_SIZE);
		if (a <= 0)
			return (ft_clear(buf, str, fd, a));
		buf[fd][a] = 0;
		size = ft_verline(buf[fd]) + 1;
		str = ft_inccpy(str, buf[fd], size);
	}
	if (*buf[fd])
		ft_strlcpy(buf[fd], &buf[fd][size], BUFFER_SIZE);
	return (str);
}
// F_OPENMAX

/*
int	main()
{
	int	fd;
	char	*ptr;

	fd = open("41_no_nl", O_RDONLY);
	ptr = get_next_line(fd);
	printf("--->%s!", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("--->%s!", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("--->%s!", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("--->%s!", ptr);
	free(ptr);
	ptr = get_next_line(fd);
	printf("--->%s", ptr);
	free(ptr);*
	ptr = get_next_line(fd);
	printf("--->%s", ptr);
	free(ptr);
	close(fd);
	return (0);
}*/
