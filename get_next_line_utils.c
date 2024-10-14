/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablalva <pablalva@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-13 16:26:52 by pablalva          #+#    #+#             */
/*   Updated: 2024-10-13 16:26:52 by pablalva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*d_less_len(char *dest, const char *s, unsigned int start, size_t len)
{
	size_t	d;

	d = 0;
	while (d < len)
	{
		dest[d] = s[start + d];
		d++;
	}
	dest[d] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dest = malloc(1 * sizeof(char));
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	d_less_len(dest, s, start, len);
	return (dest);
}
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l;
	char	*ns;
	int		i;
	int		j;

	l = ft_strlen(s1) + ft_strlen(s2);
	ns = (char *)malloc((l + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ns[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ns[i] = s2[j];
		i++;
		j++;
	}
	ns[i] = '\0';
	return (ns);
}
char	*ft_strdup(const char *s)
{
	char *dest;
	int i;

	i = ft_strlen(s);
	dest = malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}