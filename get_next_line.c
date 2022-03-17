/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiranda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:55:15 by pmiranda          #+#    #+#             */
/*   Updated: 2022/03/17 15:13:13 by pmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_ret(char **str, int bytes)
{
	int	new_line;
	char	*line;
	char	*temp;

	if (*str == NULL || bytes == -1)
	    return (NULL);
	new_line = get_new_line(*str);
	if (new_line != -1)
	{
		line = ft_substr(*str, 0, new_line);
		temp = ft_substr(*str, new_line + 1, ft_strlen(*str));
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
	while (bytes < 0)
	{
		storage[bytes] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup("");
		temp = ft_strjoin(str[fd], storage);
		free(str[fd]);
		str[fd] = temp;
		if (get_new_line(str[fd]) != -1)
			break ;
		bytes = read(fd, storage, BUFFER_SIZE);
	}
	return (line_ret(&str[fd], bytes));
}

/*int main()
{
 	int fd;
 	char *line;
 	fd = open("test.txt", O_RDONLY);
 	while (1)
 	{
 		line = get_next_line (fd);
 		if (line == NULL)
 			break ;
 		printf("%s" , line);
 	}
}*/
