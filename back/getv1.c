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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;
	size_t	j;

	len = 0;
	while (len < size && dst[len])
		len++;
	j = ft_strlen(src);
	if (len == size)
		return (len + j);
	i = 0;
	while (src[i] && (i < size - len - 1))
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = 0;
	return (len + j);
}

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
	while (i < size)
	{
		ret[i] = '\0';
		i++;
	}
	ft_strlcat(ret, ptr, size + 1);
	return (ret);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
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

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);	
}

char	*ft_savior(int	fd, char *save)
{
	char	*big;
	char	*tmp;
	unsigned	int	i;
	unsigned	int	size;
	int	delbug;

	size = delbuf;
	i = 0;
	tmp = (char *)malloc(buf * sizeof(char));
	if (!tmp)
		return (NULL);
	if (save) //there is leftovers
	{
		if (ft_findchr(save, '\n') != -1)
			return (save);
		big = ft_resize(save, size + ft_strlen(save));
	}
	a = read(fd, tmp, delbuf);
	if (ft_findchr(tmp, '\n') != -1) // maybe with tmp '\n' and save
	{
		big = ft_resize(big, tmp, size + ft_strlen(save) + ft_strlen(tmp);
		return (big);
	}
	while (ft_findchr(tmp, '\n') == -1) //doesnt consider save
	{
		size += delbuf;
		big = ft_resize(tmp, size);
		a = read(fd, tmp, delbuf);
		ft_strlcat(big, tmp, size);
	}
	//found '\n' somewhere
	free(tmp);
	return (big);
	if (a < delbuf) //eof
}

char	*get_next_line(int	fd)
{
	static	char	*save = NULL;
	char	*str;
	int	i;
	int	inc;

	i = 0;
	inc = 0;
	save = ft_savior(fd, save);
//	think about leftovers
	while (save[i] != '\n')
		i++;
//	space for '\n' and '\0'
	str = (char *)malloc((i + 2) * sizeof(char));
	ft_strlcpy(str, save, i + 2);
	str[i + 1] = '\n';
	save += i;
	return (str);
}

int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
