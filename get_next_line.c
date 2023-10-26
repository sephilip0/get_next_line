/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sephilip <sephlip@student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:41:57 by sephilip          #+#    #+#             */
/*   Updated: 2023/10/26 17:04:21 by sephilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 
#include <stdlib.h>
*/


char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char	*str;

	str = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || (read(fd, buf, 0) < 0))
		return (ft_clear(&buf, str, 0));
	return (ft_readline(&buf, str, fd));
}

// CORNER CASES

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
