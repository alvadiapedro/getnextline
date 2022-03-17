/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:55:37 by pmiranda          #+#    #+#             */
/*   Updated: 2022/03/17 16:53:06 by pmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_new_line(char *str)
{
	int	nl;

	if (!str)
		return (-1);
	nl = 0;
	while (str[nl] != '\0')
	{
		if (str[nl] == '\n')
			return (nl);
		nl++;
	}
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t end)
{
	char		*sub;
	size_t		i;
	size_t		size;

	size = end - start + 1;
	sub = (char *) malloc(sizeof(char) * (size + 1));
	i = 0;
	while (start <= end && s[start] != '\0')
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	char	*aux;
	int		i;

	i = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	aux = dest;
	while (*src)
		*aux++ = *src++;
	*aux = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc (sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	return (s3);
}
