#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	buf = 10;

int	ft_strlen(const char	*p)
{
	int	i;
	char	*str;

	str = (char *)p;
	i = 0;
	while (str[i])
		i++;
	return (i);	
}

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
	size_t	len;
	size_t	i;

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
	printf("RETURN FROM RESIZE: %s\n", ret);
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

char	*ft_savior(int	fd, char *save)
{
	char	*big;
	char	*tmp;
	unsigned	int	size;
	int	delbuf = 10;
	int	a;

	size = delbuf;
	tmp = (char *)malloc(delbuf * sizeof(char));
	if (!tmp)
		return (NULL);
	if (save) //there is leftovers
	{
		if (ft_findchr(save, '\n') != -1) // there it \n inside;
		{
			printf("volta: %s\n", save);
			return (save);
		}
		size += ft_strlen(save);
		big = ft_resize(save, size);
		a = read(fd, tmp, delbuf);
		ft_strlcat(big, tmp, size); // big is now save + tmp;
	}
	else
	{
		a = read(fd, tmp, delbuf);
		big = ft_resize(tmp, size); // big is now tmp, just to ini big
	}
	if (a < delbuf || ft_findchr(big, '\n') != -1)
	{
		return (big);
	}
	while (a == delbuf || ft_findchr(tmp, '\n') == -1) // while we still doesnt find \n;
	{
		size += delbuf;
		big = ft_resize(big, size);
		a = read(fd, tmp, delbuf);
		ft_strlcat(big, tmp, size);
	}
	//found '\n' somewhere
//	free(tmp);
	printf("RETURN FROM FT_SAVIOR\n");
	return (big);
}

char	*get_next_line(int	fd)
{
	static	char	*save = NULL;
	char	*str;
	int	i;

//	printf("ENTERED GNL\n");
	i = 0;
	save = ft_savior(fd, save);
//	think about leftovers
	while (save[i] != '\n')
		i++;
//	space for '\n' and '\0'
	str = (char *)malloc((i + 2) * sizeof(char));
	ft_strlcpy(str, save, i + 2);
	str[i + 1] = '\n';
	save += i;
	printf("RETURN FROM GNL: %s\n", str);
	return (str);
}

int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("->%s\n", get_next_line(fd));
	printf("->%s\n", get_next_line(fd));
	return (0);
}
