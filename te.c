#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	buf = 10;

int	ft_findchr(const char *s, int c)
{
	int		i;
	char	*p;

	c = (unsigned char)c;
	p = (char *)s;
	i = 0;
	while (p[i])
	{
		if (p[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_savior(int	fd)
{
	char	*big;

	big = (char *)malloc(buf * sizeof(char));
	a = read(fd, big, buf);
	if (ft_findchr(big, '\n') == -1)
		a = read(fd, big, buf);
		




	if (a < buf) //eof	
}

char	*get_next_line(int	fd)
{
	char	*str;
	int	a;

	printf("%s e %d\n", str, a);
}

int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
