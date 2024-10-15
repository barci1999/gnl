/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-13 16:26:56 by pablalva          #+#    #+#             */
/*   Updated: 2024-10-13 16:26:56 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*make_line(char **container, char *buffer, int bts_read, char *line)
{
	int		i;
	char	*temp;
	char 	*str_sub;

	i = 0;
	while (i < bts_read)
	{
		if (buffer[i] == '\n')
		{
			str_sub = ft_substr(buffer, 0, i + 1);
			temp = ft_strjoin(line, str_sub);
			free(line);
			free(str_sub);
			line = temp;
			free(*container);
			if (i + 1 < bts_read)
			{
				*container = ft_strdup(&buffer[i + 1]);
			}
			else
				*container = NULL;
			return (line);
		}
		i++;
	}
	if (line == NULL)
	{
		line = ft_strdup(buffer);
	}
	else
	{
		temp = ft_strjoin(line, buffer);
		free(line);
		line = temp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*container;
	char		buffer[BUFFER_SIZE + 1];
	int			bts_read;
	char		*line;

	line = NULL;
	if (container)
	{
		line = ft_strdup(container);
		free(container);
		container = NULL;
	}
	bts_read = read(fd, buffer, BUFFER_SIZE);
	while ((bts_read) > 0)
	{
		buffer[bts_read] = '\0';
		line = make_line(&container, buffer, bts_read, line);
		if (container)
			return (line);
		bts_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bts_read < 0)
	{
		free(line);
		return(NULL);
	}
	if(line)
		return(line);
	return (NULL);
}
int main()
{
	int fd;
	char *line;

	fd = open("chistes.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error abriendo el archivo");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line); // Sin "\n".
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}