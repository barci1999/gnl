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
	while((bts_read = read(fd,buffer,BUFFER_SIZE)) > 0)
	{
		buffer[bts_read] = '\0';
		line = make_line(&container,buffer,bts_read,line);
		if(container)
			return(line);
	}
	if(bts_read == 0 && line)
		return(line);
	return(NULL);
}
/*int main(void)
{
    // Abre el archivo en modo lectura
    int fd = open("prueba.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error al abrir el archivo.\n");
        return (1);
    }

    char *line;
    // Leer línea por línea hasta que get_next_line devuelva NULL (EOF)
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Línea: %s", line);
        free(line);  // Libera la memoria después de procesar la línea
    }

    // Cierra el archivo
    close(fd);

    return 0;
}*/