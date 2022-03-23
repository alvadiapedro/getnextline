/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:55:15 by pmiranda          #+#    #+#             */
/*   Updated: 2022/03/23 17:44:31 by pmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_ret(char **str, int bytes)
{
	int		nl;
	char	*line;
	char	*temp;

	if (*str == NULL || bytes == -1)
		return (NULL);
	nl = get_new_line(*str);
	//printf("str = %s\n", *str);
	if (nl != -1)
	{
		line = ft_substr(*str, 0, nl);
		printf("line = %s\n", line);
		temp = ft_substr(*str, nl + 1, ft_strlen(*str));
		printf("temp = %s\n", temp);
		printf("str = %s\n", *str);
		free(*str);
		*str = temp;
		if (**str != '\0')
			return (line);
	}
	else
		line = ft_strdup(*str);
	free(*str);
	*str = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	int			bytes;
	char		storage[BUFFER_SIZE + 1];
	static char	*str[OPEN_MAX];
	char		*temp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	bytes = read(fd, storage, BUFFER_SIZE);
	while (bytes > 0)
	{
		storage[bytes] = '\0';
		//printf("str[fd] = %s\n", str[fd]);
		if (str[fd] == NULL)
			str[fd] = ft_strdup("");
		//printf("str[fd] = %s\n", str[fd]);
		temp = ft_strjoin(str[fd], storage);
		//printf("storage = %s\n", storage);
		//printf("temp = %s\n", temp);
		free(str[fd]);
		str[fd] = temp;
		//printf("str[fd] = %s\n", str[fd]);
		if (get_new_line(str[fd]) != -1)
			break ;
		bytes = read(fd, storage, BUFFER_SIZE);
	}
	return (line_ret(&str[fd], bytes));
}

int main()
{
 	int fd;
 	char *line;
 	fd = open("text.txt", O_RDONLY);
 	while (1)
 	{
 		line = get_next_line (fd);
 		if (line == NULL)
 			break ;
 		printf("%s" , line);
 	}
}
