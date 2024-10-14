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

char	*ft_strchr(const char *s)
{
	int	i;
	int c;
	
	c = '\n';
	i = 0;
	while (s[i] != '\0')
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char *get_next_line(int fd)
{	
	int bts_read ;
	static char *container;
	char  *rded_line;
	char *temp;
	int i;
	i = 0;
	temp = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if(temp == NULL)
		free(temp);
		return;
	bts_read = 1;
	while (bts_read > 0)
	{
		bts_read = read(fd, &temp, BUFFER_SIZE);
		if(bts_read < 0)
		{
			free(bts_read);
			return(NULL);
		}
		rded_line = ft_strchr(temp);
		if(rded_line != NULL && *rded_line == '\n')
		{
			return(rded_line);
		}
			
	}
}
		

