/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jianwong <jianwong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:11:20 by jianwong          #+#    #+#             */
/*   Updated: 2024/11/26 13:13:47 by jianwong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*call_read(int fd, int *size, char *buf)
{
	char	*buffer;

	if (buf)
		free(buf);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	*size = read(fd, buffer, BUFFER_SIZE);
	buffer[*size] = '\0';
	return (buffer);
}

static char	*fill_buffer(int fd, char *buf)
{
	char	*buffer;
	int		size;
	char	*temp;	

	if (!buf)
	{
		buf = ft_calloc(1, 1);
		if (!buf)
			return (NULL);
	}
	buffer = NULL;
	buffer = call_read(fd, &size, buffer);
	if (size < 0)
		return (NULL);
	while (size > 0)
	{
		temp = ft_strjoin(buf, buffer);
		free(buf);
		buf = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
		buffer = call_read(fd, &size, buffer);
	}
	free(buffer);
	return (buf);
}

static char	*make_str(char *buf)
{
	char	*ptr;
	int		j;
	int		i;

	i = 0;
	j = -1;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (!i && buf[i] != '\n')
		return (NULL);
	ptr = ft_calloc(i + 2, 1);
	if (!ptr)
		return (NULL);
	while (++j <= i)
		ptr[j] = buf[j];
	return (ptr);
}

static char	*adjust_buffer(char *buf)
{
	char	*temp;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = -1;
	temp = NULL;
	while (buf[i] != '\n' && buf[i])
		i++;
	size = ft_strlen(buf) + 1 - i;
	if (size == 1)
	{
		free(buf);
		return (NULL);
	}
	temp = ft_calloc(size, 1);
	if (!temp)
		return (NULL);
	while (buf[++i])
		temp[++j] = buf[i];
	free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer[fd] || !ft_strchr(buffer[fd], '\n'))
		buffer[fd] = fill_buffer(fd, buffer[fd]);
	result = make_str(buffer[fd]);
	buffer[fd] = adjust_buffer(buffer[fd]);
	return (result);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int	fd;
// 	int fd2;
// 	int	i;
//
// 	i = 0;
// 	fd = open("./test.txt", O_RDONLY);
// 	fd2 = open("./test2.txt", O_RDONLY);
// 	// while (read(fd, buffer, 1))
// 	// {
// 	// 	if (*buffer == '\n')
// 	// 		i++;
// 	// }
// 	// printf("%d\n", i);
// 	while (i < 6)
// 	{
// 		printf("%d %s\n",i ,get_next_line(fd));
// 		printf("%d %s\n",i ,get_next_line(fd2));
// 		i++;
// 	}
// }
