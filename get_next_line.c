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

char *make_line(char **container, char *buffer, int bts_read, char *line)
{
	int i;
	i = 0;
	char *temp;

	while(i < bts_read)
	{
		if(buffer[i] == '\n')
		{
			temp = ft_strjoin(line,ft_substr(buffer,0, (i + 1)));
			free(line);
			line = temp;
			*container = ft_strdup(&buffer[i + 1]);
			return(line);
		}
		i++;
	}
	if(line == NULL)
		line = ft_strdup(buffer); 
	else
	{
		temp = ft_strjoin(line,buffer);
		free(line);
		line = temp;
	}
	return(line);
	}
  
char *get_next_line(int fd)
{
	static char *container;
	char buffer[BUFFER_SIZE];
	int bts_read;
	char *line;

	line = NULL;
	if(container)
	{
		line = ft_strdup(container);
		free(container);
	}
	container = NULL;
	while((bts_read = read(fd,(char *)buffer,BUFFER_SIZE)) > 0)
	{
		line = make_line(&container,buffer,bts_read,line);
		if(container)
			return(line);
	}
	if(bts_read == 0 && line)
		return(line);
	return(NULL);
}